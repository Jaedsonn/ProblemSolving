#include <iostream>
#include <vector>
#include <random>

using namespace std;

namespace {
    mt19937_64& random_engine() {
        static random_device rd;
        static mt19937_64 gen(rd());
        return gen;
    }

    template <typename T>
    T rand_int(const T& a, const T& b) {
        uniform_int_distribution<T> dis(a, b);
        return dis(random_engine());
    }
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool is_big = (argc > 1);

    long long max_n = is_big ? 200000 : 1000;
    long long max_val = 1000000000LL;

    long long n = rand_int(1LL, max_n);
    
    long long k = rand_int(1LL, max_val);

    cout << n << "\n";
    
    for (long long i = 0; i < n; i++) {
        long long c_i = rand_int(1LL, max_val);
        cout << c_i << (i == n - 1 ? "" : " ");
    }
    
    cout << "\n" << k << "\n";

    return 0;
}