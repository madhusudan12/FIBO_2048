#include<stdio.h>
struct data
{
	char *name;
	char *date;
	int moves;
	int size;
	struct data *left;
	struct data *right;
};
struct board
{
	int **table;
	int size;
	int empty_Tiles;
};
struct player
{
	char *name;
	int no_of_moves;
	int state;
	char* time;
};

int fib[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269 };


#include"moves.h"
#include"utils.h"
#include"game.h"


int main()
{
	int ch;
	FILE *fp = fopen("records.txt", "w");
	fclose(fp);
label0:
	system("cls");
	printf("\n\n\n\t\t\t**********FIBO-2048**********\n\n\n");
	printf("\t\t\t\t 1.Play Game \3\n\n\t\t\t\t 2.LeaderBoard \3\3\n\n\t\t\t\t 3.Continue  \3\3\3\n\n\t\t\t\t 4.exit :-) \n\n\t\t\t\t  Choice : ");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1: play_Game();
		break;
	case 2:leader_Board();
		break;
	case 3:
		continue_Last();
		break;
	case 4:
		return 0;
	default:
		printf("Invalid Choice : ");
		goto label0;

	}
	goto label0;
	return 0;
}