#include "../libs/so_long.h"

void    load_images(t_data *data)
{
    int     img_size;

    data->img = ft_calloc(6, sizeof(void *));
    img_size = 48;
    data->img[0] = mlx_xpm_file_to_image(data->mlx, "images/player_right.xpm", &img_size, &img_size);
    data->img[1] = mlx_xpm_file_to_image(data->mlx, "images/player_left.xpm", &img_size, &img_size);
    data->img[2] = mlx_xpm_file_to_image(data->mlx, "images/collectible.xpm", &img_size, &img_size);
    data->img[3] = mlx_xpm_file_to_image(data->mlx, "images/exit.xpm", &img_size, &img_size);
    data->img[4] = mlx_xpm_file_to_image(data->mlx, "images/wall.xpm", &img_size, &img_size);
    data->img[5] = mlx_xpm_file_to_image(data->mlx, "images/floor.xpm", &img_size, &img_size);
}

void    render_images(t_data *data, int i, int j)
{
    while (++i < data->map_data->lines && data->map_data->map[i] != NULL)
    {
        j = -1;
        while (++j < data->map_data->columns && data->map_data->map[i] != NULL)
        {
            if (data->map_data->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->img[4], j * 48, i * 48);
            else if (data->map_data->map[i][j] == '0')
                mlx_put_image_to_window(data->mlx, data->win, data->img[5], j * 48, i * 48);
            else if (data->map_data->map[i][j] == 'P')
                mlx_put_image_to_window(data->mlx, data->win, data->img[data->player_img_index], j * 48, i * 48);
            else if (data->map_data->map[i][j] == 'C')
                mlx_put_image_to_window(data->mlx, data->win, data->img[2], j * 48, i * 48);
            else if (data->map_data->map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx, data->win, data->img[3], j * 48, i * 48);
        }
    }
}

int     close_window(t_data *data)
{
    free_all(data);
    return (0);
}