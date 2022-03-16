#include <bits/stdc++.h>
using namespace std;

double tmp[1000005], a[1000005];
int n;







void mergesort(int l,int r)
{
    if (l == r) return;
    int mid = (l+r) >> 1;
    mergesort(l,mid);
    mergesort(mid+1,r);

    int cur = 0;
    int i = l, j = mid+1;
    while (i <= mid || j <= r)
    {
        if (i > mid)
            tmp[cur++] = a[j++];
        else if (j > r)
            tmp[cur++] = a[i++];
        else if (a[i] < a[j])
            tmp[cur++] = a[i++];
        else
            tmp[cur++] = a[j++];
    }
    for (int i = 0; i < cur; i++)
        a[l+i] = tmp[i];
}


int main()
{
    ifstream fi;
    for (int i = 0; i <= 9; i++)
    {
        fi >> n;
        string s = "test" + to_string(i) + ".txt";
        fi.open(s);
        fi >> n;
        for (int i = 1; i <= n; i++)
            fi >> a[i];
        fi.close();

        auto t1 = chrono::high_resolution_clock::now();
        mergesort(1,n);
        auto t2 = chrono::high_resolution_clock::now();
        auto time = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
        cout << "Test " << i <<": ";
        cout << fixed << setprecision(6) << time.count() << '\n';
    }
    return 0;
}
