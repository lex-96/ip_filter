#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using ip_adress = std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>;

auto split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}
std::ostream& operator<<(std::ostream& os, const ip_adress& ip) {
    os <<  (int)std::get<0>(ip) << "."
           <<  (int)std::get<1>(ip) << "."
           <<  (int)std::get<2>(ip) << "."
           << (int) std::get<3>(ip) ;
        return os;
}

ip_adress getIP(const std::string &str, char d) {

    std::vector<uint8_t> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back( std::stoi(str.substr(start, stop - start)));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(std::stoi(str.substr(start)));
    return std::make_tuple( r.at(0), r.at(1), r.at(2), r.at(3) );
}


int main(int argc, char const *argv[])
{
    try
    {
        std::vector<ip_adress > ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(getIP(v.at(0), '.'));
        }

        // TODO reverse lexicographically sort

        sort(rbegin(ip_pool), rend(ip_pool));

        for (auto& ip : ip_pool) {
            std::cout << ip << std::endl;
        }

        // TODO filter by first byte and output

        for (auto& ip : ip_pool) {
            if (std::get<0>(ip) == 1)
                std::cout << ip << std::endl;
        }

        // TODO filter by first and second bytes and output
        for (auto& ip : ip_pool) {
            if (std::get<0>(ip) == 46 && std::get<1>(ip) == 70)
                std::cout << ip << std::endl;
        }

        // TODO filter by any byte and output

        for (auto& ip : ip_pool) {
            if (std::get<0>(ip) == 46 || std::get<1>(ip) == 46 || std::get<2>(ip) == 46 || std::get<3>(ip) == 46)
                std::cout << ip << std::endl;
        }


    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
