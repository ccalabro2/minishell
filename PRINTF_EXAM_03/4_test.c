#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void    put_string(char *string, int *lenght)
{
    if (!string)
        string = "(null)";
    while (*string)
        *lenght += write(1, string++, 1);
}

void    put_digit(long long int n, int nbase, int *lenght)
{
    char    *div = "0123456789abcdef";

    if (n < 0)
    {
        n *= -1;
        *lenght += write(1, "-", 1);
    }
    if (n >= nbase)
        put_digit((n / nbase), nbase, lenght);
    *lenght += write(1, &div[n % nbase], 1);
}

int ft_printf(const char *format, ...)
{
    int lenght = 0;

    va_list pointer;
    va_start(pointer, format);
    while(*format)
    {
        if ((*format == '%') && (*(format + 1) == 's') || *(format + 1) == 'x' || *(format + 1) == 'd')
        {
            format++;
            if (*format == 's')
                put_string(va_arg(pointer, char *), &lenght);
            if (*format == 'x')
                put_digit((long long int)va_arg(pointer, unsigned int), 16, &lenght);
            if (*format == 'd')
                put_digit((long long int)va_arg(pointer, int), 10, &lenght);
        }
        else
            lenght += write(1, format, 1);
        format++;
    }
    va_end(pointer);
    return (lenght);
}
