// RotateArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k)
{
	int isize = nums.size();
	if (isize == 1)
	{
		return;
	}
	else if (k >= isize)
	{
		k = k%isize;		 
	}

	vector<int>::iterator _i = nums.begin();
	nums.insert(_i, _i + (isize - k), _i + isize);

	int jsize = nums.size();
	vector<int>::iterator _j = nums.begin();
	nums.erase( _j+isize, _j+jsize );
}

int main()
{
	vector<int> nums{1,2,3,4,5,6,7};
	rotate(nums, 3);

	for (int i=0; i<nums.size(); i++)
	{
		int val = nums[i];
		//
		//  TODO: 
		//
		int todo=0; todo++;
	}

    return 0;
}