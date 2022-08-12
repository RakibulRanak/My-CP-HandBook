#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	//dq will maintain decresing order,, high  > --- > low
	deque<int> dq;
	vector<int> ans;

	for (int i = 0; i < nums.size(); i++) {
		// when the i-k is out of current slide window, i-k should be popped
		if (!dq.empty() && dq.front() == i - k) dq.pop_front();
		while (!dq.empty() && nums[dq.back()] < nums[i])
			dq.pop_back();
		dq.push_back(i);
		// end of each slide, front of the queue is the answer
		if (i >= k - 1) ans.push_back(nums[dq.front()]);
	}
	return ans;
}

int main()
{

	vector<int>nums = { -1,-3,-2,10,-5,11,111 };
	vector<int>ans = maxSlidingWindow(nums, 3);
	for (auto x : ans)
		cout << x << " ";
	cout << endl;
	return 0;
}
