function isint()
{
    n="$1"
    m=$(echo "$n" | sed -e "1s/[+-]\?[0-9]\+//")
    ! test "$m"
}


    
function s3s(){
    if test ! $# -eq 3 ;then
	echo 1>&2  "Fatal   "
	return 0;
    fi
    
    str1=$1
    str2=$2
    str3=$3
    if test  "$str1" \> "$str2" -a "$str2" \> "$str3";then
	echo $str3;echo $str2;echo $str1
	elif test "$str1" \> "$str3" -a "$str3" \> "$str2";then
	echo $str2;echo $str3;echo $str1
	elif test "$str2" \> "$str1" -a "$str1" \> "$str3";then
	echo $str3;echo $str1;echo $str2
	elif test "$str2" \> "$str3" -a "$str3" \> "$str1";then
	echo $str1;echo $str3;echo $str2
	elif test "$str3" \> "$str2" -a "$str2" \> "$str1";then
	echo $str1;echo $str2;echo $str3
    else
	echo $str2;echo $str1;echo $str3
    fi
    test $# -eq 3
    }
function s3e ( ) {
    i=
    if test $# != 3 ;then
	echo 1>&2 "Dtal il y a juste $# arg,fuat 3 "
	return 0;
    fi
    
    for i in $*;do  

	x=$(isint $i;echo $?);
	if test $x -eq 1 ;then
	    echo 1>&2 "$i nest pas int"
	    return 0;
	    fi
	done
   ./sorarg3.sh $*
}

function s3f ( ) {
    i=0
        i=
    if test $# != 3 ;then
	echo 1>&2 "Dtal il y a juste $# arg,fuat 3 "
	return 0;
    fi

    for i in "$@" ;do
	if ! test -f $i;then
      
	    echo $i nest pas fichier
	    return 0;
	    fi
    done
    x=(0 0 0)
    j=0
    for i in "$@";do  

	x[$j]=$(stat -c %s $i);
#	 echo ${x[$j]}
	j=$j+1
  
    done
    

    
    if  test -f $1 -a  -f $2 -a -f $3 ;then
	s3e ${x[*]}
	
    else
	echo WTF
    fi
     test -f $1 -a  -f $2 -a -f $3
}


function s3d ( ) {
    i=0
    for i in "$@" ;do
	if ! test -d $i;then
      
	    echo $i nest pas repertoire
	    fi
   done
    if  test -d $1 -a  -d $2 -a -d $3 ;then
    s3s "$@"
    else
	echo WTF
    fi
     test -d $1 -a  -d $2 -a -d $3
     }
function s3f1m ( ) {
    i=0
    for i in "$@" ;do
	if ! test -r $i;then
      
	    echo $i nest pas lisible
	    fi
   done
    if  test -r $1 -a  -r $2 -a -r $3 ;then
    s3s "$@"
    else
	echo WTF
    fi
     test -r $1 -a  -r $2 -a -r $3
     }
