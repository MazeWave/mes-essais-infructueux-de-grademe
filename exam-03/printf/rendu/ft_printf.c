#include <stdarg.h>
#include <unistd.h>

int	put_str(const char *str)
{
	int	len = 0;
	int	i = -1;

	while (str[++i] != '\0')
		len += write(1, &str[i], 1);
	return (len);
}

int	put_nbrbase(long long int nb, short base)
{
	int	len = 0;
	char	*hexa = "0123456789abcedf";

	if (nb < 0)
	{
		len += write(1, "-", 1);
		len += put_nbrbase(-nb, base);
	}
	else
	{
		if (nb > base)
			len += put_nbrbase(nb / base, base);
		len += write(1, &hexa[nb % base], 1);
	}
	return (len);
}

int	ft_printf(const char *str, ... )
{
	int	i = 0;
	int	len = 0;
	va_list	ptr;
	va_start(ptr, str);

	while (str[i] != '\0')
	{
		if (str[i] == '%' && (str[i+1] == 's' || str[i+1] == 'd' || str[i+1] == 'x'))
		{
			i++;
			if (str[i] == 's')
				len += put_str(va_arg(ptr, char *));
			else if (str[i] == 'd')
				len += put_nbrbase(va_arg(ptr, int), 10);
			else if (str[i] == 'x')
				len += put_nbrbase(va_arg(ptr, int), 16);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(ptr);
	return (len);
}

int	main(void)
{
	char	*str = "Write a function named `ft_printf` that will mimic the real printf but";
	int	nb = 42;
	int	written;

	(void)str;
	(void)nb;
	(void)written;
//	ft_printf( "\n\nwritten = %d", ft_printf("Hello %s %d %x world !\n\n newline and \t\ttab test.", str, nb, nb));
	written = ft_printf("test");
//	written = ft_printf("%d %x", nb, nb);
//	ft_printf("\nwritten : %d", written);
	return (0);
}
