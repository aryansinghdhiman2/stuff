echo Enter Basic Salary
read basSal
echo Enter DA in percentage
read da
echo Enter all allowances
read all
echo Enter annual tax
read at

intermed=$(($basSal + $all - $at))
daConv=`echo "$da * $basSal / 100" | bc `

echo Gross Salary is `echo "$intermed + $daConv" | bc`

