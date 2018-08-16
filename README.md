Memory Allocation
=================

The effect of memory issues like allocation time, cache effects or alignment on the performance of a program is widely underestimated.
Here we collect some experiments and information on the topic.


Aligned Allocation
------------------

- Part of C++11 in the [`memory`](https://en.cppreference.com/w/c/memory/aligned_alloc) header.
- Probably calls either the Windows equivalent [`_aligned_malloc`](https://msdn.microsoft.com/en-us/library/8z34s9c6.aspx) or one of the
- [POSIX](https://www.gnu.org/software/libc/manual/html_node/Aligned-Memory-Blocks.html) variants like `aligned_alloc` or `memalign`


Prefetching
-----------

Indeed there are some functions to [control the cache](https://en.wikipedia.org/wiki/Cache_control_instruction), like the
`__builtin_prefetch` in GCC (also available in Clang).

### Automatic Prefetching
"In recent times [...] application processor designs from Intel and ARM devote more transistors to accelerating [...] performing automatic prefetch, with hardware to detect linear access patterns on the fly"
