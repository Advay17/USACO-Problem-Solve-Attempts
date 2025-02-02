#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int N, A, B;
        cin >> N >> A >> B;
        vector<string> p(N);
        int stars=0;
        for(int i=0; i<N; i++){
            cin >> p[i];
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(p[i].at(j)=='B'){
                    if((i-B<0 || j-A<0) || p[i-B][j-A]=='W'){
                        stars=-1;
                        break;
                    }
                    if(i+B<N && A+j<N) p[i+B].at(j+A)='W';
                    stars++;
                }
                else if(p[i].at(j)=='G'){
                    if(i+B<N && A+j<N && p[i+B].at(j+A)=='G' && !(i+2*B<N && j+2*A<N && p[i+B*2].at(j+A*2)=='B')) p[i+B].at(j+A)='W';
                    if(i+B<N && A+j<N && p[i+B].at(j+A)=='B') p[i+B].at(j+A)='G';
                    stars++;
                }
            }
            if(stars==-1) break;
        }
        cout << stars << endl;
    }
}