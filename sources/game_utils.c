//===================================================================================
//                                                                                   
//   ####      ###    ###    ###  #####        ##   ##  ######  ##  ##       ####  
//  ##        ## ##   ## #  # ##  ##           ##   ##    ##    ##  ##      ##     
//  ##  ###  ##   ##  ##  ##  ##  #####        ##   ##    ##    ##  ##       ###   
//  ##   ##  #######  ##      ##  ##           ##   ##    ##    ##  ##         ##  
//   ####    ##   ##  ##      ##  #####         #####     ##    ##  ######  ####   
//                                                                                   
//===================================================================================

#include "../includes/sudoku.h"

void	get_play_time(t_timer *timer)
{
	int time;

	time = timer->time;
	//* GET HOURS 
	timer->hours = (time/3600); 
	//* GET MINUTES 
	timer->minutes = (time -(3600*timer->hours))/60;
	//* GET SECONDS 
	timer->seconds = (time -(3600*timer->hours)-(timer->minutes*60));
	return ;
}
