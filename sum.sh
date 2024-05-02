echo "Enter a Number : "
read num
s=0
while [ $num -gt 0 ]
do
r=$(( $num % 10))
num=$(( $num / 10))
s=$(( $s + $r ))
done
echo "Sum of digits is : $s"
