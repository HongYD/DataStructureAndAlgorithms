#include<stdio.h>
struct MyQueue
{
	int queue[100];
	int head;
	int tail;
};

struct MyStack
{
	int stack[100];
	int top;
};

int main()
{
	//定义两个队列一个栈
	int temp = 0;
	struct MyQueue qa, qb;
	printf("请输入A序列\n");
	for (int i = 0; i < 6; i++)
	{
		scanf("%d", &qa.queue[i]);
	}
	printf("请输入B序列\n");
	for (int i = 0; i < 6; i++)
	{
		scanf("%d", &qb.queue[i]);
	}
	struct MyStack st;

	//初始化队列和栈；

	qa.head = 0;
	qa.tail = 6;

	qb.head = 0;
	qb.tail = 6;

	st.top = 0;

	while ((qa.head != qa.tail) || (qb.head != qb.tail))
	{
		//小哼
		st.stack[st.top++] = qa.queue[qa.head++];
		for (int i = 0; i < st.top; i++)
		{
			for (int j = i + 1; j < st.top; j++)
			{
				if (st.stack[i] == st.stack[j])
				{
					temp = j - i + 1;
					for (int k = j; k >= i; k--)
					{
						qa.queue[qa.tail++] = st.stack[k];
						
					}
				}
			}
		}
		st.top -= temp;
		temp = 0;
		//小哈
		st.stack[st.top++] = qb.queue[qb.head++];
		for (int i = 0; i < st.top; i++)
		{
			for (int j = i+1; j < st.top; j++)
			{
				if (st.stack[i] == st.stack[j])
				{
					temp = j - i + 1;
					for (int k = j; k >= i; k--)
					{
						qb.queue[qb.tail++] = st.stack[k];
						
					}
				}
			}
		}
		st.top -= temp;
		temp = 0;

		if (qa.head == qa.tail)
		{
			printf("qa won!!!!\n");
		}
		if (qb.head == qb.tail)
		{
			printf("qb won!!!!\n");
		}
	}
	return 0;

}