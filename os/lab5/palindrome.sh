echo "Enter number for which you want palindrone "
read n

temp=$n
rev=0
count=-1
temp2=$n
while [ $temp2 -gt 0 ]
do
	count=`expr $count + 1`
	temp2=`expr $temp2 / 10`
done

while [ $temp -gt 0 ]
do
	rev=`echo "( $temp % 10 ) * ( 10 ^ $count) + $rev" | bc`
	temp=`expr $temp / 10`
	count=`expr $count - 1`
	#echo "$rev $temp $count $n"
done

if [ $rev -eq $n ]
then
	echo "Is Palindrome"
else
	echo "Is not Palindrome"
fi