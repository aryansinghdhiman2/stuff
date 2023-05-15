#Rename all files in a directory

echo "Enter String you want as postfix"
read pfix

for i in *
do 
mv "$i" "$i""${pfix}"
done

#Remove common files
for i in `find ./ -name NAME_OF_FILE`
do
rm "$i"
done

#change case of a file

newname=`echo FILE_NAME | tr "[:upper]" "[:lower:]"`
mv "FILE_NAME" "${newname}"