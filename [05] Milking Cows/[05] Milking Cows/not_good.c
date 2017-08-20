/*
ID: neo.0061
LANG: C
TASK: milk2
*/

#include <stdio.h>
#include <stdlib.h>

#define TIME_MAX 1000001

int main(void)
{
	FILE *fin = fopen("milk2.in", "r");
	FILE *fout = fopen("milk2.out", "w");
	char time[TIME_MAX] = { 0 };
	int i, j, N, begin, end, very_end = 0, very_begin = 1000000;
	int free_cnt = 0, free_max = 0, busy_cnt = 0, busy_max = 0;

	fscanf(fin, "%d", &N);

	for (i = 0; i < N; i++)
	{
		fscanf(fin, "%d %d", &begin, &end);
		for (j = begin; j < end; j++)
			time[j] = 1;

		if (very_end < end)
			very_end = end;
		if (very_begin > begin)
			very_begin = begin;
	}

	i = very_begin;
	while (i < very_end)
	{
		busy_cnt = 0;
		while (time[i] == 1 && i < very_end)
		{
			busy_cnt++;
			i++;
		}
		busy_max = busy_max < busy_cnt ? busy_cnt : busy_max;

		free_cnt = 0;
		while (time[i] == 0 && i < very_end)
		{
			free_cnt++;
			i++;
		}
		free_max = free_max < free_cnt ? free_cnt : free_max;
	}

	fprintf(fout, "%d %d\n", busy_max, free_max);

	exit(0);
}