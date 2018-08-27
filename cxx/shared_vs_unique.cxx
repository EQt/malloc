#include <iostream>
#include <memory>
#include <cstdint>
#include <cstdlib>


std::unique_ptr<int8_t>
unique()
{
    int8_t *ptr = (int8_t*) malloc(5);
    ptr[0] = 1;
    ptr[1] = 2;
    ptr[2] = 5;
    ptr[3] = 7;
    ptr[4] = 11;

    return std::unique_ptr<int8_t>(ptr);
}


std::shared_ptr<int8_t>
shared()
{
    int8_t *ptr = (int8_t*) malloc(5);
    ptr[0] = 1;
    ptr[1] = 2;
    ptr[2] = 5;
    ptr[3] = 7;
    ptr[4] = 11;

    return std::shared_ptr<int8_t>(ptr);
}


int
main()
{
    auto au = unique();
    auto bs = shared();

    const int8_t
        *a = au.get(),
        *b = bs.get();

    for (int i = 0; i < 5; i++)
        std::cout << int(a[i]) << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << int(b[i]) << std::endl;

    return 0;
}
