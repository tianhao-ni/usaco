/*
ID: neo.0061
LANG: C
TASK: ride
*/
#include <stdio.h>
#include <stdlib.h>

#define STR_LEN 16

int main(void) 
{
	int i, line = 1, value, comet_v, group_v;
	char ch_line[STR_LEN] = {0};
	FILE *fin = fopen("ride.in", "r");
	FILE *fout = fopen("ride.out", "w");

	while (0 < fscanf(fin, "%s", ch_line))
	{
		i = 0;
		value = 1;

		while (ch_line[i] > 'A' && ch_line[i] < 'Z')
		{
			value *= (ch_line[i++] - 'A' + 1);
		}
	
		if (line%2)
			comet_v = value % 47;
		else
		{
			group_v = value % 47;
			
			if (comet_v == group_v)
				fprintf(fout, "GO\n");
			else
				fprintf(fout, "STAY\n");
		}
	
		line++;
	}
	exit(0);
}
