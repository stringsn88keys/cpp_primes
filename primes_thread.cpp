#include <iostream>
#include <iomanip>
#include <thread>
#include <list>
using namespace std;


void checkPrime(uint32_t *primes, uint32_t primeCandidate, bool &prime);

int main(int argc, char** argv) {
  // NOTE: Capped at 20,000,000 for reasonable runtime.
  // 1270607 for 20 million
  // 98222287 for 2 bllion
  const uint32_t max = 20000000; //00;
  uint32_t *primes = new uint32_t[99000000];
  primes[0] = 2;


  uint32_t prime_count = 1;

  bool dummy;

  thread(checkPrime, ref(primes), prime_count, dummy);

  for(uint32_t i=3;i<max;i+=2) {
    bool prime;

    if(prime_count > 100) {
      bool primeBool[4];
      uint32_t candidates[4] = {i, i + 2, i + 4, i + 6};
      //std::thread threads[4];

      for(int t=0; t < 4; t++) {
        ///threads[t] =
          //thread(checkPrime, primes, candidates[t], primeBool[t]);
      }
      for(int t=0; t < 4; t++) {
        //threads[t].join();
      }
      for(int t=0; t < 4; t++) {
        if(primeBool[t]) {
          primes[prime_count] = candidates[t];
          ++prime_count;
        }
      }
      i += 6;

    } else {
      checkPrime(primes, i, prime);
      if (prime == true) {
        primes[prime_count] = i;
        ++prime_count;
      }
    }

  }
  cout << "Number of primes between 2 and " << max << ": " <<
    prime_count << std::endl;
  return 0;
}

void checkPrime(uint32_t *primes, uint32_t primeCandidate, bool &prime) {
  prime = true;
  // OPTIMIZATION: Only search through sqrt(i) divisors.
  uint32_t *j = primes + 1;
  for(; *j && (*j * *j) <= primeCandidate; j++) {
    if (primeCandidate % *j == 0) {
      prime = false;
      return;
    }
  }
}
