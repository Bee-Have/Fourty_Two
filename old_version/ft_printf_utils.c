/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:15:19 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/17 20:30:39 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_old.h"

char	*make_empty()
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strjoin_char(char *str, char c)
{
	char	*result;
	int		i;

	i = 0;
	if (!str)
		str = make_empty();
	result = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!result)
		return (NULL);
	result[ft_strlen(str) + 1] = '\0';
	while (str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = c;
	if (str[0] == '\0')
		free(str);
	return (result);
}

char	*no_spec(char *str)
{
	char	*result;
	int		length;
	int		i;
	
	length = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != '%')
		length++;
	result = (char *)malloc((length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[length] = '\0';
	while (i < length)
	{
		result[i] = str[i];
		i++;
	}
	return (result);
}
