Implement a homogeneous (i.e. all elements have the same type) container that supports the following operations:

* `init()` initializes a container of predefined size; may be implemented as a constructor instead of a seperate method
* `get(index)` returns an element at `index`; the index is a number between 0 and 2<sup>32</sup>-1
* `set(index, value)` sets an element at `index` to `value`
* `set_all(value)` sets all elements to `value`

The container has to satisfy these requirements:
* Call to `init` is performed once and can take as much resources as needed
* `get`, `set`, and `set_all` operations shall have constant computational complexity
* Call to `get` after `set` with same index or `set_all` shall return the value which has been previously set
