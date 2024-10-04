#statement of if...then...fi
if [ -f $1 ]       #test [] !!!
then
	echo "File $1 exists."
fi

if [ -d $1 ]
then
	echo "$1 is a directory."
fi
