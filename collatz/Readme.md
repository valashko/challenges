All versions:
- assume valid input in base 10

Naive version (37 minutes):
- does not account for overflow during computation
- has no optimizations

Improved version (11 minutes):
- accounts for overflow during computation
- has fast return for powers of 2

As measurements show, improved version turned out to be rubbish.

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
```
