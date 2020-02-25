/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime_loop.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:40:48 by dpattij           #+#    #+#             */
/*   Updated: 2020/02/20 20:00:11 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUNTIME_LOOP_H
# define RUNTIME_LOOP_H

# define PROMPT_STRING "\033[31;1m%s\033[0m > "

int		runtime_loop(void);
int		display_prompt(void);
int		read_char(char *out);
int		read_line(
		char **line,
		int eof_matters);
int		take_input(char **input);

#endif
