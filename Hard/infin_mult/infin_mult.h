/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 16:18:22 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/26 16:18:23 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFIN_MULT_H
# define INFIN_MULT_H


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int 	ft_atoi(char c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_zerodup(char *str, int n);
void	init_tab(char **tab);
char	*ft_itoa(int n);
char 	ft_unitoa(int n);
int 	is_num(char c);
void	destroy_tab(char **tab);

# endif