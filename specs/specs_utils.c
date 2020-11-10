/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:19:06 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/10 10:19:30 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifications.h"

char	*ft_strjoin(char *dst, char *src)
{
	char	*result;
	int		j;
	int		i;
	int		len;

	if (!dst)
		return (src);
	i = 0;
	j = 0;
	len = ft_strlen(dst) + ft_strlen(src);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (dst[i] != '\0')
	{
		result[i] = dst[i];
		i++;
	}
	while (i < len)
	{
		result[i] = src[i - ft_strlen(dst)];
		i++;
	}
	return (result);
}