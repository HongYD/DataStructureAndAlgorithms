#include<stdio.h>
const int huochai = 24;
const int num = 1111;
const int match[10] = { 6,2,5,5,4,5,6,3,7,6 };

int GetMatchNumber(int _x);
int main()
{
	
	int i, j, m = 0;
	
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			m = i + j;
			if (GetMatchNumber(i) + GetMatchNumber(j) + GetMatchNumber(m) + 4 == huochai)
			{
				printf("%d+%d=%d   %d\n", i, j, m, GetMatchNumber(i) + GetMatchNumber(j) + GetMatchNumber(m) + 4);
			}
		}
	}
	return 0;
}

int GetMatchNumber(int _x)
{
	int sum=0;
	while (_x / 10 !=0)
	{
		sum+=match[_x % 10];
		_x /= 10;
	}
	sum += match[_x];
	return sum;
}