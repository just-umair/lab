#!/bin/bash
clear
play /usr/share/sounds/freedesktop/stereo/message.oga
clear
ships=( Carrier Battleship Submarine Destroyer Dingy )
lenght=( 5 4 3 3 2 )
#This is a Board Function 
function Board ()
{
 printf " "   


 # print A..J bar on top
for bar in {0..9}
do
printf "\e[1;37m"
printf "$bar "
printf "\e[0m"
done
printf "\n"


# print values into board
for ((i = 0 ; i < 10 ; i++ ))
do
printf "\e[1;37m"
printf "$i"
printf "\e[0m"
for ((j = 0 ; j< 10 ; j ++))
do 
printf "\e[1;34m"
printf ${tmp[$i,$j]}
printf "\e[0m"
printf " "
done
printf "\n"
done
}


# Variables creation on this line
declare -A tmp;
declare -A fPlayerD
declare -A fPlayerA
declare -A sPlayerD
declare -A sPlayerA
declare fplayer true ;
declare sPlayer false ;
flag=0;


# Give Values to the Variables
for ((i = 0 ; i <10 ;i++))
do
for (( j = 0 ; j <10 ; j++))
do
fPlayerD[$i,$j]="-"
sPlayerD[$i,$j]="-"
sPlayerA[$i,$j]="-"
fPlayerA[$i,$j]="-"
done
done


# Player One Turn to display Board and Populate board with Ships
printf "\e[1;32m"
printf 'Place Your Ships on Board  Player ONE ' 
printf '\n'
for ((i = 0 ; i <10 ;i++))
do
for (( j = 0 ; j <10 ; j++))
do
    tmp[$i,$j]=${fPlayerD[$i,$j]}
done
done

# Call function to Display Board
Board 
printf "\e[1;32m"
printf "Example Coordinates (1,1) Caution Row come first than Column \n\n"
for (( i = 0 ; i < 5 ; i ++))
do 



flag=0;

while (($flag == 0))
do
printf "\e[1;32m"
printf "input Coordinates for ${ships[$i]} \n"
 printf "ROW INPUT :- "
read row
 printf "Column INPUT :- "
read column
printf "input x for x_axis \ninput y for y_axis\n"
read axis
case $axis in 
"y")







for ((k =0 ; k <${lenght[$i]}; k++))
do 
temp=$(($row+$k))




if [ "${fPlayerD[$temp,$column]}" = "^" ] || [ "$temp" -gt 9 ] || [ "$column" -gt 9 ]
then
printf " ALLREADY FILLED PLACE"
flag=0;
break
else
flag=1;
fi
fPlayerD[$temp,$column]="^"
done

;;
"x")




for ((k =0 ; k <${lenght[$i]}; k++))
do 
temp=$(($column+$k))
if [ "${fPlayerD[$row,$temp]}" = "^" ] || [ "$temp" -gt 9 ] || [ "$row" -gt 9 ]
then
printf " ALLREADY FILLED PLACE"
flag=0;
break
else
flag=1;
fi
fPlayerD[$row,$temp]="^"
done




;;
esac

done


done







for ((i = 0 ; i <10 ;i++))
do
for (( j = 0 ; j <10 ; j++))
do
    tmp[$i,$j]=${fPlayerD[$i,$j]}
done
done
Board

printf "\e[1;32m"

printf "PRESS ANY KEY TO SHFIT CONTROL TO SECOND PLAYER"
 read anyKey




#Player 2





printf "\e[1;32m"

printf 'Place Your Ships on Board  Player TWO ' 
printf '\n'
for ((i = 0 ; i <10 ;i++))
do
for (( j = 0 ; j <10 ; j++))
do
    tmp[$i,$j]=${sPlayerD[$i,$j]}
done
done

# Call function to Display Board
Board 
printf "\e[1;32m"
printf "Example Coordinates (1,1) Caution Row come first than Column \n\n"
for (( i = 0 ; i < 5 ; i ++))
do 



flag=0;

while (($flag == 0))
do
printf "\e[1;32m"
printf "input Coordinates for ${ships[$i]} \n"
 printf "ROW INPUT :- "
read row
 printf "Column INPUT :- "
read column
printf "input x for x_axis \ninput y for y_axis\n"
read axis
case $axis in 
"y")







