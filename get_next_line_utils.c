/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:03:00 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/22 11:19:40 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//calcule la longueure d'une chaine de characters (ou string)
int		ft_strlen(char *str)
{
	//i sert à parcourir la chaine
	int		i;

	//ont commence au début de la chaine
	i = 0;
	//si la chaine n'existe pas sa longueure est 0
	if (!str)
		return (0);
	//sinon ont parcour la chaine 
	while (str[i] != '\0')
		i++;
	//ont retourne le nombre de characters trouvés dans la chaine 
	return (i);
}

//copie une chaine de characters dans une autre chaine de characters
//copie uniquement sur une longueure donné
char	*ft_strncpy(char *dst, char *src, int idst)
{
	//i sert à parcourire la chaine
	int		i;

	//ont commence au début de la chaine
	i = 0;
	//pendant que la chaine que l'ont copie n'est pas arrivé à la fin
	while (src[i] != '\0')
	{
		//ont copie le character d'une chaine à l'autre
		dst[idst] = src[i];
		//puis ont avance au character suivant
		i++;
		//idst sert à parcourir la chaine dans laquel ont copie
		//cette chaine ne part pas forcément de 0
		//ont peut copier quelque chose à la fin ou au début
		idst++;
	}
	//ont retourne par la suite la chaine dans laquelle ont à copier
	return (dst);
}

//met deux chaines de characters l'une à la suite de l'autre
//ont crée une troisième chaine qui est le resultat de l'opération
char	*ft_strjoin(char *dst, char *src)
{
	//i sert à parcourir la chaine finale
	int		i;
	//maxlen est la longueure de la chaine finale
	int		maxlen;
	//la chaine dans laquel ont vas mettre les deux chaines originales
	char	*result;

	//ont commence au début de la chaine finale
	i = 0;
	//si la static n'existe pas alors ont renvoie buffer
	if (!dst || ft_strlen(dst) == 0)
		maxlen = ft_strlen(src);
	else
	{
		//sinon maxlen= la taille des deux chaines réunis
		maxlen = ft_strlen(dst) + ft_strlen(src);
	}
	//ont alloue de la mémoire pour cette nouvelle chaine
	result = (char *)malloc((maxlen + 1) * sizeof(char));
	//si l'allocation échoue ont arréte tout
	if (!result)
		return (NULL);
	//maxlen étant la taille max, le \0 s'y trouveras
	result[maxlen] = '\0';
	//si la static existe et n'est pas vide
	if (dst || ft_strlen(dst) != 0)
	{
		//ont copie la static dans la nouvelle chaine
		//donc tout ce qu'ont à lue avant
		result = ft_strncpy(result, dst, i);
		//i nous permet de ne pas écraser les deux chaines l'une sur l'autre
		i = ft_strlen(dst);
	}
	//ont copie le contenue de buffer dans la nouvelle chaine
	//après le contenue de la static
	//donc ce qu'ont viens de lire
	result = ft_strncpy(result, src, i);
	//result est la nouvelle valeur de la static
	//l'ancienne valeur doit être supprimer pour faire place à celle-ci
	free(dst);
	//le résultat est retourné et assigné à la static
	return (result);
}

//cette fonction selectionne une partie d'une chaine de characters
//le resultat est mis dans une nouvelle chaine de characters
char	*ft_substr(char *str, int start, int len, int line)
{
	//i sert à parcourir la chaine finale
	int		i;
	//result est la chaine finale
	char	*result;

	//ont commence qu début de la chaine
	i = 0;
	//si la position du début de la nouvelle chaine n'est pas dans la chaine
	//ont retourne la chaine tel quel
	if (start > ft_strlen(str))
		return (str);
	//si le permier character est un \n
	//et que la chaine final seras *line
	//ont avance la position du début de la chaine
	if (str[start] == '\n' && line == 1)
		start++;
	//sinon ont alloue un espace mémoire à la taille fournie
	result = (char *)malloc((len + 1) * sizeof(char));
	//si l'allocation échoue, ont arrête tout
	if (!result)
		return (NULL);
	//sinon ont définie la fin de la chaine à la taille fournie
	result[len] = '\0';
	//ici ont copie la partie de la chaine d'origine dans la chaine finale
	//ont vérifie que l'ont as pas finie la chaine original
	//et que l'ont est pas arrivé à la taille fournie
	while (str[start] != '\0' && i < len)
	{
		//les characters sont copiés d'une chaine à l'autre
		result[i] = str[start];
		//ont avance dans la nouvelle chaine
		i++;
		//ainsi que dans l'original
		start++;
	}
	//si la chaine final n'est pas line
	//donc si la chaine final est la static
	if (line == 0)
	{
		//ont libère l'espace alloué pour laisser place a la nouvelle chaine
		free(str);
	}
	//et ont retourne la chaine final
	return (result);
}
