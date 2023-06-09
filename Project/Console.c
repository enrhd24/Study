#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

void Init();
void GotoXY(short x, short y);
void Setcursor(BOOL Show);
void Clear(void);

int main(){
    Init(); // 초기화
    srand(time(NULL));

    double start, end;
    start = (double)clock()/CLOCKS_PER_SEC;
    
    int x = 52; int y = 22;
    int b_x = 25;
    int u_x[30] = {0,}, u_y[30] = {0,};
    BOOL Active[30] = {0,};
  
      for(;;){ 
        
        Clear();

        if(GetAsyncKeyState(VK_LEFT) & 0x8000){b_x--; if (b_x < 0) b_x = 0;}
		if(GetAsyncKeyState(VK_RIGHT) & 0x8000){b_x++; if (b_x > 50) b_x = 50;}
        for(int i = 0; i < 20; i++){
        if (!Active[i]) { u_x[i] = (rand() % 25) * 2; u_y[i] = 0; Active[i] = 1; break;}
		if (Active[i]) { 
            GotoXY(u_x[i], u_y[i]); 
            printf("o"); u_y[i]++;
            if (u_y[i] > y) { Active[i] = 0;}
                }
            }

        GotoXY(b_x,y);
        printf("A"); 
        Sleep(25);
        Setcursor(0);
        end = (((double)clock()) / CLOCKS_PER_SEC);
        
    }
    printf("score is %lf\n", (end-start));
    return 0;
}

void Clear(void){system("cls");}
void Init(){system("mode con cols=56 lines=20 | title GAMETITLE");}

void GotoXY(short x, short y) {
    COORD pos = { x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Setcursor(BOOL Show){
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = Show;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