for ((k =0 ; k <${lenght[$i]}; k++))
do 
temp=$(($row+$k))
if [ "${sPlayerD[$temp,$column]}" = "^" ] || [ "$temp" -gt 9 ] || [ "$column" -gt 9 ]
then
printf " ALLREADY FILLED PLACE"
flag=0;
break
else
flag=1;
fi
sPlayerD[$temp,$column]="^"
done

;;
"x")




for ((k =0 ; k <${lenght[$i]}; k++))
do 
temp=$(($column+$k))
if [ "${sPlayerD[$row,$temp]}" = "^" ] || [ "$temp" -gt 9 ] || [ "$row" -gt 9 ]
then
printf " ALLREADY FILLED PLACE"
flag=0;
break
else
flag=1;
fi
sPlayerD[$row,$temp]="^"
done




;;
esac

done

done







for ((i = 0 ; i <10 ;i++))
do
for (( j = 0 ; j <10 ; j++))
do
    tmp[$i,$j]=${sPlayerD[$i,$j]}
done
done
Board
printf "\e[1;32m"



win=0

turn=0 
while (($win == 0))
do 




if [ "$turn" = 0 ]
then

printf "Player ONE TURN\nEnter Hit Point Coordinates\n"
printf "INPUT Row :- "
read row
printf "INPUT Column :- "
read column
if [ "${sPlayerD[$row,$column]}" = "^" ]
then
printf "HIT\n"
sPlayerD[$row,$column]="H"
fPlayerA[$row,$column]="H"
for ((i = 0 ; i <10 ;i++))
do
for (( j = 0 ; j <10 ; j++))
do
    tmp[$i,$j]=${fPlayerA[$i,$j]}
done
done

else
printf "MISSED\n"
fPlayerA[$row,$column]="M"
for ((i = 0 ; i <10 ;i++))
do
for (( j = 0 ; j <10 ; j++))
do
    tmp[$i,$j]=${fPlayerA[$i,$j]}
done
done
fi
Board
printf "\e[1;32m"
printf "PRESS ANY KEY TO SHFIT CONTROL TO SECOND PLAYER"
 read anyKey
clear


check=0
for ((i = 0 ; i <10 ;i++))
do
for (( j = 0 ; j <10 ; j++))
do
    if [ "${sPlayerD[$i,$j]}" = "^" ]
    then
        check=1
        break;
    fi
done
done
if [ "$check" = 0 ]
then
    printf "PLAYER ONE HAS WON THE GAME \n"
    printf "PRESS ANY KEY TO EXSIT"
    read anyKey
    EXSIT
fi










else


printf "Player SECOND TURN\nEnter Hit Point Coordinates\n"
printf "INPUT Row :- "
read row
printf "INPUT Column :- "
read column
if [ "${fPlayerD[$row,$column]}" = "^" ]
then
printf "HIT\n"
fPlayerD[$row,$column]="H"
sPlayerA[$row,$column]="H"

for ((i = 0 ; i <10 ;i++))
do
for (( j = 0 ; j <10 ; j++))
do
    tmp[$i,$j]=${sPlayerA[$i,$j]}
done
done
Board


printf "\e[1;32m"


printf "PRESS ANY KEY TO SHFIT CONTROL TO SECOND PLAYER"
 read anyKey
 clear



else
printf "MISSED\n"
sPlayerA[$row,$column]="M"
for ((i = 0 ; i <10 ;i++))
do
for (( j = 0 ; j <10 ; j++))
do
    tmp[$i,$j]=${sPlayerA[$i,$j]}
done
done
Board



printf "\e[1;32m"



printf "PRESS ANY KEY TO SHFIT CONTROL TO ONE PLAYER"
 read anyKey
    clear
    check=0
for ((i = 0 ; i <10 ;i++))
do
for (( j = 0 ; j <10 ; j++))
do
    if [ "${fPlayerD[$i,$j]}" = "^" ]
    then
        check=1
        break;
    fi
done
done
if [ "$check" = 0 ]
then
    printf "PLAYER SECOND HAS WON THE GAME \n"
    printf "PRESS ANY KEY TO EXSIT"
    read anyKey
    EXSIT
fi
fi
fi
if [ "$turn" = 0 ]
then 
turn=1
else
turn=0
fi
done