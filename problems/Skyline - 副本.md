## <b>Skyline Problem <u>hard</u> <u>24.9%</u></b>
### 思路
### [segmentfault.com](https://segmentfault.com/a/1190000003786782)
#### <i>矩形与顶点</i>
 - 按照一个矩形一个矩形来处理将会非常麻烦
 - 矩形拆成两个点，一个左上顶点，一个右上顶点
 - 横坐标排序

#### <i>堆</i>
 - 堆：当前图形的最高位置
 - 堆中先加入一个零点高度，帮助我们在只有最矮的建筑物时选择最低值
 - 堆顶是所有顶点中最高的点，只要这个点没被移出堆，说明这个最高的矩形还没结束
 - 左顶点，我们将其加入堆中
 - 右顶点，我们找出堆中其相应的左顶点，然后移出这个左顶点
 - 代码中，为了在排序后的顶点列表中区分左右顶点，左顶点的值是正数，而右顶点值则存的是负数

### [cnblogs.com/easonliu](http://www.cnblogs.com/easonliu/p/4531020.html)
#### <i>堆：multiset</i>
 - 提供erase操作
 - multiset内的数据是按BST排好序的

---
### 草稿
<s>
 - 输入数据的数据结构是典型的segment tree？

```
struct tagSTNode
{
    int start, end;
    int height;
}
```

#### <i>怎么被调用？</i>
</s>

#### <i>考虑两两线段？四种情况</i>
 - 分段（线段间有间隔）
 - 连接（线段等高）
 - 合并（不等高，两者简单重叠）
 - 插入（后者被前者覆盖，插入）

<s>
#### <i>存在左右插入、更新等情况，考虑用树结构</i>
 - treegrown/querySkyline
 - 还需要考虑height
 - <b>好麻烦！！！</b>
</s>

### Discuss
<s>
#### <i>Heap</i>
##### 190↑ <i>[(Guaranteed) Really Detailed and Good (Perfect) Explanation of The Skyline Problem](https://discuss.leetcode.com/topic/39416/guaranteed-really-detailed-and-good-perfect-explanation-of-the-skyline-problem/4)</i>
</s>

#### <i>Priority Queue</i>
##### 60↑ <i>[My C++ code using one priority queue](https://discuss.leetcode.com/topic/14939/my-c-code-using-one-priority-queue-812-ms)</i>
 - <s>compare</s>
 - <b>live building</b>

<s>
#### <i>Divide and Conquer</i>
##### 55↑ <i>[Share my divide and conquer java solution (c++ version)](https://discuss.leetcode.com/topic/16511/share-my-divide-and-conquer-java-solution-464-ms)</i>
 - merge
</s>

#### <i>Multiset</i>
<s>
##### 37↑ <i>[17-Line O(n log n)-time O(n)-space C++ Accepted Easy Solution w/ Explanations](https://discuss.leetcode.com/topic/25794/17-line-o-n-log-n-time-o-n-space-c-accepted-easy-solution-w-explanations)</i>
 - <b>multimap</b>
 - multimap::emplace (C++11)

##### 7↑ <i>[28 line of Code, My C++ solution (840ms) O(NlogN) with multiset and multimap](https://discuss.leetcode.com/topic/14868/28-line-of-code-my-c-solution-840ms-o-nlogn-with-multiset-and-multimap)</i>
 - insert
 - comp
 - <b>multimap</b>
</s>

##### 5↑ <i>[C++ 69ms 19 lines O(nlogn) clean solution with comments](https://discuss.leetcode.com/topic/60984/c-69ms-19-lines-o-nlogn-clean-solution-with-comments)</i>
 - <b>use walls to record buildings</b>
 - left wall is an <u>insertion</u> event
 - and right wall is a <u>deletion</u> event
 - sort(_beging, _end);
 - insert/eras