i=0
j=
a=($*)
petit=1
#echo ${a[*]}
#echo ${#a[@]}
while (( $i < ${#a[@]})) ;do
    petit=${a[i]}
    j=$i
    while (( $j < ${#a[@]} ));do
	if test $petit -ge ${a[j]};then
	    o=$petit
	    petit=${a[j]}
	    a[j]=$o
	fi
	j=$j+1
    done
    echo $petit
	i=$i+1
    done
	
