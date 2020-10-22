#include "../timer.hpp"
#include "../memalign.hh"
#include "../simd_test_lib.hh"

template<class SizeType>
void simd_test_sscal(SizeType n) {
    timer mytimer;
    
    // Init test
    float a = 0.7;
    float * x_1 = new float[n];
    float * x_2 = new float[n];
    float * x_3 = new float[n];  memalign16(x_3, n);
    
    std::cout << "vvvvvvvvvvv" << std::endl;
    
    for (SizeType i = 0; i < n; i++) {
        x_1[i] = i;
        x_2[i] = i;
        x_3[i] = i;
    }
    
    std::cout << "vvvvvvvvvvv1" << std::endl;
    
    std::cout << "Started SIMD sscal test" << std::endl;
    std::cout << "N TIME_REG TIME_SSE TIME_SSE_ALIGNED" << std::endl;
    
    ////////////////////////////////////
    // Time regular multiplication
    ////////////////////////////////////
    mytimer.start();
    for (SizeType i = 0; i < n; i++) { x_1[i] *= a; }
    mytimer.stop();
    double t1 = mytimer.get_timing();

    ////////////////////////////////////
    // Time SSE multiplication
    ////////////////////////////////////
    mytimer.start();
    sscal(n, a, x_2);
    mytimer.stop();
    double t2 = mytimer.get_timing();

    std::cout << "uuuuuuuuu" << std::endl;
    
    ////////////////////////////////////
    // Time SSE aligned multiplication
    ////////////////////////////////////
    mytimer.start();
    sscal(n, a, x_3);
    mytimer.stop();
    double t3 = mytimer.get_timing();
    
    ////////////////////////////////////
    // Assert SSE is correct
    ////////////////////////////////////
    for (SizeType i = 0; i < n; i++) { assert(x_1[i] == x_2[i]); }

    
    ////////////////////////////////////
    // Output result
    ////////////////////////////////////
    std::cout << n << " " << t1 << " " << t2 << " " << t3 << " " << std::endl;
    
    
    ////////////////////////////////////
    // Assert SSE is correct
    ////////////////////////////////////
    delete x_1;
    delete x_2;
    delete x_3;
}