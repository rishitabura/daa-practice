#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES];
bool included[MAX_VERTICES];
// Function to find Vertex Cover using the APPROX-VERTEX_COVER algorithm
void approxVertexCover(int vertices, int edges)
{
    bool edgesRemaining[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            edgesRemaining[i][j] = graph[i][j];
        }
    }
    while (edges > 0)
    {
        int u, v;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (edgesRemaining[i][j])
                {
                    u = i;
                    v = j;
                    break;
                }
            }
        }
        included[u] = included[v] = true;
        for (int i = 0; i < vertices; i++)
        {
            edgesRemaining[u][i] = edgesRemaining[i][u] = false;
            edgesRemaining[v][i] = edgesRemaining[i][v] = false;
        }
        edges--;
    }
}
int main()
{
    int vertices = 6;
    int edges = 6;
    int edgesData[6][2] = {{1, 2}, {2, 3}, {2, 5}, {3, 4}, {4, 5}, {5, 6}};
    for (int i = 0; i < edges; i++)
    {
        int u = edgesData[i][0];
        int v = edgesData[i][1];
        graph[u][v] = graph[v][u] = 1;
    }
    for (int i = 1; i < edges; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    approxVertexCover(vertices, edges);
    printf("Vertex Cover: ");
    for (int i = 1; i <= vertices; i++)
    {
        if (included[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}