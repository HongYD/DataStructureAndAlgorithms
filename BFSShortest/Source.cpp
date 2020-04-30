#include<stdio.h>
struct note
{
	int x;
	int s;
};
const int INFINITY = 9999999;

int main()
{
	struct note que[2501];
	int e[51][51] = { 0 }, book[51] = { 0 };
	int head, tail;
	int i, j, n, m, a, b, cur, start, end, flag = 0;
	scanf("%d %d %d %d", &n, &m, &start, &end);
	for (i = 1; i < n; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (i == j) e[i][j] = 0;
			else e[i][j] = INFINITY;
		}
	}
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1;
	}

	head = 1;
	tail = 1;
	que[tail].x = start;
	que[tail].s = 0;
	tail++;
	book[1] = start;
	while (head < tail)
	{
		cur = que[head].x;
		for (j = 1; j <= n; j++)
		{
			if (e[cur][j] != INFINITY&&book[j] == 0)
			{
				que[tail].x = j;
				que[tail].s = que[head].s + 1;//说明以这个定点为起始点的航路没能到达终点
				tail++;
				book[j] = 1;
			}
			if (que[tail].x == end)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		head++;
	}
	printf("%d", que[tail - 1].s);
	getchar(); getchar();
	return 0;
}