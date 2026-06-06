
#include <bits/stdc++.h>
#define ll float

using namespace std;

struct P{
    float pontuacao;
    float tempo;
};

bool cmp(P a, P b){
    return (a.pontuacao/a.tempo) > (b.pontuacao/b.tempo);
};

int main() {
    float n, t, m, x; cin >> n >> t >> m >> x;
    vector<P> a;

    
    for(int i = 0; i < n; i++){
        ll p;
        ll tmp;
        cin >> p >> tmp;
        P quest;
        quest.pontuacao = p;
        quest.tempo = tmp;
        a.push_back(quest);
    };
    
    sort(a.begin(), a.end(), cmp);

    ll pl = 0;
    ll pt = 0;

    ll countt = 0;

    for(int i = 0; i < n; i++){
        countt += a[i].tempo;

        if(countt > t){
            ll tempo_dedicado = t - ( countt - a[i].tempo );

           
            pt += (tempo_dedicado / a[i].tempo ) * a[i].pontuacao;
            break;
        };

        pt += a[i].pontuacao;
    }

    ll countl = t-m;

    for(int i = 0; i < n; i++){
        countl += (a[i].tempo/x);

        if(countl > t){
            float tempo_dedicado = t - ( countl - (a[i].tempo/x) );

            pl += (tempo_dedicado / (a[i].tempo / x)) * a[i].pontuacao;
            break;
        };

        pl += a[i].pontuacao;
    }


        if(pt > pl){
            cout << "TARTARUGA" << endl;
        } else if(pl > pt){
            cout << "LEBRE" << endl;
        } else{
            cout << "EMPATE" << endl;   
        }
    return 0;
}