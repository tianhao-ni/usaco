/*
ID: neo.0061
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GROUP_MAX 10
#define NAME_LEN  16

typedef struct _t_person {
	char name[NAME_LEN];
	int account;
} tPerson;

tPerson person[GROUP_MAX];

void handle_money(char *name, int money)
{
	int i;

	for (i = 0; i < GROUP_MAX; i++)
	{
		if (0 == strcmp(person[i].name, name))
		{
			person[i].account += money;
			break;
		}
	}

	return;
}

int main(void)
{
	FILE *fin = fopen("gift1.in", "r");
	FILE *fout = fopen("gift1.out", "w");
	int i, group;
	char giver[NAME_LEN];
	char receiver[GROUP_MAX - 1][NAME_LEN];
	int money_t, money_g, money_k, part;

	fscanf(fin, "%d", &group);
	for (i = 0; i < group; i++)
	{
		fscanf(fin, "%s", person[i].name);
	}

	while (0 < fscanf(fin, "%s", giver))
	{
		fscanf(fin, "%d %d", &money_t, &part);
		for (i = 0; i < part; i++)
		{
			fscanf(fin, "%s", receiver[i]);
		}

		money_g = part ? ((money_t / part) * part) : 0;
		money_k = money_t ? (money_t % part) : 0;

		handle_money(giver, 0 - money_g);
		for (i = 0; i < part; i++)
		{
			handle_money(receiver[i], money_g/part);
		}
	}

	for (i = 0; i < group; i++)
	{
		fprintf(fout, "%s %d\n", person[i].name, person[i].account);
	}

	exit(0);
}