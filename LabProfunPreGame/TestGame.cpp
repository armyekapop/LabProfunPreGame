#include<stdio.h>
#include<Windows.h>
#include<conio.h>
void draw_ship(int, int);
void erase_ship(int, int);
void setcursor(bool);
void setcolor(int, int);
void move();
void shoot(int, int);
void scr_bullet(int);
int main()
{
	system("COLOR E3");
	setcursor(0);
	char ch = ' ';
	int x = 38, y = 20;
	int x_shoot = x+3, y_shoot = y - 1;
	int bullet = 5;
	setcolor(2, 4);
	draw_ship(x, y);
	do
	{
		setcolor(2, 4);
		scr_bullet(bullet);
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'a' and x > 0)
			{
				while (x > 0)
				{
					if (_kbhit())
					{
						ch = _getch();
						if (ch == 's')
						{
							ch = ' ';
							break;
						}
					}
					setcolor(14, 14);
					erase_ship(x, y);
					setcolor(2, 4);
					draw_ship(--x, y);
					Sleep(70);
				}
			}
			if (ch == 'd' and x < 80)
			{
				while (x < 80)
				{
					if (_kbhit())
					{
						ch = _getch();
						if (ch == 's')
						{
							ch = ' ';
							break;
						}
					}
					setcolor(14, 14);
					erase_ship(x, y);
					setcolor(2, 4);
					draw_ship(++x, y);
					Sleep(70);
				}
			}
			if (ch == 'w' and y > 0)
			{
				setcolor(14, 14);
				erase_ship(x, y);
				setcolor(2, 4);
				draw_ship(x, --y);
			}
			if (ch == 's' and y < 24)
			{
				setcolor(14, 14);
				erase_ship(x, y);
				setcolor(2, 4);
				draw_ship(x, ++y);
			}
			y_shoot = y - 1;
			x_shoot = x + 3;
			if (ch == 'h' && bullet > 0)
			{
				bullet--;
				scr_bullet(bullet);
				while (y_shoot > 0)
				{
					setcolor(14, 14);
					erase_ship(x_shoot, y_shoot);
					setcolor(0, 14);
					shoot(x_shoot, --y_shoot);
					Sleep(100);
					if (y_shoot == 0)
					{
						setcolor(14, 14);
						erase_ship(x_shoot, 0);
					}
				}
			}
			fflush(stdin);
		}
		Sleep(70);
	} while (ch != 'x');
	return 0;
}
void move()
{
	char ch = ' ';
	int x = 38, y = 20;
	setcolor(2, 4);
	draw_ship(x, y);
	do
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'a' and x > 0)
			{
				while (x > 0)
				{
					if (_kbhit())
					{
						ch = _getch();
						if (ch == 's')
						{
							ch = ' ';
							break;
						}
					}
					setcolor(14, 14);
					erase_ship(x, y);
					setcolor(2, 4);
					draw_ship(--x, y);
					Sleep(70);
				}
			}
			if (ch == 'd' and x < 80)
			{
				while (x < 80)
				{
					if (_kbhit())
					{
						ch = _getch();
						if (ch == 's')
						{
							ch = ' ';
							break;
						}
					}
					setcolor(14, 14);
					erase_ship(x, y);
					setcolor(2, 4);
					draw_ship(++x, y);
					Sleep(70);
				}
			}
			if (ch == 'w' and y > 0)
			{
				setcolor(14, 14);
				erase_ship(x, y);
				setcolor(2, 4);
				draw_ship(x, --y);
			}
			if (ch == 's' and y < 24)
			{
				setcolor(14, 14);
				erase_ship(x, y);
				setcolor(2, 4);
				draw_ship(x, ++y);
			}
			fflush(stdin);
		}
		Sleep(70);
	} while (ch != 'x');
}
void draw_ship(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf(" <-0-> ");
}
void erase_ship(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("       ");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void shoot(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("*");
}
void scr_bullet(int bullet)
{
	COORD c = { 0,0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("BULLET : %d", bullet);
}