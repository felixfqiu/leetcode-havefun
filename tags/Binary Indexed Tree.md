# Contents
- Range Sum Query - Mutable
- Count of Smaller Numbers After Self
- ..\problems\Skyline.md

---
## <b>Range Sum Query - Mutable</b>
see ..\articles\Recursive Approach to Segment-Trees Range-Sum-Queries Lazy-Propagation.md

---
## <b>Count of Smaller Numbers After Self</b>
 - 涉及到动态二分排序的，考虑用binary tree

### <i>怎么被调用？</i>
 - 如下
```
vector<int> countSmaller(vector<int>& nums)
{
    vector<int> result;
    
    /*
    foreach i in nums
        result[i] = foo(tree, nums[i]);
    */
    
    return result;
}
```
 - 比较右侧与当前，所以应该从右往左 foreach
 - foo(tree, nums[i]) 改为 tree.grown(nums[i])
 - tree.grown(val) 从树的根节点开始生长（一级一级往下比较/插入）
 - cur == NULL 时，判断 val grown toleft？然后 gr->l 或 gr->r
 - = new Node(val)

### [asanchina.wordpress.com](https://asanchina.wordpress.com/2015/12/24/315-count-of-smaller-numbers-after-self/)
