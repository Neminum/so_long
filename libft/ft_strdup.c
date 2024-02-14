/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:03:43 by tsurma            #+#    #+#             */
/*   Updated: 2023/11/22 13:11:19 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	sl;
	char	*dest;

	sl = 0;
	sl = ft_strlen(s) + 1;
	dest = malloc(sl * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s, sl);
	return (dest);
}
