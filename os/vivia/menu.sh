#!/bin/sh

echo "Enter the first number: "
read num1

echo "Enter the second number: "
read num2

echo "Enter 1 for addition"
echo "Enter 2 for subtraction"
echo "Enter 3 for division"
echo "Enter 4 for multiplication"
read choice

case $choice in
    1) result=$(($num1 + $num2))
       echo "The sum of $num1 and $num2 is: $result"
       ;;
    2) result=$(($num1 - $num2))
       echo "The difference of $num1 and $num2 is: $result"
       ;;
    3) if [ $num2 -eq 0 ]; then
           echo "Error: Division by zero"
           exit
       fi
       result=`echo "$num1 / $num2" | bc`
       echo "The quotient of $num1 and $num2 is: $result"
       ;;
    4) result=`echo "$num1 * $num2" | bc`
       echo "The product of $num1 and $num2 is: $result"
       ;;
    *) echo "Invalid choice, please try again"
       ;;
esac
