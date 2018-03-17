#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <array>

using ip_adress = std::array<uint8_t, 4> ;

auto split(const std::string &str, const char& d)
{
    std::vector<std::string> r;
    r.reserve(3);

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
    os << (int)ip.at(0) << '.' << (int)ip.at(1) << '.'
        << (int)ip.at(2) << '.' << (int)ip.at(3);
   return os;
}

ip_adress getIP(const std::string &str) {
    const char dot = '.';
    ip_adress rez;
    int i =0;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(dot);
    while(stop != std::string::npos)
    {
        rez[i++] = std::stoi(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of(dot, start);
    }
    rez[i] =  std::stoi(str.substr(start));
     return rez;
}

