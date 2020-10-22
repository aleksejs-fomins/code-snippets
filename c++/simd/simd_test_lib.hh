#include <emmintrin.h>

template<class SizeType>
void sscal(SizeType n, float a, float *x) {

    __m128 x0 = _mm_set1_ps(a);

    SizeType ndiv4 = n/4;
    
    for (SizeType i=0; i<ndiv4; ++i) {
        __m128 x1 = _mm_load_ps(x+4*i); // Load aligned data
        __m128 x2 = _mm_mul_ps(x0, x1); // multiply
        _mm_store_ps(x+4*i, x2);        // Store back aligned data
    }

    // do the remaining entries
    SizeType i = ndiv4 * 4;
    switch(n-i) {
        case 3: x[i+2] *= a;
        case 2: x[i+1] *= a;
        case 1: x[i] *= a;
    }
}