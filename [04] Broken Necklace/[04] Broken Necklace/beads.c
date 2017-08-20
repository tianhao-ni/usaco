/*
ID: neo.0061
LANG: C
TASK: beads
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 350

int copy_beads_tail(char str[], int len)
{
	int i = 0, state = str[0];

	while (state == 'w')
	{
		str[i + len] = str[i];
		i++;
		if (i >= len)
			return i + len;
		if (str[i] != 'w')
			state = str[i];
	}

	do {
		str[i + len] = str[i];
		i++;
		if (i >= len)
			return i + len;
	} while (str[i] == state || str[i] == 'w');

	return i + len;
}

int count_beads(char str[], int len)
{
	char state = str[0];
	int total = 0;
	int h1 = 0, t1 = 0, h2 = 0, t2 = 0;

	while (state == 'w')
	{
		h1++;
		if (h1 >= len)
			return len;
		if (str[h1] != 'w')
			state = str[h1];
	}

	do {
		h1++;
		if (h1 >= len)
			return len;
	} while (str[h1] == state || str[h1] == 'w');

	state = str[h1];
	while (h2 < len)
	{
		t2 = h1;
		h2 = t2 + 1;

		while (str[h2] == state || str[h2] == 'w')
			h2++;

		total = (total < h2 - t1) ? (h2 - t1) : total;

		while (str[t2 - 1] == 'w')
			t2--;

		h1 = h2;
		t1 = t2;
		state = str[h2];
	}

	return total;
}

int main(void)
{
	FILE *fin = fopen("beads.in", "r");
	FILE *fout = fopen("beads.out", "w");
	int len, len_all, max_num;
	char necklace[MAX_LEN * 2] = { 0 };

	fscanf(fin, "%d", &len);
	fscanf(fin, "%s", necklace);

	len_all = copy_beads_tail(necklace, len);
	max_num = count_beads(necklace, len_all);

	if (max_num > len)
		max_num = len;

	fprintf(fout, "%d\n", max_num);

	exit(0);
}
