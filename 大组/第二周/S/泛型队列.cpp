#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct node
{
	struct node* pre;
	int data;
	struct node* next;
};



struct node* initialization(struct node* head)
{
	while (1)
	{


		scanf("%d", &head->data);

		if (head->data == 0)
		{
			break;
		}
		struct node* p = (struct node*)malloc(sizeof(struct node));

		head->next = p;
		p->pre = head;
		p->next = NULL;
		head = p;
	}
	return head;
}
void  print(struct node* head)
{
	while (head)
	{
		if (head->data != 0)
		{
			printf("%d ", head->data);
		}
		head = head->next;
	}
	printf("\n");
}
struct node* EnterLinkQueue(struct node* tail)
{
	while (1)
	{
		scanf("%d", &tail->data);

		if (tail->data == 0)
		{
			break;
		}
		struct node* p = (struct node*)malloc(sizeof(struct node));

		tail->next = p;
		p->pre = tail;
		p->next = NULL;
		tail = p;
	}
	return tail;
}
struct node* OutLinkQueue(struct node* head)
{
	head = head->next;
	return head;
}
void des(struct node* head)
{
	while (head)
	{
		struct node* L = head;
		head = head->next;
		free(L);
		L->next = NULL;
	}
}
int main()
{
	struct node* head = (struct node*)malloc(sizeof(struct node));
	struct node* tail = head;
	head->pre = NULL;
	head->next = NULL;
	int n;
	while (1)
	{
		printf("初始化 1\n");
		printf("入队 2\n");
		printf("出队 3\n");
		printf("打印 4\n");
		printf("销毁队列 5\n");
		printf("退出 6\n");
		scanf("%d", &n);
		if (n == 1)
		{
			printf("开始初始化队列\n");
			printf("输入0时,停止\n");
			tail = initialization(head);
			printf("初始化成功\n\n");
		}
		if (n == 2)
		{
			printf("开始入队\n");
			printf("输入0时,停止\n");
			tail = EnterLinkQueue(tail);
			printf("入队成功\n\n");
		}
		if (n == 3)
		{
			printf("开始出队\n");
			printf("请输入出队个数\n");
			int num;
			scanf("%d", &num);
			for (int i = 1; i <= num; i++)
			{
				head = OutLinkQueue(head);
			}
			printf("出队成功\n\n");
		}
		if (n == 4)
		{
			printf("开始打印队列\n");
			print(head);
			printf("打印成功\n\n");
		}
		if (n == 5)
		{
			printf("开始销毁队列\n");
			des(head);
			printf("销毁成功\n\n");
		}
		if (n == 6)
		{
			printf("退出成功\n");
			break;
		}
	}
	system("pause");
}