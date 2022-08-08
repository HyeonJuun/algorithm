#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using lecture = pair<int, int>;

priority_queue<lecture, vector<lecture>, greater<lecture>> pq;
int main() {
	int n;
	cin >> n;
	vector<lecture> lectures(n);
	
	for (int i = 0; i < n; i++)
	{
		int ind, start_time, end_time;
		cin >> ind >> start_time >> end_time;
		lectures[i].first = start_time;
		lectures[i].second = end_time;
	}
	sort(lectures.begin(), lectures.end());

	int room_num = 0;
	for (int i = 0; i < n; i++)
	{
		if (pq.size() > 0)
		{
			if (pq.top().first > lectures[i].first)
			{
				room_num++;
			}
			else
				pq.pop();
		}
		else 
			room_num++;
		lecture add_lecture;
		add_lecture.first = lectures[i].second;
		add_lecture.second = lectures[i].first;
		pq.push(add_lecture);
	}
	cout << room_num << endl;
	return 0;
}
