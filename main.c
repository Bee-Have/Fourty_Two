#include "ft_printf.h"
#include "specs/convert_int/convert_int.h"

int		main()
{
	int		test = 110;
	void	*add;
	//int	str;

	add = &test;
	//printf("%12 \n");
	//test = &str; 
	printf("%p\n", &test);
	printf("0x%s\n", ft_itoa_base((int)&test, 16));
	//printf("%X\n", test);
	//printf("%d\n", str);
	return (0);
}
