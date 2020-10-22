
template <class ctype, class SizeType>
void memalign16(ctype * a, SizeType n) {
    if (posix_memalign((void**) & a, 16,  n * sizeof(ctype))) { throw std::bad_alloc(); }
}

