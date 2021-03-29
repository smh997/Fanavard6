#include <iostream>
using namespace std;

int main()
{
    // we use long long int to be sure code runs truly for big test cases.
    // n object, m boxes and each box has k capacity.
    long long int n, m , k; 
    // cnt: number of boxes we need for a selected j.
    // cap: capacity of the current box we are filling it.
    long long int cnt, cap;
    // read from input.
    cin >> n >> m >> k;
    // array of object sizes.
    long long int a[n];
    // read the array of object sizes from input.
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // lo and hi represent the bound of j [0, n-1]
    // mid is used for binary search over the bound of j.
    long long int lo = 0, hi = n-1, mid;
    // binary search choose a j in the bound in O(log n).
    while(lo < hi){
        // mid is equal to median of the remaining bound.
        mid = (lo + hi) / 2;
        // initialize cnt and cap for start calculate if it is possible to do the algorithm say in the problem.
        cnt = 1;
        cap = 0;
        // do the algorithm say in the problem. O(n)
        for (int i = mid; i < n; ++i) {
            // if current box has space to contain i-th object: put the object in the box.
            if(cap + a[i] <= k){
                cap += a[i];
            }
            else{ // if current box has no more space to contain i-th object: go to next box with current cap = a[i];
                cap = a[i];
                cnt++;
            }
        }
        // if chosen j in this step (j = mid) make doing algorithm possible,
        // decrease bound to [lo, mid] to contains more objects if it is possible.
        if(cnt <= m){
            hi = mid;
        }
        else{// else decrease bound to [mid+1, hi] to make doing algorithm possible even with less objects.
            lo = mid + 1;
        }
    }
    // lo is now equal to best j we can choose and n - lo give the maximum number of objects we can put in the boxes.
    cout << n - lo << endl;
    
    return 0;
}
