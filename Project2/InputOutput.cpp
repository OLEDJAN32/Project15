#include"Mylib.h"

void chose(int** a, int& n, int* m)
{
	int N;
	printf("Выберите способ ввода данных(введите номер способа)\n");
	printf("1)Ввод данных с клавиатуры\n");
	printf("2)Случайные данные в диапозоне от А до B\n");
	printf("3)Ввод данных из файла\n");
	printf("Использовать способ под номером: "); scanf("%d", &N);
	while ((N < 1) || (N > 3))
	{
		printf("Ошибка, способа ввода под данным номером не существует, выберите способ заново\n");
		printf("Использовать способ под номером: "); scanf("%d", &N);
		printf("\n");
	}

	switch (N)
	{
	case 1:inputKeyboard(a, n, m); break;
	case 2:inputRandom(a, n, m); break;
	case 3:inputFile(a, n, m); break;
	}
}

void inputKeyboard(int** a, int& n, int* m)
{
	for (int i = 0; i < n; i++)
	{
		printf("Введите количество столбцов %d-й строки: ", i); scanf("%d", &m[i]);
		a[i] = (int*)malloc(m[i] * sizeof(int));
		for (int j = 0; j < m[i]; j++)
		{
			printf("a[%d][%d]=", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void inputRandom(int** a, int& n, int* m)
{
	int A = 0, B = 0;
	srand(time(NULL));
	printf("Введите начало и конец диапозона AB\n");
	printf("A="); scanf("%d", &A);
	printf("B="); scanf("%d", &B);
	while (A >= B)
	{
		printf("Ошибка, A должно быть меньше B, введите значения границ заново\n");
		printf("A="); scanf("%d", &A);
		printf("B="); scanf("%d", &B);
	}
	if (A < B)
	{
		for (int i = 0; i < n; i++)
		{
			printf("Введите количество столбцов %d-й строки: ", i); scanf("%d", &m[i]);
			a[i] = (int*)malloc(m[i] * sizeof(int));
			for (int j = 0; j < m[i]; j++)
			{
				a[i][j] = rand() % (B - A + 1) + A;
			}
		}
		printf("Матрица, заполненная случайными числами из диапозона AB:\n");
	}
}

void inputFile(int** a, int& n, int* m)
{
	FILE* f = fopen("D:\Lab.txt", "rt");
	if (f)
	{
		for (int i = 0; i < n; i++)
		{
			printf("Введите количество столбцов %d-й строки: ", i); scanf("%d", &m[i]);
			a[i] = (int*)malloc(m[i] * sizeof(int));
			for (int j = 0; j < m[i]; j++)
			{
				fscanf(f, "%d", &a[i][j]);
			}
		}
	}
	else
	{
		printf("Ошибка, файл пустой или не существует. Создайте заполненный файл или измените способ ввода\n");
		chose(a, n, m);
	}
	fclose(f);
}

void output(int** a, int& n, int* m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m[i]; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void save(int** a, int& n, int* m)
{
	int save = 0;
	printf("Сохранить массив в файл?(выберите номер действия)\n");
	printf("1)Да      2)Нет\n");
	scanf("%d", &save);
	while ((save > 2) || (save < 1))
	{
		printf("Действия под данным номером не существует, введите номер заново\n");
		scanf("%d", &save);
	}
	if (save == 1)
	{
		FILE* f1 = fopen("D:\Lab_res.txt", "wt");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m[i]; j++)
			{
				fprintf(f1, "%d ", a[i][j]);
			}
			fprintf(f1, "\n");
		}
		printf("Массив успешно сохранен в файл в файл\n");
	}
	if (save == 2)
		printf("Сохранение отменено\n");
}