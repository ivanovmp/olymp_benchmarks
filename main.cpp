#include <iostream>
#include <vector>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <filesystem>
#include <random>
#include <algorithm>
#include <cstdio>

using namespace std;

template<class T>
string pretty_duration(const T& t) {
    stringstream ans;
    ans << setprecision(4);
    if (t >= 1.h)
        ans << t / 1.h << " h";
    else if (t >= 1.min)
        ans << t / 1.min << " min";
    else if (t >= 1.s)
        ans << t / 1.s << " s";
    else if (t >= 1.ms)
        ans << t / 1.ms << " ms";
    else if (t >= 1.us)
        ans << t / 1.us << " us";
    else
        ans << t / 1.ns << " ns";
    return ans.str();
}

void test_eratosthenes() {
    auto start = chrono::high_resolution_clock::now();
    const int N = 45000000;
    vector<int> min_prime(N);
    vector<int> primes;
    for (int i = 2; i < N; ++i) {
        if (!min_prime[i]) {
            min_prime[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > min_prime[i])
                break;
            int product = i * p;
            if (product >= N)
                break;
            min_prime[product] = p;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    long long sum = 0;
    for (int i : primes)
        sum += i;
    for (int i = 0; i < N; ++i)
        sum += i / (min_prime[i] + 1);
    cout << "Eratosthenes' sieve (N == " << N << ") took " << pretty_duration(end - start) << " (side effect == " << sum << ")" << endl;
}

template<class Iter>
void fill_random_vector(Iter start, Iter end) {
    static mt19937 rng;
    for (Iter it = start; it != end; ++it)
        *it= rng();
}

vector<int> create_random_vector(const int length) {
    vector<int> ans(length);
    fill_random_vector(ans.begin(), ans.end());
    return ans;
}

void test_io() {
    static mt19937 rng;
    uniform_int_distribution<int> seg('a', 'z');
    const int filename_length = 17;
    const string postfix = ".txt";
    string filename;
    for (int i = 0; i < filename_length; ++i)
        filename.push_back(seg(rng));
    filename += postfix;

    const int N = 45000000; {
        vector<int> initial_vec = create_random_vector(N);
        auto start = chrono::high_resolution_clock::now();
            ofstream fout(filename);
            for (int i : initial_vec)
                fout << i << '\n';
        auto end = chrono::high_resolution_clock::now();
        long long initial_sum = 0;
        for (int i : initial_vec)
            initial_sum += i;
        cout << "Writing N int32 (N == " << N << ") took " << pretty_duration(end - start) << " (side effect == " << initial_sum << ")" << endl;
    }

    {
        vector<int> read_vec(N);
        auto start = chrono::high_resolution_clock::now();
        ifstream fin(filename);
        for (int& i : read_vec)
            fin >> i;
        auto end = chrono::high_resolution_clock::now();
        int read_sum = 0;
        for (int i : read_vec)
            read_sum += i;
        cout << "Reading N int32 (N == " << N << ") took " << pretty_duration(end - start) << " (side effect == " << read_sum << ")" << endl;
    }
    #ifndef __INTEL_COMPILER
    filesystem::remove(filename);
    #else
    remove(filename.c_str());
    #endif
}

void test_randomness() {
    const int N = 45000000;
    vector<int> v(N);
    auto start = chrono::high_resolution_clock::now();
    fill_random_vector(v.begin(), v.end());
    auto end = chrono::high_resolution_clock::now();
    long long sum = 0;
    for (int i : v)
        sum += i;
    cout << "Generating N random int32 (N == " << N << ") took " << pretty_duration(end - start) << " (side effect == " << sum << ")" << endl;
}

void test_floyd_warshall() {
    const int N = 1540;
    vector<vector<int>> v(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            v[i][j] = i + j;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
    auto end = chrono::high_resolution_clock::now();
    long long sum = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            sum += (i + 1) * (2 * j + 1) * v[i][j];
    cout << "Running Floyd-Warshall on a graph of size N (N == " << N << ") took " << pretty_duration(end - start) << " (side effect == " << sum << ")" << endl;
}

int main() {
    // Run all tests.
    test_eratosthenes();
    test_io();
    test_randomness();
    test_floyd_warshall();
}
