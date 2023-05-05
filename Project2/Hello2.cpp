#include<SDL.h>
#include<iostream>
#include<locale.h>
using namespace std;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 720;
SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* myImage = NULL;
SDL_Surface* CSKA = NULL;
SDL_Surface* Spartak = NULL;
SDL_Surface* Line1 = NULL;
SDL_Surface* Line2 = NULL;
SDL_Surface* Line3 = NULL;
SDL_Surface* Line4 = NULL;
SDL_Surface* Win_CSKA = NULL;
SDL_Surface* Win_Spartak = NULL;
SDL_Surface* Nichya = NULL;

bool init();
bool media();
void close();
bool winer(int* pobeditel_CSKA, int* pobeditel_Spartak, int k);
void pobeda(int& N);
void play();

struct povt
{
	int povtor[4][4];
};

void povtor(povt& p)
{
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			p.povtor[i][j] = 1;
		}
	}
}

bool init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_EVERYTHING < 0))
	{
		printf("SDL не смог запуститься! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		window = SDL_CreateWindow("CSKA/Spartak", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Окно не может быть создано! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
		}
	}
	return success;
}

bool media()
{
	bool success = true;
	myImage = SDL_LoadBMP("pole.bmp");
	CSKA = SDL_LoadBMP("CSKA.bmp");
	Spartak = SDL_LoadBMP("Spartak.bmp");
	Line1 = SDL_LoadBMP("Line1.bmp");
	Line2 = SDL_LoadBMP("Line2.bmp");
	Line3 = SDL_LoadBMP("Line3.bmp");
	Line4 = SDL_LoadBMP("Line4.bmp");
	Win_CSKA = SDL_LoadBMP("Win_CSKA.bmp");
	Win_Spartak = SDL_LoadBMP("Win_Spartak.bmp");
	Nichya = SDL_LoadBMP("Nichya.bmp");
	if (myImage == NULL || CSKA == NULL || Spartak == NULL || Line1 == NULL || Line2 == NULL || Line3 == NULL || Line4 == NULL || Win_CSKA == NULL || Win_Spartak == NULL || Nichya == NULL)
	{
		printf("error\n");
		success = false;
	}
	return success;
}

void pobeda(int& N)
{
	SDL_Delay(1000);

	SDL_Rect victory;
	victory.x = 165;
	victory.y = 100;
	if ((N >= 1) && (N <= 8))
	{
		SDL_BlitSurface(Win_CSKA, NULL, screenSurface, &victory);
		SDL_UpdateWindowSurface(window);
	}
	if ((N > 8) && (N <= 16))
	{
		SDL_BlitSurface(Win_Spartak, NULL, screenSurface, &victory);
		SDL_UpdateWindowSurface(window);
	}
	if (N == 17)
	{
		SDL_BlitSurface(Nichya, NULL, screenSurface, &victory);
		SDL_UpdateWindowSurface(window);
	}
}

