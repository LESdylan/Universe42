`HASH_SIZE` is the number of buckets in the hash table. we use this values because it is  a reasonable size for spreading out hash entries (code points) to reduce collisions
The hash table is used to efficiently count occurences of each Unicode code point int he message

---
# 2. initialize structure
initialize all buckets to `NULL` ensure we don't have undefined behavior when we later access them. We might dereference garbage pointer causing the `segmentation fault`


---
