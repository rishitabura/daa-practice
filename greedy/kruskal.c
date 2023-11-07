#include <stdio.h>
#include <stdlib.h>

int i, j, k, a, b, u, v, n = 6, ne = 1;
int min, mincost = 0, cost[6][6] = {
    {0, 5, 0, 3, 0, 6},
    {5, 0, 2, 0, 0, 0},
    {0, 2, 0, 7, 0, 0},
    {3, 0, 7, 0, 4, 0},
    {0, 0, 0, 4, 0, 9},
    {6, 0, 0, 0, 9, 0}
};
int parent[6];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    printf("-----Kruskal's algorithm-----\n");
    printf("The edges of Minimum Cost Spanning Tree are\n");

    while (ne < n) {
        for (i = 0, min = 999; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min && cost[i][j] != 0) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v)) {
            printf("%d edge (%d,%d) = %d\n", ne++, a + 1, b + 1, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 0;
    }
    printf("Minimum cost = %d\n", mincost);

    return 0;
}
