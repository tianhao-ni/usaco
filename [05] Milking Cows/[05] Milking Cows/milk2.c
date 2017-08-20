/*
ID: neo.0061
LANG: C
TASK: milk2
*/

#include <stdio.h>
#include <stdlib.h>

#define FARMER_MAX 5000

typedef struct _t_farmer {
	int start;
	int end;
} tFarmer;

void sort_by_start(tFarmer *farmer, int size)
{
	tFarmer key = farmer[0];
	int i = 0, j = size - 1;

	if (i >= j)
		return;

	while (i < j)
	{
		while (farmer[j].start > key.start && i < j)
			j--;

		if (i < j)
			farmer[i++] = farmer[j];

		while (farmer[i].start < key.start && i < j)
			i++;
		
		if (i < j)
			farmer[j--] = farmer[i];
	}
	farmer[i] = key;

	sort_by_start(&farmer[0], i);
	sort_by_start(&farmer[i + 1], size - i - 1);
}

int main(void)
{
	FILE *fin = fopen("milk2.in", "r");
	FILE *fout = fopen("milk2.out", "w");
	tFarmer farmer[FARMER_MAX];
	tFarmer cur;
	int i, N, busy_max = 0, free_max = 0;

	fscanf(fin, "%d", &N);
	for (i = 0; i < N; i++)
	{
		fscanf(fin, "%d %d", &farmer[i].start, &farmer[i].end);
	}

	sort_by_start(farmer, N);
	cur.start = farmer[0].start;
	cur.end = farmer[0].end;
	busy_max = cur.end - cur.start;

	for (i = 0; i < N - 1; i++)
	{
		if (farmer[i + 1].start <= cur.end)
		{
			cur.end = farmer[i + 1].end > cur.end ? farmer[i + 1].end : cur.end;
		}
		else
		{
			busy_max = busy_max < cur.end - cur.start ? cur.end - cur.start : busy_max;
			free_max = free_max < farmer[i + 1].start - cur.end ? farmer[i + 1].start - cur.end : free_max;

			cur.start = farmer[i + 1].start;
			cur.end = farmer[i + 1].end;
		}
	}

	fprintf(fout, "%d %d\n", busy_max, free_max);

	exit(0);
}