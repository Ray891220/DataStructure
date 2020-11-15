#include<iostream>
using namespace std;
#define mazesize  12

class Mouse {
public:
	int start1, start2;
	int end1, end2;
	void setStart(int i, int j)
	{
		start1 = i;
		start2 = j;
	}
	void setEnd(int i, int j)
	{
		end1 = i;
		end2 = j;
	}
	void go(int maze[mazesize][mazesize])
	{
		visit(maze, start1, start2);
	}
	void visit(int maze[mazesize][mazesize], int i, int j);
};
void Mouse::visit(int maze[mazesize][mazesize], int i, int j)
{
	maze[i][j] = 2;
	if (i == end1 && j == end2)
	{
		printf("\n找到出口\n");

		for (int i = 0; i < mazesize; i++)
		{
			printf("\t");
			for (int j = 0; j < mazesize; j++)
				if (maze[i][j] == 1)
					printf("■");
				else if (maze[i][j] == 2)
					printf("◇");
				else
					printf("　");
			printf("\n");
		}
	}
	if (maze[i][j + 1] == 0)
		visit(maze, i, j + 1);
	if (maze[i + 1][j] == 0)
		visit(maze, i + 1, j);
	if (maze[i][j - 1] == 0)
		visit(maze, i, j - 1);
	if (maze[i - 1][j]==0)
		visit(maze, i - 1, j);
	maze[i][j] = 0;
}
int  main()
{
	int maze[mazesize][mazesize] =
	{ {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	  {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	  {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
	  {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
	  {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1},
	  {1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
	  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
	  {1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
	  {1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
	  {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 ,1},
	  {1, 1 ,1, 1 ,1, 1, 1, 1, 1, 1, 1, 1} };
	printf("顯示迷宮\n");
	for (int i = 0; i < mazesize; i++)
	{
		printf("\t");
		for (int j = 0; j < mazesize; j++)
			if (maze[i][j] == 1)
				printf("■");
			else
				printf("　");
		printf("\n");
	}
	Mouse m1;
	m1.setStart(1, 1);
	m1.setEnd(mazesize - 2, mazesize - 2);
	m1.go(maze);
}
