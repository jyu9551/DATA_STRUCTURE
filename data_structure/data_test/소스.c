#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SZ 5

void doSelectionSort(int* _nums)
{

	int num[5] = { 0, };

	for (int i = 0; i < 5; i++)
	{
		num[i] = _nums[i];
		printf("%d_", num[i]);
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

		for (int j = 0; j < 5; j++)
		{
			printf("%d_", num[j]);
		}
		printf("\n");

	}
	return;
}

int main(void)
{
	int i;
	int v;
	int nums[SZ];

	for (i = 0; i < SZ; i++)
	{
		scanf("%d", &v);
		nums[i] = v;
	}

	doSelectionSort(nums);

	return 0;
}