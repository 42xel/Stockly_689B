#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%i", &n);
    
    int * a = malloc(n * sizeof(int));
    int * solution = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i ) {
    scanf("%i", &a[i]);
        a[i]--;
        solution[i] = n + 1;
    }

    int * q = malloc(n * sizeof(int));
    int bot = 0;
    int top = 0;

    solution[0] = 0;
    q[bot] = 0;
    ++top;
    int b;

    while (bot != top){
        b = q[bot];
        if (b > 0)
        {
            if (solution[b - 1] > solution[b] + 1){
                solution[b - 1] = solution[b] + 1;
                q[top++] = b - 1;
            }
        }
        if (b < n-1)
        {
            if (solution[b + 1] > solution[b] + 1){
                solution[b + 1] = solution[b] + 1;
                q[top++] = b + 1;
            }
        }
        
        if (solution[a[b]] > solution[b] + 1){
            solution[a[b]] = solution[b] + 1;
            q[top++] = a[b];
        }
        
        ++bot;
    }

    for (int i = 0; i < n; ++i ) {
        printf("%i ", solution[i]);
    }
    free(a);
    free(q);
    free(solution);
    
    return 0;
}