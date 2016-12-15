#Two-pointer technique
 - one slow-runner and the other fast-runner.
 - one starts from the beginning and the other the end.
 - https://leetcode.com/articles/two-pointer-technique/

#Eg. Reverse the characters in a string
```
public void reverse(char[] str) {
    int n = str.length;
    for (int i = 0; i < n / 2; i++) {
        swap(str, i, n - i - 1);
    }
}
```
```
public void reverse(char[] str) {
    int i = 0, j = str.length - 1;
    while (i < j) {
        swap(str, i, j);
        i++;
        j--;
    }
}
```
 - which approach is less likely to introduce bugs ?

#More.
##0.0.1
###[Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
太阳底下没有什么新鲜事，勿妄自菲薄：）
##0.0.2
###[Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
lr一夹就OK了
###~~[Reverse Words in a String II](https://leetcode.com/problems/reverse-words-in-a-string-ii/)~~
~~花钱订阅~~
###[Rotate Array](https://leetcode.com/problems/rotate-array/)
insert, erase
###[Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
isalnum, tolower 标准函数
###[Container With Most Water](https://leetcode.com/problems/container-with-most-water/)
height[l] < height[r] ? l++ : r--;
##TODO：
###[Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)