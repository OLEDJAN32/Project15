#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<conio.h>
#include<ctime>
#include<locale.h>

void chose(int** a, int& n, int* m);
void inputKeyboard(int** a, int& n, int* m);
void inputRandom(int** a, int& n, int* m);
void inputFile(int** a, int& n, int* m);
void output(int** a, int& n, int* m);
void save(int** a, int& n, int* m);
void max_min(int** a, int& n, int* m, int* dop);
