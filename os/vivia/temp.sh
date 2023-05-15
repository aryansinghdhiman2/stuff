echo "Enter Array"
read -a array

len=${!array[@]}
# echo $len
# a=$(($len - 1))

for i in $len
do
    for j in $len
    do
        if [ ${array[$j]} -gt ${array[$(($j + 1))]} ]
        then
            
            temp=${array[j]}
            array[j]=${array[$(($j + 1))]}
            array[$(($j + 1))]=$temp
            # echo "Swap"
        fi 
    done 
done

for i in ${array[@]}
do 
    echo -n "$i "
done
echo ""