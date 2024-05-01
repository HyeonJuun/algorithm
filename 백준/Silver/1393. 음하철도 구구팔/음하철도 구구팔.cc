#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

float getDistance(float x1, float y1, float x2, float y2)
{
	float dist = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	return dist;
}
int checkValue(float x1, float y1, float x2, float y2, float i, float j)
{
	float a = (y2 - y1) / (x2 - x1);
	float b = -1;
	float c = a * (-1 * x1) + y1;
	if ((a * i) + (b * j) + c == 0)
		return 1;
	else
		return 0;
}
int main()
{
	float x1, x2, x3, y1, y2, y3;
	float distance;
	float min_distance = 142;
	float min_x = 0, min_y = 0;
	cin >> x3 >> y3;
	cin >> x1 >> y1 >> x2 >> y2;
	x2 = x1 + x2;
	y2 = y1 + y2;
	if (x2 - x1 == 0)
	{
		if (y2 - y1 > 0)
		{
			for (float i = y1; i < 100; i++)
			{
				distance = getDistance(x1, i, x3, y3);
				if (distance < min_distance)
				{
					min_distance = distance;
					min_x = x1;
					min_y = i;
				}
			}
		}
		else
		{
			for (float i = y1; i > -100; i--)
			{
				distance = getDistance(x1, i, x3, y3); 
				if (distance < min_distance)
				{
					min_distance = distance;
					min_x = x1;
					min_y = i;
				}
			}
		}
	}
	else if (y2 - y1 == 0)
	{
		if (x2 - x1 > 0)
		{
			for (float i = x1; i <= 100; i++)
			{
				distance = getDistance(i, y1, x3, y3);
				if (distance < min_distance)
				{
					min_distance = distance;
					min_x = i;
					min_y = y1;
				}
			}
		}
		else
		{
			for (float i = x1; i >= -100; i--)
			{
				distance = getDistance(i, y1, x3, y3); 
				if (distance < min_distance)
				{
					min_distance = distance;
					min_x = i;
					min_y = y1;
				}
			}
		}
	}
	else
	{
		float inclination = (y2 - y1) / (x2 - x1);
		if (inclination > 0) 
		{
			if (x2 - x1 < 0 && y2 - y1 < 0)
			{
				for (float i = x1; i >= -100; i--)
				{
					for (float j = y1; j >= -100; j--)
					{
						if (checkValue(x1, y1, x2, y2, i, j) == 1)
						{
							distance = getDistance(i, j, x3, y3);
							if (distance < min_distance)
							{
								min_distance = distance;
								min_x = i;
								min_y = j;				
							}
						}
					}
				}
			}
			else if (x2 - x1 > 0 && y2 - y1 > 0) 
			{
				for (float i = x1; i <= 100; i++)
				{
					for (float j = y1; j <= 100; j++)
					{
						if (checkValue(x1, y1, x2, y2, i, j) == 1)
						{
							distance = getDistance(i, j, x3, y3);
							if (distance < min_distance)
							{
								min_distance = distance;
								min_x = i;
								min_y = j;								
							}
						}
					}
				}

			}
		}
		else if (inclination < 0) 
		{
			if (x2 - x1 < 0) 
			{
				for (float i = x1; i >= -100; i--)
				{
					for (float j = y1; j >= -100; j--)
					{
						if (checkValue(x1, y1, x2, y2, i, j) == 1)
						{
							distance = getDistance(i, j, x3, y3);
							if (distance < min_distance)
							{
								min_distance = distance;
								min_x = i;
								min_y = j;								
							}
						}
					}
				}

			}
			else if (y2 - y1 < 0)
			{
				for (float i = x1; i <= 100; i++)
				{
					for (float j = y1; j <= 100; j++)
					{
						if (checkValue(x1, y1, x2, y2, i, j) == 1)
						{
							distance = getDistance(i, j, x3, y3);
							if (distance < min_distance)
							{
								min_distance = distance;
								min_x = i;
								min_y = j;								
							}
						}
					}
				}
			}
		}
	}
	cout << min_x << " " << min_y << endl;
}