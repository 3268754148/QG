#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* pre;
	int data;
	struct node* next;
};
struct node* initialization(struct node* head)
{
	struct node* p = head;
	struct node* q;
	scanf("%d", &p->data);
	while (1)
	{
	q = (struct node*)malloc(sizeof(struct node));
	scanf("%d", &q->data);
	if (q->data == 0)
	{
		p->next =q;
		q->pre = p;
		q->next = NULL;
		break;
	}
	else 
	{
		q->pre = p;
		q->next = NULL;
		p->next = q;
		p=q;
	}
	}
	return q;
}
struct node* insert(struct node* p)
{
	struct node* q;
	scanf("%d", &p->data);
	if (p->data == 0)
	{
		return p;
	}
	while (1)
	{
		q = (struct node*)malloc(sizeof(struct node));
		scanf("%d", &q->data);
		if (q->data == 0)
		{
			p->next = q;
			q->pre = p;
			q->next = NULL;
			break;
		}
		else
		{
			q->pre = p;
			q->next = NULL;
			p->next =q;
			p = q;
		}
	}
	return q;
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
	head->pre = NULL;
	head->next = NULL;
	struct node* tail ;
	while (1)
	{
		printf("1、链表初始化\n");
		printf("2、插入表尾\n");
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
			printf("1、链表初始化\n");
			tail = initialization(head);
			printf("链表初始化成功\n");
		}
		if (n == 2)
		{
			printf("2、插入链表\n");
			tail=insert(tail);
			printf("插入链表成功\n");
		}
		if (n == 3)
		{
			printf("3、按位查找\n");
			int sum;
			scanf("%d", &sum);
			by_point(head, sum);
			printf("按位查找成功\n");
		}
		if (n == 4)
		{
			printf("4、按值查找\n");
			int num;
			scanf("%d", &num);
			by_value(head, num);
			printf("按值查找成功\n");
		}
		if (n == 5)
		{
			printf("5、删除结点\n");
			int sum;
			scanf("%d", &sum);
			del(head, sum);
			printf("删除结点成功\n");
		}
		if (n == 6)
		{
			printf("6、打印链表\n");
			print(head);
			printf("打印链表成功\n");
		}
		if (n == 7)
		{
			printf("7、销毁链表\n");
			des(head);
			printf("销毁链表成功\n");
		}
		if (n == 0)
		{
			printf("0、退出\n");
			break;
		}
	}
}


	
	
	
