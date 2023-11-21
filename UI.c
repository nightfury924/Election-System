#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<unistd.h>
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = FALSE;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void colorit(int col)
{

    HANDLE hstdout;
    hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hstdout, col);
}
void border1(int x, int c)
{
	int i;
	for(i=0; i<x; i++)
	{
		gotoxy(x-i, 1);
		printf("%c", c);
		gotoxy(x+i, 1);
		printf("%c", c);
		usleep(1000);
	}
	for(i=0; i<30; i++)
	{
		gotoxy(1, i+1);
		printf("%c", c);
		gotoxy(130, i+1);
		printf("%c", c);
		usleep(1000);
	}
	for(i=0; i<=x; i++)
	{
		gotoxy(130-i, 31);
		printf("%c", c);
		gotoxy(1+i, 31);
		printf("%c", c);
		usleep(1000);
	}
}
void border2(int x, int c)
{
	int i;
	for(i=0; i<x; i++)
	{
		gotoxy(x-i, 1);
		printf("%c", c);
		gotoxy(x+i, 1);
		printf("%c", c);
	}
	for(i=0; i<30; i++)
	{
		gotoxy(1, i+1);
		printf("%c", c);
		gotoxy(130, i+1);
		printf("%c", c);
	}
	for(i=0; i<=x; i++)
	{
		gotoxy(130-i, 31);
		printf("%c", c);
		gotoxy(1+i, 31);
		printf("%c", c);
	}
}
void menu(int x, int c)
{
	int index=1;
	char key;
	while(key!=13)
	{
		gotoxy(x-6, 10);
		colorit(12);
		printf("TYPING TUTOR");
		gotoxy(x-6, 13);
		printf("                                      ");
		gotoxy(x-6, 13);
		colorit(15);
		if(index==1)
		{
			colorit(10);
		}
		printf("Select Modes");
		gotoxy(x-6, 14);
		printf("                                      ");
		gotoxy(x-6, 14);
		colorit(15);
		if(index==2)
		{
			colorit(10);
		}
		printf("Leaderboard");
		gotoxy(x-6, 15);
		printf("                                      ");
		gotoxy(x-6, 15);
		colorit(15);
		if(index==3)
		{
			colorit(10);
		}
		printf("Help");
		gotoxy(x-6, 16);
		printf("                                      ");
		gotoxy(x-6, 16);
		colorit(15);
		if(index==4)
		{
			colorit(10);
		}
		printf("Exit");
		colorit(15);
		border2(x, c);
		key=getch();
		if(key==80)
		{
			++index;
		}
		if(key==72)
		{
			--index;
		}
		if(index==5)
		{
			index=1;
		}
		if(index==0)
		{
			index=4;
		}
	}
	if(index==1)
	{
		int index=1;
		char key;
		while(key!=13)
		{
			gotoxy(x-6, 13);
			printf("                                      ");
			gotoxy(x-6, 13);
			colorit(15);
			if(index==1)
			{
				colorit(10);
			}
			printf("Typing speed test");
			gotoxy(x-6, 14);
			printf("                                      ");
			gotoxy(x-6, 14);
			colorit(15);
			if(index==2)
			{
				colorit(10);
			}
			printf("Typing tasks");
			gotoxy(x-6, 15);
			printf("                                      ");
			gotoxy(x-6, 15);
			colorit(15);
			if(index==3)
			{
				colorit(10);
			}
			printf("Typing Game");
			gotoxy(x-6, 16);
			printf("                                      ");
			gotoxy(x-6, 16);
			colorit(15);
			if(index==4)
			{
				colorit(10);
			}
			printf("Back");
			colorit(15);
			border2(x, c);
			key=getch();
			if(key==80)
			{
				++index;
			}
			if(key==72)
			{
				--index;
			}
			if(index==5)
			{
				index=1;
			}
			if(index==0)
			{
				index=4;
			}
		}
		if(index==1)
		{
			
		}
		if(index==2)
		{
			
		}
		if(index==3)
		{
			
		}
		if(index==4)
		{
			menu(x, c);
		}
	}
	if(index==2)
	{
		int index=1;
		char key;
		while(key!=13)
		{
			gotoxy(x-6, 13);
			printf("                                      ");
			gotoxy(x-6, 13);
			colorit(15);
			if(index==1)
			{
				colorit(10);
			}
			printf("Typing Tasks");
			gotoxy(x-6, 14);
			printf("                                      ");
			gotoxy(x-6, 14);
			colorit(15);
			if(index==2)
			{
				colorit(10);
			}
			printf("Typing Game");
			gotoxy(x-6, 15);
			printf("                                      ");
			gotoxy(x-6, 15);
			colorit(15);
			if(index==3)
			{
				colorit(10);
			}
			printf("Back");
			gotoxy(x-6, 16);
			printf("    ");
			colorit(15);
			border2(x, c);
			key=getch();
			if(key==80)
			{
				++index;
			}
			if(key==72)
			{
				--index;
			}
			if(index==4)
			{
				index=1;
			}
			if(index==0)
			{
				index=3;
			}
		}
		if(index==1)
		{
			
		}
		if(index==2)
		{
			
		}
		if(index==3)
		{
			menu(x, c);
		}
	}
	if(index==3)
	{
		int index=1;
		char key;
		while(key!=13)
		{
			gotoxy(x-6, 13);
			printf("                                      ");
			gotoxy(x-6, 13);
			colorit(15);
			if(index==1)
			{
				colorit(10);
			}
			printf("Typing tasks");
			gotoxy(x-6, 14);
			printf("                                      ");
			gotoxy(x-6, 14);
			colorit(15);
			if(index==2)
			{
				colorit(10);
			}
			printf("Typing Game");
			gotoxy(x-6, 15);
			printf("                                      ");
			gotoxy(x-6, 15);
			colorit(15);
			if(index==3)
			{
				colorit(10);
			}
			printf("Back");
			gotoxy(x-6, 16);
			printf("    ");
			colorit(15);
			border2(x, c);
			key=getch();
			if(key==80)
			{
				++index;
			}
			if(key==72)
			{
				--index;
			}
			if(index==4)
			{
				index=1;
			}
			if(index==0)
			{
				index=3;
			}
		}
		if(index==1)
		{
			
		}
		if(index==2)
		{
			
		}
		if(index==3)
		{
			menu(x, c);
		}
	}
	if(index==4)
	{
		system("taskkill/IM ConsolePauser.exe");
	}
}
int main()
{
    const char *txt = " TYPING TUTOR";
    int x = 65;
    int c = 42;
    int i,k;
    hideCursor();
    border1(x, c);
    colorit(12);
    for ( i = 0; 6-i>=0; i++)
    {
        usleep(1000);

        for ( k = 0; k < 8; k++)
        {
            gotoxy(x - i, 10);
           	printf("%c", txt[6 - i]);
            if (i < 8)
            {
                gotoxy(x + i, 10);
                printf("%c", txt[6 + i]);
            }
        }
	}
	colorit(15);
    gotoxy(53, 15);
    printf("PRESS ANY KEY TO CONTINUE ...");
    getch();
    system("cls");
    menu(x, c);
}
