
#include <bits/stdc++.h>
#define  ll long long
#define IO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
const int N = 100;
bool isPrime[N]  ;
bool checkPrime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
bool checkPrime2(int n) { //O(n)=>
    if (n < 2) return 0; // for 0 , 1
    if (n == 2) return 1; //for 2 => 2 is the only prime and even.
    if (n > 2 and n % 2 == 0) return 0; // example by 8 => not prime =>always accepted divison in any even number
    for (int i = 3; i < n; i += 2) { // move on odd numbers only .
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
bool checkPrime3(int n) { // O(sqrt(x)) => Best Than Prime 1 & Prime 2 .
    if (n < 2) return 0;
    for (int i = 2; i*i <= n; i += 1 + (i & 1)) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main () {

      while (1)
      {
        int number;
       cin >> number;
       if (checkPrime2(number))
       {
            cout << "Prime\n"; cout.flush();
        }
        else {
            cout << "NotPrime";
           cout.flush();
       }
    }
}