bool winer(int* pobeditel_CSKA, int* pobeditel_Spartak, int k)
{
	bool konec = false;
	int N = 0;

	//Победа ЦСКА(крестиков)
	if ((pobeditel_CSKA[1] == 3)) N = 1;

	if ((pobeditel_CSKA[2] == 3)) N = 2;

	if ((pobeditel_CSKA[3] == 3)) N = 3;

	if ((pobeditel_CSKA[4] == 3)) N = 4;

	if ((pobeditel_CSKA[5] == 3)) N = 5;

	if ((pobeditel_CSKA[6] == 3)) N = 6;

	if ((pobeditel_CSKA[7] == 3)) N = 7;

	if ((pobeditel_CSKA[8] == 3)) N = 8;

	//Победа Спартака(ноликов)
	if ((pobeditel_Spartak[1] == 6)) N = 9;

	if ((pobeditel_Spartak[2] == 6)) N = 10;

	if ((pobeditel_Spartak[3] == 6)) N = 11;

	if ((pobeditel_Spartak[4] == 6)) N = 12;

	if ((pobeditel_Spartak[5] == 6)) N = 13;

	if ((pobeditel_Spartak[6] == 6)) N = 14;

	if ((pobeditel_Spartak[7] == 6)) N = 15;

	if ((pobeditel_Spartak[8] == 6)) N = 16;

	if ((k == 9) && (N == 0)) N = 17;

	switch (N)
	{
	case 1: {SDL_Rect polozhenie;
		polozhenie.x = 150;
		polozhenie.y = 110;
		SDL_SetColorKey(Line1, SDL_TRUE, SDL_MapRGB(Win_CSKA->format, 255, 255, 255));
		SDL_BlitSurface(Line1, NULL, screenSurface, &polozhenie); konec = true; break; }
	case 2: {SDL_Rect polozhenie;
		polozhenie.x = 150;
		polozhenie.y = 360;
		SDL_SetColorKey(Line1, SDL_TRUE, SDL_MapRGB(Win_CSKA->format, 255, 255, 255));
		SDL_BlitSurface(Line1, NULL, screenSurface, &polozhenie); konec = true; break; }
	case 3: {SDL_Rect polozhenie;
		polozhenie.x = 150;
		polozhenie.y = 610;
		SDL_SetColorKey(Line1, SDL_TRUE, SDL_MapRGB(Win_CSKA->format, 255, 255, 255));
		SDL_BlitSurface(Line1, NULL, screenSurface, &polozhenie); konec = true; break; }
	case 4: {SDL_Rect polozhenie;
		polozhenie.x = 259;
		polozhenie.y = 0;
		SDL_SetColorKey(Line2, SDL_TRUE, SDL_MapRGB(Win_CSKA->format, 255, 255, 255));
		SDL_BlitSurface(Line2, NULL, screenSurface, &polozhenie); konec = true; break; }
	case 5: {SDL_Rect polozhenie;
		polozhenie.x = 514;
		polozhenie.y = 0;
		SDL_SetColorKey(Line2, SDL_TRUE, SDL_MapRGB(Win_CSKA->format, 255, 255, 255));
		SDL_BlitSurface(Line2, NULL, screenSurface, &polozhenie); konec = true; break; }
	case 6: {SDL_Rect polozhenie;
		polozhenie.x = 769;
		polozhenie.y = 0;
		SDL_SetColorKey(Line2, SDL_TRUE, SDL_MapRGB(Win_CSKA->format, 255, 255, 255));
		SDL_BlitSurface(Line2, NULL, screenSurface, &polozhenie); konec = true; break; }
	case 7: {SDL_Rect polozhenie;
		polozhenie.x = 150;
		polozhenie.y = 0;
		SDL_SetColorKey(Line3, SDL_TRUE, SDL_MapRGB(Win_CSKA->format, 255, 255, 255));
		SDL_BlitSurface(Line3, NULL, screenSurface, &polozhenie); konec = true; break; }
	case 8: {SDL_Rect polozhenie;
		polozhenie.x = 150;
		polozhenie.y = 0;
		SDL_SetColorKey(Line4, SDL_TRUE, SDL_MapRGB(Win_CSKA->format, 255, 255, 255));
		SDL_BlitSurface(Line4, NULL, screenSurface, &polozhenie); konec = true; break; }
	case 9: {SDL_Rect polozhenie;
		polozhenie.x = 150;
		polozhenie.y = 110;
		SDL_BlitSurface(Line1, NULL, screenSurface, &polozhenie); konec = true; break; }
	case 10: {SDL_Rect polozhenie;
		polozhenie.x = 150;
		polozhenie.y = 360;
		SDL_BlitSurface(Line1, NULL, screenSurface, &polozhenie); konec = true; break; }
	case 11: {SDL_Rect polozhenie;
		polozhenie.x = 150;
		polozhenie.y = 610;
		SDL_BlitSurface(Line1, NULL, screenSurface, &polozhenie); konec = true; break; }
	case 12: {SDL_Rect polozhenie;
		polozhenie.x = 259;
		polozhenie.y = 0;
		SDL_BlitSurface(Line2, NULL, screenSurface, &polozhenie); konec = true; break; }
	case 13: {SDL_Rect polozhenie;
		polozhenie.x = 514;
		polozhenie.y = 0;
		SDL_BlitSurface(Line2, NULL, screenSurface, &polozhenie); konec = true; break; }
	case 14: {SDL_Rect polozhenie;
		polozhenie.x = 769;
		polozhenie.y = 0;
		SDL_BlitSurface(Line2, NULL, screenSurface, &polozhenie); konec = true; break; }
	case 15: {SDL_Rect polozhenie;
		polozhenie.x = 150;
		polozhenie.y = 0;
		SDL_SetColorKey(Line3, SDL_TRUE, SDL_MapRGB(Win_Spartak->format, 255, 255, 255));
		SDL_BlitSurface(Line3, NULL, screenSurface, &polozhenie); konec = true; break; }
	case 16: {SDL_Rect polozhenie;
		polozhenie.x = 150;
		polozhenie.y = 0;
		SDL_SetColorKey(Line4, SDL_TRUE, SDL_MapRGB(Win_Spartak->format, 255, 255, 255));
		SDL_BlitSurface(Line4, NULL, screenSurface, &polozhenie); konec = true; break; }
	case 17: konec = true; break;
	}

	SDL_UpdateWindowSurface(window);
	if (konec == true) pobeda(N);
	return konec;
}

