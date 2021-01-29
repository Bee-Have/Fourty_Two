#include "ft_printf.h"

int		main()
{
	int				res = 0;
	int				myres = 0;
	unsigned int	test = 422;

	myres = ft_printf("me%x\n", test);
	res = printf("ye%x\n", test);
	printf("1[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%5x\n", test);
	res = printf("ye%5x\n", test);
	printf("2[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%-5x\n", test);
	res = printf("ye%-5x\n", test);
	printf("3[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%*x\n", 5, test);
	res = printf("ye%*x\n", -5, test);
	printf("4[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%-*x\n", 5, test);
	res = printf("ye%-*x\n", -5, test);
	printf("5[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%0x\n", test);
	res = printf("ye%0x\n", test);
	printf("6[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%05x\n", test);
	res = printf("ye%05x\n", test);
	printf("7[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%0-5x\n", test);
	res = printf("ye%0-5x\n", test);
	printf("8[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%0*x\n", 5, test);
	res = printf("ye%0*x\n", 5, test);
	printf("9[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%0*x\n", -5, test);
	res = printf("ye%0*x\n", -5, test);
	printf("10[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%0-*x\n", 5, test);
	res = printf("ye%0-*x\n", 5, test);
	printf("11[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%0-*x\n", -5, test);
	res = printf("ye%0-*x\n", -5, test);
	printf("12[%d]-[%d]\n", myres, res);
	
	myres = ft_printf("me%.x\n", test);
	res = printf("ye%.x\n", test);
	printf("13[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.5x\n", test);
	res = printf("ye%.5x\n", test);
	printf("14[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.-5x\n", test);
	res = printf("ye%.-5x\n", test);
	printf("15[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.*x\n", 5, test);
	res = printf("ye%.*x\n", 5, test);
	printf("16[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.*x\n", -5, test);
	res = printf("ye%.*x\n", -5, test);
	printf("17[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.-*x\n", 5, test);
	res = printf("ye%.-*x\n", 5, test);
	printf("18[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.-*x\n", -5, test);
	res = printf("ye%.-*x\n", -5, test);
	printf("19[%d]-[%d]\n", myres, res);
	
	myres = ft_printf("me%.0x\n", test);
	res = printf("ye%.0x\n", test);
	printf("20[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.50x\n", test);
	res = printf("ye%.50x\n", test);
	printf("21[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.-50x\n", test);
	res = printf("ye%.-50x\n", test);
	printf("22[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.*0x\n", 5, test);
	res = printf("ye%.*0x\n", 5, test);
	printf("23[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.*0x\n", -5, test);
	res = printf("ye%.*0x\n", -5, test);
	printf("24[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.-*0x\n", 5, test);
	res = printf("ye%.-*0x\n", 5, test);
	printf("25[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.-*0x\n", -5, test);
	res = printf("ye%.-*0x\n", -5, test);
	printf("26[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.05x\n", test);
	res = printf("ye%.05x\n", test);
	printf("27[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.0-5x\n", test);
	res = printf("ye%.0-5x\n", test);
	printf("28[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.0*x\n", 5, test);
	res = printf("ye%.0*x\n", 5, test);
	printf("29[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.0*x\n", -5, test);
	res = printf("ye%.0*x\n", -5, test);
	printf("30[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.0-*x\n", 5, test);
	res = printf("ye%.0-*x\n", 5, test);
	printf("31[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.0-*x\n", -5, test);
	res = printf("ye%.0-*x\n", -5, test);
	printf("32[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.505x\n", test);
	res = printf("ye%.505x\n", test);
	printf("33[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.-505x\n", test);
	res = printf("ye%.-505x\n", test);
	printf("34[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.50-5x\n", test);
	res = printf("ye%.50-5x\n", test);
	printf("35[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.-50-5x\n", test);
	res = printf("ye%.-50-5x\n", test);
	printf("36[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.*05x\n", 5, test);
	res = printf("ye%.*05x\n", 5, test);
	printf("37[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.*05x\n", 5, test);
	res = printf("ye%.*05x\n", 5, test);

	printf("38[%d]-[%d]\n", myres, res);
	return (0);
}
