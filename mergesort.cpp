#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

#define FORI(s,n) for(int i = s; i < n; i++)

using vi  = vector<int>;

void print (vi v) {
    for (const auto& e : v) cout << e << ' ';
    cout << endl;
}

vi merge (vi a, vi b);

vi mergeSort (vi v) {
    
    int n = v.size (); 
    
    if (n <= 1) return v;
    
    int l1 = n/2;
    int l2 = n - l1;
    
    vi left  (l1);
    vi right (l2);
    
    FORI (0, n) {
        if (i < l1) left [i]    = v[i];
        else        right[i-l1] = v[i];
    }
    
    left  = mergeSort (left);
    right = mergeSort (right);
    
    return merge (left, right);
}

vi merge (vi a, vi b) {

    vi res;
    int i = 0;
    int j = 0;
    while (i < a.size () || j < b.size ()) {
        if (j >= b.size () || (a[i] < b[j] && i != a.size ())) {
            res.push_back (a[i]);
            i++;
        }
        else {
            res.push_back (b[j]);
            j++;
        }
    }
    
    return res;
}

int main()
{
    int n; cin >> n;
    vi v (n);
    FORI (0, n) cin >> v[i];
    
    v = mergeSort (v);
    
    print (v);

    return 0;
}
