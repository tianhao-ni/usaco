/*
ID: neo.0061
LANG: C
TASK: palsquare
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 32

char ch_str[21] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
char square_ch[MAX_N];
int square_len;
int square_n;
char num_ch[MAX_N];
int num_len;
int num_n;
char tmp[MAX_N];

int main() 
{
	FILE *fin = fopen("palsquare.in", "r");
	FILE *fout = fopen("palsquare.out", "w");
	
	int base;
	int i, j, prn_flag;

	fscanf(fin, "%d", &base);

	for (i = 1; i <= 300; i++)
	{
		num_n = i;
		square_n = num_n * num_n;

		for (square_len = 0; square_n != 0; square_len++)
		{
			square_ch[square_len] = ch_str[square_n%base];
			square_n /= base;
		}
		square_ch[square_len] = '\0';

		for (j = 0, prn_flag = 1; j < square_len / 2; j++)
		{
			if (square_ch[j] != square_ch[square_len - j - 1])
				prn_flag = 0;
		}

		if (prn_flag)
		{
			for (num_len = 0; num_n != 0; num_len++)
			{
				tmp[num_len] = ch_str[num_n  %base];
				num_n /= base;
			}

			for (j = 0; j < num_len; j++)
			{
				num_ch[j] = tmp[num_len - j - 1];
			}
			num_ch[j] = '\0';

			fprintf(fout, "%s %s\n", num_ch, square_ch);
		}
	}

	exit(0);
}