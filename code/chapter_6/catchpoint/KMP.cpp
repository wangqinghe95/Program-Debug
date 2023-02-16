#include<cstdio>
#include<cstring>
#include<cstdlib>
const int maxn = 1000100;

int KMP(char *string, char *pattern);
void buildMatch(char *pattern, int *match);

int main()
{   
    char *string = "abcabcabcabcacabxy";
    char *pattern = "abcabcacab";

    printf("result : %d\n", KMP(string, pattern));
    
    return 0;
}

int KMP(char *string, char *pattern)
{
    int n = strlen(string);
    int m = strlen(pattern);
    
    if (n < m)
    {
        return -1;
    }
    int *match = (int *)malloc(sizeof(int) * m);
    
    buildMatch(pattern, match);
    
    int s = 0;
    int p = 0;
    while (s < n && p < m)
    {
        if (string[s] == pattern[p])
        {
            s++;
            p++;
        }
        else if(p > 0)
        {
            p = match[p-1] + 1;
        }
        else
        {
            s++;
        }
    }
    
    return (p == m) ? (s - m) : -1;
}

void buildMatch(char *pattern, int *match)
{
    int m = strlen(pattern);
    match[0] = -1;
    
    for (int j = 1; j < m; j++)
    {
        int i = match[j-1];
        while( (i >= 0) && (pattern[i + 1] != pattern[j]) )
        {
            i = match[i];
        }
        
        if (pattern[i + 1] == pattern[j])
        {
            match[j] = i + 1;
        }
        else
        {
            match[j] = -1;
        }
    }
}