/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/30 20:32:04 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			main(int ac, char **av)
{
	t_env e;

	init_e(&e, ac, av);
	ft_parse_flags(&e, ac, av);
	ft_files_to_string(&e);
	init_players(&e);
	ft_parsing(&e, ac);
	ft_build_arena(&e, ac);
	ft_init_cursor(&e);
	ft_move_cursors(&e);
	ft_declare_winner(&e);
	ft_exit(&e, 0);
	return (0);
}
