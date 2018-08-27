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



Buffer Protocol
===============

This is not directly related to memory allocation.
However, the issue of providing low level access to memory, appeared in many situations, namely PyBind11, 
[PyArrow](http://arrow.apache.org/docs/python/memory.html) or for 
[saving memory in Python](https://eli.thegreenplace.net/2011/11/28/less-copies-in-python-with-the-buffer-protocol-and-memoryviews).
All of them make use of the
[Python Buffer Protocol](https://docs.python.org/3/c-api/buffer.html#bufferobjects).


C++
===

Some of the ownership ideas of Rust are already implemented in the header
[`memory`](https://mbevin.wordpress.com/2012/11/18/smart-pointers), though there are a lot of 
[pitfalls](http://www.acodersjourney.com/2016/05/top-10-dumb-mistakes-avoid-c-11-smart-pointers/) in using them correctly.
For instance
```c++
std::unique_ptr<char> a (new char[256])
```
versus
```c++
std::unique_ptr<char[]> a (new char[256])
```

std::make_shared
---------------

... is useful for what?

1. Shorter notation
2. Combines the `new` operation of the `std::shared_ptr` and the underlying object.


Address Sanitization
==================

TODO: How does it work?
Integrate an example...

