#include <bits/stdc++.h>
using namespace std;


double a[1000005];
int n;



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
        sort(a+1,a+n+1);
        auto t2 = chrono::high_resolution_clock::now();
        auto time = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
        cout << "Test " << i <<": ";
        cout << fixed << setprecision(6) << time.count() << '\n';
    }
    return 0;
}
