#include <bits/stdc++.h>
#define  ll long long
#define IO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
const int N = 100;
bool isPrime[N]  ;
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