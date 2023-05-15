echo "Enter number upto which you want series"
read n

a=0
b=1

echo -n "$a "
echo -n "$b "
while [ $a -le $n ]
do 
    c=$(($a+$b))
    echo -n "$c "
    a=$b
    b=$c 
done
echo " "