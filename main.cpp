#include <iostream>
#include <list>

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
    
    list<int> q = {0};
    solution[0] = 0;

    while (!q.empty()){
        int b = q.front();
        if (b > 0)
        {
            if (solution[b - 1] > solution[b] + 1){
                solution[b - 1] = solution[b] + 1;
                q.push_back(b - 1);
            }
        }
        if (b < n-1)
        {
            if (solution[b + 1] > solution[b] + 1){
                solution[b + 1] = solution[b] + 1;
                q.push_back(b + 1);
            }
        }
        
        if (solution[a[b]] > solution[b] + 1){
            solution[a[b]] = solution[b] + 1;
            q.push_back(a[b]);
        }
        
        q.pop_front();
    }

    for (int i = 0; i < n; ++i ) {
        cout << solution[i] << " ";
    }
    
    return 0;
}
