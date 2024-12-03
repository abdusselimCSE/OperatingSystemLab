#!/bin/bash

echo "Enter a number"
read number

if [ $((number%2)) -eq 0 ]; then
    echo "$number is even"
else
    echo "$number is odd"
fi


# echo "Enter two numbers"
# read num1 num2

# if [ $num1 -gt $num2 ];then
#     echo "$num1 is greater than $num2"
# elif [ $num2 -gt $num1 ];then
#     echo "$num2 is greater than $num1"
# else
#     echo "$num1 and $num2 are equal"
# fi




# echo "Enter two numbers and an operator (+, -, *, /)"
# read num1 num2

# while true; do
#     read oprtr
#     if [ "$oprtr" = "exit" ];then
#         break
#     fi
#     if [ "$oprtr" = "+" ];then
#         result=$((num1 + num2))
#         echo "Result: $num1 + $num2 = $result"
#     elif [ "$oprtr" = "-" ];then
#         result=$((num1 - num2))
#         echo "Result: $num1 - $num2 = $result"
#     elif [ "$oprtr" = "*" ];then
#         result=$((num1 * num2))
#         echo "Result: $num1 * $num2 = $result"
#     else
#         result=$((num1 / num2))
#         echo "Result: $num1 / $num2 = $result"
#     fi
# done

# echo "Enter your name"
# read name

# echo "$name, you are good boy:)"

# for num in {10..1}; do
#   echo $num
#   ((num-=2))
# done

# for ((i=10; i>=1; i-=2)); do
#   echo "Iterate $i"
# done



# count=1
# while [ $count -lt 5 ]
# do
#   echo "Count is $count"
#   ((count++))
# done

#!/bin/bash

# num=1
# until [ $num -gt 10 ]; do
#   echo "7 * $num = $((7 * num))"
#   num=$((num + 1))
# done

# echo "---------------"

# cnt=1
# while [ $cnt -le 10 ]; do
#     echo "7 * $cnt = $((7 * cnt))"
#     cnt=$((cnt + 1))
# done


# friends=('Sayem' 'Ahmed', 'Jilany')
# echo ${friends[*]}

# i=1
# while [ $i -le 10 ]; do
#     a=$((i * 7))
#     b=7
#     echo "$b * $i = $a"
#     i=$((i + 1))
# done





# sum=('1' '2' '4')
# sum[9]=6
# echo ${sum[3]}

# total=0
# echo "Full array = ${sum[@]}"
# echo "${!sum[@]}"
# echo "length = ${#sum[@]}"
# echo "${sum[9]}"

# for element in ${sum[@]}; do
#     total=$((total + element))
# done

# echo "Total sum = $total"


# read -p "File_Name: " file_name
# # if [ -e $file_name ]
# # then echo "File exists"
# # else echo "File doesn't exist"
# # fi


# if [ -f $file_name ]
# then echo "Take input : "
# cat >> $file_name
# else echo "title not found"
# fi
