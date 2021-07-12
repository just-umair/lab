

# Question 3

# #!/bin/bash

# fun()
# {

# num=$(( $1+$2 ))
# return $num
# }
# fun 2 3
# echo "The Result is $num"


# Question 4
# #!/bin/bash

# fun()
# {

# if (( $1 < 1 ));
# then
# 	return
# else
# echo "$1 "
# fun $(($1-1))
# fi
# }


# fun 5



# Question 5
# #!/bin/bash

# array=(1 2 3 4)
# fun()
# {

# if (( $1 < 0 ));
# then
# 	return
# else
# a=$1
# echo $((array[$a]))
# fun $((a-1))
# fi
# }


# fun 3


# Question 6

# #!/bin/bash

# time

# Question 7
# #!/bin/bash

# Calculate()
# {
# echo "Enter your Choice"
# echo "1) Addition"
# echo "2) Subtraction"
# echo "3) Multiplication"
# echo "4) Division"
# echo -n "Enter: "
# read choice
# case $choice in
# 1)result=$(( $1 + $2 ));;
# 2)result=$(( $1 - $2 ));;
# 3)result='expr $1 \* $2';;
# 4)result=$(( $1 / $2 ));;
# esac
# echo "Result: $result"
# }


# echo -n "Enter first integer: "
# read num1
# echo -n "Enter second integer: "
# read num2



# Calculate num1 num2



# Question 8

# #!/bin/bash

# Reverse()
# {
# original=$num
# reverse=0
# while [ $num -gt 0 ]
# do
# 	temp=$(( $num % 10 ))
# 	a=10
# 	reverse=$(expr $reverse \* 10)
# 	reverse=$(( reverse+temp ))
# 	num=$(( $num / 10 ))
# done
# checkPalindrome reverse original
# }
# checkPalindrome()
# {
# if (( $reverse == $original ));
# then	
# 	echo "Number is Palindrome"
# 	return
# fi
# echo "Number is not Palindrome"
# }


# echo -n "Enter Number to Check: "
# read num

# Reverse num












# Question 9

# #!/bin/bash

# fun()
# {
# factorial=1

# while [ $num -gt 1 ]
# do
# factorial=$(expr $factorial \* $num)
# num=$((num - 1))
# done
# }


# echo -n "Enter Number: "
# read num

# fun

# echo "Factorial is $factorial"



