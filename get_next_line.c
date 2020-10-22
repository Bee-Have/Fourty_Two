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

//cette fonction vas chercher un \n dans la static
int		find_newline(char *str, int read)
{
	//i sert à parcourir la static
	int		i;

	//comme ont parcour la static, ont commence par l'index 0
	i = 0;
	//si la static est NULL alors ont à un problème
	if (!str)
		return (-1);
	//ont parcour la static jusqu'au \0
	while (str[i] != '\0')
	{
		//si ont rencontre un \n
		if (str[i] == '\n')
		{
			//alors ont retourne sa position dans la static
			return (i);
		}
		//sinon ont continue à parcourir la static
		i++;
	}
	//si ont à lus 0 characters
	//et que la static est vide
	//alors ont return 0
	if (read == 0 && ft_strlen(str) == 0)
		return (i);
	//sinon ont renvoie la valeur original de l'index : -1
	return (-1);
}

//cette fonction lis le fichier fournis
int		read_fd(int fd, int *index, char **leftover)
{
	//comme dans gnl, ont déclare un résultat pour le retour de read()
	//ceci permet de vérifier que l'ont a bien lue
	//ainsi que combien de characters ont été lus
	int		result;
	//sert à récupérer ce qui à été lus par read()
	//sont contenue est par la suite transféré à la static
	char	*buffer;

	//comme gnl, result doit être supèrieur à0
	result = 1;
	//si ont à bien lue des characters du fichier
	//et que l'ont à pas encore trouvé de \n
	while (result > 0 && *index == -1)
	{
		//ont alloue un espace de BUFFER_SIZE pour notre buffer
		//read() liras max BUFFER_SIZE character dans le fichier
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		//si notre allocation de mémoire échoue alors ont s'arrête
		if (!buffer)
			return (-1);
		//ont lis sur le fichier en mettant tous les characters lus dans buffer
		result = read(fd, buffer, BUFFER_SIZE);
		//result est le nombre de characters lus
		//ont s'assure de ne renvoyer que des characters qui seront lus
		buffer[result] = '\0';
		//la static vas ajouter à sont contenue ce qui à été lus
		*leftover = ft_strjoin(*leftover, buffer);
		//ont vérifier que l'ont à pas lus de \n
		*index = find_newline(*leftover, result);
		//ont libère l'espace aloué à notre buffer pour recommencer
		free(buffer);
	}
	//ont ne sort que l'orsqu'ont à trouvé un \n
	//ou que l'ont à finis de lire
	//ont renvoie le nombre de characters qui ont été lus en dernier
	return (result);
}

//!!!!!!!PROGRAMME COMMENCE ICI!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//**line != line[][] | **line = la variable original envoyé
int		get_next_line(int fd, char **line)
{
	//déclaration de la static, ici à NULL
	//static signifie que l'ont ne déclare qu'une seule fois la variable
	//quand la fonction est rappeler, cette ligne est ignoré
	static char		*leftover = NULL;
	//les resultat de read()
	//le nombre de character lus par read()
	int				result;
	//la position du \n dand leftover
	int				index;

	//si index=0, quand le read() renveras 0, ont ne sauras pas si c'est
	//un retour de read ou la variable original
	//read ne peut pas renvoyer -1 donc index est une valeur sur
	//(peut étre un tout autre nombre qui ne peut pas étre un retour de read())
	index = -1;
	//result=1 permet de vérifier que l'ont à bien tout lue
	//si read=0 alors ont à finit de lire
	result = 1;
	//si la static existe
	//si la static n'est PAS vide
	if (leftover && leftover[0] != '\0')
	{
		//ont vérifie si la static contient déja un \n
		index = find_newline(leftover, 0);
	}
	//si la static ne contient pas de \n
	//ou que notre static est vide ou NULL
	if (index == -1)
	{
		//ont appel notre fonction qui vas lire notre fd
		result = read_fd(fd, &index, &leftover);
	}
	//si aprés avoir lus notre index est toujours vide
	//(ce cas n'arrive que en fin de fichier car l'EOF n'est pas un \n)
	if (index == -1)
	{
		//ont met TOUT le contenue de la static dans *line
		//il n'y as plus rien a lire, la static contient la dernière ligne
		*line = ft_substr(leftover, 0, ft_strlen(leftover), 1);
	}
	//si la static contient un \n
	//index est donc l'address du \n
	else
	{
		//ont met la static JUSQU'AU \n dans *line
		//le reste de la static ne nous intéresse pas ici
		*line = ft_substr(leftover, 0, index, 1);
	}
	//index étant l'addresse du \n, ont incrément index
	//cela nous permet de passer au character d'après
	index++;
	//la static est donc égale à tout ce qui n'as pas été mis dans *line
	//la static est égale à TOUT ce qui est APRÈS le \n
	leftover = ft_substr(leftover, index, ft_strlen(leftover) - index, 0);
	//SI un malloc a échoué ou read{} a eu un probléme
	//OU read() n'as rien lu (read à donc lue tout le texte)
	//ET que la static est vide (*line à déja tout récupérer)
	//dans le cas ou BUFFER_SIZE est grand, ont vas lire très vite
	//il faut donc s'assurer que l'ont à bien tout renvoyer avant de return 0
	if (result == -1 || (result == 0 && ft_strlen(leftover) == 0))
	{
		//alors ont ne ferras plus d'appel de gnl
		//notre static ne seras donc plus utiliser
		//ont libère donc l'espace mémoire qui lui était aloué
		free(leftover);
		//ont retourne par la suite result
		//SOIT result=-1 : un problème est survenue
		//SOIT result = 0 : ont à finis de lire
		return (result);
	}
	//si l'ont à bien lut
	//que l'ont à pas d'erreures
	//et que l'ont as pas atteint la fin du fichier
	//alors ont renvoie 1 (ont a bien lue une ligne)
	return (1);
}
