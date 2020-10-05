#include "session12_WarshallsFloyds.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define min(a,b)            (((a) < (b)) ? (a) : (b))

double time_elapsed(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec);				  //diff of tv_sec
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
	return t;
}

void transitive_closure_warshalls(int **g, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", g[i][j]);
        printf("\n");
    }
}

void all_pairs_shortest_path_distances_floyds(int **g, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", g[i][j]);
        printf("\n");
    }
}

int main()
{
    int size;
    scanf("%d", &size);
    int **g = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        g[i] = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++)
            scanf("%d", &g[i][j]);
    }

    struct timespec start, end;

	// Test case 1
	clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
	transitive_closure_warshalls(g, size);
	clock_gettime(CLOCK_REALTIME, &end); //Stop timestamp

    printf("%lf seconds spent on Warshall's algorithm.\n\n", time_elapsed(start, end));

    scanf("%d\n", &size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            scanf("%d", &g[i][j]);
    }

    // Test case 2
	clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
	all_pairs_shortest_path_distances_floyds(g, size);
	clock_gettime(CLOCK_REALTIME, &end); //Stop timestamp

    printf("%lf seconds spent on Floyd's algorithm.\n", time_elapsed(start, end));

    for (int i = 0; i < size; i++)
        free(g[i]);
    free(g);

    return 0;
}
