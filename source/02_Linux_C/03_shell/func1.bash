# statement for function edition and call

check_user()
{
	rst=`who | grep $1 | wc -l`   # ???

	if [ $rst -eq 0 ]    # xxx
	then
		return 0
	else
		return 1
	fi
}

while true
do
	echo -n "Please input user name:"
	read uname

	check_user $uname

	if [ $? -eq 1 ]
	then
		echo "$uname is online."
	else
		echo "$uname is offline."
	fi
done
