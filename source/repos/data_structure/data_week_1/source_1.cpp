#include<stdio.h>
#include<time.h>  //clock() �Լ� ����
/* ������ �� clk, ���� �� clk �ϸ� ����ð� Ȯ�� ���� */

int factorial(int n);
int power(int a, int n);
int fibo(int n);

int main(void)
{
	/*
	clock_t start_time, end_time;
	start_time = clock();
	printf("%d", 4);
	end_time = clock();
	printf("%d", end_time - start_time);
	*/
	printf("%d %d %d %d\n", factorial(2), factorial(3), factorial(4), factorial(5));
	printf("%d %d %d %d\n", power(2,2), power(2,3), power(2,4), power(2,5));
	printf("%d %d %d %d\n", fibo(2), fibo(3), fibo(4), fibo(5));
}

/* ���丮�� */

int factorial(int n)		// ���丮�� - �ݺ�
{
	int result = 1;

	for (int i = n; i > 0; i--)
		result = result * i;
	return result;
}

int factorial_recursion(int n)		// ���丮�� - ��ȯ
{
	if (n <= 1)	return 1;
	return n * factorial_recursion(n - 1);
}


/* �ŵ����� */

int power(int a, int n)	// �ŵ����� - �ݺ�
{
	int result = 1;
	if (n == 1)	return a;
	for (int i = 0; i < n; i++)
	{
		result = result * a;
	}
	return result;
}

int power_recursion(int a, int n)	// �ŵ����� - ��ȯ
{
	if (n == 1) {		// Ż������
		return a;
	}
	
	return a * power_recursion(a, n - 1);
}

int power_fast(int a, int n)	// �ŵ����� - ��ȯ (�ӵ� ����)
{
	if (n == 1)
	{
		return a;
	}

	if (n % 2 == 0)	// n�� ¦��
	{
		return power_fast(a * a, n / 2);
	}
	else if (n % 2 == 1)	// n�� Ȧ��
	{
		return a * power_fast(a * a, n / 2);
	}
}



/* fibonacci */

int fibo(int n)		// �Ǻ���ġ - �ݺ�
{
	if (n == 0)		return 0;
	if (n == 1)		return 1;

	int cur = 0, prev = 1, prev2 = 0;

	for (int i = 0; i < n-1; i++)
	{
		cur = prev + prev2;
		prev2 = prev;
		prev = cur;
	}
	return cur;
}

int fibo_recursion(int n)		// �Ǻ���ġ - ��ȯ
{
	if (n == 0)	return 0;
	else if (n == 1) return 1;

	return fibo_recursion(n-2) + fibo_recursion(n-1);
}

int fibo_fast()	// �Ǻ���ġ - ��ȯ (�ӵ�����)
{
	return 0;
}


/* hanoi tower */

void hanoi(int n, int from, int temp, int to)		// n���� ���ø� �Űܶ�. (from -> temp -> to)
{
	if (n == 1) {
		printf("%d���� %d�� ���� �� �� �����Դϴ�./n", from, to);
		return;
	}

	hanoi(2, 1, 3, 2);
	printf("%d���� %d�� ���� �� �� �����Դϴ�.\n", from, to);
	hanoi(n - 1, temp, from, to);
	return;
}