/*
Solution smart utilisant les observations suivantes :

- la solution et en dent de scie avec des écarts -1, 0 ou 1 entre deux noeuds consécutifs
- les minima locaux correspondent à des destinations de shortcuts
- Si on connaît la positions et la "hauteur" (distance au point 1) des minima locaux, on peut reconstituer la solution
- Les antécédant des minima locaux par shortcut sont croissants.

Le dernier points découle du fait que les a_i sont croissants.
Il est fort de conséquences. Par exemple, il permet de guarantir que a_1 est le premier minimum local.
Plus généralement, cela permet de savoir que le prochain minimum local à partir de k ne dépend que des a_i pour i<=k

*/

#include <iostream>
#include <utility>      //pair
#include <list>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){     //computes whether a new shortcut destination b is actually a new pit considering a is already one.
    return get<1>(b) - get<1>(a) < get<0>(b) - get<0>(a);
}
bool betterPit(pair<int,int> a, pair<int,int> b){     //computes whether a newly discovered pit `b` erases a former one `a`
    return get<1>(a) - get<1>(b) >= get<0>(b) - get<0>(a);
}
pair<int,int> peak (pair<int,int> a, pair<int,int> b){    //computes the peak position between two consecutive pits. Also returns the height at 1 + the peak position
    int pos = (get<0>(b) + get<0>(a) + get<1>(b) - get<1>(a) );
    int h = (get<1>(b) + get<1>(a) + get<0>(b) - get<0>(a) ) / 2;
    return make_pair(
        pos / 2,
        pos%2 ? h : h - 1
    );
}
void pushPit (list<pair<const int, const int>> & minima, pair<const int, const int> potentialMin){ //pushes a potential pit if suitable
    if (!cmp(minima.back(), potentialMin)) return;
    while(betterPit(minima.back(), potentialMin)) minima.pop_back();
    minima.push_back(potentialMin);
}

int main() {
    int n;
    cin >> n;

    list<pair<const int, const int>> minima;
    int d = 0;

    for (int i = 0; i < n; ){
        pair<const int, const int> currentMin {i, d};
        //pair<const int, const int> nextMin ;
        //pair<const int, const int> lastMin ;
        if (minima.empty()) {
            minima.push_back(currentMin);
        }

        pair<int,int> p = peak(currentMin, minima.front());
        for (; i <= get<0>(p); ++i, ++d) {
            cout << d << " ";
            int a;
            cin >> a; --a;
            pair<const int, const int> potentialMin {a, d + 1};

            pushPit(minima, potentialMin);
        }

        d = get<1>(p);
        for (; i <= get<0>(minima.front()); ++i, --d) {
            cout << d << " ";
            int a;
            cin >> a; --a;
            pair<const int, const int> potentialMin {a, d + 1};

            pushPit(minima, potentialMin);
        }

        d = get<1>(minima.front()) + 1;
        minima.pop_front();
    }


    return 0;
}

/*
5
1 2 3 4 5

3
2 2 3

8
1 2 3 4 5 6 7 8

7
4 4 4 4 7 7 7

*/