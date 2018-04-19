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
            auto v = split(line, '\t');
//           try
//            {
                ip_pool.push_back(getIP( v.at(0) ));
//            }
//            catch (std::out_of_range& e) {}
        }

        // TODO reverse lexicographically sort

        sort(std::begin(ip_pool), std::end(ip_pool), std::greater<ip_adress>());

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
              if ( std::find(std::begin(ip), std::end(ip), 46) != std::end(ip) )
                std::cout << ip << std::endl;
        }


    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
