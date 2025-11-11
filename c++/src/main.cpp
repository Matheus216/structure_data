#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void include_vertex(vector<vector<int>> &graph, int base, int adjacent)
{
    graph[base].push_back(adjacent);
    graph[adjacent].push_back(base);
}

int breadth_first_search(vector<vector<int>>& graph, int target) {
    
    int size = graph.size(); 
    queue<int> queue;

    vector<bool> visited(size, false);

    visited[target] = true; 

    queue.push(visited[target]); 

    while (!queue.empty()) {
        int actualIndex = queue.front();
        queue.pop();
        cout << "Actual: " << actualIndex; 

        for (int item : graph[actualIndex]) {
            if (!visited[item]) {
                cout << "Vertex: " << item << "\n";
                visited[actualIndex] = true;
                queue.push(item); 
            }
        }

        cout << endl; 
    }

    return 1;
}  

int main()
{
    int v = 0, a = 0, maxCompare = 0, operation = 0;
    bool control = 1;
    vector<vector<int>> graph(v);

    while (control)
    {
        cout << "What operation do you want do? \n";
        cout << "1 - Add \n";
        cout << "2 - Read \n";
        cout << "3 - Delete \n";
        cout << "-1 - Out \n";

        cin >> operation;

        switch (operation)
        {
            case 1:
                cout << "Give me origin vertex to connect: \n";
                cin >> v;
                if (v < 0)
                    break;

                cout << "Give me adjacent vertex: \n";
                cin >> a;
                if (a < 0 || a == v)
                    break;

                maxCompare = max(a, v);
                if (maxCompare > graph.capacity())
                    graph.resize(maxCompare + 1);

                include_vertex(graph, v, a);
                break;
            case 2:
                breadth_first_search(graph, 0); 
                break; 
            default:
                graph.clear();
                control = false;
                break;
        }
    }

    return 0;
}