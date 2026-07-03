/*
Euler Phi Extension and Divisor Sum Theorem 
https://forthright48.com/euler-phi-extension-and-divisor-sum/

From last class:
phi(1) = 1;
phi(p) = p - 1
phi(p^y) = p^y - p^(y - 1)
phi(a * b) = p(a) * p(b)
phi(p1^x * p2^y * p3^z) = (p1^x * p2^y * p3^z) * ((p1 - 1) / p1) * ((p2 - 1) / p2) * ((p3 - 1) / p3)

Euler Phi Extension theorem:
Given a number N, let d be a divisor of N. Then the number of pairs a, N, where 1 ≤ a ≤ N and gcd(a,N) = d, is ϕ(N / d).

Euler Phi Divisor Sum Theorem:
For a given integer N, the sum of Euler Phi of each of the divisors of N equals to N, i.e, N = sigma(phi(d)), where d is the divisors of n, sigma means summation(∑)
*/
