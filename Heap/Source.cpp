#include<stdio.h>
int h[101];//用来存放堆的数组
int n;
//堆节点的交换函数
void swap(int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
}

void shiftdown(int i)//传入一个需要向下调整的节点编号,这里传入1，即从堆顶开始向下调整
{
	int t, flag = 0;//flag标记是否需要继续向下调整,t则用来标记较大节点的编号
	while (i * 2 <= n && flag == 0)
	{
		//如果有左儿子，判断左儿子与自己的关系
		if (h[i] < h[i * 2])
		{
			t = i * 2;
		}
		else
		{
			t = i;
		}
		//如果有右儿子，则判断谁大谁小，t记录较大的点
		if (i * 2 + 1 <= n)
		{
			if (h[t] < h[i * 2 + 1])
			{
				t = i * 2 + 1;
			}
		}

		//如果发现最大的节点编号不是自己，说明子节点中有比父节点更大的，需要进行节点交换
		if (t != i)
		{
			swap(t, i);
			i = t;//更新i为刚才与它交换的儿子的节点的编号，便于接下来继续向下调整
		}
		else
		{
			flag = 1;//否则说明当前父亲节点已经比儿子节点要大了，无需交换
		}

	}
}

//建立堆
void create()
{
	int i;
	//从最后一个非叶结点到第一个结点依次进行向上调整。
	for (i = n / 2; i >= 1; i--)
	{
		shiftdown(i);
	}
}

void heapsort()
{
	while (n > 1)
	{
		swap(1,n);
		n--;
		shiftdown(1);
	}
}

int main()
{
	int i, num;
	scanf("%d", &num);
	for (i = 1; i <= num; i++)
	{
		scanf("%d", &h[i]);
	}
	n = num;
	create();
	heapsort();

	for (i = 1; i <= num; i++)
	{
		printf("%d ", h[i]);
	}

	getchar();
	getchar();
	return 0;
}