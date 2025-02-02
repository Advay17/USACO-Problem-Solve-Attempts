#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    for(int i=0; i<N; i++){
        cin >> b[i];
    }
    vector<int> o(N+1);
    int precount=0;
    for(int i=0; i<N; i++){
        if(a[i]==b[i]) precount++;
    }
    o[precount]+=N;
    for(int l=0; l<N; l++){
        vector<int> t;
        copy(a.begin(), a.end(), back_inserter(t));
        int c=precount;
        int sectPairs=0;
        if(t[l]==b[l]) sectPairs++;
        for(int r=l+1; r<N; r++){
            int temp = t[r];
            c-=sectPairs;
            if(t[r]==b[r]) c--;
            sectPairs=0;
            t.erase(t.begin()+r);
            t.insert(t.begin()+l, temp);
            for(int i=l; i<=r; i++){
                if(t[i]==b[i]){
                    sectPairs++;
                    c++;
                }
            }
            o[c]++;
        }

    }

    for(int i=0; i<N+1; i++){
        cout << o[i] << endl;
    }
}