// #include <iostream>
// using namespace std;
// #define V 5

// void nextVertex(int k, int x[V], int G[V][V])
// {
//     do
//     {
//         x[k] = (x[k] + 1) % (V + 1);
//         cout << k << " " << x[k];
//         if (x[k] == 0)
//         {
//             return;
//         }
//         if (G[x[k - 1]][x[k]] != 0)
//         {
//             int j;
//             for (j = 1; j < k-1; j++)
//             {
//                 if (x[j] == x[k])
//                 {
//                     break;
//                 }
//             }
//             if (j == k )
//             {
//                 if (k < V || (k == V && G[x[V-1]][x[0]]) != 0)
//                 {
//                     return;
//                 }
//             }
//         }

//     } while (true);
// }

// void HC(int k, int x[V], int G[V][V])
// {
//     do
//     {
//         cout << "a\n";
//         nextVertex(k, x, G);
//         if (x[k] == 0)
//         {
//             return;
//         }
//         if (k == V-1)
//         {
//             for (int i = 0; i < V; i++)
//             {
//                 cout << x[i] << " ";
//             }
//         }
//         else
//         {
//             HC(k + 1, x, G);
//         }

//     } while (true);
// }

// int main()
// {
//     int G[V][V] = {
//         {0, 1, 1, 0, 1},
//         {1, 0, 1, 1, 1},
//         {1, 1, 0, 1, 0},
//         {0, 1, 1, 0, 1},
//         {1, 1, 0, 1, 0}};
//     int x[V] = {0};

//     HC(0, x, G);
//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;

#define V 5

void printSolution(const vector<int>& path);

bool isSafe(int v, bool graph[V][V], vector<int>& path, int pos) {
    if (!graph[path[pos - 1]][v])
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianCycleUtil(bool graph[V][V], vector<int>& path, int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]])
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1))
                return true;
            path[pos] = -1;
        }
    }

    return false;
}

bool hamiltonianCycle(bool graph[V][V]) {
    vector<int> path(V, -1);
    path[0] = 0;

    if (!hamiltonianCycleUtil(graph, path, 1)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    printSolution(path);
    return true;
}

void printSolution(const vector<int>& path) {
    cout << "Hamiltonian Cycle exists: ";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    cout << path[0] << endl;
}

int main() {
    bool graph[V][V] = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}};

    hamiltonianCycle(graph);

    return 0;
}