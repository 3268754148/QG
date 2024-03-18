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
		printf("1�������ʼ��\n");
		printf("2�������β\n");
		printf("3����λ����\n");
		printf("4����ֵ����\n");
		printf("5��ɾ�����\n");
		printf("6����ӡ����\n");
		printf("7����������\n");
		printf("0���˳�\n");
		int n;
		scanf("%d", &n);
		if (n == 1)
		{
			printf("1�������ʼ��\n");
			tail = initialization(head);
			printf("�����ʼ���ɹ�\n");
		}
		if (n == 2)
		{
			printf("2����������\n");
			tail=insert(tail);
			printf("��������ɹ�\n");
		}
		if (n == 3)
		{
			printf("3����λ����\n");
			int sum;
			scanf("%d", &sum);
			by_point(head, sum);
			printf("��λ���ҳɹ�\n");
		}
		if (n == 4)
		{
			printf("4����ֵ����\n");
			int num;
			scanf("%d", &num);
			by_value(head, num);
			printf("��ֵ���ҳɹ�\n");
		}
		if (n == 5)
		{
			printf("5��ɾ�����\n");
			int sum;
			scanf("%d", &sum);
			del(head, sum);
			printf("ɾ�����ɹ�\n");
		}
		if (n == 6)
		{
			printf("6����ӡ����\n");
			print(head);
			printf("��ӡ����ɹ�\n");
		}
		if (n == 7)
		{
			printf("7����������\n");
			des(head);
			printf("��������ɹ�\n");
		}
		if (n == 0)
		{
			printf("0���˳�\n");
			break;
		}
	}
}


	
	
	
