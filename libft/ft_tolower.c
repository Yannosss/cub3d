/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:39:25 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/01 17:43:24 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int character)
{
	if (character >= 'A' && character <= 'Z')
		return (character += 32);
	return (character);
}