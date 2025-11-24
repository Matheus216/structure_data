#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution
{
    public:
        int findCenterStart(vector<vector<int>>& edges) {
            int n = edges.size();
            vector<int> list(n * 2);

            for (int i = 0; i < n; i++)
            {
                list[edges[i][0]]++;
                list[edges[i][1]]++;
            }
            
            for (int i = 0; i <= n; i++)
                if(list[i] == n)
                    return i;

            return -1; 
        }

    public: 
        bool findPath(int n, vector<vector<int>>& edges, int source, int destination) {
            queue<int> toVisited;
            vector<bool> visited(n, false);
            
            vector<vector<int>> graph(n); 

            for(auto x : edges){
                graph[x[0]].push_back(x[1]); 
                graph[x[1]].push_back(x[0]);
            }

            toVisited.push(source); 

            while (!toVisited.empty()) {
                auto last = toVisited.front();
                toVisited.pop();

                if (visited[last]) continue;
                visited[source] = true;

                for (int x : graph[last]) {
                    if (!visited[x]) {
                        if (x == destination)
                            return true;
                        visited[x] = true;
                        toVisited.push(x);
                    }
                }
            }
            return false;
        }
};

int main()
{
    int n = 10, source = 5, destination = 9; 
    vector<vector<int>> inputVector = {{4,3},{1,4},{4,8},{1,7},{6,4},{4,2},{7,4},{4,0},{0,9},{5,4}};
    Solution s; 

    auto response = s.findPath(n,inputVector,source, destination); 
    cout << "result: " << response << "\n";

    return 1;
}