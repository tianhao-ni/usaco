/*
ID: neo.0061
LANG: C
TASK: friday
*/

#include <stdio.h>
#include <stdlib.h>



int main(void)
{
	FILE *fin = fopen("friday.in", "r");
	FILE *fout = fopen("friday.out", "w");
	int year, month, N, feb_add;
	int days[12] = { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
	int week[7] = { 0 };
	int thirteenth = 13 - 31;

	fscanf(fin, "%d", &N);

	for (year = 1900; year < 1900 + N; year++)
	{
		feb_add = 0;
		if (0 == year % 400)
			feb_add = 1;
		
		if (0 == year % 4 && 0 != year % 100)
			feb_add = 1;

		for (month = 0; month < 12; month++)
		{
			thirteenth += days[month];
			if (month == 2)
				thirteenth += feb_add;
			week[thirteenth % 7]++;
		}
	}

	fprintf(fout, "%d %d %d %d %d %d %d\n", week[6], week[0], week[1], week[2], week[3], week[4], week[5]);

	exit(0);
}