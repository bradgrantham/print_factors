// C++11

#include <cstdio>
#include <vector>
#include <iostream>
#include <numeric>

std::vector<int> all_factors(int n)
{
    std::vector<int> factors;

    int i = 1;

    while(i < n){
        if((n % i) == 0)
            factors.push_back(i);

        i++;
    }

    return factors;
}

int main(
    int    argc,
    char    **argv)
{
    int i = 2;

    while(true) {
        auto factors = all_factors(i);
        int sum = std::accumulate(factors.begin(), factors.end(), 0);

        if(sum > i) {

            auto factors2 = all_factors(sum);
            int sum2 = std::accumulate(factors2.begin(), factors2.end(), 0);

            if(i == sum2)
                printf("%d %d\n", i, sum);
        }

        i++;
    }

}
