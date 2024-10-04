#statement of case...esac
if [ $# -eq 0 ]
then
	echo "No argument is declared."
	exit
fi

case $1 in
	if1.bash)
		echo "if1.bash is elected."
		;;
	if2.bash)
		echo "if2.bash is elected."
		;;
	*)
		echo "You must elected. if1.bash or if2.bash!"
		;;
esac
