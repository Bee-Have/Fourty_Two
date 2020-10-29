#include "ft_printf.h"
#include "convert_int/convert_int.h"

int		main()
{
	int		test = 110;
	//int	str;

	printf("%s\n", ft_itoa_base(test, 16));
	//test = &str; 
	//printf("%p\n", &str);
	//printf("%X\n", test);
	//printf("%d\n", str);
	return (0);
}
