#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>

#include "ip_filter.h"


int main(int argc, char const *argv[])
{
    try
    {
        std::vector<ip_adress > ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(getIP(  std::move( v.at(0) ) ));
        }

        // TODO reverse lexicographically sort

        sort(ip_pool.begin(), ip_pool.end(), std::greater<ip_adress>());

        for (const auto& ip : ip_pool) {
            std::cout << ip << std::endl;
        }

        // TODO filter by first byte and output

        for (const auto& ip : ip_pool) {
            if (ip.at(0) == 1)
                std::cout << ip << std::endl;
        }

        // TODO filter by first and second bytes and output

        for (const auto& ip : ip_pool) {
            if (ip.at(0) == 46 && ip.at(1) == 70)
                std::cout << ip << std::endl;
        }

        // TODO filter by any byte and output

        for (const auto& ip : ip_pool) {
            if (ip.at(0) == 46 || ip.at(1) == 46 || ip.at(2) == 46 || ip.at(3) == 46)
                std::cout << ip << std::endl;
        }


    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
