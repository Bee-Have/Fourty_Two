/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:28:15 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/30 15:28:25 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//fonction qui remplis un autre fichier avec le retour de gnl
void	fill_fd(int fd, char *str)
{
	//la fonction write ayant un retour, j'ai besoin d'une valeur de base
	//write() renvoie le nombre de character qu'il a écrit
	int		i;

	//ont écrit dans le fichier la ligne lue par gnl
	i = write(fd, str, ft_strlen(str));
	//les lignes donnés n'ayant pas de \n, ont imprime un \n manuellement
	i = write(fd, "\n", 1);
}

int		main(void)
{
	//le file descriptor qui seras lue 
	int		fd1;
	//le file descriptor sur lequel je vais mettre toutes les lignes lues
	int		fd2;
	//la ligne qui seras envoyer a gnl
	char	*line;
	//le retour de gnl:
	//1=lue
	//0=fin de lecture
	//-1=pb pendant gnl
	int		read;

	//si read = 0 alors rien ne seras lu puisque 0=fin de lecture
	//read = 1 assure que ce seras bien lue, même une  seule fois
	read = 1;
	//ouvre le fichier que l'ont vas lire
	//(ont ne peut pas lire un fichier que l'ont a pas ouver)
	//O_RDONLY = on l'ouvre en signifiant que l'ont va uniquement le lire
	//si l'ont essaie de faire autre chose sur le fichier ont ne pourras pas
	fd1 = open("text2.txt", O_RDONLY);
	//ouvre le fichier sur lequel ont vas écrire le résultat
	//O_WRONLY = ont l'ouvre en signifiant que l'ont vas uniquement écrire
	fd2 = open("result0.txt", O_WRONLY);
	//ont vérifie que le fd éxist et qu'il est bien déclarer
	if (fd1 >= 0 && fd2)
	{
		//pendant que le retour de gnl lis
		//le retour de gnl étant 1, ont lis uniquement quand read=1
		while (read != 0 && read != -1)
		{
			//appel de gnl, lecture du fichier
			read = get_next_line(fd1, &line);
			//fill_fd vas remplir un autre fichier avec les valeurs de retour
			fill_fd(fd2, line);
			//print de line, la ligne lue pas gnl
			printf("line=[%s]\n", line);
			//ont libère l'espace mémoire de line
			//ainsi ont ne vas pas assigner de valeurs par dessus celle qui existe
			//ont auras pas de garbage memory
			free(line);
		}
		//si gnl renvoie -1, c'est une erreure
		if (read == -1)
			printf("-1\n");
		//ont ferme les deux fichier que l'ont a ouvert
		close(fd1);
		close(fd2);
	}
	//classique return (0) pour signifier la fin du programe
	return (0);
}
