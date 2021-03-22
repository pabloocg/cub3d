/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:37:22 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/10 12:51:37 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

unsigned char	*create_bitmap_file_header(t_data *player, int paddingsiz)
{
	int						filesize;
	static unsigned char	fileheader[] = {
		0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
	};

	filesize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (BYTES_PER_PIXEL *
	player->map.width + paddingsiz) * player->map.screen_height;
	fileheader[0] = (unsigned char)('B');
	fileheader[1] = (unsigned char)('M');
	fileheader[2] = (unsigned char)(filesize);
	fileheader[3] = (unsigned char)(filesize >> 8);
	fileheader[4] = (unsigned char)(filesize >> 16);
	fileheader[5] = (unsigned char)(filesize >> 24);
	fileheader[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
	return (fileheader);
}

unsigned char	*create_bitmap_info_header(t_data *player)
{
	static unsigned char	infoheader[] = {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
	};

	infoheader[0] = (unsigned char)(INFO_HEADER_SIZE);
	infoheader[4] = (unsigned char)(player->map.width);
	infoheader[5] = (unsigned char)(player->map.width >> 8);
	infoheader[6] = (unsigned char)(player->map.width >> 16);
	infoheader[7] = (unsigned char)(player->map.width >> 24);
	infoheader[8] = (unsigned char)(player->map.width);
	infoheader[9] = (unsigned char)(player->map.screen_height >> 8);
	infoheader[10] = (unsigned char)(player->map.screen_height >> 16);
	infoheader[11] = (unsigned char)(player->map.screen_height >> 24);
	infoheader[12] = (unsigned char)(1);
	infoheader[14] = (unsigned char)(BYTES_PER_PIXEL * 8);
	return (infoheader);
}

static int		write_bmp_data(int file, unsigned char *image, t_data *player)
{
	static unsigned char	zero[3] = {
		0, 0, 0
	};
	int						i;
	int						j;
	int						color;
	int						paddingsize;

	paddingsize = (4 - (player->map.width * BYTES_PER_PIXEL) % 4) % 4;
	i = -1;
	while ((++i < player->map.screen_height) && (j = -1))
		while (++j < player->map.width)
		{
			color = get_color_bmp(image, j, i, player);
			write(file, &color, BYTES_PER_PIXEL);
			if (paddingsize > 0)
			{
				write(file, &zero, paddingsize);
				return (0);
			}
		}
	return (1);
}

void			generate_bitmap_image(unsigned char *image, t_data *player)
{
	int						paddingsize;
	unsigned char			*fileheader;
	unsigned char			*infoheader;
	int						fd;

	paddingsize = (4 - (player->map.width * BYTES_PER_PIXEL) % 4) % 4;
	if ((fd = open(SCREENSHOT_PATH, O_WRONLY | O_CREAT, 0777)) < 0)
		return ;
	fileheader = create_bitmap_file_header(player, paddingsize);
	infoheader = create_bitmap_info_header(player);
	write(fd, fileheader, FILE_HEADER_SIZE);
	write(fd, infoheader, INFO_HEADER_SIZE);
	write_bmp_data(fd, image, player);
	close(fd);
}

int				create_bmp(t_data *player)
{
	if (!(player->depth = (double*)malloc(sizeof(double) * player->map.width)))
		return (0);
	if (!(player->img.id = mlx_new_image(player->mlx_ptr, player->map.width,
		player->map.screen_height)))
		return (0);
	player->img.image = (int*)mlx_get_data_addr(player->img.id,
		&player->img.data, &player->img.size_line, &player->img.endian);
	srand(time(0));
	render(player);
	generate_bitmap_image((unsigned char*)player->img.image, player);
	ft_printf("Image BMP 'screenshot.bmp' create correctly.\n");
	exit_program_bmp(player);
	return (1);
}
