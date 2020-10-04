#include<stdio.h>
#include<windows.h>
#include<conio.h>
void setcursor(bool);
void setcolor(int, int);
void gotoxy(int, int);
void erase_ship(int, int);
void draw_ship(int, int);
int main() 
{
    setcursor(0);
    char ch = ' ';
    int x = 38, y = 20;
    draw_ship(x, y);
    int direction_x = 0;
    int direction_y = 0;
    bool bulletStatus = false;
    int xbullet, ybullet, maxbullet = 5;
    do {
        if (_kbhit())
        {
            ch = _getch();
            if (ch == 'a')
            {
                direction_x = -1;
            }
            if (ch == 'd')
            {
                direction_x = 1;
            }
            if (ch == 's')
            {
                if (direction_x == 0)
                {
                    direction_y = 1;
                }
                direction_x = 0;
            }
            if (ch == 'w')
            {
                if (direction_x == 0)
                {
                    direction_y = -1;
                }
            }
            if (ch == ' ' && !bulletStatus) {
                bulletStatus = true;
                xbullet = x + 2, ybullet = y;
                maxbullet--;
            }
            fflush(stdin);
        }
        if (bulletStatus && maxbullet >= 0) 
        {
            gotoxy(xbullet, (ybullet != y) ? ybullet : ybullet - 1);
            setcolor(0, 0);
            printf(" ");
            if (ybullet > 0) {
                gotoxy(xbullet, --ybullet);
                setcolor(6, 0);
                printf("*");
            }
            else bulletStatus = false;
        }
        if (direction_x != 0 && x + direction_x >= 0 && x + direction_x <= 80)
        {
            erase_ship(x, y);
            draw_ship(x += direction_x, y);
        }
        if (direction_y != 0 && y + direction_y >= 0 && y + direction_y <= 24)
        {
            erase_ship(x, y);
            draw_ship(x += direction_x, y += direction_y);
            direction_y = 0;
        }
        Sleep(100);
    } while (ch != 'x');
    setcolor(7, 0);
    return 0;
}
void setcolor(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void gotoxy(int x, int y)
{
    COORD c = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void erase_ship(int x, int y)
{
    gotoxy(x, y);
    setcolor(0, 0);
    printf("     ");
}
void draw_ship(int x, int y)
{
    gotoxy(x, y);
    setcolor(2, 4);
    printf("<-0->");
}
void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}