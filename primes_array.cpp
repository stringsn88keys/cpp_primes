#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
  // NOTE: Capped at 20,000,000 for reasonable runtime.
  // 1270607 for 20 million
  // 98222287 for 2 bllion
  const uint32_t max = 200000000; //0;
  uint32_t *primes = new uint32_t[99000000]();
  primes[0] = 2;


  uint32_t prime_count = 1;

  for(uint32_t i=3;i<max;i+=2) {
    bool prime = true;
    // OPTIMIZATION: Only search through sqrt(i) divisors.
    uint32_t *j = primes + 1;
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
