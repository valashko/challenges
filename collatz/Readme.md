All versions:
- assume valid input in base 10

Naive version (37 minutes):
- does not account for overflow during computation
- has no optimizations

Improved version (11 minutes):
- accounts for overflow during computation
- has fast return for powers of 2

Memento version (19 minutes):
- does not account for overflow during computation
- saves the results from previous runs for sequences above certain length

As measurements show, improved version turned out to be rubbish.
Caching previous results did not improve running time either.

```shell
❯ time ./naive/cmake-build-release/Collatz 50000000
Starting number 36791535 has the longest sequence of 745
./naive/cmake-build-release/Collatz 50000000  9.45s user 0.01s system 99% cpu 9.471 total

❯ time ./improved/cmake-build-release/Collatz 50000000 # w/ overflow check
Starting number 36791535 has the longest sequence of 745
./improved/cmake-build-release/Collatz 50000000  16.55s user 0.02s system 99% cpu 16.596 total

❯ time ./improved/cmake-build-release/Collatz 50000000 # w/o overflow check
Starting number 36791535 has the longest sequence of 745
./improved/cmake-build-release/Collatz 50000000  13.41s user 0.01s system 96% cpu 13.961 total

❯ time ./memento/cmake-build-release/Collatz 50000000
Starting number 36791535 has the longest sequence of 745
./memento/cmake-build-release/Collatz 50000000  17.39s user 0.83s system 96% cpu 18.785 total
```

Future considerations:
- I believe there is potential in the memento version. According to profiling results,
  `Collatz::impl` accounted for 62.99% of CPU time. Rest is `new` (12.73%), `free` (13.63%) and `rehash` (2.83%).
  Pre-allocating a buffer at startup and pointing the hash table there could be a next step.
- Naive implementation could be effectively split between several threads since no data needs to be shared.
- Low-level optimizations could be considered as well.
- For certain use cases memento implementation would be superior. The most extreme optimization would be
  precomputing all values in the expected input range at start.
