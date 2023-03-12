# if 0
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SZ 5

int* sort(int* _nums)
{

	int num[5] = { 0, };

	for (int i = 0; i < 5; i++)
	{
		num[i] = _nums[i];
	}
	printf("\n");


	int  i = 0, k = 0;
	int tmp = 0;
	int cnt = 0;

	while (1)
	{
		cnt = 0;
		for (i = 0; i < 4; i++)
		{
			k = i + 1;

			if (num[i] > num[k])
			{
				tmp = num[i];
				num[i] = num[k];
				num[k] = tmp;
				break;
			}
			else
			{
				cnt++;
			}

		}
		if (cnt == 4)
		{
			return;
		}
	}
	return num;
}


void doSelectionSort(int* _nums)
{
	int num[5] = { 0 , };
	int tmp = 0;

	for (int i = 0; i < 5; i++)
	{
		num[i] = sort(_nums);
	}
	for (int i = 0; ; i++)
	{
		if (num[i] != _nums[i])
		{
			for (int k = 1; k < 5; k++)
			{
				if (_nums[i] == _nums[k])
				{
					tmp = _nums[k];
					_nums[k] = _nums[i];
					_nums[i] = tmp;
					printf("%d", _nums[0]);
					return;
				}

			}
		}
	}


}

int main(void)
{
	int i;
	int v;
	int nums[SZ];
	int a;

	scanf("%d", &a);


	for (i = 0; i < a; i++)
	{
		scanf("%d", &v);
		nums[i] = v;
	}

	doSelectionSort(nums);

	return 0;
}
#endif

