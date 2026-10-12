// Problem: https://lightoj.com/problem/triangle-partitioning
#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-14;

int main()
{
    int t; cin>>t;
    for(int tc = 1; tc<=t; ++tc)
    {
        long double AB,AC,BC,k;
        cin>>AB>>AC>>BC>>k;

        k = 1.0 + (1.0/k); //this is ABC/abc

        long double L = 0, R = AB;

        for(int i=0; i<100; ++i)
        {
            long double mid = (L+R)/2.0;

            long double val = (AB*AB)/(mid*mid);
            if(abs(val-k)<=eps)
            {
                L = mid;
                R = mid;
                break;
            }
            else if(val > k)
            {
                L = mid;
            }
            else
            {
                R = mid;
            }
        }
        cout<<"Case "<<tc<<": "<<fixed<<setprecision(8)<<L<<'\n';

    }

}
