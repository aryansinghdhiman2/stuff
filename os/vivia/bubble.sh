echo "Enter Array"
read -a array
l=0
i=${#array[@]}
while [ $l -lt $(($i - 1)) ]
do
	if [ ${array[$l]} -gt ${array[$(($l + 1))]} ]
	then
		temp=${array[$l]}
		array[$l]=${array[$l+1]}
		array[$(($l + 1))]=$temp
		l=0
	else
		l=$(($l + 1))
	fi
done

for i in ${!array[@]}
do
	echo -n "${array[$i]} "
done

echo ""