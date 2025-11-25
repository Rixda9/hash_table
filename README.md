# Hash Table Implementation

A hash table (hash map) implementation in C using separate chaining for collision resolution.

## Features

- Insert key-value pairs
- Retrieve values by key
- Delete entries
- Automatic collision handling via linked lists
- Memory-safe with proper cleanup

## Implementation Details

**Collision Resolution:** Separate chaining with linked lists

**Hash Function:** DJB2 variant (good distribution)

**Operations:**
- Insert: O(1) average case
- Get: O(1) average case
- Delete: O(1) average case

## Usage

```c
#include "hash_table.h"

HashTable *ht = hash_table_create(100);

hash_table_insert(ht, "name", "Alice");
hash_table_insert(ht, "age", "25");

char *name = hash_table_get(ht, "name");  // Returns "Alice"

hash_table_delete(ht, "age");

hash_table_destroy(ht);
```

## Building

```bash
gcc -Wall -Wextra -o test test.c hash_table.c
./test
```

## What I Learned

- Hash functions and collision handling
- Separate chaining with linked lists
- Memory management with dynamic structures
- O(1) average case lookup performance

## Limitations

- Fixed capacity (no automatic resizing)
- String keys and values only
- Not thread-safe
