#include <array>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <utility>
using std::cout;
using std::size_t;


template< class T, size_t N >
class curious_container
{
public:
  constexpr size_t size() const
  {
    return N;
  }

  void init()
  { }
  
  T get(size_t index) const
  {
    assert_index(index);
    const auto & element_at_index = data[index];
    if(value_for_all < element_at_index) {
      return element_at_index.value;
    } else {
      return value_for_all.value;
    }
  }
  
  void set(size_t index, T value)
  {
    assert_index(index);
    data[index] = std::move(value);
  }

  void set_all(T value)
  {
    value_for_all = std::move(value);
  }

private:
  void assert_index(size_t index) const
  {
    assert(index < data.size());
  }

  template< class E >
  struct element
  {
    element() = default;

    element(const E& v)
    : value{v}
    { }

    element(E&& v)
    : value{std::move(v)}
    { }

    element& operator=(const element&) = default;
    element& operator=(element&&) = default;
    ~element() = default;
    
    bool operator<(const element & other) const
    {
      return id < other.id;
    }

    using id_t = long;
    static id_t next()
    {
      static id_t id{};
      return id++;
    }
    

    id_t id{next()};
    E value;
  };


  std::array< element<T>, N > data;
  element<T> value_for_all;
};


int main()
{
  auto print = [](const auto & cc) {
    for(size_t i = 0; i < cc.size(); ++i) {
      cout << cc.get(i) << ' ';
    }
  };
  auto fill = [](auto & cc) {
    for(size_t i = 0; i < cc.size(); ++i) {
      cc.set(i, i);
    }
  };

  curious_container< int, 10 > cc{};
  
  cout << "Just filled with consequent numbers: ";
  fill(cc);
  print(cc);
  cout << '\n';
  
  cout << "All set to 0: ";
  cc.set_all(0);
  print(cc);
  cout << '\n';
  
  cout << "First set to 42: ";
  cc.set(0, 42);
  print(cc);
  cout << '\n';
  
  cout << "Last set to 42: ";
  cc.set(cc.size() - 1, 42);
  print(cc);
  cout << '\n';
  
  return 0;
}

