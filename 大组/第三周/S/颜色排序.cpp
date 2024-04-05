#include<stdio.h>
#include<windows.h>;
int main()
{
	int n;
	printf("请输入数组的长度\n");
	scanf("%d", &n);
	int a[100];
	printf("请初始化数组（0/1/2）\n");
	for (int m = 0; m < n; m++)
	{
		scanf("%d", &a[m]);
	}
	int i, j, k;
	i = 0, j = 0, k = n-1;
	int t;
	while (1)
	{
		if (j <k)
		{
			if (a[j] ==2 && a[k] <= 1)
			{
				int tmp = a[j];
				a[j] = a[k];
				a[k] = tmp;
				k--;
		
			}
			else if (a[j] != 2 && a[k] <=1)
			{
				j++;
			}
			else if (a[j] == 2 && a[k] == 2)
			{
				k--;
			}
			else if (a[j] != 2 && a[k] == 2)
			{
				j++;
			}
		}
		else  if(k <= j)
		{
			if (a[i] == 1 && a[k] == 0)
			{
				int tmp = a[k];
				a[k] = a[i];
				a[i] = tmp;
				k--;
			}
			else if (a[i] == 1 && a[k] == 1)
			{
				k--;
			}
			else if (a[i] == 0 && a[k] == 0)
			{
				i++;
			}
			else if (a[i] == 0 && a[k] == 1)
			{
				i++;
			}
			if (i == k)
			{
				break;
			}
		}

	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
}