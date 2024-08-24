echo "Enter array"
read -a arr

echo "Enter number to be searched"
read num

#sorting
l=0
i=${#arr[@]}
while [ $l -lt $(($i - 1)) ]
do
	#echo "numnum:${array[$l]}  ${array[$(($l+1))]}"
	if [ ${arr[$l]} -gt ${arr[$(($l + 1))]} ]
	then
		#echo "Temp:$temp"
		temp=${arr[$l]}
		arr[$l]=${arr[$l+1]}
		arr[$(($l + 1))]=$temp
		l=0
	else
		l=$(($l + 1))
	fi
done

echo "Sorted Array is:"
for i in ${!arr[@]}
do
	echo -n "${arr[$i]} "
done
echo ""

found=0

start=0
end=$((${#arr[@]} - 1))

while [ $start -le $end ]
do
	mid=`echo "( $end + $start ) / 2" | bc`
	if [ ${arr[mid]} -eq $num ]
	then
		echo "Found at $mid"
		found=1
		break
	elif [ ${arr[mid]} -gt $num ]
	then
		end=`expr $mid - 1`
	else
		start=`expr $mid + 1`
	fi
done
if [ $found -eq 0 ]
then
	echo "Not Found"
fi
