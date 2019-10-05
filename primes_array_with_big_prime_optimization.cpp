#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
  // NOTE: Capped at 20,000,000 for reasonable runtime.
  // 1270607 for 20 million
  // 98222287 for 2 bllion
  const uint32_t max = 2000000000;
  const double percentage = 100.0;
  const double percent_of_prime_count = 99.0;
  uint32_t *primes = new uint32_t[99000000]();
  primes[0] = 2;

  uint32_t max_stop = (uint32_t) sqrt(max) * percentage / 100.0;
  unordered_set<uint32_t> not_prime_cache {};
  bool not_prime_initialized = false;

  uint32_t prime_count = 1;

  for(uint32_t i=3;i<max;i+=2) {
    bool prime = true;
    // OPTIMIZATION: Only search through sqrt(i) divisors.
    uint32_t *j = primes + 1;

    if(i > max_stop && !not_prime_initialized) {
      not_prime_initialized = true;
      // initialize the big primes from 80% of prime count * up to prime_count
      for(int f1idx=(int)(prime_count * percent_of_prime_count / 100.0);
          f1idx<(prime_count-1);
          f1idx++) {
        for(int f2idx=f1idx+1;
            f2idx < prime_count;
            f2idx++) {
          not_prime_cache.insert(primes[f1idx] * primes[f2idx]);
        }
      }
    }
    if(not_prime_initialized && not_prime_cache.find(i) != not_prime_cache.end()) {
      continue;
    }
    for(; *j && (*j * *j) <= i; j++) {
      if (i % *j == 0) {
        prime = false;
        break;
      }
    }
    if (prime == true) {
      primes[prime_count] = i;
      //      cout << "Prime count: " << prime_count << " Prime:" << i << endl;
      ++prime_count;
    }
  }
  cout << "Number of primes between 2 and " << max << ": " <<
    prime_count << std::endl;
  return 0;
}
