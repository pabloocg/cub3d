/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:37:22 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/09 14:49:18 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned char	*create_bitmap_file_header(int height, int width)
{
	int						file_size;
	static unsigned char	file_header[] = {
		0, 0,
		0, 0, 0, 0,
		0
	};

	file_size = INFO_HEADER_SIZE + (BYTES_PER_PIXEL * width) * height;
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(0);
	file_header[4] = (unsigned char)(0);
	file_header[5] = (unsigned char)(0);
	return (file_header);
}

unsigned char	*create_bitmap_file_info(int height, int width)
{
	int						file_size;
	static unsigned char	file_info[] = {
		0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0
	};

	file_size = INFO_HEADER_SIZE + (BYTES_PER_PIXEL * width) * height;
	file_info[0] = (unsigned char)(sizeof(file_info));
	file_info[1] = (unsigned char)(width);
	file_info[2] = (unsigned char)(height);
	file_info[3] = (unsigned char)(1);
	file_info[4] = (unsigned char)(24);
	file_info[5] = (unsigned char)(0);
	file_info[6] = (unsigned char)(file_size);
	file_info[7] = (unsigned char)(2);
	file_info[8] = (unsigned char)(2);
	file_info[9] = (unsigned char)(0);
	file_info[10] = (unsigned char)(0);
	return (file_info);
}

void			write_rgb(t_data *player, int height, int width, int fd)
{
	int						x;
	int						y;

	y = height + 1;
	while ((--y >= 0) && (x = -1))
		while (++x < width)
			ft_putnbr_fd(player->img.image[(y * player->map.width) + x], fd);
}

void			generate_bitmap_image(t_data *player, int height, int width)
{
	int						fd;
	unsigned char			*file_header;
	unsigned char			*file_info;

	file_header = create_bitmap_file_header(height, width);
	file_info = create_bitmap_file_info(height, width);
	if ((fd = open(SCREENSHOT_PATH, O_WRONLY | O_CREAT, 0777)) < 0)
		;
	write(fd, &file_header, sizeof(file_header));
	write(fd, &file_info, sizeof(file_info));
	write_rgb(player, height, width, fd);
	close(fd);
}

int				create_bmp(t_data *player)
{
	int						height;
	int						width;

	height = player->map.height - 1;
	width = player->map.width;
	if (!(player->img.id = mlx_new_image(player->mlx_ptr, player->map.width,
		player->map.height)))
		return (0);
	player->img.image = (int*)mlx_get_data_addr(player->img.id, &player->img.
		data, &player->img.size_line, &player->img.endian);
	if (!(player->depth = malloc(sizeof(double) * player->map.width)))
		return (0);
	render(player);
	generate_bitmap_image(player, height, width);
	ft_printf("Image BMP 'screenshot.bmp' create correctly.\n");
	exit_program(player);
	return (1);
}
