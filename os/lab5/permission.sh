#!/bin/sh

echo "Enter a file or directory name: "
read name

if [ -d $name ]; then
    echo "$name is a directory."
    echo "Permissions: $(stat -c '%A' $name)"
elif [ -f $name ]; then
    echo "$name is a regular file."
    echo "Permissions: $(stat -c '%A' $name)"
else
    echo "$name is not a file or directory."
fi
