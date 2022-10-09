/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alpahbet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 07:51:41 by tumolabs          #+#    #+#             */
/*   Updated: 2022/10/05 08:47:46 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_print_comb(void);

void	ft_print_comb(void)
{
	char first;
   
	first = '0';
   	while(first <= '9')
	{

		char sec;

		sec = '0';
		while(sec <= '9')
		{
			write(1, &first, 1);
			write(1, &sec, 1);
			write(1, ", ", 2);
			++sec;
		}
		++first;
	}
}

int main (void)
{
	ft_print_comb();
	return (0);
}
