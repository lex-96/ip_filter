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
    os << static_cast<int>(ip[0]) << '.' << static_cast<int>(ip[1]) << '.'
        << static_cast<int>(ip[2]) << '.' << static_cast<int>(ip[3]);
   return os;
}

ip_adress getIP(const std::string &str) {
    const char dot = '.';
    ip_adress res;
    int i =0;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(dot);
    while(stop != std::string::npos)
    {
        auto part = std::stoul(str.substr(start, stop - start));
	if (part > 255)
		throw std::invalid_argument("wrong ip");
	res[i++] = part;
        start = stop + 1;
        stop = str.find_first_of(dot, start);
    }
    res[i] =  std::stoi(str.substr(start));
     return res;
}

