// Problem: https://lightoj.com/problem/olympics
#include <bits/stdc++.h>
using namespace std;

#define ld long double

const ld eps = 1e-9;

int main()
{
    int t; cin>>t;
    for(int tc = 1; tc<=t; ++tc)
    {
        ld a,b;
        char tmp;
        cin>>a>>tmp>>b;

        ld Lo = 0, Hi = 400;

        for(int i=0; i<100; ++i)
        {
            ld mid = (Lo+Hi)/2;
            ld L = mid;
            ld W = (L*b)/a;
            ld r = sqrtl(L*L+W*W) / 2.0;
            ld theta = asin(W/(r*2.0)) * 2.0;
            
            ld S = r*theta;

            ld val = (L+S)*2.0;

            if(abs(val-400.0)<=eps)
            {
                Lo = mid;
                Hi = mid;
                break;
            }
            else if(val > 400.0)
            {
                Hi = mid;
            }
            else
            {
                Lo = mid;
            }


        } 

        ld L = Lo;

        ld W = (L*b)/a;

        cout<<"Case "<<tc<<": "<<fixed<<setprecision(7)<<L<<' '<<W<<'\n';
    }


}
