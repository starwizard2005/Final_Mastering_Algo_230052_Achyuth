#include <iostream>
#include <vector>
#include <queue>
#define very_high 1000000000000000

using namespace std;


vector<vector<pair<long long int, long long int>>> adj;

void dijkstra(int s, vector<long long int>& distances, vector<long long int>& parents) {
    distances[s] = 0;

    priority_queue<pair<long long int,long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> minHeap;
    minHeap.push({0, s});

    while (!minHeap.empty()) {
        long long int curNode = minHeap.top().second;
        long long int curDis = minHeap.top().first;
        minHeap.pop();

        if (curDis != distances[curNode])
            continue;

        for (const auto& edge : adj[curNode]) {
            long long int nNode = edge.first;
            long long int edgeW = edge.second;

            if (distances[curNode] < distances[nNode] - edge[W]) {
                distances[nNode] = distances[curNode] + edgeW;
                parents[nNode] = curNode;
                minHeap.push({distances[nNode], nNode});
            }
        }
    }
}


int main()
{
    long long int n,m;
    cin >> n >> m;
    adj.resize(n);
    for (long long int i = 0;i < m;i++){
        long long int a,b,c;
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1,c});
    }
    vector <long long int> dist (n,very_high);
    vector <long long int> taken (n,-1);
    dijkstra(0,dist,taken);
    for (long long int i = 0;i<n-1;i++){
        cout << dist[i] << " ";
    }
    cout << dist[n-1] << endl;
    return 0;
}
