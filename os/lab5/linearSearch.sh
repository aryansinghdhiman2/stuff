echo "Enter array"
read -a arr

echo "Enter number to be searched"
read num

found=0

for i in ${!arr[@]}
do
	if [ $num -eq ${arr[$i]} ]
	then
		echo "Found at index $i"
		found=1
		break
	fi
done

if [ $found -eq 0 ]
then
	echo "Not Found"
fi
