#include "computorv1.hpp"

std::string delete_spaces(char *str)
{
	std::string ret;

	while (*str)
	{
		if (*str != ' ')
			ret += *str;
		str++;
	}
	return ret;
}

float sqrt(float number)
{
	long i;
	float x2;
	float y;

	x2 = number * 0.5F;
	y = number;
	i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y * (1.5 - (x2 * y * y));
	y = y * (1.5 - (x2 * y * y));
	y = y * (1.5 - (x2 * y * y));
	return (1 / y);
}

int sep_char(char c)
{
	if (c == '+' || c == '-' || c == '=')
		return (1);
	return (0);
}

int parse_input(std::string str)
{
	while (str != "")
	{
		if (str[0] == '=')
		{
			rhs = 1;
			str = &(str[1]);
		}
		int i = (start ? 0 : 1);
		start = 0;
		while (str[i] && str[i] != '*' && !sep_char(str[i]) && str[i] != 'X')
			i++;
		if (!str[i] || sep_char(str[i]))
			exp = 0;
		else if (str[i] == 'X')
		{
			if (!str[i + 1] || str[i + 1] != '^')
				exp = 1;
			else
			{
				i += 2;
				exp = atoi(&(str[i]));
			}
			coe1 = 1;
		}
		else if (!str[i + 1] || str[i + 1] != 'X')
			throw (std::exception());
		else if (!str[i + 2] || str[i + 2] != '^')
			exp = 1;
		else
		{
			i += 3;
			exp = atoi(&(str[i]));
		}
		if (exp >= 3 || exp < 0)
		{
			std::cout << RED << "Degree of the polynomial must be between 0 and 2\n";
			exit(1);
		}
		if (coe1)
		{
			c[exp] += 1 * (rhs ? -1 : 1);
			coe1 = 0;
		}
		else
			c[exp] += stof(str) * (rhs ? -1 : 1);
		while (str[i] && !sep_char(str[i]))
			i++;
		str = &(str[i]);
	}
	deg = 2;
	while (!c[deg] && deg >= 0)
		deg--;
	return (1);
}

int print_output(void)
{
	std::cout << WHITE << "Reduced form: " << YELLO;
	std::cout << c[0] << " ";
	if (deg >= 1)
		std::cout << (c[1] >= 0 ? "+ " : "- ") << (c[1] >= 0 ? 1 : -1) * c[1] << "X ";
	if (deg >= 2)
		std::cout << (c[2] >= 0 ? "+ " : "- ") << (c[2] >= 0 ? 1 : -1) * c[2] << "X^2 ";
	std::cout << "= 0\n" << WHITE << "Polynomial degree: " << YELLO << deg << std::endl;
	if (deg == -1)
		std::cout << "All real (and complex) numbers are solutions\n";
	else if (deg == 0)
		std::cout << "Solution does not exist\n";
	else if (deg == 1)
	{
		float t = (0 - c[0]) / c[1];
		std::cout << WHITE << "The solution is: " << YELLO << t << std::endl;
	}
	else if (deg == 2)
	{
		int des = c[1] * c[1] - 4 * c[2] * c[0];
		if (des < 0)
		{
			std::cout << YELLO << "Solution does not exist in real numbers\n"
			<< WHITE << "Complex solutions are: "
			<< YELLO << (-1) * c[1] / (2 * c[2]) << " + "
			<< sqrt(-1 * des) / (2 * c[2]) << "i" << WHITE << " and "
			<< YELLO << -1 * c[1] / (2 * c[2])
			<< " - " << sqrt(-1 * des) / (2 * c[2]) << "i\n";
		}
		else if (des == 0)
			std::cout << WHITE << "The solution is: "
			<< YELLO << -1 * c[1] / (2 * c[2]) << "\n";
		else
			std::cout << WHITE << "The solutions are: "
			<< YELLO << (-1 * c[1] + sqrt(des)) / (2 * c[2]) << WHITE << " and "
			<< YELLO << (-1 * c[1] - sqrt(des)) / (2 * c[2]) << "\n";
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << ORANGE << "Usage: computor polynomial\n";
		std::cout << "\tPolynomial format: n1 + n2 * X + n3 * X^2 = m1 + m2 * X + m3 * X^2\n";
		std::cout << "\tor n1 * X^0 + n2 * X^1 + n3 * X^2 = 0\n";
		std::cout << "\tor n1 * X^0 + n2 * X^1 + n3 * X^2 (default to = 0)\n";
		return (-1);
	}
	std::string str = delete_spaces(av[1]);
	try {
		parse_input(str);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Invalid expression format\n";
		return (0);
	}
	print_output();
	return (0);
}
