/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:46:54 by dpattij           #+#    #+#             */
/*   Updated: 2020/02/20 19:50:24 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <runtime_loop.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		display_prompt(void)
{
	char	*current_directory;

	current_directory = getcwd(NULL, 0);
	if (current_directory == NULL)
	{
		perror("unable to get working directory");
		return (1);
	}
	ft_printf(PROMPT_STRING, current_directory);
	free(current_directory);
	return (0);
}
