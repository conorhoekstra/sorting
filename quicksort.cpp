#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

using vi = vector<int>;
using v_it = vector<int>::iterator;

#define FORI(s,n) for(int i = s; i < n; i++)

void print (vi vv) {
    for (const auto& e : vv) cout << e << ' ';
    cout << endl;
}


void quickSort (v_it a, v_it b) {
    
    if (distance (a, b) <= 1) return;
    
    // 1. Choose pivot
    int p = rand () % distance (a, b);
    
    // 2. Partition around pivot
    int val        = *(a+p);
    auto lessThanP = [val](int i) {return i < val;};
    
    auto q = partition (a, b, lessThanP);
    
    quickSort (a, q);
    quickSort (q, b);
}

int main()
{
    int n; cin >> n;
    vi v (n);
    FORI (0, n) cin >> v[i];
    
    quickSort (v.begin (), v.end ());
    
    print (v);
    
    return 0;
}
