#include "ft_printf.h"

int		main()
{
	int		res = 0;
	int		myres = 0;
	//char	*test = "hey";

	myres = ft_printf("me%%\n");
	res = printf("ye%%\n");
	printf("1[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%5%\n");
	res = printf("ye%5%\n");
	printf("2[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%-5%\n");
	res = printf("ye%-5%\n");
	printf("3[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%*%\n", 5);
	res = printf("ye%*%\n", -5);
	printf("4[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%-*%\n", 5);
	res = printf("ye%-*%\n", -5);
	printf("5[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%0%\n");
	res = printf("ye%0%\n");
	printf("6[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%05%\n");
	res = printf("ye%05%\n");
	printf("7[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%0-5%\n");
	res = printf("ye%0-5%\n");
	printf("8[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%0*%\n", 5);
	res = printf("ye%0*%\n", 5);
	printf("9[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%0*%\n", -5);
	res = printf("ye%0*%\n", -5);
	printf("10[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%0-*%\n", 5);
	res = printf("ye%0-*%\n", 5);
	printf("11[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%0-*%\n", -5);
	res = printf("ye%0-*%\n", -5);
	printf("12[%d]-[%d]\n", myres, res);
	
	myres = ft_printf("me%.%\n");
	res = printf("ye%.%\n");
	printf("13[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.5%\n");
	res = printf("ye%.5%\n");
	printf("14[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.-5%\n");
	res = printf("ye%.-5%\n");
	printf("15[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.*%\n", 5);
	res = printf("ye%.*%\n", 5);
	printf("16[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.*%\n", -5);
	res = printf("ye%.*%\n", -5);
	printf("17[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.-*%\n", 5);
	res = printf("ye%.-*%\n", 5);
	printf("18[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.-*%\n", -5);
	res = printf("ye%.-*%\n", -5);
	printf("19[%d]-[%d]\n", myres, res);
	
	myres = ft_printf("me%.0%\n");
	res = printf("ye%.0%\n");
	printf("20[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.50%\n");
	res = printf("ye%.50%\n");
	printf("21[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.-50%\n");
	res = printf("ye%.-50%\n");
	printf("22[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.*0%\n", 5);
	res = printf("ye%.*0%\n", 5);
	printf("23[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.*0%\n", -5);
	res = printf("ye%.*0%\n", -5);
	printf("24[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.-*0%\n", 5);
	res = printf("ye%.-*0%\n", 5);
	printf("25[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.-*0%\n", -5);
	res = printf("ye%.-*0%\n", -5);
	printf("26[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.05%\n");
	res = printf("ye%.05%\n");
	printf("27[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.0-5%\n");
	res = printf("ye%.0-5%\n");
	printf("28[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.0*%\n", 5);
	res = printf("ye%.0*%\n", 5);
	printf("29[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.0*%\n", -5);
	res = printf("ye%.0*%\n", -5);
	printf("30[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.0-*%\n", 5);
	res = printf("ye%.0-*%\n", 5);
	printf("31[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.0-*%\n", -5);
	res = printf("ye%.0-*%\n", -5);
	printf("32[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.505%\n");
	res = printf("ye%.505%\n");
	printf("33[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.-505%\n");
	res = printf("ye%.-505%\n");
	printf("34[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.50-5%\n");
	res = printf("ye%.50-5%\n");
	printf("35[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.-50-5%\n");
	res = printf("ye%.-50-5%\n");
	printf("36[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.*05%\n", 5);
	res = printf("ye%.*05%\n", 5);
	printf("37[%d]-[%d]\n", myres, res);
	myres = ft_printf("me%.*05%\n", 5);
	res = printf("ye%.*05%\n", 5);

	printf("38[%d]-[%d]\n", myres, res);
	return (0);
}
