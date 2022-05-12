//===========================================================================================================
//                                                                                                           
//   ####  ##   ##  ####     #####   ##  ##  ##   ##        #####   #####    ##  ##     ##  ######   ####  
//  ##     ##   ##  ##  ##  ##   ##  ## ##   ##   ##        ##  ##  ##  ##   ##  ####   ##    ##    ##     
//   ###   ##   ##  ##  ##  ##   ##  ####    ##   ##        #####   #####    ##  ##  ## ##    ##     ###   
//     ##  ##   ##  ##  ##  ##   ##  ## ##   ##   ##        ##      ##  ##   ##  ##    ###    ##       ##  
//  ####    #####   ####     #####   ##  ##   #####         ##      ##   ##  ##  ##     ##    ##    ####   
//                                                                                                           
//===========================================================================================================

#include "../includes/sudoku.h"

void	print_testes(void)
{
	printf("TESTING FASE!\n");
	exit(1);
}

void	print_start_menu(void)
{
	system("clear");
	printf(C_WHITE);
	printf("======================================================\n");
	printf("\n");
	printf("   ####  ##   ##  ####     #####   ##  ##  ##   ##  \n");
	printf("  ##     ##   ##  ##  ##  ##   ##  ## ##   ##   ##  \n");
	printf("   ###   ##   ##  ##  ##  ##   ##  ####    ##   ##  \n");
	printf("     ##  ##   ##  ##  ##  ##   ##  ## ##   ##   ##  \n");
	printf("  ####    #####   ####     #####   ##  ##   #####   \n");
	printf("\n");
	printf("======================================================\n");
	printf("\n");
	printf("CHOOSE YOUR LEVEL\n");
	printf("1 > EASY\n");
	printf("2 > MEDIUM\n");
	printf("3 > HARD\n");
	printf("\n0 > EXIT\n");
	printf("\nOPTION > ");
	return ;
}

void	print_end_menu(t_game *game)
{
	system("clear");
	printf(C_WHITE);
	printf("========================================================================================================================================================\n");
	printf("\n");
	printf("  ######  ##   ##    ###    ##     ##  ##  ##   ####        #####   #####   #####          #####   ##        ###    ##    ##  ##  ##     ##   ####      \n");
	printf("    ##    ##   ##   ## ##   ####   ##  ## ##   ##           ##     ##   ##  ##  ##         ##  ##  ##       ## ##    ##  ##   ##  ####   ##  ##         \n");
	printf("    ##    #######  ##   ##  ##  ## ##  ####     ###         #####  ##   ##  #####          #####   ##      ##   ##    ####    ##  ##  ## ##  ##  ###    \n");
	printf("    ##    ##   ##  #######  ##    ###  ## ##      ##        ##     ##   ##  ##  ##         ##      ##      #######     ##     ##  ##    ###  ##   ##    \n");
	printf("    ##    ##   ##  ##   ##  ##     ##  ##  ##  ####         ##      #####   ##   ##        ##      ######  ##   ##     ##     ##  ##     ##   ####      \n");
	printf("\n");
	printf("========================================================================================================================================================\n");
	printf("\n");
	printf("DIFFICULTY \t- ");
	if (game->difficulty == 1)
		printf("EASY\n");
	else if (game->difficulty == 2)
		printf("MEDIUM\n");
	else if (game->difficulty == 3)
		printf("HARD\n");
	else if (game->difficulty == 13)
		printf("TEST LEVEL\n");
	printf("TIME \t\t- %d:%d:%d\n", game->time.hours, game->time.minutes, game->time.seconds);
	printf("VALIDATIONS \t- %d\n", game->validation);
	printf("MAP STATUS \t- ");
	if (game->map_status == MAP_COMPLETED)
		printf("COMPLETED\n");
	else
		printf("INCOMPLETED\n");
	printf("\n");
}

void	print_validation(int choice)
{
	if (choice == 0)
	{
		printf(C_WHITE);
		printf("\n-------------------\n");
		printf("Validation: ");
		printf(C_GREEN);
		printf("[OK]\n");
		printf(C_WHITE);
		printf("-------------------\n");
	}
	else
	{
		printf(C_WHITE);
		printf("\n-------------------\n");
		printf("Validation: ");
		printf(C_RED);
		printf("[KO]\n");
		printf(C_WHITE);
		printf("-------------------\n");
	}
	return ;
}
