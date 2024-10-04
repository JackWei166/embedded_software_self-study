#statement for continue
if [ $# = 0 ]
then
	echo "No argument to do it."
	exit
fi

if [ $# -gt 10 ]
then
	echo "More than 10 arguments are not allowed."
	exit
fi

for number
do
	conut=`expr $number % 2`
	if [ $conut -eq 1 ]
	then
		continue
	else
		even="$even $number"
	fi
done

echo $even
