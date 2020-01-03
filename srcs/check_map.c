/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 18:04:00 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/25 19:55:10 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		if (line[i] == '2')
			count++;
	return (count);
}

int		check_file(char *line, valid_t *check)
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
		return ((check_sprite(line, check) == 1) ? 1 : 0);
	else if (ft_strchr(line, 'F') || ft_strchr(line, 'C'))
		return ((check_color(line, check) == 1) ? 1 : 0);
	else if (line_empty(line))
		return (1);
	else
		return (0);
}

int		check_main(int fd_open, valid_t *check)
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
	valid_t		*check;
	int			count_sprites;

	if ((fd_open = open(argv[1], O_RDONLY)) < 0)
		ft_exit(1);
	if (!(check = (valid_t *)malloc(sizeof(valid_t))))
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