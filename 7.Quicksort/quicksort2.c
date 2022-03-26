#include <stdio.h>
#include <string.h>

int Part(int K[], int LB, int UB)
{
	int i, m;
	i = LB + 1;
	int j = UB;
	while (i <= j)
	{
		while (K[i] > K[LB])
		{
			i = i + 1;
		}
		while (K[j] < K[LB])
		{
			j = j - 1;
		}
		if (i < j)
		{
			m = K[i];
			K[i] = K[j];
			K[j] = m;
			i = i + 1;
			j = j - 1;
		}
	}
	if (K[LB] < K[j])
	{
		m = K[LB];
		K[LB] = K[j];
		K[j] = m;
	}
	return j;
}

void QuickSort(int K[], int LB, int UB)
{
	int j;
	if (LB < UB)
	{
		j = Part(K, LB, UB);
		QuickSort(K, LB, j - 1);
		QuickSort(K, j + 1, UB);
	}
}

void print_array(int k[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", k[i]);
	}
}

int main(void)
{
	int K[6] = {37, 11, 9, 65, 24, 57};
	printf("\nMang truoc khi sap xep: ");
	print_array(K, 6);
	QuickSort(K, 0, 6);
	printf("\nMang sau khi sap xep: ");
	print_array(K, 6);
	return 0;
}
