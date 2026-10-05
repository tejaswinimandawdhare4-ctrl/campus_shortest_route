#include <stdio.h>
#include <string.h>

#define MAX 20
#define INF 9999

char location[MAX][50];
int graph[MAX][MAX];
int n = 0;
int source = -1;

void displayMatrix()
{
    int i, j;
    if (n == 0)
    {
        printf("\nPlease enter the campus graph first.\n");
        return;
    }
    printf("\nAdjacency Matrix:\n\n");
    printf("%-20s", "");
    for (i = 0; i < n; i++)
        printf("%-10d", i + 1);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%-20s", location[i]);
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == INF)
                printf("%-10s", "INF");
            else
                printf("%-10d", graph[i][j]);
        }
        printf("\n");
    }
}

void enterGraph()
{
    int i, j, weight;
    printf("\nEnter number of locations: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter name of location %d: ", i + 1);
        scanf(" %[^\n]", location[i]);
    }
    printf("\nEnter distances between locations.\n");
    printf("Enter 0 if there is no direct connection.\n");
    printf("Enter -1 for diagonal elements.\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                graph[i][j] = 0;
            }
            else
            {
                printf("Distance from %s to %s: ",
                       location[i], location[j]);
                scanf("%d", &weight);

                if (weight == 0)
                    graph[i][j] = INF;
                else
                    graph[i][j] = weight;
            }
        }
    }
    printf("\nCampus graph entered successfully.\n");
}

void selectSource()
{
    int choice;
    if (n == 0)
    {
        printf("\nPlease enter the campus graph first.\n");
        return;
    }
    printf("\nCampus Locations:\n");
    for (int i = 0; i < n; i++)
        printf("%d. %s\n", i + 1, location[i]);
    printf("\nEnter source location number: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > n)
    {
        printf("Invalid location number.\n");
        source = -1;
        return;
    }
    source = choice - 1;
    printf("Source location selected: %s\n", location[source]);
}

void dijkstra(int dist[], int visited[], int parent[])
{
    int i, j, min, u;
    for (i = 0; i < n; i++)
    {
        dist[i] = graph[source][i];
        visited[i] = 0;
        if (graph[source][i] != INF && i != source)
            parent[i] = source;
        else
            parent[i] = -1;
    }
    dist[source] = 0;
    for (i = 0; i < n - 1; i++)
    {
        min = INF;
        u = -1;
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }
        if (u == -1)
            break;
        visited[u] = 1;
        for (j = 0; j < n; j++)
        {
            if (!visited[j] &&
                graph[u][j] != INF &&
                dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
                parent[j] = u;
            }
        }
    }
}

void printPath(int parent[], int vertex)
{
    if (vertex == -1)
        return;
    if (parent[vertex] != -1)
    {
        printPath(parent, parent[vertex]);
        printf(" -> ");
    }
    printf("%s", location[vertex]);
}

void displayShortestPaths()
{
    int dist[MAX], visited[MAX], parent[MAX];
    if (n == 0)
    {
        printf("\nPlease enter the campus graph first.\n");
        return;
    }
    if (source == -1)
    {
        printf("\nPlease select a source location first.\n");
        return;
    }
    dijkstra(dist, visited, parent);
    printf("\nSource Location: %s\n", location[source]);
    printf("\n%-25s %-20s %-40s\n", "Destination", "Shortest Distance", "Shortest Path");
    for (int i = 0; i < n; i++)
    {
        if (i == source)
            continue;
        printf("%-25s ", location[i]);
        if (dist[i] == INF)
        {
            printf("%-20s ", "INF");
            printf("No path available");
        }
        else
        {
            printf("%-20d ", dist[i]);
            printPath(parent, i);
        }
        printf("\n");
    }
}

void displayDistances()
{
    int dist[MAX], visited[MAX], parent[MAX];
    if (n == 0)
    {
        printf("\nPlease enter the campus graph first.\n");
        return;
    }
    if (source == -1)
    {
        printf("\nPlease select a source location first.\n");
        return;
    }
    dijkstra(dist, visited, parent);
    printf("\nShortest distances from %s:\n\n", location[source]);
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            printf("%-25s : No path\n", location[i]);
        else
            printf("%-25s : %d\n", location[i], dist[i]);
    }
}

int main()
{
    int choice;
    do
    {
        printf("CAMPUS SHORTEST ROUTE FINDER\n");
        printf("DIJKSTRA'S ALGORITHM\n");

        printf("1. Enter Campus Graph\n");
        printf("2. Display Adjacency Matrix\n");
        printf("3. Select Source Location\n");
        printf("4. Find Shortest Distance\n");
        printf("5. Display Shortest Paths\n");
        printf("6. Display Distance from Source to All Locations\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enterGraph();
                break;
            case 2:
                displayMatrix();
                break;
            case 3:
                selectSource();
                break;
            case 4:
                if (source == -1)
                    printf("\nPlease select a source location first.\n");
                else
                    displayShortestPaths();
                break;
            case 5:
                displayShortestPaths();
                break;
            case 6:
                displayDistances();
                break;
            case 7:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 7);
    return 0;
}
