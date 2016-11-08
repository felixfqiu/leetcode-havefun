## <b>Skyline Problem <u>hard</u> <u>24.9%</u></b>
### 思路
#### <i>考虑两两线段？四种情况</i>
 - 分段（线段间有间隔）
 - 连接（线段等高）
 - 合并（不等高，两者简单重叠）
 - 插入（后者被前者覆盖，插入）

#### <i>矩形与顶点^[1]</i>
 - 按照一个矩形一个矩形来处理将会非常麻烦
 - 矩形拆成两个点，一个左上顶点，一个右上顶点
 - 横坐标排序

#### <i>堆^[1]</i>
 - 堆：当前图形的最高位置
 - 堆中先加入一个零点高度，帮助我们在只有最矮的建筑物时选择最低值
 - 堆顶是所有顶点中最高的点，只要这个点没被移出堆，说明这个最高的矩形还没结束
 - 左顶点，我们将其加入堆中
 - 右顶点，我们找出堆中其相应的左顶点，然后移出这个左顶点
 - 代码中，为了在排序后的顶点列表中区分左右顶点，左顶点的值是正数，而右顶点值则存的是负数

#### <i>堆：multiset^[2]</i>
 - 提供erase操作
 - multiset内的数据是按BST排好序的

[1] [segmentfault.com](https://segmentfault.com/a/1190000003786782)  
[2] [cnblogs.com/easonliu](http://www.cnblogs.com/easonliu/p/4531020.html)

---
### Discuss

#### <i>Multiset</i>
##### <i>[C++ 69ms 19 lines O(nlogn) clean solution with comments](https://discuss.leetcode.com/topic/60984/c-69ms-19-lines-o-nlogn-clean-solution-with-comments)</i>
 - <b>use walls to record buildings</b>
 - left wall is an <u>insertion</u> event
 - and right wall is a <u>deletion</u> event
 - sort(_beging, _end);
 - insert/eras
```
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
```

---
##### <i>[My C++ code using one priority queue](https://discuss.leetcode.com/topic/14939/my-c-code-using-one-priority-queue-812-ms)</i>
 - <s>compare</s>
 - <b>live building ？</b>


