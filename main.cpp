#include <iostream>
#include <vector>
#include <chrono>
 
using namespace std;
 
 
bool isPrime1(int n) {
    if(n <= 1)
        return false;
 
    for(int i=2; i<n; i++) {
        if(n % i == 0)
            return false;
    }
 
    return true;
}
 
bool isPrime2(int n) {
    if(n == 2)
        return true;
 
    if(n <= 1 | n % 2 == 0)
        return false;
 
    for(int i=3; i<n; i+=2) {
        if(n % i == 0)
            return false;
    }
 
    return true;
}
 
bool isPrime3(int n) {
    if(n == 2)
        return true;

    if(n <= 1 | n % 2 == 0)
        return false;
 
    for(int i=3; i*i<=n; i+=2) {
        if(n % i == 0)
            return false;
    }
 
    return true;
}


void first_method(int range) {

    auto start = chrono::high_resolution_clock::now();

    int primes_count = 0;
    for(int i=1; i<=range; i++) {
        if(isPrime1(i))
            primes_count++;
    }

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<long long, nano> elapsed = end - start;

    cout << "First method  | range: " << range << " primes count: " << primes_count << " time: " << fixed << elapsed.count() << " nanoseconds" << endl;
}


void second_method(int range) {

    auto start = chrono::high_resolution_clock::now();

    int primes_count = 0;
    for(int i=1; i<=range; i++) {
        if(isPrime2(i))
            primes_count++;
    }

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<long long, nano> elapsed = end - start;

    cout << "Second method | range: " << range << " primes count: " << primes_count << " time: " << fixed << elapsed.count() << " nanoseconds" << endl;
}


void third_method(int range) {

    auto start = chrono::high_resolution_clock::now();

    int primes_count = 0;
    for(int i=1; i<=range; i++) {
        if(isPrime3(i))
            primes_count++;
    }

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<long long, nano> elapsed = end - start;

    cout << "Third method  | range: " << range << " primes count: " << primes_count << " time: " << fixed << elapsed.count() << " nanoseconds" << endl;
}


void eratosthenes(int range) {

    auto start = chrono::high_resolution_clock::now();

    bool tab[1000009];
    tab[0] = false;
    tab[1] = false;
    for(int i=2; i<=range; i++) {
        tab[i] = true;
    }

    for(int i=2; i*i<=range; i++) {
        if(!tab[i])
            continue;

        for(int j=i*i; j<=range; j+=i)
            tab[j] = false;
    }
    
    int primes_count = 0;

    for(int i=2; i<=range; i++) {
        if(tab[i])
            primes_count++;
    }

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<long long, nano> elapsed = end - start;

    cout << "Eratosthenes  | range: " << range << " primes count: " << primes_count << " time: " << fixed << elapsed.count() << " nanoseconds" << endl;
             
}

int main() {

    cout.precision(20);
 
    vector<int> ranges = {1000, 10000, 100000, 1000000};
 
    // Pierwsze 3 metody
    for(int range: ranges) {
        first_method(range);
        second_method(range);
        third_method(range);
        eratosthenes(range);
        cout << endl;
    }
 
    return 0;
}
