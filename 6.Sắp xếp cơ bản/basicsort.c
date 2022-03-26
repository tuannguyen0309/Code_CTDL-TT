#include <stdio.h>
#include <stdlib.h>

void selection_sort(int k[], int n)
{
	int i, j, m, x;
	for (i = 1; i < n + 1; i++)
	{
		m = i;
		for (j = i + 1; j < n + 1; j++)
		{
			if (k[j] < k[m])
				m = j;
		}
		if (m != i)
		{
			x = k[i];
			k[i] = k[m];
			k[m] = x;
		}
	}
}

void insert_sort(int k[], int n)
{
	int i, j, x;
	for (i = 2; i < n + 1; i++)
	{
		x = k[i];
		j = i - 1;
		while (x < k[j])
		{
			k[j + 1] = k[j];
			j = j - 1;
		}
		k[j + 1] = x;
	}
}

void bubble_sort(int k[], int n)
{
	int i, j, x;
	for (i = 1; i < n + 1; i++)
	{
		for (j = 1; j < i; j++)
		{
			if (k[j+1] < k[j])
			{
				x = k[j];
				k[j] = k[j + 1];
				k[j + 1] = x;
			}
		}
	}
}

void printArray(int k[], int n, int i)
{
	for (i = 1; i <= n; i++)
	{
		printf("%d ", k[i]);
	}
	printf("\n");
}

int main()
{
	int k[1000];
	int n, i;
	printf("Nhap n: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("Nhap k[%d]=", i);
		scanf("%d", &k[i]);
	}
	printf("selection_sort:\n");
	selection_sort(k, n);
	printArray(k, n, i);
	printf("insert_sort:\n");
	insert_sort(k, n);
	printArray(k, n, i);
	printf("bubble_sort:\n");
	bubble_sort(k, n);
	printArray(k, n, i);
}
