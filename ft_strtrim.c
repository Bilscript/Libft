/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:16:41 by bhamani           #+#    #+#             */
/*   Updated: 2024/11/01 21:16:41 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isset(char c, const char *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*result;

	i = 0;
	end = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	while (end > start && ft_isset(s1[end - 1], set))
		end--;
	result = (char *)malloc((end - start + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (start < end)
	{
		result[i] = s1[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}

/*
#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set);

int main()
{
	// Cas de test
	char	str1[] = "xxxHelxlo Worldxxx";
	char	set1[] = "x";
	char	str2[] = "xxxHelxlo Worldxxx";
	char	set2[] = "x";
	//char	str3[] = "****Hello***";
	//char	set3[] = "*";
	//char	str4[] = "NoTrimmingHere";
	//char	set4[] = "xyz";

	// Test 1
	char *result1 = ft_strtrim(str1, set1);
	printf("Avant : '%s'\n", str1);
	printf("Après : '%s'\n\n", result1);
	free(result1);

	// Test 2
	char *result2 = ft_strtrim(str2, set2);
	printf("Avant : '%s'\n", str2);
	printf("Après : '%s'\n\n", result2);
	free(result2);

	return 0;
}
*/