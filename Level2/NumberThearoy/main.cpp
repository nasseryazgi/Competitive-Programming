#include <bits/stdc++.h>
#define  ll long long
#define IO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
const int N = 100;
bool isPrime[N]  ;
vector<int> findDivisors(int x) {
    //return vector divisors
    vector<int> divisors;
    //Here Complixty O(x)
    for (int i = 0; i <= x; ++i) {
        if (x % i == 0) divisors.push_back(i);

    }
    return divisors;
}
vector<int> findDivisors2(int x) {// O(sqrt(x))
    vector<int> divisors2;
    //   for(int i = 2 ; i< sqrt(x);i++){
//                     if(i==x/i){ // 5 / 2 = 2 . Here is Problem .
//                         divisors2.push_back(i);
//                     } else if(x%i==0){
//                         divisors2.push_back(i) ,divisors2.push_back(x/i);
//
//                     }



//            Now This Code is Correct, but we will make some Changes for be More Profissinal
//    for(int i = 2 ; i*i<x;i++){
//                if(x%i==0){
//                    if(i==x/i)
//                        divisors2.push_back(i);
//                        else
//                    divisors2.push_back(i) ,divisors2.push_back(x/i);
//                }}
    int i = 1;
    //c++ standrd make flor => for less number .
    // i*i < x = i <x/i => Same . but good for over flow .
    //20 , 1 <20/1 , 2 <20/2
    for (; i * i < x; i++) {//(1,20
        if (x % i == 0) {
            divisors2.push_back(i), divisors2.push_back(x / i);
        }
    }
    if (i * i == x) {
        divisors2.push_back(i);
    }
    return divisors2;
}
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
bool checkPrime3(int n) { // O(sqrt(x))
    if (n < 2) return 0;
    for (int i = 2; i*i <= n; i += 1 + (i & 1)) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
vector<int> sieve(int n ) {
    fill(isPrime , isPrime+n , 1) ;
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i *i<n ; ++i) { // Complexity O(log log n)
        if(isPrime[i])//Prime is true . (so no on delete it .)
        {
            /*  isPrime[4]=0; not prime         isPrime[6]=0;   isPrime[8]=0;  */
            //int j = 2*i
            for (int j = i*i; j <=n ; j+=i) {
                isPrime[j]=0;

            }
        }

    }
//bitset =>search best that bool isPrime[N] .=> bytes ( int *n )
    for (int i = 2; i *i<n ; i+=i+(i&1)) { // Complexity O(log log n)
        if(isPrime[i])//Prime is true . (so no on delete it .)
        {
            /*  isPrime[4]=0; not prime         isPrime[6]=0;   isPrime[8]=0;  */
            //int j = 2*i
            for (int j = i*i; j <=n ; j+=i) {
                isPrime[j]=0;

            }
        }

    }
    vector<int> prime_sieve ;
    for(int i = 2;i<=n ;i++) {
        if(isPrime[i]){
            prime_sieve.push_back(i);
        }
    }
    return prime_sieve ;
}
int main() {
//  vector<int> ans = findDivisors2(20);//He will back value as vector , so i will get it as vector
//  for(auto x : ans){
//      cout<<x<<"\n";
//  }
//    while (1){
//        int number;
//        cin >> number;
//        if (checkPrime2(number)){
//            cout << "Prime\n";
//            cout.flush();
//        }
//        else {cout << "NotPrime";
//            cout.flush();
//        }
//    }


vector<int> ans = sieve(1000) ;
  for(auto x : ans)
      cout<<x<<"\t";
cout<<'\n';
  cout<<ans.size()<<'\n';

    //10^1 => 4 primes
  // 10^100 =>25 primes
  /*
    primes => n/log2(n)
    تقريبا عشان تعرف كم عدد راح يطلع منك
   */
}