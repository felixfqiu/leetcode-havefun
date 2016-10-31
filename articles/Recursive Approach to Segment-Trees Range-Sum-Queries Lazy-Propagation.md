#[Recursive Approach to Segment-Trees Range-Sum-Queries Lazy-Propagation](https://leetcode.com/articles/recursive-approach-segment-trees-range-sum-queries-lazy-propagation/#bonus)

#Note
##分而治之
 - 对数组分割为线段树，减少Update的开销
 - 根据不同的查询需要，记录子树的属性值

#[Step](https://discuss.leetcode.com/topic/29918/17-ms-java-solution-with-segment-tree/2)
 - tagSegmentTreeNode* root_;
 - BuildTree

#Q&A
 - 可无脑构造二分树？（输入数组大小就可得线段树的结构，再对每叶子节点赋值？）
 - 其他应用のPlanar Range Searching（[K-d tree/BBF](http://blog.csdn.net/v_july_v/article/details/8203674)？）
 - [Segment_tree](https://en.wikipedia.org/wiki/Segment_tree)？[Interval_tree](https://en.wikipedia.org/wiki/Interval_tree)？


#More
 - [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)
 - [Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/)