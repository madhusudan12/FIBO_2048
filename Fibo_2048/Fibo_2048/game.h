#include"stores.h"
#include<stdlib.h>
void leader_Board()
{
	int a;
	FILE *fp = fopen("records.txt", "r");
	struct data *d = (struct data*)malloc(sizeof(struct data));
	struct data *root = NULL;
	while (feof(fp))
	{
		fread(d, sizeof(struct data), 1, fp);		
		root=insert(root,d);
	}
	system("cls");
	print_InOrder(root);
	fclose(fp);
	printf("press 1 to exit : ");
	scanf("%d", &a);
	if (a == 1)
		return;
}

void continue_Last()
{

}



struct board* initialize_Board(int size)
{
	struct board* b1 = (struct board*)malloc(sizeof(struct board*));
	int **t = (int**)malloc(size*sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		t[i] = (int*)malloc(size*sizeof(int));
	}
	b1->table = t;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			b1->table[i][j] = 0;
		}
	}
	b1->size = size;
	b1->empty_Tiles = size*size;
	return b1;
}
struct player* initialize_Game(char *name)
{
	struct player *p1 = (struct player*)malloc(sizeof(struct player));
	p1->name = name;
	p1->no_of_moves = 0;
	p1->state = 0;
	time_t t = time(NULL);
	struct tm *tim = localtime(&t);
	p1->time = asctime(tim);
	return p1;
}

void play_Game()
{
	int op;
	char name[20];
	struct player *p1=NULL;
	struct board *b1=NULL;
label1:
	system("cls");
	printf("\n\n\n\t\t\t\t***********FIBO-2048************\n\n\n");
	printf("\n\n\n\t\t\t 1.2*2 Board\n\n\t\t\t 2.4*4 Board\n\n\t\t\t\t Choice : ");
	scanf("%d", &op);
	fflush(stdin);
	printf("\n\t\t\tenter your name :");
	gets(name);
	p1 = initialize_Game(name);
	switch (op)
	{
	case 1:
		b1 = initialize_Board(2);
		break;
	case 2:
		b1 = initialize_Board(4);
		break;
	default:
		printf("Invalid Choice\n");
		goto label1;

	}

	start_Game(p1, b1);
}