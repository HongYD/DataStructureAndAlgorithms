#include<stdio.h>
int h[101];//������Ŷѵ�����
int n;
//�ѽڵ�Ľ�������
void swap(int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
}

void shiftdown(int i)//����һ����Ҫ���µ����Ľڵ���,���ﴫ��1�����ӶѶ���ʼ���µ���
{
	int t, flag = 0;//flag����Ƿ���Ҫ�������µ���,t��������ǽϴ�ڵ�ı��
	while (i * 2 <= n && flag == 0)
	{
		//���������ӣ��ж���������Լ��Ĺ�ϵ
		if (h[i] < h[i * 2])
		{
			t = i * 2;
		}
		else
		{
			t = i;
		}
		//������Ҷ��ӣ����ж�˭��˭С��t��¼�ϴ�ĵ�
		if (i * 2 + 1 <= n)
		{
			if (h[t] < h[i * 2 + 1])
			{
				t = i * 2 + 1;
			}
		}

		//����������Ľڵ��Ų����Լ���˵���ӽڵ����бȸ��ڵ����ģ���Ҫ���нڵ㽻��
		if (t != i)
		{
			swap(t, i);
			i = t;//����iΪ�ղ����������Ķ��ӵĽڵ�ı�ţ����ڽ������������µ���
		}
		else
		{
			flag = 1;//����˵����ǰ���׽ڵ��Ѿ��ȶ��ӽڵ�Ҫ���ˣ����轻��
		}

	}
}

//������
void create()
{
	int i;
	//�����һ����Ҷ��㵽��һ��������ν������ϵ�����
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