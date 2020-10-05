#include<string.h>

typedef struct
{
    int firstOccurrence;
    int lastOccurrence;
    int numOccurrences;
    int charactersCompared;
} Result;

/*
* Given the pattern fill the shift table used by Horspool's algorithm
* Table[pattern[i]] indicates the amount to be shifted when there is mismatch
* Initialize all the elements of Table with the length of the pattern    
* The table size can be 256
*/
int shiftTable[256];
Result result;

int max (int a, int b) { return (a > b)? a: b; } 

int *buildShiftTable(char *pattern){
    int i;
    int m=strlen(pattern);
    for(i=0;i<256;i++)
        shiftTable[i]=-1; 
    for(i=0;i<m;i++) 
        shiftTable[(int)pattern[i]]=i; 
    return shiftTable;
}

Result *horspoolStringMatch(char *pattern, char *text){
    int m=strlen(pattern); 
    int n=strlen(text); 
    buildShiftTable(pattern);
    result.firstOccurrence=-1;
    result.lastOccurrence=-1;
    result.numOccurrences=0;
    result.charactersCompared=0;
    result.charactersCompared+=1;
    int s=-1,k=0;
    while(s<=(n-m)){ 
        int j=m-1;
         
        while((j>=0)&&(pattern[j]==text[s+j])){
            result.charactersCompared+=1;
            j--;
        }
        if(j<0){
            if(k==0) 
                result.firstOccurrence=s;
            result.lastOccurrence=s;
            s+=(s+m<n)?m-shiftTable[(int)text[s+m]]:1; 
            result.numOccurrences+=1;
            k++;
        }
        else
            s+=max(1,j-shiftTable[(int)text[s+j]]); 
    }
    return &result;
    
}