# Hash Table

Hash table combines the random access ability of an array with the dynamism of a linked list;
while mitigating the disadvantages of these data structures.


## Hash Table Properties:

    Insertion       →Θ(1)
    Deletion        →Θ(1)
    Lookup          →Θ(1)

[Math Symbols](http://www.uefap.com/speaking/symbols/symbols.htm)

Hash Table is a data structure whereby when we insert data into the structure, the data itself
gives us a clue about where we will find the data, should we need to look it up later.

The trade-off is that a hash table is not great at ordering or sorting data.

### Hash Table is a combination of two things:

1. Hash Function, which returns a non-negative integer valued called a _hash code_.
2. Array, capable of storing data of the type we wish to place into the data structure.


## How it works?

The data is run through the hash function, and then stored in the element of the array
represented by the returned hash code.


## Collisions

A collision occurs when two pieces of data, when run through the hash function, yield the same hash code.

Since we want both pieces of data in the hash table, we shouldn't simply overwrite the data that
happened to be placed in there first.


## Resolving Collisions

### Linear Probing

In this method, if we have a collision, we try to place the data in the next consecutive element
in the array (wrapping around to the beginning if necessary) until we find a vacancy.

When it comes to lookup, if we don't find what we're looking for in the hash code location,
hopefully the element is somewhere nearby.

#### Clustering

Linear Probing is subject to a problem called *clustering*.

Once there's a miss, two adjacent cells will contain data, making it more likely in the future
that the cluster will grow.

This highlights the fundamental problem with storing the data directly in the array of the hash table,
we can only store as much data as we have locations in our array.

(?) There are other probing techniques; but fundamentally there are better solutions to avoid collisions altogether.

### Chaining

Instead of each element of the array holding just one piece of data, we can store a pointer
to the head of a linked list; allowing the data that yields the same hash code to be stored together.

This method eliminates clustering.

Complexity:

    Insertion   O(1)
    Deletion    O(1)
    Lookup      →Θ(1)

Given a good hash function, we need to search through what is hopefully a small list,
since we're distributing what would otherwise be a huge list across _n_ lists.

i.e. if the hash table size is 10, the lookup is O(n)/10; we're distributing one long chain (n) across 10 different chains.


## Non-Cryptographic Hash Algorithms (Hash Functions)

A good hash function should:

1. Use only the data being hashed
2. Use all the data being hashed
3. Be deterministic (consistent, no randomness)
4. Uniformly distribute data
5. Generate very different hash codes for very similar data

* [StackOverflow Discussion](https://softwareengineering.stackexchange.com/questions/49550/which-hashing-algorithm-is-best-for-uniqueness-and-speed)
* [Aras Blog - Hash Functions Comparison - Part 1](https://aras-p.info/blog/2016/08/02/Hash-Functions-all-the-way-down/)
* [Aras Blog - Hash Functions Comparison - Part 2](https://aras-p.info/blog/2016/08/09/More-Hash-Function-Tests/)
* [OpenSSL strhash()](https://raw.githubusercontent.com/openssl/openssl/master/crypto/lhash/lhash.c)


`size_t` is an unsigned integer type of at least 16 bit that is used to represent the size of an object.

It is defined in `stddef.h`, `size_t` is a type guaranteed to hold any array index.


## Optimizing for the CPU

`lscpu` - lists information about the installed CPUs

`cat /proc/cpuinfo` - lists technical information about the installed CPUs (i.e. instruction sets)
