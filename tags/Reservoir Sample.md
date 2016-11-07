# [Reservoir Sampling](https://en.wikipedia.org/wiki/Reservoir_sampling)

## 1	Example: sample size 1
 - Keep first item in memory
 - When the <i>i</i>-th item arrives (for <b><i>i</i> > 1</b>)
 - with probability <b>1 / <i>i</i></b>, keep the new item (discard the old one)

So
 - when there is only one item, it is kept with probability 1
 - when there are 2 items, each of them is kept with probability 1/2
 - when there are 3 items, the third item is kept with probability 1/3, and each of the previous 2 items is also kept with probablity (1/2)(1-1/3) = 1/3
 - by induction, each item is kept with probability 1 / <i>n</i>

## 2	Algorithm R
## 3	Reservoir with Random Sort
## 4	Weighted Random Sampling using Reservoir
### 4.1	Algorithm A-Res
### 4.2	Algorithm A-Chao
## 5	Distributed Reservoir Sampling
## 6	Relation to Fisher-Yates shuffle
## 7	Fast Approximation
## 8	Example implementation
## 9	Statistical properties
## 10	Limitations
## 11	See also
## 12	References