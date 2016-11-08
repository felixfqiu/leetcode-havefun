// Skyline.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)
	{
		vector<pair<int, int>> walls;
		vector<pair<int, int>> ans;

		for (auto b : buildings) {
			walls.push_back(make_pair(b[0], -b[2]));
			walls.push_back(make_pair(b[1], b[2]));
		}

		sort(walls.begin(), walls.end());

		multiset<int> tops = { 0 };

		int top = 0;
		for (auto w : walls) {
			if (w.second < 0) {
				// left wall, insert the height
				tops.insert(-w.second);
			}
			else {
				tops.erase(tops.find(w.second));
			}

			if (top != *(tops.rbegin())) {
				top = *(tops.rbegin());

				ans.push_back(make_pair(w.first, top));
			}
		}

		return ans;
	}
};

int main()
{
	vector<int> b1;	b1.push_back(2), b1.push_back(9), b1.push_back(10);
	vector<int> b2;	b2.push_back(3), b2.push_back(7), b2.push_back(15);
	vector<int> b3;	b3.push_back(5), b3.push_back(12), b3.push_back(12);
	vector<int> b4;	b4.push_back(15), b4.push_back(20), b4.push_back(10);
	vector<int> b5;	b5.push_back(19), b5.push_back(24), b5.push_back(8);

	vector<vector<int>> buildings;
	buildings.push_back(b1);
	buildings.push_back(b2);
	buildings.push_back(b3);
	buildings.push_back(b4);
	buildings.push_back(b5);

	Solution sol;
	sol.getSkyline(buildings);

    return 0;
}

