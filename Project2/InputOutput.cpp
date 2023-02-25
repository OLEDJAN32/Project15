#include"Mylib.h"

void chose(int** a, int& n, int* m)
{
	int N;
	printf("�������� ������ ����� ������(������� ����� �������)\n");
	printf("1)���� ������ � ����������\n");
	printf("2)��������� ������ � ��������� �� � �� B\n");
	printf("3)���� ������ �� �����\n");
	printf("������������ ������ ��� �������: "); scanf("%d", &N);
	while ((N < 1) || (N > 3))
	{
		printf("������, ������� ����� ��� ������ ������� �� ����������, �������� ������ ������\n");
		printf("������������ ������ ��� �������: "); scanf("%d", &N);
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
		printf("������� ���������� �������� %d-� ������: ", i); scanf("%d", &m[i]);
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
	printf("������� ������ � ����� ��������� AB\n");
	printf("A="); scanf("%d", &A);
	printf("B="); scanf("%d", &B);
	while (A >= B)
	{
		printf("������, A ������ ���� ������ B, ������� �������� ������ ������\n");
		printf("A="); scanf("%d", &A);
		printf("B="); scanf("%d", &B);
	}
	if (A < B)
	{
		for (int i = 0; i < n; i++)
		{
			printf("������� ���������� �������� %d-� ������: ", i); scanf("%d", &m[i]);
			a[i] = (int*)malloc(m[i] * sizeof(int));
			for (int j = 0; j < m[i]; j++)
			{
				a[i][j] = rand() % (B - A + 1) + A;
			}
		}
		printf("�������, ����������� ���������� ������� �� ��������� AB:\n");
	}
}

void inputFile(int** a, int& n, int* m)
{
	FILE* f = fopen("D:\Lab.txt", "rt");
	if (f)
	{
		for (int i = 0; i < n; i++)
		{
			printf("������� ���������� �������� %d-� ������: ", i); scanf("%d", &m[i]);
			a[i] = (int*)malloc(m[i] * sizeof(int));
			for (int j = 0; j < m[i]; j++)
			{
				fscanf(f, "%d", &a[i][j]);
			}
		}
	}
	else
	{
		printf("������, ���� ������ ��� �� ����������. �������� ����������� ���� ��� �������� ������ �����\n");
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
	printf("��������� ������ � ����?(�������� ����� ��������)\n");
	printf("1)��      2)���\n");
	scanf("%d", &save);
	while ((save > 2) || (save < 1))
	{
		printf("�������� ��� ������ ������� �� ����������, ������� ����� ������\n");
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
		printf("������ ������� �������� � ���� � ����\n");
	}
	if (save == 2)
		printf("���������� ��������\n");
}