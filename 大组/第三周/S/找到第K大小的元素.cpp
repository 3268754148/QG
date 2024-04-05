#include <stdio.h> 
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
int sortLevelN(int* a, int n, int k) {
	if (k < 0 || k >= n) return -1;
	int low = 0, high = n - 1, i, j, t;
	do {
		i = low;
		j = high;
		t = a[i];
		do {
			while (a[j] > t) j--;
			while (a[i] < t) i++;
			if (i < j) {
				swap(&a[i], &a[j]);
			}
		} while (i < j);
		if (i == k) return t;
		if (i > k) high = i - 1;
		if (i < k) low = i + 1;
	} while (low < high);
	return -1;
}
int main() {
	printf("�����������Ԫ�ظ���\n");
	int n;
	scanf("%d", &n);
	int arr[100];
	printf("���ʼ������\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("�ҵ���kС��Ԫ�أ�������k\n");
	int k;
	scanf("%d", &k);
	int num = sortLevelN(arr, n, k - 1);
	printf("%d", num);
	return 0;
}
