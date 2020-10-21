/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:16:18 by amarini-          #+#    #+#             */
/*   Updated: 2020/10/09 15:12:12 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//ici ont cherche dans notre static si l'ont à un \n
int		find_newline(char *str, int read)
{
	//int servant a parcourir la static
	int		i;

	//ont innitialise à 0 pour commencer au début de la chaine
	i = 0;
	//si la static n'existe pas, ont à donc un problème
	//problème = -1
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	if (read == 0 && ft_strlen(str) == 0)
		return (i);
	return (-1);
}

//ici ont vas lire le fichier
//ont liras BUFFER_SIZE character du fichier
int		read_fd(int fd, int *index, char **leftover)
{
	//ont déclare le résultat de ce qu'ont vas lire
	int		result;
	//buffer vas récolter les characters lus par read()
	char	*buffer;

	//ont met result à 1 pour etre sur d'avoir au moins un appel
	//ainsi même si read à renvoyé 0, ont pourras vérifier si l'ont a bien tout lue
	result = 1;
	//pendant que l'ont lit quelque chose
	//et que l'ont a pas touvé de \n
	while (result > 0 && *index == -1)
	{
		//ont malloc le buffer a BUFFER_SIZE
		//read ne lisant QUE BUFFER_SIZE character, ont ne dépasseras jamais cette valeure
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		//si le malloc n'as pas marcher ont renvoie NULL
		if (!buffer)
			return (-1);
		//ont read BUFFER_SIZE character sur le fichier envoyer
		result = read(fd, buffer, BUFFER_SIZE);
		//comme ont peut lire moins que BUFFER_SIZE
		//result étant le nombre de characters lue, ont met le \0 après
		buffer[result] = '\0';
		//ont rajoute ce qui à été lue a la static
		*leftover = ft_strjoin(*leftover, buffer);
		//ont vérifie qu'il n'y a pas de \n dans ce qui a été lue
		*index = find_newline(*leftover, result);
		//enfin ont free buffer pour ne pas re-écrire dessus et ainsi ne pas avoir de problèmes
		free(buffer);
	}
	//ont retourne le nombre de character lus juste avant d'avoir trouvé un \n
	return (result);
}

//!!!!!!!!!!!!PROGRAMME COMMENCE ICI !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int		get_next_line(int fd, char **line)
{
	//déclaration de la chaine de character static
	static char		*leftover = NULL;
	//le retour de ce qui à été lue
	//le nombre de charactères lus
	int				result;
	//position dans leftover du \n
	int				index;

	//si index = 1 alors ont a trouvé un \n
	//si index = 0 alors ont a pas trouvé \n et ont est donc a la fin du fichier
	index = -1;
	//result > 0 pour lui permettre de lire dès le début
	//ceci permet de tester la lecture même si le retour précédant était 0
	result = 1;
	//si leftover existe
	//si leftover n'est pas vide (si le premier character n'est pas \0)
	if (leftover && leftover[0] != '\0')
	{
		//cherche si il existe un \n dans leftover
		index = find_newline(leftover, 0);
	}
	//si l'ont a pas trouvé de \n ou que leftover n'existe pas
	if (index == -1)
	{
		//fonction permettant de lire le fichier envoyé
		result = read_fd(fd, &index, &leftover);
	}
	//une fois que l'ont a lue, si l'index est toujours a -1
	//dans le cas ou ont a finis de lire le fichier
	//ont veux copier tout leftover dans line puisque l'index est -1
	if (index == -1)
	{
		//ont remplis line avec TOUT le contenue de leftover
		//puisque l'ont a pas trouvé de \n dans leftover
		//ont sait aussi que l'ont a tout lue puisque read est au dessus
		*line = ft_substr(leftover, 0, ft_strlen(leftover), 1);
	}
	//si ont a trouvé un \n dans leftover après ou avant avoir lue
	//ont peut passer ici directement après le premier check
	else
	{
		//ont met tout JUSQU'AU \n
		//ce qui ce trouve après le \n dans leftover seras ignoré
		//1 signifie que l'ont envoie line (c'est un boolean oui oui)
		*line = ft_substr(leftover, 0, index, 1);
	}
	//ont ajoute un a index car ont veux aller a l'index après le \n
	index++;
	//ont enleve tout ce qui a été mis dans ligne
	//donc tout à partir de index et jusqu'à la fin de la statique
	//(tout ce qui à été lue après le \n touvé)
	leftover = ft_substr(leftover, index, ft_strlen(leftover) - index, 0);
	//si le retour de read est 0 et que la static est vide
	//ont peut avoir finis de lire le fichier mais pas avoir finis de trouver les \n
	if (result == 0 && ft_strlen(leftover) == 0)
	{
		//comme ont à finis de lire le fichier, gnl ne seras pas rappeler
		//notre statique est donc innutile, ont libère l'espace aloué
		free(leftover);
		//le retour (0) ferme officielement la fonction et renvoie 0
		//ont signifie que l'ont a finis de lire le fichier
		return (0);
	}
	//si le retour de read est -1, alors il y as eu un problème
	if (result == -1)
	{
		//comme il y as eu un problème, ont return -1 pour le signifier
		return (-1);
	}
	//si tout c'est bien passer, ont retourne 1
	//1 impliquant qu'ont a bien lue une ligne du fichier
	return (1);
}
