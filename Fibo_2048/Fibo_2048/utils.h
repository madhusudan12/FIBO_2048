#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
void fill_one_for_next_move(struct board *b1)
{
	int k = find_empty_tiles(b1);
	int r = rand();
	int count = 0;
	r = (r + 10) % k;
	int flag = 0;
	for (int i = 0; i < b1->size; i++)
	{
		for (int j = 0; j < b1->size; j++)
		{
			if (b1->table[i][j] == 0)
			{
				if (count == r)
				{
					b1->table[i][j] = 1;
					flag = 1;
					break;
				}
				count++;
			}
		}
		if (flag == 1)
			break;

	}
}


int check_Game_State(struct player*p1, struct board *b1)
{
	for (int i = 0; i < b1->size; i++)
	{
		for (int j = 0; j < b1->size; j++)
		{
			if (b1->table[i][j] == fib[(2 * b1->size*b1->size) - 2])
			{
				p1->state = 1;
				display_Board(b1, p1);
				printf("%s won the game in %d moves ", p1->name, p1->no_of_moves);
				FILE *fp = fopen("records.txt", "a");
				struct data *d1 = (struct data*)malloc(sizeof(struct data));
				d1->date = p1->time;
				d1->name = p1->name;
				d1->moves = p1->no_of_moves;
				d1->size = b1->size;
				d1->right = NULL;
				d1->left = NULL;
				fwrite(d1, sizeof(struct data), 1, fp);
				fclose(fp);
				return 0;
			}
		}
	}	
	return 1;
}

void play_Move(struct board *b1, struct player *p1)
{
	int flag = 0;
	char c;
	do
	{
		flag = 0;
		int **t = (int**)malloc(sizeof(int*)*b1->size);
		for (int i = 0; i < b1->size; i++)
		{
			t[i] = (int*)malloc(sizeof(int)*b1->size);
		}
		for (int i = 0; i < b1->size; i++)
			for (int j = 0; j < b1->size; j++)
				t[i][j] = b1->table[i][j];

		printf("\t\t\t\t\t\t Enter the direction : ");
		fflush(stdin);
		//scanf("%c", &c);
		c = _getche();
		if (c == 'w' || c == 'W')
			move_Up(b1, p1);
		else if (c == 'a' || c == 'A')
			move_Left(b1, p1);
		else if (c == 's' || c == 'S')
			move_Down(b1, p1);
		else if (c == 'd' || c == 'D')
			move_Right(b1, p1);
		else
		{
			printf("Invalid move !");
			system("cls");
		}
		if (b1->empty_Tiles = 0)
		{
			display_Board(b1, p1);
			printf(" \t\t\t%s lost the match with %d moves ", p1->name, p1->no_of_moves);
			break;
		}
		for (int i = 0; i < b1->size; i++)
		{
			for (int j = 0; j < b1->size; j++)
			{
				if (t[i][j] != b1->table[i][j])
				{
					flag = 1;
					break;
				}

			}
		}
		if (flag == 1)
		{
			fill_one_for_next_move(b1);
			display_Board(b1, p1);
		}
		else
		{
			p1->no_of_moves -= 1;
			display_Board(b1, p1);
		}

	} while (check_Game_State(p1, b1));
}


void start_Game(struct player *p1, struct board *b1)
{
	int r = rand();
	int count = 0;
	int flag = 0;
	r = (r+5) % (b1->size);
	for (int i = 0; i < b1->size; i++)
	{
		for (int j = 0; j < b1->size; j++)
		{
			if (count == r)
			{
				b1->table[i][j] = 1;
				break;
				flag = 1;
			}
			else
				count++;
		}
		if (flag == 1||count==r)
			break;

	}
	display_Board(b1, p1);
	play_Move(b1, p1);
}
