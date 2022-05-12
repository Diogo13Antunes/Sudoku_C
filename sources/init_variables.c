//======================================================
//                                                      
//   ####  ##   ##  ####     #####   ##  ##  ##   ##  
//  ##     ##   ##  ##  ##  ##   ##  ## ##   ##   ##  
//   ###   ##   ##  ##  ##  ##   ##  ####    ##   ##  
//     ##  ##   ##  ##  ##  ##   ##  ## ##   ##   ##  
//  ####    #####   ####     #####   ##  ##   #####   
//                                                      
//======================================================

#include "../includes/sudoku.h"

/**========================================================================
 **                           INIT MLX
 *========================================================================**/

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 644, 644, "SUDOKU");
}

/**========================================================================
 **                           INIT IMAGES
 *========================================================================**/

t_pict	img_creator(char *path, void *mlx)
{
	t_pict	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &img.size, &img.size);
	return (img);
}

void	init_images(t_game *game)
{
	game->images.nbr_01 = img_creator(I_01, game->mlx);
	game->images.nbr_02 = img_creator(I_02, game->mlx);
	game->images.nbr_03 = img_creator(I_03, game->mlx);
	game->images.nbr_04 = img_creator(I_04, game->mlx);
	game->images.nbr_05 = img_creator(I_05, game->mlx);
	game->images.nbr_06 = img_creator(I_06, game->mlx);
	game->images.nbr_07 = img_creator(I_07, game->mlx);
	game->images.nbr_08 = img_creator(I_08, game->mlx);
	game->images.nbr_09 = img_creator(I_09, game->mlx);
	game->images.walls = img_creator(I_BACKGROUND, game->mlx);
	game->images.active = img_creator(I_ACTIVE, game->mlx);
	game->images.squares = img_creator(I_SQUARES, game->mlx);
}

/**========================================================================
 **                           INIT TIMER
 *========================================================================**/

void	init_timer(t_game *game)
{
	game->time.start_t = time(NULL);
	return ;
}

/**========================================================================
 **                           INIT MAP
 *========================================================================**/

void	get_start(t_game *game)
{
	if (game->difficulty == 13)
		game_testes(game);
	else if (game->difficulty == 1)
		game_easy(game);
	else
		return ;
}

void	init_map(t_game *game, char *b_clear, char *b_solved)
{
	int		board;
	int		board_solved;

	board = open(b_clear, O_RDONLY);
	if (board == -1)
		exit(1);
	board_solved = open(b_solved, O_RDONLY);
	if (board_solved == -1)
	{
		close(board);
		exit(1);
	}
	game->board = create_board(board);
	game->board_solved = create_board(board_solved);
	close(board);
	close(board_solved);
	return ;
}

void	init_board(t_game *game)
{
	int i = 0;
	int ii = 0;

	while (i < 9)
	{
		ii = 0;
		while (ii < 9)
		{
			game->nbr[i][ii].v = game->board[i][ii] - '0';
			game->nbr[i][ii].v_c = game->board_solved[i][ii] - '0';
			if (game->nbr[i][ii].v == 0)
				game->nbr[i][ii].pt = 0;
			else
				game->nbr[i][ii].pt = 1;
			ii++;
		}
		i++;
	}
	return ;
}
