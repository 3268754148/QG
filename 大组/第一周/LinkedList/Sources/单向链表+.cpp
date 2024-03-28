#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
struct node
{
	int data;
	struct node* next;
};
struct node* initialization(struct node* head)
{
	struct node* tail = head;
	while (tail)
	{
		scanf("%d", &tail->data);
		tail->next = (struct node*)malloc(sizeof(struct node));
		if (tail->data == 0)
		{
			tail->next = NULL;
			break;
		}
		else
		{
			tail = tail->next;
		}
	}
	return tail;
}

struct node* insert(struct node* tail)
{
	while (tail)
	{
		scanf("%d", &tail->data);
		tail->next = (struct node*)malloc(sizeof(struct node));
		if (tail->data == 0)
		{
			tail->next = NULL;
			break;
		}
		else
		{
			tail = tail->next;
		}
	}
	return tail;
}
void print(struct node* head)
{
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}
void by_value(struct node* head, int num)
{
	while (head)
	{
		if (head->data == num)
		{
			printf("%d\n", head->data);
		}
		head = head->next;
	}
}
void by_point(struct node* head, int sum)
{
	int s = 1;
	while (head)
	{
		if (s == sum)
		{
			printf("%d\n", head->data);
			break;
		}
		head = head->next;
		s++;
	}
}
void del(struct node* head, int sum)
{
	int s = 1;
	while (head)
	{
		if (s == sum - 1)
		{
			head->next = head->next->next;

			break;
		}
		head = head->next;
		s++;
	}
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
	head->next = NULL;
	struct node* tail;
	while (1)
	{
		printf("1、链表初始化\n");
		printf("2、插入链表\n");
		printf("3、按位查找\n");
		printf("4、按值查找\n");
		printf("5、删除结点\n");
		printf("6、打印链表\n");
		printf("7、销毁链表\n");
		printf("0、退出\n");
		int n;
		scanf("%d", &n);
		if (n == 1)
		{
			printf("链表初始化\n");
			printf("输入0时，停止\n");
			tail = initialization(head);
			printf("链表初始化成功\n\n");
		}
		if (n == 2)
		{
			printf("插入链表\n");
			printf("输入0时，停止\n");
			tail = insert(tail);
			printf("插入链表成功\n\n");
		}
		if (n == 3)
		{
			printf("按位查找\n");
			int sum;
			scanf("%d", &sum);
			by_point(head, sum);
			printf("按位查找成功\n\n");
		}
		if (n == 4)
		{
			printf("按值查找\n");
			int num;
			scanf("%d", &num);
			by_value(head, num);
			printf("按值查找成功\n\n");
		}
		if (n == 5)
		{
			printf("删除结点\n");
			int sum;
			scanf("%d", &sum);
			del(head, sum);
			printf("删除结点成功\n\n");
		}
		if (n == 6)
		{
			printf("打印链表\n");
			print(head);
			printf("打印链表成功\n\n");
		}
		if (n == 7)
		{
			printf("销毁链表\n");
			des(head);
			printf("销毁链表成功\n\n");
		}
		if (n == 0)
		{
			printf("退出\n\n");
			break;
		}
	}
	system("pause");
}