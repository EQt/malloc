Memory Allocation
=================

The effect of memory issues like allocation time, cache effects or alignment on the performance of a program is widely underestimated.
Here we collect some experiments and information on the topic.


Aligned Allocation
------------------

- Part of C++11 in the [`memory`](https://en.cppreference.com/w/c/memory/aligned_alloc) header.
- Probably calls either the Windows equivalent [`_aligned_malloc`](https://msdn.microsoft.com/en-us/library/8z34s9c6.aspx) or one of the
- [POSIX](https://www.gnu.org/software/libc/manual/html_node/Aligned-Memory-Blocks.html) variants like `aligned_alloc` or `memalign`
