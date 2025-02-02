import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class MooingTime {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N=sc.nextInt();
        long[] a = new long[N];
        Multiset m = new Multiset();
        for(int i=0; i<N; i++){
            a[i] = sc.nextLong();
            m.insert(a[i]);
        }
        m.trim();
        HashSet<Long> s = new HashSet<Long>();
        long o=(long) 0;
        for(int i=0; i<N; i++){
            m.subtract(a[i]);
            if(!s.contains(a[i])){
                for(Long key:m.keys()){
                    if(key!=a[i]){
                        o++;
                    }
                }
                s.add(a[i]);
            }
        }
        System.out.println(o);
        sc.close();
    }

}
class Multiset{
    HashMap<Long, Long> hash;
    public Multiset(){
        hash = new HashMap<Long, Long>();
    }
    public void insert(long n){
        if(!hash.containsKey(n)) hash.put(n, (long) 1);
        else hash.put(n, hash.get(n)+1);
    }
    public void subtract(long n){
        if(hash.containsKey(n)){
            long s=hash.get(n)-1;
            if(s<2) hash.remove(n);
            hash.put(n, s);
        }
    }
    public long count(long n){
        return hash.get(n);
    }
    public boolean contains(long n){
        return hash.containsKey(n);
    }
    public Set<Long> keys(){
        return hash.keySet();
    }
    public void trim(){
        Object[] keyList = keys().toArray();
        for(Object key: keyList){
            if(count((long) key)<2) hash.remove(key);
        }
    }
}
