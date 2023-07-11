#include <iostream>       // std::cout
#include <vector>         // std::vector

using namespace std;

class mycomparison
{
    int* sol;
    public:
    mycomparison(int* s)
        {sol=s;}
    bool operator() (const int& lhs, const int&rhs) const
    {
        return (sol[lhs]<sol[rhs]);
    }
};

int main() {
    int n;
    cin >> n;
    
    int * a = new int (n);
    for (int i = 0; i < n; ++i ) {
        cin >> a[i];
        a[i] --;
    }

    int * solution = new int (n);
    for (int i = 0; i < n; ++i ) {
        solution[i] = n + 1;
    }
    
    std::vector<int> q (n);
    std::vector<int>::iterator bot = q.begin();
    std::vector<int>::iterator top = q.begin();

    solution[0] = 0;
    *bot = 0;
    ++top;

    while (bot != q.end()){
        if (*bot > 0)
        {
            if (solution[*bot - 1] > solution[*bot] + 1){
                solution[*bot - 1] = solution[*bot] + 1;
                *top = *bot - 1;
                if (top != q.end()) ++top;
            }
        }
        if (*bot < n-1)
        {
            if (solution[*bot + 1] > solution[*bot] + 1){
                solution[*bot + 1] = solution[*bot] + 1;
                *top = *bot + 1;
                if (top != q.end()) ++top;
            }
        }
        
        if (solution[a[*bot]] > solution[*bot] + 1){
            solution[a[*bot]] = solution[*bot] + 1;
            *top = a[*bot];
            if (top != q.end()) ++top;
        }
        ++bot;
    }

    for (int i = 0; i < n; ++i ) {
        cout << solution[i] << " ";
    }
    
    return 0;
}

/*

5
1 2 3 4 5


7
4 4 4 4 7 7 7
*/
