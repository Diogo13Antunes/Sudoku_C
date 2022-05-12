//=============================================================================
//                                                                             
//   ####      ###    ###    ###  #####        ######  #####   ####  ######  
//  ##        ## ##   ## #  # ##  ##             ##    ##     ##       ##    
//  ##  ###  ##   ##  ##  ##  ##  #####          ##    #####   ###     ##    
//  ##   ##  #######  ##      ##  ##             ##    ##        ##    ##    
//   ####    ##   ##  ##      ##  #####          ##    #####  ####     ##    
//                                                                             
//=============================================================================

#include "../includes/sudoku.h"

void	game_testes(t_game *game)
{
	init_map(game, MAP_TESTES_001, MAP_TESTES_001_SOLVED);
	return ;
}

void	game_easy(t_game *game)
{
	int map = 0;

	map = rand() % NBR_MAPS_EASY + 1;
	if (map == 1)
		init_map(game, MAP_EASY_001, MAP_EASY_001_SOLVED);
	else if (map == 2)
		init_map(game, MAP_EASY_002, MAP_EASY_002_SOLVED);
	else
		exit(1);
}

int	validate_game(t_game *game)
{
	int i = 0;
	int ii = 0;
	int counter = 0;

	while (i < 9)
	{
		ii = 0;
		while (ii < 9)
		{
			if (game->nbr[i][ii].v != game->nbr[i][ii].v_c && game->nbr[i][ii].v != 0)
				counter += 1;
			ii++;
		}
		i++;
	}
	print_validation(counter);
	if (counter == 0)
		return (0);
	else
		return (1);
}

int	check_end_game(t_game *game)
{
	int i = 0;
	int ii = 0;
	int	counter = 0;

	while (i < 9)
	{
		ii = 0;
		while (ii < 9)
		{
			if (game->nbr[i][ii].v == 0)
				counter++;
			ii++;
		}
		i++;
	}
	if (counter == 0 && validate_game(game) == 0)
		game->map_status = MAP_COMPLETED;
	else
		game->map_status = MAP_INCOMPLETED;
	return (0);
}

void	finish_game(t_game *game)
{
	game->time.end_t = time(NULL);
	game->time.time = game->time.end_t - game->time.start_t;
	get_play_time(&game->time);
	check_end_game(game);
	print_end_menu(game);
	end_game(game);
	return ;
}
