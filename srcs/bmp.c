/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:37:22 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/09 18:27:43 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned char*	create_bitmap_file_header(t_data *player, int paddingsiz)
{
    int fileSize;
    static unsigned char fileHeader[] = {
        0,0,
        0,0,0,0,
        0,0,0,0,
        0,0,0,0,
    };

	fileSize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (BYTES_PER_PIXEL *
	player->map.width + paddingsiz) * player->map.height;
    fileHeader[0] = (unsigned char)('B');
    fileHeader[1] = (unsigned char)('M');
    fileHeader[2] = (unsigned char)(fileSize);
    fileHeader[3] = (unsigned char)(fileSize >> 8);
    fileHeader[4] = (unsigned char)(fileSize >> 16);
    fileHeader[5] = (unsigned char)(fileSize >> 24);
    fileHeader[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
    return (fileHeader);
}

unsigned char*	create_bitmap_info_header(t_data *player)
{
	static unsigned char infoHeader[] = {
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
	};

	infoHeader[0] = (unsigned char)(INFO_HEADER_SIZE);
	infoHeader[4] = (unsigned char)(player->map.width);
	infoHeader[5] = (unsigned char)(player->map.width >> 8);
	infoHeader[6] = (unsigned char)(player->map.width >> 16);
	infoHeader[7] = (unsigned char)(player->map.width >> 24);
	infoHeader[8] = (unsigned char)(player->map.width);
	infoHeader[9] = (unsigned char)(player->map.height >> 8);
	infoHeader[10] = (unsigned char)(player->map.height >> 16);
	infoHeader[11] = (unsigned char)(player->map.height >> 24);
	infoHeader[12] = (unsigned char)(1);
	infoHeader[14] = (unsigned char)(BYTES_PER_PIXEL * 8);
	return (infoHeader);
}

static int		write_bmp_data(int file, unsigned char *image, t_data *player)
{
	static unsigned char	zero[3] = {
		0, 0, 0
	};
	int					i;
	int					j;
	int					color;
	int					paddingSize;

	paddingSize = (4 - (player->map.width * BYTES_PER_PIXEL) % 4) % 4;
	i = -1;
	while ((++i < player->map.height) && (j = -1))
		while (++j < player->map.width)
		{
			color = get_color_bmp(image, j, i, player);
			write(file, &color, BYTES_PER_PIXEL);
			if (paddingSize > 0)
			{
				write(file, &zero, paddingSize);
				return (0);
			}
		}
	return (1);
}

void			generate_bitmap_image(unsigned char *image, t_data *player)
{
    int						paddingSize;
    unsigned char*			fileHeader;
    unsigned char*			infoHeader;
	int						fd;

	paddingSize = (4 - (player->map.width * BYTES_PER_PIXEL) % 4) % 4;
	if ((fd = open(SCREENSHOT_PATH, O_WRONLY | O_CREAT, 0777)) < 0)
		return ;
	fileHeader = create_bitmap_file_header(player, paddingSize);
	infoHeader = create_bitmap_info_header(player);
	write(fd, fileHeader, FILE_HEADER_SIZE);
	write(fd, infoHeader, INFO_HEADER_SIZE);
	write_bmp_data(fd, image, player);
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
	generate_bitmap_image((unsigned char*)player->img.image, player);
	ft_printf("Image BMP 'screenshot.bmp' create correctly.\n");
	exit_program(player);
	return (1);
}
