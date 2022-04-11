echo "#ifndef LIBFT_H"
echo "# define LIBFT_H"
echo "# include <unistd.h>"
echo "# include <stdlib.h>"
echo ''
grep -h ^int sources/*.c | sed -e 's/$/;/g' | sed -e 's/^int/int	/g'
grep -h ^char sources/*.c | sed -e 's/$/;/g'
grep -h ^void sources/*.c | sed -e 's/$/;/g'
echo "#endif"