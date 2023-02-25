#include"Mylib.h"

int max = INT_MIN, min = INT_MAX, max_stroka = 0, min_stroka = 0, vrem = 0;
bool flag = 0;
void max_min(int** a, int& n, int* m, int* dop)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m[i]; j++)
		{
			if (a[i][j] < min) { min = a[i][j]; min_stroka = i; }
			if (a[i][j] > max) { max = a[i][j]; max_stroka = i; }
		}
	}
	printf("Минимальный элемент массива равен %d и находится в %d-й строке\n", min, min_stroka);
	printf("Максимальный элемент массива равен %d и находится в %d-й строке\n", max, max_stroka);

	dop = a[min_stroka];
	a[min_stroka] = a[max_stroka];
	a[max_stroka] = dop;

	vrem = m[min_stroka];
	m[min_stroka] = m[max_stroka];
	m[max_stroka] = vrem;

	printf("Поменяв местами строки с максимальным и минимальным элементом, массив примет вид:\n");
}