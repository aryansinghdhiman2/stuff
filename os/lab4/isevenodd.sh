echo Enter Number:
read x
if [ $(($x%2)) -eq 0 ]
	then
		echo "Even"
else
	echo "Odd"
fi
