#include<stdio.h>
#include<time.h>  //clock() 함수 제공
/* 시작할 때 clk, 끝날 때 clk 하면 수행시간 확인 가능 */

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

/* 팩토리얼 */

int factorial(int n)		// 팩토리얼 - 반복
{
	int result = 1;

	for (int i = n; i > 0; i--)
		result = result * i;
	return result;
}

int factorial_recursion(int n)		// 팩토리얼 - 순환
{
	if (n <= 1)	return 1;
	return n * factorial_recursion(n - 1);
}


/* 거듭제곱 */

int power(int a, int n)	// 거듭제곱 - 반복
{
	int result = 1;
	if (n == 1)	return a;
	for (int i = 0; i < n; i++)
	{
		result = result * a;
	}
	return result;
}

int power_recursion(int a, int n)	// 거듭제곱 - 순환
{
	if (n == 1) {		// 탈출조건
		return a;
	}
	
	return a * power_recursion(a, n - 1);
}

int power_fast(int a, int n)	// 거듭제곱 - 순환 (속도 개선)
{
	if (n == 1)
	{
		return a;
	}

	if (n % 2 == 0)	// n이 짝수
	{
		return power_fast(a * a, n / 2);
	}
	else if (n % 2 == 1)	// n이 홀수
	{
		return a * power_fast(a * a, n / 2);
	}
}



/* fibonacci */

int fibo(int n)		// 피보나치 - 반복
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

int fibo_recursion(int n)		// 피보나치 - 순환
{
	if (n == 0)	return 0;
	else if (n == 1) return 1;

	return fibo_recursion(n-2) + fibo_recursion(n-1);
}

int fibo_fast()	// 피보나치 - 순환 (속도개선)
{
	return 0;
}


/* hanoi tower */

void hanoi(int n, int from, int temp, int to)		// n개의 접시를 옮겨라. (from -> temp -> to)
{
	if (n == 1) {
		printf("%d에서 %d로 돌을 한 개 움직입니다./n", from, to);
		return;
	}

	hanoi(2, 1, 3, 2);
	printf("%d에서 %d로 돌을 한 개 움직입니다.\n", from, to);
	hanoi(n - 1, temp, from, to);
	return;
}