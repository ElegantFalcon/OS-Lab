echo "Enter a number : "
read num
s=0
while [ $num -gt 0 ]
do 
r=$((num%10))
num=$((num/10))
s=$(( $s + $r ))
done 
echo $s