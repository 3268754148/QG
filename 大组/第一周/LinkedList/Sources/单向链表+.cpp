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
		printf("1�������ʼ��\n");
		printf("2����������\n");
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
			printf("�����ʼ��\n");
			printf("����0ʱ��ֹͣ\n");
			tail = initialization(head);
			printf("�����ʼ���ɹ�\n\n");
		}
		if (n == 2)
		{
			printf("��������\n");
			printf("����0ʱ��ֹͣ\n");
			tail = insert(tail);
			printf("��������ɹ�\n\n");
		}
		if (n == 3)
		{
			printf("��λ����\n");
			int sum;
			scanf("%d", &sum);
			by_point(head, sum);
			printf("��λ���ҳɹ�\n\n");
		}
		if (n == 4)
		{
			printf("��ֵ����\n");
			int num;
			scanf("%d", &num);
			by_value(head, num);
			printf("��ֵ���ҳɹ�\n\n");
		}
		if (n == 5)
		{
			printf("ɾ�����\n");
			int sum;
			scanf("%d", &sum);
			del(head, sum);
			printf("ɾ�����ɹ�\n\n");
		}
		if (n == 6)
		{
			printf("��ӡ����\n");
			print(head);
			printf("��ӡ����ɹ�\n\n");
		}
		if (n == 7)
		{
			printf("��������\n");
			des(head);
			printf("��������ɹ�\n\n");
		}
		if (n == 0)
		{
			printf("�˳�\n\n");
			break;
		}
	}
	system("pause");
}