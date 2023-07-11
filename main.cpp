#include <iostream>       // std::cout

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int * a = new int [n];
    for (int i = 0; i < n; ++i ) {
        cin >> a[i];
        a[i] --;
    }

    int * solution = new int [n];
    for (int i = 0; i < n; ++i ) {
        solution[i] = n + 1;
    }
    
    int * q = new int [n];
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
        cout << solution[i] << " ";
    }
    
    return 0;
}
