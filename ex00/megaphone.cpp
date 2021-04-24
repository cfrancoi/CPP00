#include <iostream>
#include <string>

static void	print_to_upper(std::string str)
{
	int		i;

	i = 0;

	while (str[i])
	{
		if (islower(str[i]))
			str[i] = str[i] - 32;
		i++;
	}
	std::cout << str << std::endl;
}	

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	ac--;
	while (ac > 0)
	{

		print_to_upper(std::string(av[ac]));
		ac--;
	}
	return (0);
}
	