//=============================================================================================================
//                                                                                                             
//   ####  ##   ##  ####     #####   ##  ##  ##   ##        ##   ##  #####    ###    ####    #####  #####    
//  ##     ##   ##  ##  ##  ##   ##  ## ##   ##   ##        ##   ##  ##      ## ##   ##  ##  ##     ##  ##   
//   ###   ##   ##  ##  ##  ##   ##  ####    ##   ##        #######  #####  ##   ##  ##  ##  #####  #####    
//     ##  ##   ##  ##  ##  ##   ##  ## ##   ##   ##        ##   ##  ##     #######  ##  ##  ##     ##  ##   
//  ####    #####   ####     #####   ##  ##   #####         ##   ##  #####  ##   ##  ####    #####  ##   ##  
//                                                                                                             
//=============================================================================================================

#ifndef SUDOKU_HPP
# define SUDOKU_HPP

/**========================================================================
 **                            INCLUDES
 *========================================================================**/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <time.h>
# include <mlx.h>

/**========================================================================
 **                            DEFINES
 *========================================================================**/

# define BUFFER_SIZE			1

# define C_WHITE 				"\e[1;37m"
# define C_RED					"\e[1;31m"
# define C_GREEN				"\e[1;32m"

# define MAP_COMPLETED			1
# define MAP_INCOMPLETED		2

# define NBR_MAPS_EASY			2
# define NBR_MAPS_MEDIUM		1
# define NBR_MAPS_HARD			1

/**========================================================================
 **                            DEFINES MAPS TESTES
 *========================================================================**/

# define MAP_TESTES_001			"boards/0_testes/001.txt"
# define MAP_TESTES_001_SOLVED	"boards/0_testes/001_solved.txt"

/**========================================================================
 **                            DEFINES MAPS EASY
 *========================================================================**/

# define MAP_EASY_001			"boards/1_easy/001.txt"
# define MAP_EASY_001_SOLVED	"boards/1_easy/001_solved.txt"
# define MAP_EASY_002			"boards/1_easy/002.txt"
# define MAP_EASY_002_SOLVED	"boards/1_easy/002_solved.txt"

/**========================================================================
 **                            DEFINES MAPS MEDIUM
 *========================================================================**/



/**========================================================================
 **                            DEFINES MAPS HARD
 *========================================================================**/



/**========================================================================
 **                            DEFINES IMAGES
 *========================================================================**/

# define I_BACKGROUND	"imgs/background.xpm"
# define I_SQUARES		"imgs/squares.xpm"
# define I_ACTIVE		"imgs/selection.xpm"
# define I_01			"imgs/01.xpm"
# define I_02			"imgs/02.xpm"
# define I_03			"imgs/03.xpm"
# define I_04			"imgs/04.xpm"
# define I_05			"imgs/05.xpm"
# define I_06			"imgs/06.xpm"
# define I_07			"imgs/07.xpm"
# define I_08			"imgs/08.xpm"
# define I_09			"imgs/09.xpm"

/**========================================================================
 **                            STRUCTS
 *========================================================================**/

typedef struct s_timer
{
	time_t		time;
	time_t		end_t;
	time_t		start_t;
	int			hours;
	int			minutes;
	int			seconds;
}				t_timer;

typedef	struct s_pict
{
	void		*img;
	int			size;
}				t_pict;

typedef struct s_image
{
	t_pict		walls;
	t_pict		squares;
	t_pict		active;
	t_pict		nbr_01;
	t_pict		nbr_02;
	t_pict		nbr_03;
	t_pict		nbr_04;
	t_pict		nbr_05;
	t_pict		nbr_06;
	t_pict		nbr_07;
	t_pict		nbr_08;
	t_pict		nbr_09;
}				t_image;

typedef struct s_numbers
{
	int			v;
	int			v_c;
	int			pt;
}				t_numbers;

typedef struct s_game
{
	t_numbers	nbr[9][9];
	char		**board;
	char		**board_solved;
	int			map_status;
	int			difficulty;
	int			validation;
	int			v_x;
	int			v_y;
	int			keycode;
	void		*mlx;
	void		*window;
	t_image		images;
	t_timer		time;
	// struct timespec	end_t;
	// struct timespec	start_t;
}				t_game;

/**========================================================================
 **                            PROTOTYPES
 *========================================================================**/

//* GAMES 

void	game(void);
int		mouse(int key, int x, int y, t_game *game);
int		key(int keycode, t_game *game);

//* PRINT INFORMATION 

void	print_testes(void);
void	print_start_menu(void);
void	print_end_menu(t_game *game);
void	print_validation(int choice);

//* UTILS 

char	*get_next_line(int fd);
void	get_play_time(t_timer *timer);

//* INITS 

void	init_mlx(t_game *game);
void	init_images(t_game *game);
void	init_map(t_game *game, char *b_clear, char *b_solved);
void	init_board(t_game *game);
void	init_timer(t_game *game);
void	get_start(t_game *game);

//* OTHERS 

int		validate_game(t_game *game);
char	**create_board(int file);
void	print_board(t_game *game);
void	game_testes(t_game *game);
void	game_easy(t_game *game);
int 	end_game(t_game *game);
void	finish_game(t_game *game);

#endif