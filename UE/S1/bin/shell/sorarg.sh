i=1
cat /dev/null > /tmp/1

for i in "$@"
do
    echo $i >> /tmp/1
done
    
sort /tmp/1  > /tmp/2
cat -n /tmp/2
