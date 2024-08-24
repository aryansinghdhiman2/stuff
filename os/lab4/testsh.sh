echo "Insert Value of x"
read x
echo "Insert Value of y"
read y
z=$(($x+$y))

sum1=`expr $x + $y`
sum2=`echo $x + $y | bc `

echo Sum1 is $sum1
echo Sum2 is $sum2
echo z is $z

