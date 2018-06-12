#include <stdio.h>
#include <memory.h>

bool Search(int id, int* x, int* y);
bool CheckMap(int x, int y);



typedef struct BU
{
	int x;
	int y;
}VEC;


int g_Map[5][5] =


{

	{ -2,99,-2,-2,-2 },
	{ -2,99,-2,-2,-2 },
	{ -2,99,99,99,-2 },
	{ -2,-2,-2,-2,-2 },
	{ -1,-2,-2,-2,-2 },

};



void main()
{



	BU bu[30];

	memset(bu, 0xFF, sizeof(bu));


	Search(-1, &bu[0].x, &bu[0].y);

	int count = 0;

	BU point;


	while (count != 31)
	{


		for (count = 0; count < 30; count++)
		{

			if (bu[count].x != -1)
			{
				point = bu[count];
				memset(&bu[count], 0xFF, sizeof(BU));
				break;

			}

		}


		if (count >= 30)
			break;

		VEC vec[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 }, };

		for (int i = 0; i < 4; i++)
		{


			if (CheckMap(point.x + vec[i].x, point.y + vec[i].y) == true)
			{

				if (

					g_Map[point.y + vec[i].y][point.x + vec[i].x] == -2 ||
					g_Map[point.y + vec[i].y][point.x + vec[i].x] > g_Map[point.y][point.x] + 1

					)
				{
					g_Map[point.y + vec[i].y][point.x + vec[i].x] = g_Map[point.y][point.x] + 1;

					for (int j = 0; j < 30; j++)
					{
						if (bu[j].x == -1)
						{
							bu[j].x = point.x + vec[i].x;
							bu[j].y = point.y + vec[i].y;
							break;
						}

					}


				}

			}

		}

	}



	for (int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 5; j++)
		{

			printf("%2d,", g_Map[i][j]);

		}

		printf("\n");
	}


	getchar();
}



bool CheckMap(int x, int y)
{

	if (x < 0) return false;
	if (x > 5) return false;
	if (y < 0) return false;
	if (y > 5) return false;
	if (g_Map[y][x] == 99) return false;
	if (g_Map[y][x] == -1) return false;


	return true;

}

bool Search(int id, int* x, int* y)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (g_Map[i][j] == id)
			{
				*y = i;
				*x = j;
				return true;
			}


		}

	}

}