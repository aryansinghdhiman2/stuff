#!/bin/sh

echo "Enter the first number: "
read num1

echo "Enter the second number: "
read num2

echo "Choose an operation to perform:"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
read choice

case $choice in
    1) result=$(($num1 + $num2))
       echo "The sum of $num1 and $num2 is: $result"
       ;;
    2) result=$(($num1 - $num2))
       echo "The difference of $num1 and $num2 is: $result"
       ;;
    3) result=$(($num1 * $num2))
       echo "The product of $num1 and $num2 is: $result"
       ;;
    4) if [ $num2 -eq 0 ]; then
           echo "Error: Division by zero"
           exit
       fi
       result=$(($num1 / $num2))
       echo "The quotient of $num1 and $num2 is: $result"
       ;;
    *) echo "Invalid choice, please try again"
       ;;
esac

