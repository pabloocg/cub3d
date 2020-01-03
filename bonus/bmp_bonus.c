/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:37:22 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/27 11:34:46 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

unsigned char	*create_bitmap_file_header(int height, int width, int padding_size)
{
	int						file_size;
	static unsigned char	file_header[] = {
		0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
	};

	file_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (BYTES_PER_PIXEL * width + padding_size) * height;
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
	file_header[4] = (unsigned char)(width);
	file_header[5] = (unsigned char)(height);
	file_header[10] = (unsigned char)(BYTES_PER_PIXEL);
	return (file_header);
}

void			write_rgb(data_t *player, int height, int width, int fd)
{
	int		x;
	int		y;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			ft_putnbr_fd(player->img.image[(y * player->map.width) + x], fd);
			y++;
		}
		x++;
	}
}

void			generate_bitmap_image(data_t *player, int height, int width)
{
	int				fd;
	unsigned char	*file_header;

	file_header = create_bitmap_file_header(height, width, (4 - (width * BYTES_PER_PIXEL) % 4) % 4);
	fd = open(SCREENSHOT_PATH, O_WRONLY);
	write(fd, file_header, FILE_HEADER_SIZE);
	write_rgb(player, height, width, fd);
	close(fd);
}

int				create_bmp(data_t *player)
{
	int height;
	int width;

	height = player->map.height - 1;
	width = player->map.width;
	if (!(player->img.id = mlx_new_image(player->mlx_ptr, player->map.width, player->map.height)))
		return (0);
	player->img.image = (int*)mlx_get_data_addr(player->img.id, &player->img.data, &player->img.size_line, &player->img.endian);
	if (!(player->depth = malloc(sizeof(int) * player->map.width)))
		return (0);
	render(player);
	generate_bitmap_image(player, height, width);
	ft_printf("Image BMP 'screenshot.bmp' create correctly.\n");
	exit_program(player);
	return (1);
}

void			bmp_check(data_t *player, char *argv[])
{
	if (!ft_strcmp(argv[2], "-save"))
	{
		if (!(create_bmp(player)))
		{
			free_all(player);
			ft_exit(5);
		}
	}
	else
	{
		free_all(player);
		ft_exit(3);
	}
}
