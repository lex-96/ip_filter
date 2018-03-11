#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>


std::vector<std::vector<std::string> > ip_pool, ip_tmp;
int bit_pos = 0;


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


template<typename T>
void print_ip_pool(const T& ip_pool)
{
    for(auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        for(auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";

            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }

}

template<typename T>
auto filtrate(T& t, const int& bit_value,const int& bit_pos )
{
    std::vector<std::vector<std::string> > res;
    for(auto ip = t.cbegin(); ip != t.cend(); ++ip)
    {
        if (std::stoi((*ip).at(bit_pos)) == bit_value)
            res.push_back(*ip);
    }
    return res;
}


void filter ()
{
    print_ip_pool(ip_tmp);
    ip_tmp.clear();
    bit_pos = 0;
}

template<typename T, typename... Args>
void filter (T t, Args... args)
{
    if(ip_tmp.empty())
        ip_tmp = ip_pool;

    ip_tmp = filtrate(ip_tmp, t, bit_pos);
    //ip_tmp.emplase_back(filtrate(t, bit_pos));
    ++bit_pos;
    filter(args...);
}

//auto filter(const int& bit)
//{
//    std::vector<std::vector<std::string> > res;
//    for(auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
//    {
//        if (std::stoi((*ip).at(0)) == bit)
//            res.push_back(*ip);
//    }
//    return res;
//}

//auto filter(const int& bit1, const int& bit2)
//{
//    std::vector<std::vector<std::string> > res;
//    for(auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
//    {
//        if (std::stoi((*ip).at(0)) == bit1 && std::stoi((*ip).at(1)) == bit2)
//            res.push_back(*ip);
//    }
//    return res;
//}

auto filter_any(const int& bit)
{
    std::vector<std::vector<std::string> > res;
    for(auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        for(auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (std::stoi(*ip_part) == bit)
            {
                res.push_back(*ip);
                break;
            }
        }
    }
    return res;
}


int main(int argc, char const *argv[])
{
    try
    {
        for(std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }

        // TODO reverse lexicographically sort

        sort(begin(ip_pool),end(ip_pool),[] (const std::vector<std::string> &lhs, const std::vector<std::string> &rhs) {
            return std::make_tuple( std::stoi(lhs.at(0)), std::stoi(lhs.at(1)), std::stoi(lhs.at(2)), std::stoi(lhs.at(3)) )
                > std::make_tuple( std::stoi(rhs.at(0)), std::stoi(rhs.at(1)), std::stoi(rhs.at(2)), std::stoi(rhs.at(3)) );
        });

        print_ip_pool(ip_pool);


        // TODO filter by first byte and output

        //auto ip = filter(1);
        //print_ip_pool(ip);

        filter(1);


        // TODO filter by first and second bytes and output

        //ip = filter(46, 70);
        //print_ip_pool(ip);

        filter(46, 70);


        // TODO filter by any byte and output

        //ip = filter_any(46);

        auto ip = filter_any(46);
        print_ip_pool(ip);


    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
