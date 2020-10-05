#include<stdbool.h>
#include "tsp.h"
#include <limits.h>
#include<stdlib.h>
#include<stdio.h>
#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif


static int* stack;
static int* treetracker;
static int index = 0;
int test = 0;
void arraycopy(int *a,int *b, int n){
    for(int i = 0; i<n; i++){
        b[i] = a[i];
    }
}

void create(int n)
{
    stack = (int*)malloc(sizeof(int)*n);
    treetracker = (int*)malloc(sizeof(int)*n);

    for(int i = 0; i<n; i++){
        stack[i]=0;
        treetracker[i] = 0;
    }
}




void tspBackTrackRecursively(int currPos, int n, int graph[][n], bool* visited, int count, int cost, int* minCost) 
{ 
    if(cost>*minCost){
        return;
    }
    printf("%d: %d \n",test++,currPos);
    if (count == n && graph[currPos][0]) { 
        
        if(*minCost>(cost + graph[currPos][0]))
	{
		arraycopy(treetracker,stack,n);

	}
        *minCost = min(*minCost, cost + graph[currPos][0]); 
        
    	return; 
	} 

	for (int i = 0; i < n; i++) { 
		if (!visited[i] && graph[currPos][i]) { 
            
            index++;
            treetracker[index] = i;
			visited[i] = true;              
			tspBackTrackRecursively( i, n,graph, visited, count + 1, cost + graph[currPos][i], minCost);                         
            index--;
            visited[i] = false; 
		} 

	}
}

int tspBackTrack(int n, int graph[][n]){
    bool v[n];
    for (int i = 0; i < n; i++) 
		v[i] = false; 

    v[0] = true; 
	int ans = INT_MAX; 
    create(n);

    tspBackTrackRecursively(0, n, graph, v, 1, 0, &ans); 
    
   // printf("\n%d\n\n",ans);
    return ans;
}

int *printPath(int n, int graph[][n]){
    
    return stack;
}
