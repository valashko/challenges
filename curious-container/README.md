Implement a container that supports the following operations:

* `init()`
* `get(index)`
* `set(index, value)`
* `set_all(value)`

The container has to satisfy these requirements:
* Call to `init` is performed once and can take as much resources as needed
* `get`, `set`, and `set_all` operations shall have constant computational complexity
* Call to `get` after `set` with same index or `set_all` shall return the value which has been previously set
