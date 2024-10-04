#statement of if...then...else...fi
if [ -d $1 ]
then
	echo "$1 is a directory."
else
	if [ -f $1 ]
	then
		echo "$1 is a file."
	else
		echo "Unknown."
	fi
fi
