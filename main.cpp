#include <iostream>
#include <vector>

using namespace std;

void searching(int x,vector <int> &vis, vector < vector <int> > &arr){
    vis[x] = 1;
    for (int i = 0;i<arr[x].size();i++){
        if (!vis[arr[x][i]]){
            searching(arr[x][i],vis,arr);
        }
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector <vector <int> > arr(n);
    vector <int> vis(n,0);
    for (int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        arr[a-1].push_back(b-1);
        arr[b-1].push_back(a-1);
    }
    vector <int> connecting_group;
    for (int i = 0;i<n;i++){
        if (!vis[i]){
            connecting_group.push_back(i);
            searching(i,vis,arr);
        }
    }
    int sz = connecting_group.size() - 1;
    cout << sz << endl;
    for (int i = 0;i<sz;i++){
        cout << connecting_group[i] + 1 << " " << connecting_group[i+1] + 1 << endl;
    }
    return 0;
}
