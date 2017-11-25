//
// Brad Grantham 2016-12-5
//

#include <cstdio>
#include <vector>
#include <iostream>

std::vector<int> factor(int n, bool all)
{
    std::vector<int> factors;

    int i = all ? 1 : 2;

    while(i < n){
        if((n % i) == 0){
            factors.push_back(i);
            if(all) {
                i++;
            } else {
                n = n / i;
                i = 2;
            }
        } else 
            i++;
    }

    return factors;
}

int main(
    int    argc,
    char    **argv)
{
    bool all = false;

    while(--argc > 0) {
        if(strcmp(argv[1], "-a") == 0) {

            all = true;

        } else {

            auto factors = factor(atoi(argv[1]), all);
            bool first = true;
            for(auto& it : factors) {
                if(!first)
                    std::cout << " ";
                first = false;
                std::cout << it;
            }
            std::cout << '\n';
        }

        argv++;
    }
}
