grep -h ^int sources/*/*.c | sed -e 's/$/;/g' | sed -e 's/^int/int	/g'
grep -h ^char sources/*/*.c | sed -e 's/$/;/g'
grep -h ^void sources/*/*.c | sed -e 's/$/;/g'
echo "#endif"