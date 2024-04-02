#include <stdarg.h>
#include <unistd.h>

int	ft_putstr(const char *str)
{
	int	len = 0;
	int	i = -1;

	if (!str)
	{
		len += write(1, "(null)", 6);
		return (len);
	}
	while (str[++i] != '\0')
		len += write(1, &str[i], 1);
	return (len);
}

int	ft_putnbrbase(long long int nb, short int base)
{
	char	hexa[16] = "0123456789abcdef";

	if (base == 16)
		nb = (unsigned int)nb;
	if (nb < 0 && base == 10)
	{
		len += write(1, "-", 1);
		len += ft_putnbrbase(-nb, base);
	}
	else
	{
		if (nb > base)
			len += ft_putnbrbase(nb/base, base);
		len += write(1, &hexa[nb%base], 1);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
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
				len += ft_putstr(va_arg(ptr, char *));
			else if (str[i] == 'd')
				len += ft_putnbrbase(va_arg(ptr, int), 10);
			else if (str[i] == 'x')
				len += ft_putnbrbase(va_arg(ptr, int), 16);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(ptr);
	return (len);
}
/*
int	main(void)
{
	int	len = 0;

	len += ft_printf("Hello World !\n");				// len = 14
	len += ft_printf("a string : %s\n", "IM A F*CKING STRING");	// len = 13 + 19 = 32
	len += ft_printf("nb = %d\nnb hex = %x\n", 42, 42);		// len = 18
	len += ft_printf("%x\n", (int)0xFFFFFFFF);
	ft_printf("written : %d\n", len);				// len == 64
	return (0);
}*/
