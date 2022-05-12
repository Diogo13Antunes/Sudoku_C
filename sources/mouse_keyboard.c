//============================================================================================================================================================
//                                                                                                                                                            
//  ###    ###   #####   ##   ##   ####  #####          ###    ##     ##  ####          ##  ##  #####  ##    ##  #####    #####     ###    #####    ####    
//  ## #  # ##  ##   ##  ##   ##  ##     ##            ## ##   ####   ##  ##  ##        ## ##   ##      ##  ##   ##  ##  ##   ##   ## ##   ##  ##   ##  ##  
//  ##  ##  ##  ##   ##  ##   ##   ###   #####        ##   ##  ##  ## ##  ##  ##        ####    #####    ####    #####   ##   ##  ##   ##  #####    ##  ##  
//  ##      ##  ##   ##  ##   ##     ##  ##           #######  ##    ###  ##  ##        ## ##   ##        ##     ##  ##  ##   ##  #######  ##  ##   ##  ##  
//  ##      ##   #####    #####   ####   #####        ##   ##  ##     ##  ####          ##  ##  #####     ##     #####    #####   ##   ##  ##   ##  ####    
//                                                                                                                                                            
//============================================================================================================================================================

#include "../includes/sudoku.h"

void	move_active(t_game *game, int key)
{
	if (key == 126 && game->v_y - 1 >= 0 && game->v_y - 1 < 9)
		game->v_y -= 1;
	else if (key == 123 && game->v_x - 1 >= 0 && game->v_x - 1 < 9)
		game->v_x -= 1;
	else if (key == 125 && game->v_y + 1 >= 0 && game->v_y + 1 < 9)
		game->v_y += 1;
	else if (key == 124 && game->v_x + 1 >= 0 && game->v_x + 1 < 9)
		game->v_x += 1;
	mlx_clear_window(game->mlx, game->window);
	print_board(game);
	mlx_put_image_to_window(game->mlx, game->window, game->images.active.img, (game->v_x * 71) + 5, (game->v_y * 71) + 5);
}

int	mouse(int key, int x, int y, t_game *game)
{
	if (key != 1 || x < 0 || x > 644 || y < 0 || y > 644)
		return (1);
	game->v_x = (x - (x % 71)) / 71;
	game->v_y = (y - (y % 71)) / 71;
	mlx_clear_window(game->mlx, game->window);
	print_board(game);
	mlx_put_image_to_window(game->mlx, game->window, game->images.active.img, (game->v_x * 71) + 5, (game->v_y * 71) + 5);
	return (0);
}

int	key(int keycode, t_game *game)
{
	if (keycode >= 82 && keycode < 90)
		game->keycode = keycode - 82;
	else if (keycode > 90 && keycode < 93)
		game->keycode = keycode - 83;
	else if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
	{
		move_active(game, keycode);
		return (0);
	}
	else if (keycode == 9)
	{
		game->validation += 1;
		validate_game(game);
		return (0);
	}
	else if (keycode == 53)
	{
		finish_game(game);
		return (0);
	}
	else if (keycode == 3 || keycode == 36)
	{
		finish_game(game);
		return (0);
	}
	else
	{
		// printf("KEY -> %d\n", keycode)
		return (1);
	}
	if (game->nbr[game->v_y][game->v_x].pt == 1)
		return (1);
	game->nbr[game->v_y][game->v_x].v = game->keycode;
	game->keycode = 0;
	mlx_clear_window(game->mlx, game->window);
	mlx_put_image_to_window(game->mlx, game->window, game->images.active.img, (game->v_x * 70) + 5, (game->v_y * 70) + 5);
	print_board(game);
	return (0);
}
