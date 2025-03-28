#include <iostream>
#include <limits.h>
using namespace std;
int miniDist(int distance[], bool fin[]) // finding minimum distance
{
    int minimum = INT_MAX, ind;

    for (int k = 0; k < 6; k++)
    {
        if (fin[k] == false && distance[k] <= minimum)
        {
            minimum = distance[k];
            ind = k;
        }
    }
    return ind;
}
void DijkstraAlgo(int graph[6][6], int src) // adjacency matrix
{
    int distance[6]; // // array to calculate the minimum distance for each node
    bool fin[6];     // boolean array to mark visited and unvisited for each node

    for (int k = 0; k < 6; k++)
    {
        distance[k] = INT_MAX;
        fin[k] = false;
    }
    distance[src] = 0; // Source vertex distance is set 0

    for (int i = 0; i < 6; i++)
    {
        int m = miniDist(distance, fin);
        fin[m] = true;
        for (int k = 0; k < 6; k++)
        {
            // updating the distance of neighbouring vertex
            if (!fin[k] && graph[m][k] && distance[m] != INT_MAX &&
                distance[m] + graph[m][k] < distance[k])
                distance[k] = distance[m] + graph[m][k];
        }
    }
    cout << "Vertex\t\tDistance from source vertex" << endl;
    for (int k = 0; k < 6; k++)
    {
        char str = 65 + k;
        cout << str << "\t\t\t" << distance[k] << endl;
    }
}
int main()
{
    int graph[6][6] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};
    DijkstraAlgo(graph, 0);
    return 0;
}
