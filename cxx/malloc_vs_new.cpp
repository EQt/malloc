/**
   Analyze, why std::vector<...> allocation seems so slow.
   Basically, the results of [1] are reconstructed, i.e.

      std::vector<int> (n)

   is the same as

      std::vector<int> (n, 0)

   (which is somehow unexpected).

   [1]: https://stackoverflow.com/q/17347254
*/
#include <vector>
#include <string>
#include <iostream>
#include <cstring>                  // for std::memset

#include "malloc.hpp"
#include "timer.hpp"
#include "thousand.hpp"


void
test_malloc(const size_t n)
{
    Timer timer ("malloc");
    Malloc<char> a (n);
    char *b = a.data();
    timer.stop();
    {
        Timer _ ("memset");
        std::memset((void*)b, 0, n);
    }
    for (size_t i = 0; i < n; i += 8)
        b[i] = char(i + b[i]);
    Timer::startit("free");
}


void
test_vector_res(const size_t n)
{
    Timer timer ("vector.reserve");
    std::vector<char> a;
    a.reserve(n);
    char *b = a.data();
    timer.stop();
    for (size_t i = 0; i < n; i += 8)
        b[i] = char(i);
    Timer::startit("free");
}


void
test_vector(const size_t n)
{
    Timer timer ("vector");
    std::vector<char> a (n);
    char *b = a.data();
    timer.stop();
    for (size_t i = 0; i < n; i += 8)
        b[i] = char(i);
    Timer::startit("free");
}


int
main()
{
    set_thousand_sep(std::cout);
    const size_t n = 1024 * 1024 * 256;
    for (size_t i = 1; i < 10; i++) {
        std::cout << "n = " << i * n << std::endl;
        test_vector(i*n);
        Timer::stopit();
        test_vector_res(i*n);
        Timer::stopit();
        test_malloc(i*n);
        Timer::stopit();
    }
    return 0;
}
