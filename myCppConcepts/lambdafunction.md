You got it! Lambda expressions are incredibly versatile. Here are some different examples, showcasing various features and common use cases:

### 1. Simple Lambda (No captures, no parameters)

The most basic form, essentially a block of code.

```cpp
#include <iostream>

int main() {
    // A lambda that just prints a message
    auto greet = []() {
        std::cout << "Hello from a simple lambda!" << std::endl;
    };

    greet(); // Call the lambda

    // You can also invoke it immediately (IIFE - Immediately Invoked Function Expression)
    []() {
        std::cout << "This lambda runs immediately!" << std::endl;
    }(); // The '()' at the end invokes it

    return 0;
}
```

### 2. Lambda with Parameters

Just like regular functions, lambdas can take arguments.

```cpp
#include <iostream>

int main() {
    // Lambda to add two integers
    auto add = [](int a, int b) {
        return a + b;
    };

    int sum = add(5, 3);
    std::cout << "Sum: " << sum << std::endl; // Output: Sum: 8

    // Lambda to print a string multiple times
    auto repeat_message = [](const std::string& msg, int count) {
        for (int i = 0; i < count; ++i) {
            std::cout << msg << std::endl;
        }
    };

    repeat_message("Repeat after me!", 2);
    // Output:
    // Repeat after me!
    // Repeat after me!

    return 0;
}
```

### 3. Lambda with Explicit Return Type

While the compiler often deduces the return type, you can specify it explicitly using `-> return_type`. This is useful for complex types or when the body contains multiple return paths with different (but convertible) types.

```cpp
#include <iostream>
#include <string>

int main() {
    // Lambda that returns a double, explicitly specified
    auto divide = [](double a, double b) -> double {
        if (b == 0) {
            return 0.0; // Or throw an exception, depending on error handling
        }
        return a / b;
    };

    std::cout << "Division result: " << divide(10.0, 3.0) << std::endl; // Output: 3.33333

    // Lambda returning a string (compiler would deduce this anyway)
    auto create_greeting = [](const std::string& name) -> std::string {
        return "Hello, " + name + "!";
    };
    std::cout << create_greeting("Alice") << std::endl; // Output: Hello, Alice!

    return 0;
}
```

### 4. Lambda with Capture by Value (`[variable]` or `[=]`)

This is where lambdas become truly powerful: capturing variables from their surrounding scope.

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For std::for_each

int main() {
    int x = 10;
    int y = 20;

    // Capture 'x' by value: a copy of x (10) is made when the lambda is created.
    auto lambda_capture_x = [x]() {
        // x is 10 here, even if outer x changes later
        std::cout << "Captured x (by value): " << x << std::endl;
    };
    lambda_capture_x(); // Output: Captured x (by value): 10

    x = 100; // Change outer x
    lambda_capture_x(); // Still Output: Captured x (by value): 10 (because it's a copy)

    // Capture all used variables by value (`[=]`)
    auto lambda_capture_all_by_value = [=]() {
        // x and y are copies of their values at the time of lambda creation
        std::cout << "Captured x (by value): " << x << ", y (by value): " << y << std::endl;
    };
    lambda_capture_all_by_value(); // Output: Captured x (by value): 100, y (by value): 20

    // Example with std::for_each and capture
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int factor = 5;

    std::cout << "Multiplied numbers: ";
    std::for_each(numbers.begin(), numbers.end(), [factor](int n) {
        std::cout << (n * factor) << " ";
    });
    std::cout << std::endl; // Output: Multiplied numbers: 5 10 15 20 25

    return 0;
}
```

### 5. Lambda with Capture by Reference (`[&variable]` or `[&]`)

Capturing by reference allows the lambda to access and modify the original variable.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int counter = 0;

    // Capture 'counter' by reference: the lambda accesses the original variable.
    auto increment_counter = [&counter]() {
        counter++;
        std::cout << "Counter: " << counter << std::endl;
    };

    increment_counter(); // Output: Counter: 1
    increment_counter(); // Output: Counter: 2
    std::cout << "Final counter in main: " << counter << std::endl; // Output: Final counter in main: 2

    std::vector<int> values = {10, 20, 30};
    int sum_of_values = 0;

    // Capture all used variables by reference (`[&]`)
    std::for_each(values.begin(), values.end(), [&](int val) {
        sum_of_values += val; // Modifies the original sum_of_values
    });
    std::cout << "Sum of values: " << sum_of_values << std::endl; // Output: Sum of values: 60

    return 0;
}
```

### 6. Lambda with `mutable` (for modifying captured-by-value variables)

By default, the `operator()` of a lambda is `const`. If you capture by value and want to modify the *copy* of the captured variable within the lambda, you need the `mutable` keyword.

```cpp
#include <iostream>

int main() {
    int value = 5;

    // Capture 'value' by value, but allow modification of the *copy*
    auto modify_captured_value = [value]() mutable {
        std::cout << "Inside lambda (before modify): " << value << std::endl;
        value += 10; // This modifies the lambda's copy of 'value'
        std::cout << "Inside lambda (after modify): " << value << std::endl;
    };

    modify_captured_value(); // Output:
                             // Inside lambda (before modify): 5
                             // Inside lambda (after modify): 15

    std::cout << "Outside lambda: " << value << std::endl; // Output: Outside lambda: 5
                                                            // Original 'value' is unchanged

    return 0;
}
```

### 7. Lambda for Custom Sorting (`std::sort`)

A very common and powerful use case for lambdas is providing custom comparison functions to algorithms.

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <string>

struct Person {
    std::string name;
    int age;
};

int main() {
    std::vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35},
        {"David", 25}
    };

    // Sort people by age in ascending order
    std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        return a.age < b.age;
    });

    std::cout << "Sorted by age (ascending):" << std::endl;
    for (const auto& p : people) {
        std::cout << p.name << " (" << p.age << ")" << std::endl;
    }
    // Output:
    // Bob (25)
    // David (25)
    // Alice (30)
    // Charlie (35)

    // Sort people by name length (descending)
    std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        return a.name.length() > b.name.length();
    });

    std::cout << "\nSorted by name length (descending):" << std::endl;
    for (const auto& p : people) {
        std::cout << p.name << " (" << p.age << ")" << std::endl;
    }
    // Output:
    // Charlie (35)
    // Alice (30)
    // David (25)
    // Bob (25)

    return 0;
}
```

### 8. Lambdas with `std::function` (for type erasure)

While `auto` is great for storing lambda types, `std::function` allows you to store *any* callable object (lambda, function pointer, functor) that matches a specific signature, providing type erasure.

```cpp
#include <iostream>
#include <functional> // For std::function

int main() {
    // A lambda that adds two ints and returns an int
    auto my_add_lambda = [](int a, int b) {
        return a + b;
    };

    // Store the lambda in a std::function object
    std::function<int(int, int)> func = my_add_lambda;

    std::cout << "Result from std::function: " << func(10, 5) << std::endl; // Output: 15

    // Another lambda, stored in the same std::function
    func = [](int a, int b) {
        return a * b;
    };
    std::cout << "New result from std::function: " << func(10, 5) << std::endl; // Output: 50

    // Lambda that captures a variable
    int offset = 100;
    std::function<int(int)> add_offset_func = [offset](int val) {
        return val + offset;
    };

    std::cout << "Result with offset: " << add_offset_func(20) << std::endl; // Output: 120

    return 0;
}
```

These examples demonstrate the flexibility and power of lambda expressions in C++, covering basic usage to more advanced scenarios involving captures, `mutable`, and integration with the Standard Library.
