// CountOfSmallerNumbersAfterSelf.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	struct Node {
		Node(int v) : val(v) {
			leftcount = 0;
			l = NULL;
			r = NULL;
		}
		int val;
		int leftcount; // 左子树节点个数
		Node* l;
		Node* r;
	};

	class Tree {
		//
		// treefree
		//
		void treefree(Node* nd) {
			if (nd != NULL) {
				treefree(nd->l);
				treefree(nd->r);
				delete nd;
				nd = NULL;
			}
		}

		Node* root_;

	public:
		Tree() {
			root_ = NULL;
		}

		~Tree() {
			treefree(root_);
		}

		//
		// grown
		//
		int grown(int val) {
			if (root_ == NULL) {
				root_ = new Node(val);
				return 0;
			}

			Node* cur = root_;
			Node* p = root_;
			bool toleft = true;
			int small = 0;

			while (cur != NULL)
			{
				p = cur;

				if (val <= cur->val)
				{
					cur->leftcount++;

					toleft = true;
					cur = cur->l;
				}
				else
				{
					small += cur->leftcount + 1;

					toleft = false;
					cur = cur->r;
				}
			}

			if (toleft)
			{
				p->l = new Node(val);
			}
			else
			{
				p->r = new Node(val);
			}

			return small;
		}
	};

	vector<int> countSmaller(vector<int>& nums) {
		int size = nums.size();

		vector<int> result(size, 0);
		Tree tree;

		for (int i = size - 1; i >= 0; i--) {
			result[i] = tree.grown(nums[i]);
		}

		return result;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(5);
	nums.push_back(2);
	nums.push_back(6);
	nums.push_back(1);

	Solution solution;
	solution.countSmaller(nums);

    return 0;
}

