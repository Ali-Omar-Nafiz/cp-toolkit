int fastPow(int a, int p) // find a to the power p
{
    if(p == 0) return 1;
    if(p == 1) return a;
    // a^10 = a^5 * a^5   (even case)
    // a^11 = a^5 * a^5 * a   (odd case)
    int x = fastPow(a, p / 2);
    x = x * x % MOD;
    if(p & 1) x = x * a % MOD;
    return x;
}
