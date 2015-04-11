#include <stdio.h>  //输出一个n阶魔方阵

int main()
{
	long a[50][50], i, j, k, n, sum, p, q, ii, jj, t;

	printf("please input n:"); 
	scanf("%ld", &n);

	if (n % 2 == 1)                     //奇数阶魔方阵
	{
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				a[i][j] = 0;

		i = 1; j = n / 2 + 1; a[i][j] = 1;
		for (k = 2; k <= n*n; k++)
		{
			i--; j++;
			if ((i>0) && (j<n + 1))
			{
				if (a[i][j] != 0)
				{
					i += 2; j--;
				}
			}
			else if ((i == 0) && (j == n + 1))
			{
				i += 2; j--;
			}
			else if ((i == 0) && (j<n + 1)) i = n;
			else if ((i>0) && (j == n + 1)) j = 1;
			a[i][j] = k;
		}

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
				printf("%-3ld", a[i][j]);
			printf("\n");
		}
	}
	else if (n % 4 == 0)              //双偶数阶魔方阵
	{
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				a[i][j] = (i - 1)*n + j;
		sum = 1 + n*n; k = n / 4;
		for (p = 1; p <= k; p++)
			for (q = 1; q <= k; q++)
			{
				ii = (p - 1) * 4 + 1; jj = (q - 1) * 4 + 1;
				for (i = ii; i <= ii + 3; i++)
				{
					a[i][jj + i - ii] = sum - a[i][jj + i - ii];
					a[i][jj + 3 - (i - ii)] = sum - a[i][jj + 3 - (i - ii)];
				}
			}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
				printf("%-5ld", a[i][j]);
			printf("\n");
		}
	}
	else                        //单偶数阶魔方阵
	{
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				a[i][j] = 0;
		//A象限
		i = 1; j = n / 4 + 1; a[i][j] = 1;
		for (k = 2; k <= n*n / 4; k++)
		{
			i--; j++;
			if ((i>0) && (j<n / 2 + 1))
			{
				if (a[i][j] != 0)
				{
					i += 2; j--;
				}
			}
			else if ((i == 0) && (j == n / 2 + 1))
			{
				i += 2; j--;
			}
			else if ((i == 0) && (j<n / 2 + 1)) i = n / 2;
			else if ((i>0) && (j == n / 2 + 1)) j = 1;
			a[i][j] = k;
		}

		//D象限
		i = n / 2 + 1; j = n / 2 + n / 4 + 1; a[i][j] = n*n / 4 + 1;
		for (k = n*n / 4 + 2; k <= n*n / 2; k++)
		{
			i--; j++;
			if ((i>n / 2) && (j<n + 1))
			{
				if (a[i][j] != 0)
				{
					i += 2; j--;
				}
			}
			else if ((i == n / 2) && (j == n + 1))
			{
				i += 2; j--;
			}
			else if ((i == n / 2) && (j<n + 1)) i = n;
			else if ((i>n / 2) && (j == n + 1)) j = n / 2 + 1;
			a[i][j] = k;
		}

		//B象限
		i = 1; j = n / 2 + n / 4 + 1; a[i][j] = n*n / 2 + 1;
		for (k = n*n / 2 + 2; k <= n*n * 3 / 4; k++)
		{
			i--; j++;
			if ((i>0) && (j<n + 1))
			{
				if (a[i][j] != 0)
				{
					i += 2; j--;
				}
			}
			else if ((i == 0) && (j == n + 1))
			{
				i += 2; j--;
			}
			else if ((i == 0) && (j<n + 1)) i = n / 2;
			else if ((i>0) && (j == n + 1)) j = n / 2 + 1;
			a[i][j] = k;
		}

		//C象限
		i = n / 2 + 1; j = n / 4 + 1; a[i][j] = n*n * 3 / 4 + 1;
		for (k = n*n * 3 / 4 + 2; k <= n*n; k++)
		{
			i--; j++;
			if ((i>n / 2) && (j<n / 2 + 1))
			{
				if (a[i][j] != 0)
				{
					i += 2; j--;
				}
			}
			else if ((i == n / 2) && (j == n / 2 + 1))
			{
				i += 2; j--;
			}
			else if ((i == n / 2) && (j<n / 2 + 1)) i = n;
			else if ((i>n / 2) && (j == n / 2 + 1)) j = 1;
			a[i][j] = k;
		}

		//AC象限某些元素互换
		k = (n - 2) / 4;
		for (i = 1; i <= n / 4; i++)
			for (j = 1; j <= k; j++)
			{
				t = a[i][j];
				a[i][j] = a[i + n / 2][j];
				a[i + n / 2][j] = t;
			}
		for (i = n / 4 + 2; i <= n / 2; i++)
			for (j = 1; j <= k; j++)
			{
				t = a[i][j];
				a[i][j] = a[i + n / 2][j];
				a[i + n / 2][j] = t;
			}
		i = n / 4 + 1;
		for (j = n / 4 + 1; j <= n / 4 + k; j++)
		{
			t = a[i][j];
			a[i][j] = a[i + n / 2][j];
			a[i + n / 2][j] = t;
		}

		//BD象限某些元素交换
		for (i = 1; i <= n / 2; i++)
			for (j = n * 3 / 4 + 1; j >= n * 3 / 4 + 3 - k; j--)
			{
				t = a[i][j];
				a[i][j] = a[i + n / 2][j];
				a[i + n / 2][j] = t;
			}

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
				printf("%-5ld", a[i][j]);
			printf("\n");
		}
	}

	return 0;
}