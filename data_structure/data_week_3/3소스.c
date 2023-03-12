#if 0				//SLL 구현
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
	p->i = 10;											//node에 값 할당
	free(p);											//node deletion

	return 0;
}
#endif
////////////////////////////////////////////////////////////////////////////////////
#if 1				//SLL 구현 (add)
#include<stdio.h>
#include<stdlib.h>

struct node {
	int i;
	struct node *next;		//자기참조 구조체
};
struct node *head = 0;		//head의 초기값 = NULL

void addtoSLL(int v)		//v값을 가진 node를 추가
{
	struct node *new;											//새로운 node가 들어올 공간 new 생성
	new			= (struct node*)malloc(sizeof(struct node));	//새로운 node가 들어올 공간 new 생성
	new->i      = v;		//node data에 v 저장
	new->next   = 0;		//new의 다음 node는 NULL
	 
	if (head == 0)		//SLL에 아무것도 없는 경우
	{
		head = new;
	//	return;
	}
	else               //SLL에 무언가가 있는 경우
	{
		struct node* last;
		last = head;

		while (last->next != 0)		//last가 NULL에 위치하기 전까지
		{
			last = last->next;
		}
		last->next = new;			//last 뒤에 new "add"
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

void printSLL()					//added SLL을 printf 하는 printSLL()
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
