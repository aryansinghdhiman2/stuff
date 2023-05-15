if [ -d $1 ]
then 
    echo "$1 is directory"
    perm=`stat -c "%A" $1`
    siz=`stat -c "%s" $1`
    echo "Permissions are ${perm} and size is $siz"
elif [ -f $1 ]
then
    echo "$1 is file"
    perm=`stat -c "%A" $1`
    siz=`stat -c "%s" $1`
    leng=`wc -l $1`
    echo "Permissions are ${perm} ,size is $siz and number of lines are: $leng"
else
    echo "Not a file or directory"
fi