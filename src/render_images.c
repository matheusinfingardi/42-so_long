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
    if (data->img && data->img[0])
    {
        mlx_destroy_image(data->mlx, data->img[0]);
        free(data->img);
        data->img = NULL;
    }
    if (data->win)
    {
        mlx_destroy_window(data->mlx, data->win);
        data->win = NULL;
    }
    if (data->end_win)
    {
        mlx_destroy_window(data->mlx, data->end_win);
        data->end_win = NULL;
    }
    free_all(data);
    exit(0);
    return (0);
}

int handle_expose(t_data *data)
{
    int win_width = 0;
    int win_height = 0;
    mlx_get_screen_size(data->mlx, &win_width, &win_height);
    int x = 0;
    int y = 0;
    while (y < win_height)
    {
        x = 0;
        while (x < win_width)
        {
            mlx_pixel_put(data->mlx, data->win, x, y, 0x000000);
            x++;
        }
        y++;
    }
    render_images(data, -1, -1);
    return (0);
}

int handle_intro_expose(t_data *data)
{
    int win_width;
    int win_height;
    int x;
    int y;

    win_width = 0;
    win_height = 0;
    x = 0;
    y = 0;
    mlx_get_screen_size(data->mlx, &win_width, &win_height);
    while (y < win_height)
    {
        x = 0;
        while (x < win_width)
        {
            mlx_pixel_put(data->mlx, data->win, x, y, 0x000000);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img[0], 0, 0);
    return 0;
}

int handle_end_expose(t_data *data)
{
    int win_width;
    int win_height;
    int x;
    int y;

    win_width = 0;
    win_height = 0;
    x = 0;
    y = 0;
    mlx_get_screen_size(data->mlx, &win_width, &win_height);
    while (y < win_height)
    {
        x = 0;
        while (x < win_width)
        {
            mlx_pixel_put(data->mlx, data->end_win, x, y, 0x000000);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->end_win, data->end_img, 0, 0);
    return 0;
}