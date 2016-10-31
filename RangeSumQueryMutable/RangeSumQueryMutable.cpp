// RangeSumQueryMutable.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;


class NumArray {
public:
	struct tagSegmentTreeNode {
		int start, end; // 区间
		int sum; // 属性

		//
		// 树
		//
		tagSegmentTreeNode* left;
		tagSegmentTreeNode* right;

		tagSegmentTreeNode(int start, int end)
		{
			this->start = start;
			this->end = end;
			this->left = NULL;
			this->right = NULL;
			this->sum = 0;
		};

	}*root_;

	tagSegmentTreeNode* buildTree(const vector<int>& nums, int start, int end)
	{
		if (start > end)
		{
			return NULL;
		}
		else
		{
			tagSegmentTreeNode* tree = new tagSegmentTreeNode(start, end);
			if (start == end)
			{
				tree->sum = nums[start];
			}
			else
			{
				int mid = start + (end - start) / 2;
				tagSegmentTreeNode* lsubtree = buildTree(nums, start, mid);
				tagSegmentTreeNode* rsubtree = buildTree(nums, mid+1, end);
				tree->left = lsubtree;
				tree->right = rsubtree;
				tree->sum = lsubtree->sum + rsubtree->sum;
			}

			return tree;
		}
	}

	void update(tagSegmentTreeNode* root, int pos, int val)
	{
		if (root->start == root->end)
		{
			root->sum = val;
		}
		else
		{
			int mid = root->start + (root->start + root->end) / 2;
			if (pos <= mid)
			{
				update(root->left, pos, val);
			}
			else
			{
				update(root->right, pos, val);
			}
			root->sum = root->left->sum + root->right->sum;
		}
	}

	int sumRange(tagSegmentTreeNode* root, int start, int end)
	{
		if (root->start == start && root->end == end)
		{
			return root->sum;
		}
		else
		{
			int mid = root->start + (root->end - root->start) / 2;
			if (end <= mid)
			{
				return sumRange(root->left, start, end);
			}
			else if (start >= mid + 1)
			{
				return sumRange(root->right, start, end);
			}
			else
			{
				return sumRange(root->left, start, mid) + sumRange(root->right, mid + 1, end);
			}
		}
	}

	NumArray(vector<int> &nums) {
		root_ = buildTree(nums, 0, nums.size() - 1);
	}

	void update(int i, int val) {
		update(root_, i, val);
	}

	int sumRange(int i, int j) {
		return sumRange(root_, i, j);
	}
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);


int main()
{
	vector<int> nums;

	nums.push_back(0);
	nums.push_back(9);
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(3);

	NumArray numArray(nums);

	numArray.sumRange(4, 4);

    return 0;
}