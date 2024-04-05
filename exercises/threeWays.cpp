#include <iostream>
#include <vector>
#include <algorithm>

// use STL algorithm to check if all elements are divisible by 3
// implement 3 versions:
// * lambda
// * functor
// * function

bool check_divisibility(int divident)
{
    return (divident % 3 == 0);
}

struct DivisiblityChecker {
  DivisiblityChecker(int _divisor)
          :divisor{_divisor} { };

  bool operator()(int dividend)
  {
      return (dividend % divisor == 0);
  }
  int divisor;
};

auto check_divisibility_named_lambda = [](int dividend) {
  return (dividend % 3 == 0);
};

int main()
{
    std::vector<unsigned int> numbers = {18, 21, 36, 90, 27, 14, 103};
    std::vector<unsigned int> numbers2 = {3, 6, 9, 15, 18, 21, 24};
    bool all_numbers_divisible;

    all_numbers_divisible = std::all_of(numbers.begin(), numbers.end(),
            check_divisibility);
    std::cout << "Function: " << std::boolalpha << all_numbers_divisible
              << std::endl;

    all_numbers_divisible = std::all_of(numbers.begin(), numbers.end(),
            DivisiblityChecker{3});
    std::cout << "Functor: " << std::boolalpha << all_numbers_divisible
              << std::endl;

    all_numbers_divisible = std::all_of(numbers.begin(), numbers.end(),
            check_divisibility_named_lambda);
    std::cout << "Named lambda: " << std::boolalpha << all_numbers_divisible
              << std::endl;

    all_numbers_divisible = std::all_of(numbers.begin(), numbers.end(),
            [](int dividend) { return dividend % 3 == 0; });
    std::cout << "Unnamed lambda: " << std::boolalpha << all_numbers_divisible
              << std::endl;

    std::cout << "---------------------------" << std::endl;
    all_numbers_divisible = std::all_of(numbers2.begin(), numbers2.end(),
            check_divisibility);
    std::cout << "Function: " << std::boolalpha << all_numbers_divisible
              << std::endl;

    all_numbers_divisible = std::all_of(numbers2.begin(), numbers2.end(),
            DivisiblityChecker{3});
    std::cout << "Functor: " << std::boolalpha << all_numbers_divisible
              << std::endl;

    all_numbers_divisible = std::all_of(numbers2.begin(), numbers2.end(),
            check_divisibility_named_lambda);
    std::cout << "Named lambda: " << std::boolalpha << all_numbers_divisible
              << std::endl;

    all_numbers_divisible = std::all_of(numbers2.begin(), numbers2.end(),
            [](int dividend) { return dividend % 3 == 0; });
    std::cout << "Unnamed lambda: " << std::boolalpha << all_numbers_divisible
              << std::endl;

    return 0;
}
