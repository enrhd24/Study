#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>


void intro();
void gotoxy(short x, short y);
void game_control(void);
void draw_check(int height, int width);

int main(void)
{
	intro();
	system("cls");
	game_control();
	return 0;
}

void intro(){
	printf("please push keyboard");
	getch();
}
void gotoxy(short x, short y) {
	COORD pos = { x-1, y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void draw_check(int height, int width)
{
	int i , j;
	unsigned char a = 0xa6;
    unsigned char b[20];

	for(i = 1; i < width; i++){
		b[i] = 0xa0 + i; 
		//특수문자 넣기 위한 배열 초기화
	}

	printf("%c%c", a, b[3]);
	for(i = 0; i < width; i++){
		printf("%c%c",a,b[8]);
	}
	printf("%c%c",a,b[4]);
	printf("\n"); 
	// 첫번째 출 입력

	for(i =0; i < height; i++)
	{
	printf("%c%c",a,b[7]);
	for(j=0;j<20; j++)
	{
	printf("%c%c",a,b[11]);
	} 
	printf("%c%c",a,b[9]);
	printf("\n");
	} // 중간째 줄 모두 입력

	printf("%c%c",a,b[6]);
	for(i=0; i< width; i++){
		printf("%c%c",a,b[10]);
	}
	printf("%c%c",a,b[5]);
	printf("\n");
	// 마지막 줄 입력
}


void game_control(void){
	int x = 1, y = 1, other = 0;
	char key;
	char *stone[2] = {"A","B"};
	do{
		 gotoxy(1,1);
		 draw_check(12, 20);
		 gotoxy(x,y);
		 printf("%s",stone[other]);
		 gotoxy(1,20);
		 key = getch();
	}while(1);
}