#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater

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
    
    int * q = new int (n);
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
                ++top;
            }
        }
        ++bot;
    }


/*
    for (std::vector<int>::iterator it = q.begin(); it != q.end(); ++it ) {
        cout << (*it) << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i ) {
        cout << solution[i] << " ";
    }
    */
    return 0;
    
}

/*

5
1 2 3 4 5

*/

/*
// constructing priority queues
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};

int main ()
{
  int myints[]= {10,60,50,20};

  std::priority_queue<int> first;
  std::priority_queue<int> second (myints,myints+4);
  std::priority_queue<int, std::vector<int>, std::greater<int> >
                            third (myints,myints+4);
  // using mycomparison:
  typedef std::priority_queue<int,std::vector<int>,mycomparison> mypq_type;

  mypq_type fourth;                       // less-than comparison
  mypq_type fifth (mycomparison(true));   // greater-than comparison

  return 0;
}
*/