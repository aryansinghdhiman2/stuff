echo "Enter the number for which you want factorial"
read n

res=1

while [ $n -gt 0 ]
do
	res=`echo "$res * $n" | bc `
	n=`echo "$n - 1" | bc`
done

echo "Factorial is $res"