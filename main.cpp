#include <vector>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int dur = 0;
        priority_queue <int> durations;
        sort(courses.begin(),courses.end(),[](const vector <int> &a,const vector <int> &b)
        {
            return a[1] < b[1];
        });
        for (int i = 0;i<courses.size();i++){
            int di = courses[i][0];
            int last = courses[i][1];
            dur += di;
            durations.push(di);
            if (dur > last){
                dur -= durations.top();
                durations.pop();
            }

        }
        return durations.size();
    }
};
