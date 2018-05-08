#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

using ip_adress = std::array<uint8_t, 4> ;

auto split(const std::string &str, const char& d)
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
    os << static_cast<int>(ip[0]) << '.' << static_cast<int>(ip[1]) << '.'
        << static_cast<int>(ip[2]) << '.' << static_cast<int>(ip[3]);
   return os;
}

ip_adress getIP(const std::string &str)
{
    auto v = split(str, '.');
    if (v.size() != 4)
        throw std::length_error("wrong ip format");

    ip_adress res;
    int i = 0;
    int tmp;

    for(const auto& e : v)
    {
        tmp = std::stoul(e);
        if(tmp > 255)
            throw std::invalid_argument("wrong ip");
        res[i++] = tmp;
    }

     return res;
}

