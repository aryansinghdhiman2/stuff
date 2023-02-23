echo Enter Marks for DSA
read dsa
echo Enter Marks for DBMS
read dbms
echo Enter Marks for Economics
read eco
echo Enter Marks for Microprocessor
read micr
echo Enter Marks for Discrete Mathematics
read disc

averageMarks=$(($(($dsa+$dbms+$eco+$micr+$disc))/5))

if [ $averageMarks -ge 90 ]
then
	echo CGPA 10
elif [[ $averageMarks -lt 90 && $averageMarks -ge 80 ]]
then
	echo CGPA 9
elif [[ $averageMarks -lt 80 && $averageMarks -ge 70 ]]
then
	echo CGPA 8
elif [[ $averageMarks -lt 70 && $averageMarks -ge 60 ]]
then
	echo CGPA 7
elif [[ $averageMarks -lt 60 && $averageMarks -ge 50 ]]
then
	echo CGPA 6
elif [[ $averageMarks -lt 50 && $averageMarks -ge 40 ]]
then
	echo CGPA 5
else
	echo CGPA 4
fi
