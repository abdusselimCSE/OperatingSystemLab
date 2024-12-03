class Process:
    def __init__(self, id, burst_time, priority):
        self.id = id
        self.burst_time = burst_time
        self.priority = priority
        self.waiting_time = 0
        self.turnaround_time = 0


def calculate_waiting_time(processes):
    processes[0].waiting_time = 0
    for i in range(1, len(processes)):
        processes[i].waiting_time = (
            processes[i - 1].waiting_time + processes[i - 1].burst_time
        )


def calculate_turnaround_time(processes):
    for process in processes:
        process.turnaround_time = process.waiting_time + process.burst_time


def print_results(processes):
    total_waiting_time = 0
    total_turnaround_time = 0

    print("Process\tB-Time\tPriority\tW-Time\tT-Time")
    for process in processes:
        print(
            f"P{process.id}\t\t{process.burst_time}\t\t{process.priority}\t\t{process.waiting_time}\t\t{process.turnaround_time}"
        )
        total_waiting_time += process.waiting_time
        total_turnaround_time += process.turnaround_time

    avg_waiting_time = total_waiting_time / len(processes)
    avg_turnaround_time = total_turnaround_time / len(processes)

    print(f"\nAverage Waiting Time: {avg_waiting_time}")
    print(f"Average Turnaround Time: {avg_turnaround_time}")


def main():
    n = int(input("Enter the number of processes: "))
    processes = []

    for i in range(n):
        burst_time = int(input(f"Enter burst time for process {i + 1}: "))
        priority = int(input(f"Enter priority for process {i + 1}: "))
        processes.append(Process(i + 1, burst_time, priority))

    processes.sort(key=lambda x: x.priority)

    calculate_waiting_time(processes)
    calculate_turnaround_time(processes)
    print_results(processes)


if __name__ == "__main__":
    main()
