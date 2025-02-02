#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
int main(){
    long long N;
    cin >> N;
    if(N==1 || N==2) cout << 0;

    vector<long long> a(N);
    unordered_multiset<long long> m;
    for(int i=0; i<N; i++){
        cin >> a[i];
        m.insert(a[i]);
    }
    for(auto iter = m.begin(); iter!=m.end();){
            auto count = m.count(*iter);

            if(count>=2){
                m.erase(iter);
            }

            advance(iter, count);
    }
    unordered_set<string> s;
    long long o=0;


    m.insert(a[N-1]);
    m.insert(a[N-2]);
    for(int i=N-3; i>=0; i--){
        for(auto iter = m.begin(); iter!=m.end();){
            auto count = m.count(*iter);

            if(count>=2 && *iter!=a[i] && s.count(to_string(a[i])+to_string(*iter)+to_string(*iter))==0){
                o++;
                s.insert(to_string(a[i])+to_string(*iter)+to_string(*iter));
            }

            advance(iter, count);
        }

        m.insert(a[i]);
    }
    cout << o;
}