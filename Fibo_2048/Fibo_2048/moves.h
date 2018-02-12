#include<stdlib.h>

int find_empty_tiles(struct board *b1)
{
	int count = 0;
	for (int i = 0; i < b1->size; i++)
	{
		for (int j = 0; j < b1->size; j++)
		{
			if (b1->table[i][j] == 0)
				count++;
		}
	}
	return count;
}


void display_Board(struct board *b1, struct player *p1)
{
	system("cls");
	printf("\n\n\n\t\t\t\t**********FIBO-2048************\n\n\n");
	printf("\t\tPlayer      : %s\n", p1->name);
	printf("\t\tNo of Moves : %d\n", p1->no_of_moves);
	printf("\t\tDate        :%s\n\n\n", p1->time);

	for (int i = 0; i < b1->size; i++)
	{
		if (b1->size==2)
			printf("\t\t\t________________________\n\t\t\t");
		else
		    printf("\t\t\t________________________________________________\n\t\t\t");
		for (int j = 0; j < b1->size; j++)
		{
			printf("|           ");
		}
		printf("|\n\t\t\t");
		
		for (int j = 0; j < b1->size; j++)
		{
			if (b1->table[i][j] == 0)
				printf("|           ");
			else
				printf("|%10d ", b1->table[i][j]);
		}

		printf("|\n");
	}
	if (b1->size==2)
		printf("\t\t\t________________________\n\t\t\t");
	else
		printf("\t\t\t________________________________________________\n");
	printf("\n\n\t\t----------[W] UP --- [S] Down --- [A] LEFT --- [D] Right--------------\n\n\n\n\n\n\n\n");
}


int fun(int a, int b)
{
	int min, max;
	if (a == 1 && b == 1)
		return 2;
	if (a > b)
	{
		min = b;
		max = a;
	}
	else if (a < b)
	{
		min = a;
		max = b;
	}
	else
	{
		return 0;
	}
	for (int i = 1; i < 31; i++)
		if (fib[i] == min&&fib[i + 1] == max)
			return fib[i + 2];
	return 0;
}


void move_Row_Up(struct board *b1, int c)
{

	for (int i = 0; i < b1->size - 1; i++)
	{
		for (int j = i + 1; j < b1->size; j++)
		{
			if (fun(b1->table[i][c], b1->table[j][c]))
			{
				b1->table[i][c] = fun(b1->table[i][c], b1->table[j][c]);
				for (int k = i + 1; k <= j; k++)
					b1->table[k][c] = 0;
				break;
			}
			if (b1->table[j][c] != 0)
				break;
		}
	}
	for (int i = 0; i < b1->size; i++)
	{
		if (b1->table[i][c] == 0)
		{
			for (int j = i; j < b1->size; j++)
				if (b1->table[j][c] != 0)
				{
					b1->table[i][c] = b1->table[j][c];
					b1->table[j][c] = 0;
					break;
				}
		}
	}

}




void move_Row_Down(struct board *b1, int c)
{
	for (int i = b1->size - 1; i > 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (fun(b1->table[i][c], b1->table[j][c]))
			{
				b1->table[i][c] = fun(b1->table[i][c], b1->table[j][c]);
				for (int k = i - 1; k >= j; k--)
					b1->table[k][c] = 0;
				break;
			}
			if (b1->table[j][c] != 0)
				break;
		}
	}
	for (int i = b1->size - 1; i >= 0; i--)
	{
		if (b1->table[i][c] == 0)
		{
			for (int j = i; j >=0; j--)
				if (b1->table[j][c] != 0)
				{
					b1->table[i][c] = b1->table[j][c];
					b1->table[j][c] = 0;
					break;
				}
		}
	}
}


void move_Row_Right(struct board *b1, int r)
{
	for (int i = b1->size - 1; i > 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (fun(b1->table[r][i], b1->table[r][j]))
			{
				b1->table[r][i] = fun(b1->table[r][i], b1->table[r][j]);
				for (int k = i - 1; k >= j; k--)
					b1->table[r][k] = 0;
				break;
			}
			if (b1->table[r][j] != 0)
				break;
		}
	}
	for (int i = b1->size-1; i>=0; i--)
	{
		if (b1->table[r][i] == 0)
		{
			for (int j = i; j >=0; j--)
				if (b1->table[r][j] != 0)
				{
					b1->table[r][i] = b1->table[r][j];
					b1->table[r][j] = 0;
					break;
				}
		}
	}
}


void move_Row_Left(struct board *b1,int r)
{
	for (int i = 0; i < b1->size-1; i++)
	{
		for (int j = i + 1; j < b1->size; j++)
		{
			if (fun(b1->table[r][i], b1->table[r][j]))
			{
				b1->table[r][i] = fun(b1->table[r][i], b1->table[r][j]);
				for (int k = i + 1; k <= j; k++)
					b1->table[r][k] = 0;
				break;
			}
			if (b1->table[r][j] != 0)
				break;
		}
	}
	for (int i = 0; i < b1->size; i++)
	{
		if (b1->table[r][i] == 0)
		{
			for (int j = i; j < b1->size; j++)
				if (b1->table[r][j] != 0)
				{
					b1->table[r][i] = b1->table[r][j];
					b1->table[r][j] = 0;
					break;
				}
		}
	}
}

void move_Up(struct board *b1, struct player *p1)
{
	for (int i = 0; i < b1->size; i++)
	{
		move_Row_Up(b1, i);
	}
	p1->no_of_moves += 1;

}
void move_Down(struct board *b1, struct player *p1)
{
	for (int i = 0; i < b1->size; i++)
	{
		move_Row_Down(b1, i);
	}
	p1->no_of_moves += 1;

}
void move_Left(struct board *b1, struct player *p1)
{
	for (int i = 0; i < b1->size; i++)
	{
		move_Row_Left(b1, i);
	}
	p1->no_of_moves += 1;
}
void move_Right(struct board *b1, struct player *p1)
{
	for (int i = 0; i < b1->size; i++)
	{
		move_Row_Right(b1, i);
	}
	p1->no_of_moves += 1;
}

