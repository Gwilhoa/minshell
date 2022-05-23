/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:27:23 by guyar             #+#    #+#             */
/*   Updated: 2022/05/23 20:14:43 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redirec(t_process *process)
{
	process->all_redirec = split_files(process->redirec);
	// ici on devrait renvoyer les directions mais je bug
	// les fonctions en commentaire sont les trucs sur lesquelles j'ai patogé
}

// void	ft_send_out(t_process *process)
// {
// 	int	i;
// 	int j;
// 	int	tmp;

// 	i = 0;
// 	j = 0;
// 	while (process->all_redirec[i])
// 	{
// 		if (ft_find_outfile(&process->code, process->all_redirec[i]) != NULL)
// 		{
// 			if (open(ft_find_outfile(&process->code, process->all_redirec[i]), O_RDONLY) == -1)
// 				process->outfile = ft_find_outfile(&process->code, process->all_redirec[i])
// 			else
// 				process->outfile = ft_find_outfile(&process->code, process->all_redirec[i]; 
// 		}
// 		if (ft_find_infile(&process->code, process->all_redirec[i]) != NULL)
// 		{
			
// 		}
// 	}

// }

// char *ft_find_outfile(int *code, char *str)
// {
// 	int i;

// 	i = 0;
// 	if (str[i] == '>')
// 		i++;
// 	if (str[i] == '>')
// 	{
// 		code = 1;
// 		i++;
// 	}
// 	if (str[i] == ' ')
// 		i++;
// 	if (str[i] == ' ')
// 		return (NULL);
// 	return (str[i]);
// }
