#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%i", &n);
    
    int * a = calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i ) {
    scanf("%i", a + i);
        a[i] --;
    }

    int * solution = calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i ) {
        solution[i] = n + 1;
    }

    int * q = calloc(n, sizeof(int));
    int bot = 0;
    int top = 0;

    solution[0] = 0;
    q[bot] = 0;
    ++top;

    while (bot != top){

        if (q[bot] > 0)
        {
            if (solution[q[bot] - 1] > solution[q[bot]] + 1){
                solution[q[bot] - 1] = solution[q[bot]] + 1;
                q[top++] = q[bot] - 1;
            }
        }
        if (q[bot] < n-1)
        {
            if (solution[q[bot] + 1] > solution[q[bot]] + 1){
                solution[q[bot] + 1] = solution[q[bot]] + 1;
                q[top++] = q[bot] + 1;
            }
        }
        
        if (solution[a[q[bot]]] > solution[q[bot]] + 1){
            solution[a[q[bot]]] = solution[q[bot]] + 1;
            q[top++] = a[q[bot]];
        }
        
        ++bot;
    }

    for (int i = 0; i < n; ++i ) {
        printf("%i ", solution[i]);
    }
    
    return 0;
}