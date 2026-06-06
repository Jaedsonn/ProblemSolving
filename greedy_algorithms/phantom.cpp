#include <bits/stdc++.h>
#define vi vector<int>
#define vl vector<long long>

typedef long long ll;

using namespace std;

struct Time{
    int hours;
    int minutes;
    Time(){};
    Time(int a, int b): hours(a), minutes(b){};
};

struct Phantom{
    Time start;
    Time end;
    Phantom(){};
    Phantom(Time a, Time b): start(a),  end(b){};
};


bool cmp(Phantom a, Phantom b){
    if(a.end.hours == b.end.hours){
        return a.end.minutes < b.end.minutes;
    }
    return a.end.hours < b.end.hours;
}

int main(){
    int n; cin >> n;
    vector<Phantom> a(n); 
    for(int i = 0; i < n; i++){
        int hs, ms, he, me;
        cin >> hs >> ms >> he >> me;
        a[i] = Phantom(Time(hs, ms), Time(he, me));
    }

    sort(a.begin(), a.end(), cmp);

    vector<Phantom> b = {a[0]};
    int best = 0;

    for(int i = best+1;i < n; i++){
        int d1 = a[i].start.hours;
        int d2 = b[best].end.hours;

        if(a[i].start.hours < b[best].end.hours){
            continue;
        }

        if(a[i].start.hours > b[best].end.hours){
            b.push_back(a[i]);
            best += 1;
            continue;
        } else if(a[i].start.hours == b[best].end.hours && a[i].start.minutes >= b[best].end.minutes){
            b.push_back(a[i]);
            best += 1;
            continue;
        }
    }

    cout << b.size() << endl;

    return 0;
}
 