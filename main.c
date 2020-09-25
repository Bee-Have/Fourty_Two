/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:21:26 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/25 16:02:49 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"


int		main(void)
{
	char	*s = "T h e m o s t m e r c i f u l t h i n g i n t h e w o r l d , I t h i n k , i s t h e i n a b i l i t y o f t h e h u m a n m i n d t o c o r r e l a t e a l l i t s c o n t e n t s . W e l i v e o n a p l a c i d i s l a n d o f i g n o r a n c e i n t h e m i d s t o f b l a c k s e a s o f i n f i n i t y, a n d i t w a s n o t m e a n t t h a t w e s h o u l d v o y a g e f a r . T h e s c i e n c e s , e a c h s t r a i n i n g i n i t s o w n d i r e c t i o n , h a v e h i t h e r t o h a r m e d u s l i t t l e ; b u t s o m e d a y t h e p i e c i n g t o g e t he r o f d i s s o c i a t e d k n o w l e d g e w i l l o p e n u p s u c h t e r r i f y i n g v i s t a s o f r e a l i t y , a n d o f o u r f r i g h t f u l p o s i t i o n t h e r e i n , t h a t w e s h a l l e i t h e r g o m a d f r o m t h e r e v e l a t i o n o r f l e e f r o m t h e d e a d l y l i g h t i n t o t h e p e a c e a n d s a f e t y o f a n e w d a r k a g e . T h e o s o p h i s t s h a v e g u e s s e d a t t h e a w e s o m e g r a n d e u r o f t h e c o s m i c c y c l e w h e r e i n o u r w o r l d a n d h u m a n r a c e f o r m t r a n s i e n t i n c i d e n t s . T h e y h a v e h i n t e d a t s t r a n g e s u r v i v a l s i n t e r m s w h i c h w o u l d f r e e z e t h e b l o o d i f n o t m a s k e d b y a b l a n d o p t i m i s m . B u t i t i s n o t f r o m t h e m t h a t t h e r e c a m e t h e s i n g l e g l i m p s e o f f o r b i d d e n a e o n s w h i c h c h i l l s m e w h e n I t h i n k o f i t a n d m a d d e n s m e w h e n I d r e a m o f i t . T h a t g l i m p s e , l i k e a l l d r e a d g l i m p s e s o f t r u t h , f l a s h e d o u t f r o m a n a c c i d e n t a l p i e c i n g t o g e t h e r o f s e p a r a t e d t h i n g s — i n t h i s c a s e a n o l d n e w s p a p e r i t e m a n d t h e n o t e s o f a d e a d p r o f e s s o r . I h o p e t h a t n o o n e e l s e w i l l a c c o m p l i s h t h i s p i e c i n g o u t ; c e r t a i n l y , i f I l i v e , I s h a l l n e v e r k n o w i n g l y s u p p l y a l i n k i n s o h i d e o u s a c h a i n . I t h i n k t h a t t h e p r o f e s s o r , t o o , i n t e n d e d t o k e e p s i l e n t r e g a r d i n g t h e p a r t h e k n e w , a n d t h a t h e w o u l d h a v e d e s t r o y e d h i s n o t e s h a d n o t s u d d e n d e a t h s e i z e d h i m . ";
	char	c = ' ';
	char	**result;
	int		i;
	
	i = 0;
	result = ft_split((const char *)s, c);
	if (result == NULL)
		return (0);
	while (result != NULL && result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}

	return (0);
}
