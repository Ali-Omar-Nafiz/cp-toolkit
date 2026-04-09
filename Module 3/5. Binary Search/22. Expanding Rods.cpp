// Problem: https://lightoj.com/problem/expanding-rods
#include <bits/stdc++.h>
using namespace std;

#define ld long double

const ld eps = 1e-9;

int main()
{
    int t; cin>>t;
    for(int tc = 1; tc<=t; ++tc)
    {
        ld L,n,c; cin>>L>>n>>c;
        ld S = (1.0 + n*c)*L;

        ld Lo = L/2.0, Hi = 1e18;

        for(int i=0; i<100; ++i)
        {
            ld mid = (Lo+Hi)/2.0;
            ld val = mid*2.0 * asin(L/(mid*2.0));


            // if(val == S) //kora jabe na
            if(abs(val-S)<=eps)
            {
                Lo = mid;
                Hi = mid;
                break;

            }
            else if(val>S)
            {
                Lo = mid;
            }
            else
            {
                Hi = mid;
            }
        } 

        ld r = Lo;

        ld h = r - sqrtl(r*r - (L/2.0)*(L/2.0));


        cout<<"Case "<<tc<<": "<<fixed<<setprecision(7)<<h<<'\n';
    }


}
