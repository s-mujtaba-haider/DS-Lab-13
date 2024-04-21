#include <iostream>
#include <list>
#include<vector>
#include<string>
#include<queue>
using namespace std;
class Graph {
    int numVertices;
    list<int>* adjLists;
    bool* visited;
public:
    Graph(int vertices) {
        numVertices = vertices;
        adjLists = new list<int>[vertices];
    }
    void TakeInput(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }
    void ExploreFunction(int startVertex) {
        visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++)
            visited[i] = false;
        list<int> queue;
        visited[startVertex] = true;
        queue.push_back(startVertex);
        list<int>::iterator i;
        while (!queue.empty()) {
            int currVertex = queue.front();
            cout << "Visited : " << currVertex << endl;;
            queue.pop_front();
            for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
                int adjVertex = *i;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    queue.push_back(adjVertex);
                }
            }
        }
        cout << endl;
    }
    void Print() {
        for (int i = 0; i < numVertices; i++) {
            cout << i;
            for (auto x : adjLists[i]) {
                cout << " -> " << x;
            }
            cout << endl;
        }
    }
    void print() {
        for (int i = 1; i < numVertices; i++) {
            cout << i;
            for (auto x : adjLists[i]) {
                cout << " -> " << x;
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);
    g.TakeInput(0, 1);
    g.TakeInput(0, 2);
    g.TakeInput(1, 2);
    g.TakeInput(2, 0);
    g.TakeInput(2, 3);
    g.TakeInput(3, 3);
    cout << "Following is Breath First Traversal\n";
    g.ExploreFunction(2);
    cout << "BFS Tree" << endl;
    g.Print();
    Graph g1(6);
    g1.TakeInput(5, 3);
    g1.TakeInput(1, 2);
    g1.TakeInput(3, 4);
    g1.TakeInput(4, 5);
    cout << endl;
    cout << "Dis-Joint Vertices" << endl;
    g1.ExploreFunction(2);
    g1.print();
    return 0;
}