/*84
题意：求直方图中最大的矩形面积

思路：比较直接的方式是，遍历数组，计算以每个值为起点的最大面积，取其最大值，如题中例子，值得注意的是，以2为起点，遍历到5时，应该是1*3=3，即取最小值相乘。但其时间复杂度为O(n^2)。于是上网找到了实验室小纸贴校外版的博客，其给出了时间复杂度为O(n)的算法。其主要的思想是：用一个栈来保存下标（索引），遇到比栈中下标对应的值大的高度时，就将这个这个高度的下标压入栈中，即保证栈中下标对应的高度是非降型的；遇到比栈中下标对应值小的高度，就计算此时的面积，和res比较，取较大值。为了保证到最后时依旧存在一个不升状态，即结束状态，要在height中压入一个0。下面结合自己的想法给出详细的说明。
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         int res=0;
	   if(heights.empty())return 0;
	   heights.push_back(0);
	   stack<int>index;
	   for(int i=0;i<heights.size();++i)
	   {
			  if(index.empty()||heights[i]>=heights[index.top()])index.push(i);
			  else
			  {
					 int temp=index.top();
					 index.pop();
					 res=max(res,heights[temp]*(index.empty()?i:(i-index.top()-1)));
					 i--;
			  }
	   }
	   return res;
    }
};
