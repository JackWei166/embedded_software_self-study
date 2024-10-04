# statement for function val local global

scope()
{
	gblval=1
	local localval=2   # xxx

	echo "gblval = $gblval"
	echo "localval = $localval"
}

scope

echo "gblval = $gblval"
echo "localval = $localval"

