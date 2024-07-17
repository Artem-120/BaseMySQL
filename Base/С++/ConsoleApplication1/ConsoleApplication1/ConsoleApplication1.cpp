// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
#include <iomanip>
#include <deque>
#include "stdio.h"
#include "math.h"
#include <locale>
#include "conio.h"


using  namespace std;
const int MAX = 8;
int dx[] = { 1,1,-1,-1,2,2,-2,-2 };
int dy[] = { 2,-2,2,-2,1,-1,1,-1 };

struct CELL
{
	int x, y;
	CELL(int a = -1, int b = -1) : x(a), y(b) {};
};
int operator==(CELL a, CELL b)
{
	return (a.x == b.x) && (a.y == b.y);
}
int operator!=(CELL a, CELL b)
{
	return !((a.x == b.x) && (a.y == b.y));
}
CELL EMPTY_CELL(-1, -1), Start(-1, -1), Finish(-1, -1);
CELL Parent[MAX][MAX];
char s[MAX][MAX];
int CanGo(CELL c)
{
	return !((c.x < 0) || (c.x >= n) || (c.y < 0) || (c.y >= n));
}
void bfs(CELL Start)
{
	deque < CELL > d;
	d.push_back(Start);
	s[Start.x][Start.y] = '#';
	while (!d.empty())
	{
		CELL Node = d.front(); d.pop_front();
		for (int k = 0; k < 8; k++)
		{
			CELL Next = CELL(Node.x + dx[k], Node.y + dy[k]);
			if (!CanGo(Next)) continue;
			{
				Parent[Next.x][Next.y] = Node;
				if (Next == Finish) return;
				d.push_back(Next);
			}
		}
	}
}
scanf("%d\n", &n);
for (i = 0; i < n; i++) gets(s[i]);
for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		if (s[i][j] == '@')
		{
			if (Start.x == -1) { Start.x = i; Start.y = j; }
			else { Finish.x = i; Finish.y = j; }
		}
bfs(Start);
if (Parent[Finish.x][Finish.y] == EMPTY_CELL) printf("Impossible\n");
else
{
	s[Start.x][Start.y] = '@';
	while (Start != Finish)
	{
		s[Finish.x][Finish.y] = '@';
		Finish = Parent[Finish.x][Finish.y];
	}
	for (i = 0; i < n; i++) puts(s[i]);
}