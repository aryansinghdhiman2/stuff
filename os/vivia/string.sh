echo "Enter 1 for Length"
echo "Enter 2 for Concatenate"
echo "Enter 3 for Case Change"
echo "Enter 4 for Pattern Search"
echo "Enter 5 for Reverse"
echo "Enter 6 for Palindrome"
echo "Enter 7 for Comparison"
read choice

case $choice in
    1)  echo -n "Enter String: "
        read str
        echo "Length of String is ${#str}"
    ;;
    2)  echo -n "Enter First String: "
        read str1
        echo -n "Enter Second String: "
        read str2
        echo "Concatenated Strings are: ${str1}${str2}"
    ;;
    3)  echo -n "Enter String: "
        read str
        echo "Enter 1 for upper case"
        echo "Enter 2 for lower case"
        read anotherchoice
        case $anotherchoice in
        1) echo "$str" | tr '[:lower:]' '[:upper:]'
        ;;
        2) echo "$str" | tr '[:upper:]' '[:lower:]'
        ;;
        *) echo "Invalid case"
        ;;
        esac
        ;;
    4)  echo -n "Enter String: "
        read str
        echo -n "Enter Pattern to be searched: "
        read patt
        echo "$str" | grep --color=auto "${patt}"
    ;;
    5)  echo -n "Enter String: "
        read str
        echo "${str}" | rev 
    ;;
    6)  echo -n "Enter String: "
        read str
        reversed=`echo "${str}" | rev`
        if [ "$str" == "$reversed" ]
        then
            echo "Is Palindrome"
        else
            echo "Not Palindrome"
        fi 
    ;;
    7)  echo -n "Enter First String: "
        read str1
        echo -n "Enter Second String: "
        read str2
        if [ "$str1" == "$str2" ]
        then 
            echo "Equal"
        else   
            echo "Not Equal"
        fi
    ;;
    *) echo "Invalid Input"
    ;;
esac