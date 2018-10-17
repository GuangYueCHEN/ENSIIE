cat $1 |read c d;

for x in $(cat $1) ;do

echo $x
done


for x in $(cat $2) ;do
echo $x
done
