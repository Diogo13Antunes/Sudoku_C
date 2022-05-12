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

void	free_board(char **board)
{
	int	i;

	i = 0;
	while (board[i])
		free(board[i++]);
	free(board);
}

int	end_game(t_game *game)
{
	free_board(game->board);
	free_board(game->board_solved);
	exit(0);
	return (0);
}

void	game(void)
{
	t_game	game;

	game.validation = 0;
	game.difficulty = 0;
	game.v_x = 0;
	game.v_y = 0;
	print_start_menu();
	scanf("%d", &game.difficulty);
	init_mlx(&game);
	init_images(&game);
	if (game.difficulty == 1)
		get_start(&game);
	else if (game.difficulty == 2)
		print_testes();
	else if (game.difficulty == 3)
		print_testes();
	else if (game.difficulty == 13)
		get_start(&game);
	else
		exit(1);
	system("clear");
	init_board(&game);
	print_board(&game);
	mlx_put_image_to_window(game.mlx, game.window, game.images.active.img, (game.v_x * 70) + 5, (game.v_y * 70) + 5);
	init_timer(&game);
	mlx_mouse_hook(game.window, mouse, &game);
	mlx_key_hook(game.window, key, &game);
	mlx_hook(game.window, 17, 0, end_game, &game);
	mlx_loop(game.mlx);
}

int	main(void)
{ 
	game();
	return (0);
}
