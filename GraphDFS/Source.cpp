#include<stdio.h>
int book[101], sum, n, e[101][101];
void dfs(int cur) {
	int i;
	printf("%d ", cur);
	sum++;
	if (sum == n)
		return;
	for (int i = 1; i < n + 1; i++)
	{
		if (e[cur][i] == 1 && book[i] == 0)
		{
			book[i] = 1;
			dfs(i);
		}
	}
	return;
}
int main()
{
	int i, j, a, b;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = 999999;//999999表示正无穷
		}
	}

	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1;
	}

	book[1] = 1;
	dfs(1);
	getchar();
	getchar();
	return 0;
}