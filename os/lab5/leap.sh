echo "Enter year: "
read year

result=`echo "$year % 4" | bc `

if [ $result -eq 0 ]
then
	echo "Year is Leap"
else
	echo "Year is not leap"
fi
