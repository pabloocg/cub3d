/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 18:04:00 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/10 10:55:03 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int		line_empty(char *line)
{
	char *cpyline;

	cpyline = line;
	if (*cpyline == '\0')
		return (1);
	return (0);
}

int		check_sprites(char *line)
{
	int i;
	int	count;

	i = -1;
	count = 0;
	while (line[++i])
		if (line[i] == '2' || line[i] == '3' || line[i] == '4' ||
			line[i] == '5' || line[i] == '6')
			count++;
	return (count);
}

int		check_file(char *line, t_valid *check)
{
	if (check_map_bg(line))
	{
		check->num_sprites += check_sprites(line);
		return ((check_map(check) == 1) ? 1 : 0);
	}
	else if (ft_strchr(line, 'R'))
		return ((check_resolution(line, check) == 1) ? 1 : 0);
	else if (ft_strchr(line, 'O') || ft_strchr(line, 'E') ||
		ft_strchr(line, 'W'))
		return ((check_textures(line, check) == 1) ? 1 : 0);
	else if (ft_strchr(line, 'S'))
		return ((check_sprite(line, check, 'S') == 1) ? 1 : 0);
	else if (ft_strchr(line, 'L'))
		return ((check_sprite(line, check, 'L') == 1) ? 1 : 0);
	else if (ft_strchr(line, 'G'))
		return ((check_sprite(line, check, 'G') == 1) ? 1 : 0);
	else if (ft_strchr(line, 'F'))
		return ((check_sprite(line, check, 'F') == 1) ? 1 : 0);
	else if (ft_strchr(line, 'C'))
		return ((check_sprite(line, check, 'C') == 1) ? 1 : 0);
	else if (line_empty(line))
		return (1);
	else
		return (0);
}

int		check_main(int fd_open, t_valid *check)
{
	char	*line;
	int		ok;

	while (get_next_line(fd_open, &line) > 0)
	{
		ok = check_file(line, check);
		free(line);
		if (ok == 0)
			return (0);
	}
	free(line);
	return (1);
}

int		isvalid(char *argv[])
{
	int			fd_open;
	t_valid		*check;
	int			count_sprites;

	if ((fd_open = open(argv[1], O_RDONLY)) < 0)
		ft_exit(1);
	if (!(check = (t_valid *)malloc(sizeof(t_valid))))
		return (-1);
	check->first_map = 0;
	check->content_map = 0;
	check->last_map = 0;
	check->num_sprites = 0;
	if (!(check_main(fd_open, check)))
	{
		free(check);
		close(fd_open);
		ft_exit(2);
	}
	close(fd_open);
	count_sprites = check->num_sprites;
	free(check);
	return (count_sprites);
}
