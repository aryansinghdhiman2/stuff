echo "Enter number till you want prime: "
read pri

echo -n "2 "

for i in $(seq 2 $pri)
do
	#echo "i:$i"
	varvar=`expr $i - 1`
	#echo "varvar:$varvar"
	for j in $(seq 2 $varvar)
	do
		#echo "j:$j"
		ifEqual=`expr $i % $j `
		#echo "ifEqual:$ifEqual"
		#echo "Other:$j $varvar $i"
		if [ $ifEqual -eq 0 ]
		then
			break
		elif [ $j -eq $varvar ]
		then
			echo -n "$i "
		fi
	done
done
		