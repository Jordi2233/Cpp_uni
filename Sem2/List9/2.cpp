#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <cstdlib>

template <typename T> std::ostream& operator<<(std::ostream& os, std::vector<T> v)
{
    // print on screen all elements of vector
    for (auto& i: v)
    {
        os << i << " ";
    }
    return os;
}

// functor that returns square of integer a
int functor(int a) { return a*a; }

// functor that returns random int between 0 and 14
int functor_random_number_v2() { return rand() % 15; }

int main()
{
    // two vectors, size - 10
    std::vector<int> v1(10);
    std::vector<int> v2(10);
    // write numbers between 0 and 9 to vector v1
    std::iota(v1.begin(), v1.end(), 0);
    // print them
    std::cout << "v1: 0-10\n" << v1 << std::endl;



    // sum of vector elements
    std::cout << "Sum of v1 elements:\n" << std::accumulate(v1.begin(), v1.end(),0) << "\n";


    
    // change every element of vector into their square, using lambda
    //std::transform(v1.begin(),v1.end(), v1.begin(),[](int a){return a*a;});
    // change every element of vector into their square, using funktor
    std::transform(v1.begin(),v1.end(), v1.begin(),functor);
    std::cout << "v1: squares\n";
    std::cout << v1 << std::endl;



    // start new time to get always new random integers
    srand( time( NULL ) );
    // write ten random numbers to vector v2 by lambda
    std::generate(v2.begin(), v2.end(), [](){ return rand() % 15 ;});
    // write ten random numbers to vector v2 by functor
    //std::generate(v2.begin(), v2.end(),functor_random_number_v2);
    std::cout << "Random numbers between 0-14 vector v2:\n";
    std::cout << v2 << std::endl;


    // max element of v2
    std::cout << "Max element of vector v2:\n";
    std::cout << *std::max_element(v2.begin(),v2.end()) << "\n";

    //sorting vector v2 min to max
    std::sort(v2.begin(), v2.end());
    std::cout << "Sorted vector v2:\n";
    std::cout << v2 << std::endl;

    // set unique elements first
    std::unique(v2.begin(), v2.end());
    std::cout << "Unique elements first\n";
    std::cout << v2 << std::endl;

    //deleting non unique elements from v2
    sort( v2.begin(), v2.end() );
    v2.erase( std::unique( v2.begin(), v2.end() ), v2.end() );
    std::cout << "Deleting non unique elements from vector v2\n";
    std::cout << v2 << std::endl;

    // create new empty vector v3
    std::vector<int> v3;
    // multiple product of two sets v1,v2
    std::set_intersection(v1.begin(),v1.end(), v2.begin(), v2.end(), std::back_inserter(v3));
    std::cout << "Vector v3 - intersections of v1 and v2\n";
    std::cout << v3 << std::endl;

    return 0;
}