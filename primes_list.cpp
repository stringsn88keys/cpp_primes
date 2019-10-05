#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

int main(int argc, char** argv) {
  // NOTE: Capped at 20,000,000 for reasonable runtime.
  const uint32_t max = 20000000;
  list<uint32_t> primes = {2};
  uint32_t prime_count = 2;


  for(uint32_t i=3;i<max;i+=2) {
    bool prime = true;
    // OPTIMIZATION: Only search through sqrt(i) divisors.
    auto it = primes.begin();
    it ++;
    for(; it != primes.end() && (*it * *it) <= i; it++) {
      if (i % *it == 0) {
        prime = false;
        break;
      }
    }
    if (prime == true) {
      primes.push_back(i);
      //      cout << "Prime count: " << prime_count << " Prime:" << i << endl;
      ++prime_count;
    }
  }
  cout << "Number of primes between 2 and " << max << ": " <<
    prime_count << std::endl;
  return 0;
}

