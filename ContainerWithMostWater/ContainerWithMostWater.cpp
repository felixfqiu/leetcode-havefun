// ContainerWithMostWater.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int area(vector<int>& height, int l, int r)
{
	int h = min(height[r], height[l]);
	return (r - l) * h;
}

int maxArea(vector<int>& height)
{
	vector<int>& h = height;
	int l = 0;
	int r = height.size() - 1;
	int s = 0;

	while (r > l)
	{
		s = max(area(height, l, r), s);
		height[l] < height[r] ? l++ : r--;
	}

	return s;
}

int main()
{
	vector<int> height{2,3,4,5,18,17,6};

	int area = maxArea(height);
    return 0;
}

