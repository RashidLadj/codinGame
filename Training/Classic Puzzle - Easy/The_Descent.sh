## @file The_Descent.sh
## @author Ladjouzi Rachid (RashidLadj@gmail.com)
## @brief
## @version 0.1
## @date 2021-10-11

## @copyright Copyright (c) 2021

# game loop
while true; do
    index=-1
    maxHeight=-1
    for (( i=0; i<8; i++ )); do
        read -r mountainH
        if [ $maxHeight -lt $mountainH ]  #(("$a" < "0"))
        then
            maxHeight=$mountainH
            index=$i
        fi  
    done

    echo $index # The index of the mountain to fire on.
done