read n
read -a temperatures

if [ $n == 0 ] 
then
    echo 0
else
    best=${temperatures[0]}
    pos=0
    
    if [ $best -lt 0 ]  #(("$a" < "0"))
    then
        best=$(( 0 - $best ))
    fi

    for (( i=1; i<$n; i++ )); do
        temp=${temperatures[$((i))]}
        if [ $temp -lt 0 ]  #(("$a" < "0"))
        then
            temp=$(( 0 - $temp ))
        fi

        if [ $temp -lt $best ] || ([ $temp -eq $best ] && [ ${temperatures[${i}]} -ge 0 ])  #(("$a" < "0"))
        then
            best=$temp
            pos=$i
        fi  
    done
    echo  ${temperatures[${pos}]}
fi