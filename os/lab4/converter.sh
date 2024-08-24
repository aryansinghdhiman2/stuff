echo Enter F for f-to-c or C for c-to-f
read chic
if [ $chic = 'F' ] 
then
	echo Enter Temperature
	read temp
	cels=$(($(($temp-32))*5/9))
	echo Temperature in Celsius is $cels
elif [ $chic = 'C' ]
then
	echo Enter Temperature
	read temp
	fahrn=$(($(($temp*9/5))+32))
	echo Temperature in Fahreheit is $fahrn
else
	echo Invalid Input
fi
