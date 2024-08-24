echo "Enter number upto which you want Fibonacci series: "
read fb

a=0
b=1
c=`expr $a + $b`
echo -n "$a $b "

while [ $c -le $fb ]
do
	echo -n "$c "
	a=$b
	b=$c
	c=`expr $a + $b `
done
echo ""