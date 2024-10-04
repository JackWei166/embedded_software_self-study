#statement of for...do...done
if [ ! -d $HOME/backup ]
then
	mkdir $HOME/backup
fi

files=`ls`

for file in $files
do
	if [ $# -eq 1 ]
	then
		if [ $file = $1 ]
		then
			echo "$1 is found."
			exit
		fi
	else
		if [ -f $file ]
		then
			cp $file $HOME/backup
			echo "$file backup."
		else
			cp -r $file $HOME/backup
			echo "$file backup."
		fi
	fi
done

echo "Backup Completed."

# 软连接 最好还是绝对路径，相对路径的话，不是本文件夹，可能过不来
