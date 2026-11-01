// Extracted from DSA-9.pdf
#include <stdio.h>
#include <string.h>

#define MAX 20

char cities[MAX][50];
int graph[MAX][MAX];
int visited[MAX];
int n;
// Initialize graph
void initializeGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

// Display city names
void displayCities() {
    printf("\nCities:\n");

    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, cities[i]);
    }
}

// Add a flight between two cities
void addFlight() {
    int src, dest, cost;

    displayCities();

    printf("\nEnter source city number: ");
    scanf("%d", &src);

    printf("Enter destination city number: ");
    scanf("%d", &dest);


    if (src < 1 || src > n || dest < 1 || dest > n) {
        printf("Invalid city number!\n");
        return;
    }

    printf("Enter flight cost: ");
    scanf("%d", &cost);

    if (cost <= 0) {
        printf("Flight cost must be positive.\n");
        return;
    }

    // Undirected graph: flight available in both directions
    graph[src - 1][dest - 1] = cost;
    graph[dest - 1][src - 1] = cost;

    printf("Flight added successfully!\n");
}

// Display adjacency matrix
void displayGraph() {
    printf("\nAdjacency Matrix (Flight Costs):\n\n");

    printf("%-12s", "");

    for (int i = 0; i < n; i++) {
        printf("%-12s", cities[i]);
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%-12s", cities[i]);

        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 0)
                printf("%-12s", "-");
            else
                printf("%-12d", graph[i][j]);
        }

        printf("\n");
    }
}

// Depth-First Search
void DFS(int city) {

    visited[city] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[city][i] != 0 && !visited[i]) {
            DFS(i);
        }
    }
}

// Check graph connectivity
void checkConnectivity() {
    if (n == 0) {
        printf("No cities available.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    DFS(0);

    int connected = 1;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("\nThe graph is CONNECTED.\n");
    else
        printf("\nThe graph is NOT CONNECTED.\n");
}

// Display cities reachable from a selected city
void showReachableCities() {
    int start;

    displayCities();

    printf("\nEnter starting city number: ");
    scanf("%d", &start);

    if (start < 1 || start > n) {
        printf("Invalid city number!\n");

        return;
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    DFS(start - 1);

    printf("\nCities reachable from %s:\n", cities[start - 1]);

    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            printf("%s\n", cities[i]);
        }
    }
}

int main() {
    int choice;

    printf("Enter number of cities (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of cities!\n");
        return 1;
    }

    initializeGraph();

    // Input city names
    for (int i = 0; i < n; i++) {
        printf("Enter name of city %d: ", i + 1);
        scanf(" %49[^\n]", cities[i]);
    }

    do {
        printf("\n===== FLIGHT PATH GRAPH =====\n");
        printf("1. Add Flight\n");
        printf("2. Display Graph\n");
        printf("3. Check Connectivity\n");
        printf("4. Show Reachable Cities\n");
        printf("5. Display Cities\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;

        }

        switch (choice) {
            case 1:
                addFlight();
                break;

            case 2:
                displayGraph();
                break;

            case 3:
                checkConnectivity();
                break;

            case 4:
                showReachableCities();
                break;

            case 5:
                displayCities();
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
