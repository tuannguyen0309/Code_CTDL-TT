#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Phep tao Dong
void ADJUST(int K[], int i, int n)
{
	int KEY = K[i];
	int j = 2 * i;
	while (j <= n)
	{
		if ( (j < n) && (K[j] < K[j+1]) ) j = j + 1;

		if (KEY > K[j])
		{
			K[ (int) floor(j/2) ] = KEY;
			return;
		}
		K[ (int) floor(j/2) ] = K[j];
		j = 2 * j ;
	}
	K[ (int) floor(j/2) ] = KEY;
}

void HeapSort(int K[], int n)
{
	int i;
	for (i = floor(n/2) ; i >=1; i--)
		ADJUST(K, i, n);//ADJUST_Smallest(i,n);
	for (i = n - 1; i >= 1; i--)
	{
		int tmp = K[1];
		K[1] = K[ i + 1] ;
		K[i+1] = tmp;
		ADJUST(K, 1, i );//ADJUST_Smallest(i,n);
	}
}

void print_array(int K[], int n)
{
	int i;
	for ( i = 0; i < n; ++i)
		printf("%d ", K[i]);
}

int main()
{
	int K[6]= {1,3,6,2,8,7};
	printf("\nMang truoc khi sap xep: ");
	print_array(K, 6);
	printf("\nMang sau khi sap xep: ");
	HeapSort(K, 5);
	print_array(K, 6);
}











