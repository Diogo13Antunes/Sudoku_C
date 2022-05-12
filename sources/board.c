//=======================================================================================================
//                                                                                                       
//   ####  ##   ##  ####     #####   ##  ##  ##   ##        #####    #####     ###    #####    ####    
//  ##     ##   ##  ##  ##  ##   ##  ## ##   ##   ##        ##  ##  ##   ##   ## ##   ##  ##   ##  ##  
//   ###   ##   ##  ##  ##  ##   ##  ####    ##   ##        #####   ##   ##  ##   ##  #####    ##  ##  
//     ##  ##   ##  ##  ##  ##   ##  ## ##   ##   ##        ##  ##  ##   ##  #######  ##  ##   ##  ##  
//  ####    #####   ####     #####   ##  ##   #####         #####    #####   ##   ##  ##   ##  ####    
//                                                                                                       
//=======================================================================================================

#include "../includes/sudoku.h"

char	**create_board(int file)
{
	int i = 0;
	char **board;

	board = (char **)malloc(sizeof(char *) * 10);
	if (board == NULL)
		return (NULL);
	while (i < 9)
	{
		board[i] = get_next_line(file);
		i++;
	}
	board[i] = NULL;
	return (board);
}

void	print_numbers(t_game *game)
{
	int y = 5;
	int x;
	int i = 0;
	int ii;

	while (i < 9)
	{
		ii = 0;
		x = 5;
		while (ii < 9)
		{
			if (game->nbr[i][ii].v == 1)
				mlx_put_image_to_window(game->mlx, game->window, game->images.nbr_01.img, x, y);
			else if (game->nbr[i][ii].v == 2)
				mlx_put_image_to_window(game->mlx, game->window, game->images.nbr_02.img, x, y);
			else if (game->nbr[i][ii].v == 3)
				mlx_put_image_to_window(game->mlx, game->window, game->images.nbr_03.img, x, y);
			else if (game->nbr[i][ii].v == 4)
				mlx_put_image_to_window(game->mlx, game->window, game->images.nbr_04.img, x, y);
			else if (game->nbr[i][ii].v == 5)
				mlx_put_image_to_window(game->mlx, game->window, game->images.nbr_05.img, x, y);
			else if (game->nbr[i][ii].v == 6)
				mlx_put_image_to_window(game->mlx, game->window, game->images.nbr_06.img, x, y);
			else if (game->nbr[i][ii].v == 7)
				mlx_put_image_to_window(game->mlx, game->window, game->images.nbr_07.img, x, y);
			else if (game->nbr[i][ii].v == 8)
				mlx_put_image_to_window(game->mlx, game->window, game->images.nbr_08.img, x, y);
			else if (game->nbr[i][ii].v == 9)
				mlx_put_image_to_window(game->mlx, game->window, game->images.nbr_09.img, x, y);
			ii++;
			x += 5 + 66;
		}
		y += 5 + 66;
		i++;
	}
}

void	print_board(t_game *game)
{
	int y = 5;
	int x;
	int i = 0;
	int ii;

	mlx_put_image_to_window(game->mlx, game->window, game->images.walls.img, 0, 0);
	while (i < 9)
	{
		ii = 0;
		x = 5;
		while (ii < 9)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->images.squares.img, x, y);
			ii++;
			x += 5 + 66;
		}
		y += 5 + 66;
		i++;
	}
	print_numbers(game);
}
