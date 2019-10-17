﻿// 198_rob.cpp : 定义控制台应用程序的入口点。
//
/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
	 示例 2:

	 输入: [2,7,9,3,1]
	 输出: 12
	 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
	      偷窃到的最高金额 = 2 + 9 + 1 = 12 。

		  来源：力扣（LeetCode）
		  链接：https://leetcode-cn.com/problems/house-robber
		  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "stdafx.h"
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
	if (nums.size() == 0)return 0;
	if (nums.size() == 1)return nums[0];
	//if(nums.size()==2)return (nums[0]>nums[1]?nums[0]:nums[1]);
	vector<int> dp(nums.size(), 0);
	dp[0] = nums[0];
	dp[1] = nums[1];
	int max = dp[0] > dp[1] ? dp[0] : dp[1];
	for (int i = 2; i < nums.size(); i++)
	{
		if (i > 2 && dp[i - 2] < dp[i - 3])dp[i] = nums[i] + dp[i - 3];
		else dp[i] = nums[i] + dp[i - 2];
		if (max < dp[i])max = dp[i];
		//cout << dp[i] <<" ";
	}
	return max;
}

int main()
{
    return 0;
}

