#include<stdio.h>

//����ü
struct card {
	int i;
	char c;
} one;

struct card two;
//typedef struct card AA;

int fact(int n);
int calc_power1(int x, int n);
int calc_power2(int x, int n);
int fibo(int n);
void hanoi(int n, int from, int tmp, int to);

int main()
{
	printf("fact(3) = %d\n", fact(3));
	printf("calc_power1(2, 4) = %d\n", calc_power1(2, 4));
	printf("calc_power2(3, 4) = %d\n", calc_power2(3, 4));
	printf("%d, %d, %d, %d, %d\n\n", fibo(1), fibo(2), fibo(3), fibo(4), fibo(5));
	
	hanoi(3, 1, 2, 3);		//3���� ���ø� 1������ 2���� �ӽ÷� ����Ͽ� 3������ �ű��


	one.i = 3;
	one.c = 5;
	two.i = one.c;	printf("%d ", two.i);
	two.c = one.i;	printf("%d", two.c);
	two = one;		printf("\n%d %d", two.i, two.c);

	//AA k = 3;

}


//recursion�Լ� fact()
int fact(int n)
{
	if (n <= 1) { return 1; }
	else { return n * fact(n - 1); }
}


//recursion�Լ� calc_power1()
int calc_power1(int  x, int n)
{
	if (n == 0) return 1;
	else return x * calc_power1(x, n - 1);
}


//recursion�Լ� calc_power2()
int calc_power2(int  x, int n)
{
	if (n == 0) return 1;
	if (n % 2 == 0) { return calc_power2(x * x, n / 2); }
	else return x * calc_power2(x * x, (n - 1) / 2);
}


//recursion�Լ� fibo()
int fibo(int n)
{
	if (n == 1 || n == 2) { return 1; }
	else return fibo(n - 1) + fibo(n - 2);
}


//recursion�Լ� hanoi()
// 1. n-1 ���� from ---> tmp�� �Ű� ���´�.	(�ӽ� to)
// 2. 1���� from ---> to�� �ű��.			(�ӽ� tmp)
// 3. n-1���� tmp ---> to�� �ű��.			(�ӽ� from)

void hanoi(int n, int from, int tmp, int to)
{
	if (n == 1)	
	{
		printf("move one dish from %d to %d\n", from, to);
		return;	
	}
	hanoi(n - 1, from, to, tmp);  //1
	hanoi(1, from, tmp, to);    //2
	hanoi(n - 1, tmp, from, to);  //3
}
