#include <vector>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>

using namespace std; 

// iterative way bfs search 
void breadth_first_search(vector<vector<int>>& graph, int n, vector<bool>& visited, int start) { 
    queue<int> toVisit;

    if (graph[start].empty() || visited[start]) 
        return;

    toVisit.push(start); 
    visited[start] = true; 

    while(!toVisit.empty()){ 
        int last = toVisit.front(); 
        toVisit.pop();
        
        std::cout << last << "\n"; 
         
        for (int actual : graph[last])
        {
            std::cout <<  "\t" << actual << "\n"; 
            if (!visited[actual]) {
                visited[actual] = true;
                toVisit.push(actual);
            }
        }
    }
}

// using recursive way 
void dfs(vector<vector<int>>& graph, vector<bool>& visited, int start) {
    if (visited[start]) return; 

    visited[start] = true; 

    cout << start << "\n"; 

    for (int actual : graph[start])
        dfs(graph, visited, actual);
}

// using iterative way
void dfs_iterative(vector<vector<int>>& graph, int n, int start) {
    stack<int> next; 
    vector<bool> visited(n + 1); 

    next.push(start);

    while(!next.empty()) {
        auto last = next.top();
        next.pop(); 

        if (visited[last]) continue; 

        cout << last << "\n"; 

        for (int i = 0; i < graph[last].size(); i++) {
            cout << "  " << graph[last][i];
            if (!visited[graph[last][i]])
                next.push(graph[last][i]);
        }
        cout << "\n";
        visited[last] = true;
    }
}

vector<vector<int>> convertVectorToGraph(vector<vector<int>>& input, int n) {
    vector<vector<int>> response(n); 

    for (vector<int> item : input) {
        response[item[0]].push_back(item[1]);
    }

    return response;
}


int findJugde(int n, vector<vector<int>>& trust) {
    vector<int> incoming(n + 1);
    vector<int> outcoming(n + 1);  

    int result = -1; 

    for(int i = 0; i < trust.size(); i++) {
        incoming[trust[i][0]]++; 
        outcoming[trust[i][1]]++; 
    }

    for (int i = 0; i < outcoming.size(); i++)
        if (outcoming[i] == n - 1 && incoming[i] == 0)
            result = i; 

    return result; 
}

int main() {

    std::vector<std::vector<int>> input = { 
        {1,2},
    };
    auto result = findJugde(2, input); 
    cout << "result: " << result << "\n";  

    // int n = 6; 
    // vector<bool> visited(n, false); 

    // auto graph = convertVectorToGraph(input, n);

    // cout << "BFS: \n";
    // for (int i = 0; i < n; i++)
    // {
    //     breadth_first_search(graph, n, visited, i); 
    // }
    
    // vector<bool> visited2(n, false); 

    // cout << "\n DFS Recursive: \n";
    // dfs(graph, visited2, 0);

    // cout << "\n DFS Iterative: \n";
    // dfs_iterative(graph, 5, 0); 
    // return 0;
}