void play()
{
	povt p;
	povtor(p);
	bool quit = false, hod = true;
	int k = 0;
	int pobeditel_CSKA[9];
	for (int i = 1; i <= 8; i++)
	{
		pobeditel_CSKA[i] = 0;
	}
	int pobeditel_Spartak[9];
	for (int i = 1; i <= 8; i++)
	{
		pobeditel_Spartak[i] = 0;
	}
	SDL_Event event;
	while (!quit)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) quit = true;

		if ((event.button.button == SDL_BUTTON_LEFT) && !(winer(pobeditel_CSKA, pobeditel_Spartak, k)))
		{
			int x = event.button.x, y = event.button.y;

			//ЦСКА(крестики)
			if ((x >= 145) && (x <= 380) && (y >= 5) && (y <= 240) && (hod == true) && (p.povtor[1][1] == 1))//клетка 1
			{
				SDL_Rect razmer;
				razmer.x = 200;
				razmer.y = 30;
				SDL_BlitSurface(CSKA, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = false;
				p.povtor[1][1] = 0;
				pobeditel_CSKA[1] = pobeditel_CSKA[1] + 1;
				pobeditel_CSKA[4] = pobeditel_CSKA[4] + 1;
				pobeditel_CSKA[7] = pobeditel_CSKA[7] + 1;
				k += 1;
			}

			if ((x >= 400) && (x <= 630) && (y >= 5) && (y <= 240) && (hod == true) && (p.povtor[1][2] == 1))//клетка 2
			{
				SDL_Rect razmer;
				razmer.x = 455;
				razmer.y = 30;
				SDL_BlitSurface(CSKA, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = false;
				p.povtor[1][2] = 0;
				pobeditel_CSKA[1] = pobeditel_CSKA[1] + 1;
				pobeditel_CSKA[5] = pobeditel_CSKA[5] + 1;
				k += 1;
			}

			if ((x >= 645) && (x <= 880) && (y >= 5) && (y <= 240) && (hod == true) && (p.povtor[1][3] == 1))//клетка 3
			{
				SDL_Rect razmer;
				razmer.x = 710;
				razmer.y = 30;
				SDL_BlitSurface(CSKA, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = false;
				p.povtor[1][3] = 0;
				pobeditel_CSKA[1] = pobeditel_CSKA[1] + 1;
				pobeditel_CSKA[6] = pobeditel_CSKA[6] + 1;
				pobeditel_CSKA[8] = pobeditel_CSKA[8] + 1;
				k += 1;
			}

			if ((x >= 145) && (x <= 380) && (y >= 255) && (y <= 480) && (hod == true) && (p.povtor[2][1] == 1))//клетка 4
			{
				SDL_Rect razmer;
				razmer.x = 200;
				razmer.y = 280;
				SDL_BlitSurface(CSKA, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = false;
				p.povtor[2][1] = 0;
				pobeditel_CSKA[2] = pobeditel_CSKA[2] + 1;
				pobeditel_CSKA[4] = pobeditel_CSKA[4] + 1;
				k += 1;
			}

			if ((x >= 400) && (x <= 630) && (y >= 255) && (y <= 480) && (hod == true) && (p.povtor[2][2] == 1))//клетка 5
			{
				SDL_Rect razmer;
				razmer.x = 455;
				razmer.y = 280;
				SDL_BlitSurface(CSKA, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = false;
				p.povtor[2][2] = 0;
				pobeditel_CSKA[2] = pobeditel_CSKA[2] + 1;
				pobeditel_CSKA[5] = pobeditel_CSKA[5] + 1;
				pobeditel_CSKA[7] = pobeditel_CSKA[7] + 1;
				pobeditel_CSKA[8] = pobeditel_CSKA[8] + 1;
				k += 1;
			}

			if ((x >= 645) && (x <= 880) && (y >= 255) && (y <= 480) && (hod == true) && (p.povtor[2][3] == 1))//клетка 6
			{
				SDL_Rect razmer;
				razmer.x = 710;
				razmer.y = 280;
				SDL_BlitSurface(CSKA, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = false;
				p.povtor[2][3] = 0;
				pobeditel_CSKA[2] = pobeditel_CSKA[2] + 1;
				pobeditel_CSKA[6] = pobeditel_CSKA[6] + 1;
				k += 1;
			}

			if ((x >= 145) && (x <= 380) && (y >= 495) && (y <= 720) && (hod == true) && (p.povtor[3][1] == 1))//клетка 7
			{
				SDL_Rect razmer;
				razmer.x = 200;
				razmer.y = 530;
				SDL_BlitSurface(CSKA, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = false;
				p.povtor[3][1] = 0;
				pobeditel_CSKA[3] = pobeditel_CSKA[3] + 1;
				pobeditel_CSKA[4] = pobeditel_CSKA[4] + 1;
				pobeditel_CSKA[8] = pobeditel_CSKA[8] + 1;
				k += 1;
			}

			if ((x >= 400) && (x <= 630) && (y >= 495) && (y <= 720) && (hod == true) && (p.povtor[3][2] == 1))//клетка 8
			{
				SDL_Rect razmer;
				razmer.x = 455;
				razmer.y = 530;
				SDL_BlitSurface(CSKA, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = false;
				p.povtor[3][2] = 0;
				pobeditel_CSKA[3] = pobeditel_CSKA[3] + 1;
				pobeditel_CSKA[5] = pobeditel_CSKA[5] + 1;
				k += 1;
			}

			if ((x >= 645) && (x <= 880) && (y >= 495) && (y <= 720) && (hod == true) && (p.povtor[3][3] == 1))//клетка 9
			{
				SDL_Rect razmer;
				razmer.x = 710;
				razmer.y = 530;
				SDL_BlitSurface(CSKA, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = false;
				p.povtor[3][3] = 0;
				pobeditel_CSKA[3] = pobeditel_CSKA[3] + 1;
				pobeditel_CSKA[6] = pobeditel_CSKA[6] + 1;
				pobeditel_CSKA[7] = pobeditel_CSKA[7] + 1;
				k += 1;
			}

			//Спартак(нолики)
			if ((x >= 145) && (x <= 380) && (y >= 5) && (y <= 240) && (hod == false) && (p.povtor[1][1] == 1))//клетка 1
			{
				SDL_Rect razmer;
				razmer.x = 150;
				razmer.y = 30;
				SDL_BlitSurface(Spartak, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = true;
				p.povtor[1][1] = 0;
				pobeditel_Spartak[1] = pobeditel_Spartak[1] + 2;
				pobeditel_Spartak[4] = pobeditel_Spartak[4] + 2;
				pobeditel_Spartak[7] = pobeditel_Spartak[7] + 2;
				k += 1;
			}

			if ((x >= 400) && (x <= 630) && (y >= 5) && (y <= 240) && (hod == false) && (p.povtor[1][2] == 1))//клетка 2
			{
				SDL_Rect razmer;
				razmer.x = 405;
				razmer.y = 30;
				SDL_BlitSurface(Spartak, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = true;
				p.povtor[1][2] = 0;
				pobeditel_Spartak[1] = pobeditel_Spartak[1] + 2;
				pobeditel_Spartak[5] = pobeditel_Spartak[5] + 2;
				k += 1;
			}

			if ((x >= 645) && (x <= 880) && (y >= 5) && (y <= 240) && (hod == false) && (p.povtor[1][3] == 1))//клетка 3
			{
				SDL_Rect razmer;
				razmer.x = 660;
				razmer.y = 30;
				SDL_BlitSurface(Spartak, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = true;
				p.povtor[1][3] = 0;
				pobeditel_Spartak[1] = pobeditel_Spartak[1] + 2;
				pobeditel_Spartak[6] = pobeditel_Spartak[6] + 2;
				pobeditel_Spartak[8] = pobeditel_Spartak[8] + 2;
				k += 1;
			}

			if ((x >= 145) && (x <= 380) && (y >= 255) && (y <= 480) && (hod == false) && (p.povtor[2][1] == 1))//клетка 4
			{
				SDL_Rect razmer;
				razmer.x = 150;
				razmer.y = 280;
				SDL_BlitSurface(Spartak, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = true;
				p.povtor[2][1] = 0;
				pobeditel_Spartak[2] = pobeditel_Spartak[2] + 2;
				pobeditel_Spartak[4] = pobeditel_Spartak[4] + 2;
				k += 1;
			}

			if ((x >= 400) && (x <= 630) && (y >= 255) && (y <= 480) && (hod == false) && (p.povtor[2][2] == 1))//клетка 5
			{
				SDL_Rect razmer;
				razmer.x = 405;
				razmer.y = 280;
				SDL_BlitSurface(Spartak, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = true;
				p.povtor[2][2] = 0;
				pobeditel_Spartak[2] = pobeditel_Spartak[2] + 2;
				pobeditel_Spartak[5] = pobeditel_Spartak[5] + 2;
				pobeditel_Spartak[7] = pobeditel_Spartak[7] + 2;
				pobeditel_Spartak[8] = pobeditel_Spartak[8] + 2;
				k += 1;
			}

			if ((x >= 645) && (x <= 880) && (y >= 255) && (y <= 480) && (hod == false) && (p.povtor[2][3] == 1))//клетка 6
			{
				SDL_Rect razmer;
				razmer.x = 660;
				razmer.y = 280;
				SDL_BlitSurface(Spartak, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = true;
				p.povtor[2][3] = 0;
				pobeditel_Spartak[2] = pobeditel_Spartak[2] + 2;
				pobeditel_Spartak[6] = pobeditel_Spartak[6] + 2;
				k += 1;
			}

			if ((x >= 145) && (x <= 380) && (y >= 495) && (y <= 720) && (hod == false) && (p.povtor[3][1] == 1))//клетка 7
			{
				SDL_Rect razmer;
				razmer.x = 150;
				razmer.y = 530;
				SDL_BlitSurface(Spartak, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = true;
				p.povtor[3][1] = 0;
				pobeditel_Spartak[3] = pobeditel_Spartak[3] + 2;
				pobeditel_Spartak[4] = pobeditel_Spartak[4] + 2;
				pobeditel_Spartak[8] = pobeditel_Spartak[8] + 2;
				k += 1;
			}

			if ((x >= 400) && (x <= 630) && (y >= 495) && (y <= 720) && (hod == false) && (p.povtor[3][2] == 1))//клетка 8
			{
				SDL_Rect razmer;
				razmer.x = 405;
				razmer.y = 530;
				SDL_BlitSurface(Spartak, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = true;
				p.povtor[3][2] = 0;
				pobeditel_Spartak[3] = pobeditel_Spartak[3] + 2;
				pobeditel_Spartak[5] = pobeditel_Spartak[5] + 2;
				k += 1;
			}

			if ((x >= 645) && (x <= 880) && (y >= 495) && (y <= 720) && (hod == false) && (p.povtor[3][3] == 1))//клетка 9
			{
				SDL_Rect razmer;
				razmer.x = 660;
				razmer.y = 530;
				SDL_BlitSurface(Spartak, NULL, screenSurface, &razmer);
				SDL_UpdateWindowSurface(window);
				hod = true;
				p.povtor[3][3] = 0;
				pobeditel_Spartak[3] = pobeditel_Spartak[3] + 2;
				pobeditel_Spartak[6] = pobeditel_Spartak[6] + 2;
				pobeditel_Spartak[7] = pobeditel_Spartak[7] + 2;
				k += 1;
			}

			winer(pobeditel_CSKA, pobeditel_Spartak, k);
		}
	}
}


int main(int argc, char* args[])
{
	setlocale(LC_ALL, "Russian");

	if (!(init()))
	{
		printf("Ошибка инициализации окна\n");
	}
	else
	{
		if (!(media()))
		{
			printf("Ошибка загрузки картинки\n");
		}
		else
		{
			SDL_Rect dest;
			dest.x = 20;
			dest.y = -41;
			SDL_BlitSurface(myImage, NULL, screenSurface, &dest);
			SDL_UpdateWindowSurface(window);

			//ИГРА
			play();
		}
	}

	SDL_FreeSurface(myImage);
	SDL_FreeSurface(CSKA);
	SDL_FreeSurface(Spartak);
	SDL_FreeSurface(Line1);
	SDL_FreeSurface(Line2);
	SDL_FreeSurface(Line3);
	SDL_FreeSurface(Line4);
	SDL_FreeSurface(Win_CSKA);
	SDL_FreeSurface(Win_Spartak);
	SDL_FreeSurface(Nichya);
	SDL_DestroyWindow(window);

	return 0;
}