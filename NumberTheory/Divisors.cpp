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
int main() {
 vector<int> ans = findDivisors2(20);//He will back value as vector , so i will get it as vector
  for(auto x : ans){
      cout<<x<<"\n";
  }
}