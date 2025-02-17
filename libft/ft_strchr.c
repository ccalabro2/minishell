/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:55:16 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/17 15:55:36 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

char *ft_strchr(const char *str, int c)
{
    while (*str)  // Finché non incontriamo il terminatore di stringa
    {
        if (*str == (char)c)  // Se troviamo il carattere c
            return (char *)str;  // Restituiamo il puntatore alla posizione trovata
        str++;  // Passiamo al carattere successivo
    }
    if ((char)c == '\0')  // Se cerchiamo il terminatore di stringa
        return (char *)str;  // Restituiamo il puntatore a NULL
    return NULL;  // Se non trovato
}
