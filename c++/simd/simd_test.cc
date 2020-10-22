#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <assert.h>

#include "simd_test_files/simd_test_sscal.hh"

template<class T, class SizeType>
std::string arr2str(T * arr, SizeType n) {
    if (n <= 1) { return ""; }
    
    std::stringstream rez;
    rez << "{";
    for (SizeType i = 0; i < n-1; i++) { rez << arr[i] << " "; }
    rez << arr[n-1] << "}";
    return rez.str();
}


int main(int argc, char ** argv)
{
    // Preamble
    typedef long int  SizeType;
    
    // Parse Data
    assert(argc > 1);
    SizeType n = atol(argv[1]);
    
    simd_test_sscal(n);

    
    return 0;
}