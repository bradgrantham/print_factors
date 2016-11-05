//
// Brad Grantham 2016-12-5
//

#include <cstdio>
#include <vector>
#include <iostream>

std::vector<int> factor(int n)
{
    std::vector<int> factors;

    int i = 2;

    while(i <= n){
        if((n % i) == 0){
            factors.push_back(i);
            n = n / i;
            i = 2;
        } else 
            i++;
    }

    return factors;
}

int main(
    int    argc,
    char    **argv)
{
    while(--argc > 0) {
        auto factors = factor(atoi(argv[1]));
        for(auto it = factors.begin(); it != factors.end(); it++) {
            if(it != factors.begin())
                std::cout << " ";
            std::cout << *it;
        }
        std::cout << std::endl;
        argv++;
    }
}
