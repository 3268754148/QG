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
		printf("��ʼ�� 1\n");
		printf("��� 2\n");
		printf("���� 3\n");
		printf("��ӡ 4\n");
		printf("���ٶ��� 5\n");
		printf("�˳� 6\n");
		scanf("%d", &n);
		if (n == 1)
		{
			printf("��ʼ��ʼ������\n");
			printf("����0ʱ,ֹͣ\n");
			tail = initialization(head);
			printf("��ʼ���ɹ�\n\n");
		}
		if (n == 2)
		{
			printf("��ʼ���\n");
			printf("����0ʱ,ֹͣ\n");
			tail = EnterLinkQueue(tail);
			printf("��ӳɹ�\n\n");
		}
		if (n == 3)
		{
			printf("��ʼ����\n");
			printf("��������Ӹ���\n");
			int num;
			scanf("%d", &num);
			for (int i = 1; i <= num; i++)
			{
				head = OutLinkQueue(head);
			}
			printf("���ӳɹ�\n\n");
		}
		if (n == 4)
		{
			printf("��ʼ��ӡ����\n");
			print(head);
			printf("��ӡ�ɹ�\n\n");
		}
		if (n == 5)
		{
			printf("��ʼ���ٶ���\n");
			des(head);
			printf("���ٳɹ�\n\n");
		}
		if (n == 6)
		{
			printf("�˳��ɹ�\n");
			break;
		}
	}
	system("pause");
}