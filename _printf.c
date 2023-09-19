#include "main.h"

/**
 * _printf - printf function
 * @format: format
 * Return: print char
 */

int _printf(const char *format, ...)
{
	int tobi_print = 0;
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			tobi_print++;
		}
		else 
		{
			format++;
			if (format == '\0')
				break;

					if (*format == '%')
					{
						write(1, format, 1);
						tobi_print++;
					}
					else if (*format == 'c')
					{
						char c = va_arg(list, int);

						write(1, &c, 1);
						tobi_print++
					}
					else if (*format == 's')
					{
						char *str = va_arg(list, char*);
						int str_len = 0;
						
					while (str[str_len] != '\0')
							str_len++;

						write(1, str, str_len);
						chara_print += str_len;
					}
		}
		format++;
	}
	va_end(list);

	return (chara_print);
}
