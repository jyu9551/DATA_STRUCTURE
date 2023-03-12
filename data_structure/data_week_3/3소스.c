#if 0				//SLL ����
#include<stdio.h>

struct node
{
	int i;
	struct node* next;
};


int main()
{
	struct node* p;

	p = (struct node*)malloc(sizeof(struct node));		//node creation
	p->i = 10;											//node�� �� �Ҵ�
	free(p);											//node deletion

	return 0;
}
#endif
////////////////////////////////////////////////////////////////////////////////////
#if 1				//SLL ���� (add)
#include<stdio.h>
#include<stdlib.h>

struct node {
	int i;
	struct node *next;		//�ڱ����� ����ü
};
struct node *head = 0;		//head�� �ʱⰪ = NULL

void addtoSLL(int v)		//v���� ���� node�� �߰�
{
	struct node *new;											//���ο� node�� ���� ���� new ����
	new			= (struct node*)malloc(sizeof(struct node));	//���ο� node�� ���� ���� new ����
	new->i      = v;		//node data�� v ����
	new->next   = 0;		//new�� ���� node�� NULL
	 
	if (head == 0)		//SLL�� �ƹ��͵� ���� ���
	{
		head = new;
	//	return;
	}
	else               //SLL�� ���𰡰� �ִ� ���
	{
		struct node* last;
		last = head;

		while (last->next != 0)		//last�� NULL�� ��ġ�ϱ� ������
		{
			last = last->next;
		}
		last->next = new;			//last �ڿ� new "add"
	//	return;
	}

}

void destroySLL()
{
	struct node *cur = head;

	while (1)
	{
		if (head == 0)
		{
			break;
		}

		head = head->next;
		free(cur);
		cur = head;
	}
}

void insertSLL(int a, int b)
{
	struct node* cur = head;

	while (cur != 'null')
	{
		if (cur->i == a)
		{
			struct node* new = (struct node*)malloc(sizeof(struct node));
			new->i = b;
			new->next = cur->next;
			cur->next = new;

			return;
		}
		else
		{
			cur = cur->next;
		}
	}
}

void deleteFromSLL(int v)
{
	struct node *del_next, *del;
	del_next = head;

	if (head->i == v)
	{
		del = head;
		head = head->next;
		free(del);
		return;
	}
	else
	{
		while (del_next->next != 0)
		{
			if (del_next->next->i == v)
			{
				del = del_next->next;
				del_next->next = del->next;
				free(del);
				return;
			}
			else
			{
				del_next = del_next->next;
			}
		}

	}
}

void printSLL()					//added SLL�� printf �ϴ� printSLL()
{
	struct node* cur = 0;
	cur = head;

	while (cur != 0)
	{
		printf("%d\n", cur->i);
		cur = cur->next;
	}
}

int main()
{
	addtoSLL(1);
	addtoSLL(2);
	addtoSLL(3);

	destroySLL();

	addtoSLL(4);
	addtoSLL(5);
	addtoSLL(6);

	insertSLL(4, 8); 
	insertSLL(5, 10);
	insertSLL(6, 12);

	deleteFromSLL(4);
	deleteFromSLL(5);
	deleteFromSLL(6);

	printSLL();

	return 0;
}
#endif
