#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
 

void put_string(char *string, int *length)
{
	/*se la stringa è nulla, mettiamo "(null)" */
	if (!string) 
		string = "(null)";
    // Scorriamo ogni carattere della stringa e lo stampiamo
	while (*string)
		*length += write (1, string++, 1);
 // scrive un carattere alla volta sulla console
}


// Funzione per stampare un numero in una base qualsiasi (decimale o esadecimale)
void put_digit(long long int number, int nbase, int *length)
{
    // Stringa che contiene i caratteri per rappresentare i numeri
	char *div = "0123456789abcdef";
    // Se il numero è negativo, lo rendiamo positivo e stampiamo il segno
	if (number < 0)
	{
		number *= -1; // Rendiamo il numero positivo
		*length += write(1, "-", 1);    // Scriviamo il segno "-" e incrementiamo il contatore
	}
    // Se il numero è maggiore o uguale alla base, ricorsivamente scriviamo la parte superiore del numero
	if (number >= nbase)
		put_digit((number / nbase), nbase, length); // ricorsione per scrivere la parte superiore
    // Scriviamo il carattere corrispondente alla cifra corrente
	*length += write(1, &div[number % nbase], 1); // Scrive il carattere corrispondente alla cifra
}
 
int	ft_printf(const char *format, ...)
{
	int length = 0; // Variabile per tracciare la lunghezza totale del testo stampato
 
	va_list pointer; // Lista di argomenti variabili
 
	va_start(pointer, format); // inizializzazione della lista degli argomenti variabili

    // Ciclo attraverso il formato di stringa
	while(*format)
	{
        // Se troviamo un segno di percentuale seguito da uno dei formati validi ('s', 'd', 'x')
		if ((*format == '%') && (*(format + 1) == 's' || *(format + 1) == 'd' || *(format + 1) == 'x'))
		{
			format++;  // Avanza al prossimo carattere per leggere il tipo di formato

			if (*format == 's') // Se il formato è 's', chiamiamo la funzione per scrivere una stringa
				put_string(va_arg(pointer, char *), &length);
			if (*format == 'x') // Se il formato è 'x', chiamiamo la funzione per scrivere un numero in esadecimale
				put_digit((long long int)va_arg(pointer, unsigned int), 16, &length);
			if (*format == 'd') // Se il formato è 'd', chiamiamo la funzione per scrivere un numero intero
				put_digit((long long int)va_arg(pointer, int), 10, &length);
		}
		else
			length += write(1, format, 1); // Se non è un formato, scriviamo il carattere così com'è
		format++; // Avanza al prossimo carattere nella stringa di formato
	}
	va_end(pointer);  // Termina l'uso della lista di argomenti variabili
	return (length);  // Ritorna la lunghezza totale dei caratteri stampati
}
