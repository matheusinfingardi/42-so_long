#include "../libs/so_long.h"

void count_lines(char *argv, t_data *data)
{
    char *lines;
    int fd;

    fd = open(argv, O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Erro ao abrir o arquivo: %s\n", argv);
        return;
    }
    lines = get_next_line(fd);
    while (lines != NULL)
    {
        data->map_data->lines++;
        free(lines);
        lines = get_next_line(fd);
    }
    close(fd);
}

void    count_columns(char *argv, t_data *data)
{
    char    *lines;
    int     i;
    int     fd;

    fd = open(argv, O_RDONLY);
    lines = get_next_line(fd);
    i = 0;
    while (lines[i] != '\0' && lines[i] != '\n')
    {
        data->map_data->columns++;
        i++;
    }
    while (lines != NULL)
    {
        free(lines);
        lines = get_next_line(fd);
    }
    close(fd);
}

int     check_map_content(char **map)
{
    int     i;
    int     j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
                && map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != '\n')
                return(0);
            j++;
        }
        i++;
    }
    return (1);
}

int     check_map_components(char **map, t_data *data)
{
    int     i;
    int     j;

    i = 0;
    while(map[i] != NULL)
    {
        j = 0;
        while(map[i][j] != '\0')
        {
            if (map[i][j] == 'P')
                data->content->player++;
            if (map[i][j] == 'C')
                data->content->collectible++;
            if (map[i][j] == 'E')
                data->content->exit++;
            j++;
        }
        i++;
    }
    if (data->content->player != 1 || data->content->collectible == 0
        || data->content->exit != 1)
        return (0);
    return (1);
}

void    extract_from_fd_to_map(char *argv, t_data *data)
{
    char    *lines;
    int     i;
    int     fd;

    fd = open(argv, O_RDONLY);
    data->map_data->map = ft_calloc(sizeof(char *), data->map_data->lines + 1);
    data->map_data->dummy_map = ft_calloc(sizeof(char *), data->map_data->lines + 1);
    i = 0;
    lines = get_next_line(fd);
    while (lines != NULL)
    {
        data->map_data->map[i] = ft_strdup(lines);
        data->map_data->dummy_map[i] = ft_strdup(lines);
        free(lines);
        lines = get_next_line(fd);
        i++;
    }
    close(fd);
}
