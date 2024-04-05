#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>


int a[200001], n;


void quicksort(int left, int right)
{
	int i, j, temp;
	if (left > right)
	{
		return;
	}
	temp = a[left];
	i = left;
	j = right;
	while (i != j)
	{
		while (a[j] >= temp && i < j)
		{
			j--;
		}
		while (a[i] <= temp && i < j)
		{
			i++;
		}
		if (i < j)
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	a[left] = a[j];
	a[j] = temp;
	quicksort(left, i - 1);
	quicksort(i + 1, right);
	return;
}


void insertsort()
{
	for (int i = 1; i < n; i++)
	{
		int temp = a[i];
		int j = i - 1;
		while (a[j] > temp && j >= 0)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}


void countsort()
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	int range = max + 1;
	int* countarr = (int*)malloc(sizeof(int)*range);
	memset(countarr, 0, sizeof(int) * range);
	for (int i = 0; i < n; i++)
	{
		countarr[a[i]]++;
	}
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (countarr[i]--)
		{
			a[j++]=i;
		}
	}
	free(countarr);
}


void merge(int arr[], int start, int mid, int end) {
	int result[200001];
	int k = 0;
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]) {
			result[k++] = arr[i++];
		}
		else {
			result[k++] = arr[j++];
		}
	}
	if (i == mid + 1) {
		while (j <= end)
			result[k++] = arr[j++];
	}
	if (j == end + 1) {
		while (i <= mid)
			result[k++] = arr[i++];
	}
	for (j = 0, i = start; j < k; i++, j++) {
		arr[i] = result[j];
	}
}


void mergesort(int arr[], int start, int end) {
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	mergesort(arr, start, mid);
	mergesort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}
int get_max() 
{
	int i, max;
	max = a[0];
	for (i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}


void count_sort( int exp) 
{
	int* output = (int*)malloc(n * sizeof(int)); 
	int i, buckets[10] = { 0 };
	for (i = 0; i < n; i++) {
		buckets[(a[i] / exp) % 10]++;
	}
	for (i = 1; i < 10; i++) {
		buckets[i] += buckets[i - 1];
	}
	for (i = n - 1; i >= 0; i--) {
		output[buckets[(a[i] / exp) % 10] - 1] = a[i];
		buckets[(a[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++) {
		a[i] = output[i];
	}
}


void radix_sort() {
	int exp;
	int max = get_max();
	for (exp = 1; max / exp > 0; exp *= 10) {
		count_sort(exp);
	}
}


int main()
{
	FILE* fp = NULL;
	fp = fopen("data.txt", "r");
	fscanf(fp, "%d", &n);
	int num;
	printf("请输入生成次数\n");
	scanf("%d", &num);
	
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%d", &a[i]);
	}
	clock_t start1 = clock();
	for(int i=1;i<=num;i++)
	quicksort(0,n-1);
	clock_t diff1 = clock() - start1;
		printf( "快速排序=%dms\n",diff1);
	fseek(fp, 2, SEEK_SET);

	
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%d", &a[i]);
	}
	clock_t start2 = clock();
	for (int i = 1; i <= num; i++)
	insertsort();
	clock_t diff2 = clock() - start2;
	printf("插入排序=%dms\n", diff2);
	fseek(fp, 2, SEEK_SET);
	

	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%d", &a[i]);
	}
	clock_t start3 = clock();
	for (int i = 1; i <= num; i++)
	countsort();
	clock_t diff3 = clock() - start3;
	printf("计数排序=%dms\n", diff3);
	fseek(fp, 2, SEEK_SET);
	
	
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%d", &a[i]);
	}
	clock_t start4 = clock();
	for (int i = 1; i <= num; i++)
	mergesort(a,0,n-1);
	clock_t diff4 = clock() - start4;
	printf("基数排序=%dms\n", diff4);
	fseek(fp, 2, SEEK_SET);

	
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%d", &a[i]);
	}
	clock_t start5 = clock();
	for (int i = 1; i <= num; i++)
	radix_sort();
	clock_t diff5 = clock() - start5;
	printf("归并排序=%dms\n", diff5);
	fseek(fp, 2, SEEK_SET);
	
	fclose(fp);
}









