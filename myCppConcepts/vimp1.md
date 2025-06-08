Absolutely! Below are **detailed explanations** for the selected C++ MCQs:

---

### ✅ **2. Valid Lambda Declaration**

**Question:**
Which of the following is a valid way to declare a lambda function?

**Answer:**
**A. `auto f = [] { return 5; };`**

**Explanation:**
Lambda functions in C++11 and later are declared using the syntax:

```cpp
[ capture_list ] (parameter_list) -> return_type { body }
```

* Option A is correct — it’s a lambda with no captures, no parameters, and returns 5.
* Other options use incorrect syntax (`lambda` is not a keyword in C++).

---

### ✅ **4. `explicit` Constructor**

**Question:**
What does the keyword `explicit` prevent in constructors?

**Answer:**
**B. Implicit conversions**

**Explanation:**
The `explicit` keyword is used to **prevent implicit conversion** of types when a constructor takes a single argument.

Without `explicit`:

```cpp
class A {
public:
    A(int x) { ... }
};

A a = 10; // Implicit conversion
```

With `explicit`:

```cpp
explicit A(int x); // Now A a = 10; is a compile error
```

---

### ✅ **6. Defining Threads**

**Question:**
What is the correct way to define a thread in C++11?

**Answer:**
**A. `std::thread t(function);`**

**Explanation:**
`std::thread` is introduced in C++11.
To create a thread, pass a function (or lambda) to the constructor.

```cpp
std::thread t(my_function);  // Valid
```

Options B, C, and D are either invalid syntax or non-existent constructs.

---

### ✅ **8. Scoped Type-Safe Enums**

**Question:**
Which C++ feature provides type safety and scoped values?

**Answer:**
**C. `enum class`**

**Explanation:**
`enum class` (introduced in C++11) provides:

* **Type safety**: enum values won’t implicitly convert to `int`.
* **Scoped enums**: avoids polluting the global namespace.

```cpp
enum class Color { Red, Green };
Color c = Color::Red; // Scoped and safe
```

---

### ✅ **10. Non-virtual Functions**

**Question:**
Which function cannot be virtual in C++?

**Answer:**
**A. Constructor**

**Explanation:**
Constructors **cannot be virtual** because:

* A virtual constructor would require dynamic dispatch before an object is fully constructed.
* However, **destructors** can and often **should** be virtual in base classes.

---

### ✅ **13. Rule of Five**

**Question:**
What does the rule of five include?

**Answer:**
**A. Constructor, Destructor, Copy Constructor, Move Constructor, Copy Assignment Operator**

**Explanation:**
If your class **manages a resource**, you should define:

1. Default constructor
2. Destructor
3. Copy constructor
4. Copy assignment operator
5. Move constructor
6. Move assignment operator

C++11 introduced **move semantics**, expanding the old “Rule of 3” to the **Rule of 5**.

---

### ✅ **14. `emplace_back` Function**

**Question:**
What does `std::vector::emplace_back()` do?

**Answer:**
**C. Constructs in-place at the end**

**Explanation:**
`emplace_back()` constructs an object **directly in-place** at the end of the vector, avoiding a copy or move.

```cpp
vec.emplace_back(1, "hello"); // Constructs MyClass(1, "hello") in-place
```

More efficient than `push_back(MyClass(1, "hello"))` because it avoids a temporary.

---

### ✅ **16. Constructor Calls with Pass-by-Value**

**Question:**
How many times is a constructor called when an object is passed by value?

**Answer:**
**C. 2**

**Explanation:**

1. When passing the object to the function (copy constructor).
2. When returning the object from the function (copy or move constructor).

If Return Value Optimization (RVO) is applied, this may be reduced, but in general — **2 constructor calls** happen.

---

### ✅ **19. Object Slicing**

**Question:**
What is slicing in C++?

**Answer:**
**C. Losing derived part when assigning to base class**

**Explanation:**
Object slicing happens when a **derived object is assigned to a base class object** by value, and the derived part gets sliced off.

```cpp
Derived d;
Base b = d; // b gets only the Base part of d
```

To preserve polymorphism, use pointers or references instead.

---

### ✅ **20. RAII (Resource Acquisition Is Initialization)**

**Question:**
Which of these is used for RAII in C++?

**Answer:**
**C. Smart pointer**

**Explanation:**
RAII ensures that resources are tied to object lifetime.
When the object goes out of scope, the resource (memory, file, etc.) is automatically released.

Smart pointers like `std::unique_ptr` and `std::shared_ptr` are perfect examples of RAII.

---

### ✅ **21. Fast Insertion at Both Ends**

**Question:**
Which container allows fast insertion/removal at both ends?

**Answer:**
**B. `std::deque`**

**Explanation:**

* `std::vector` is fast at the **end**, slow at the **front**.
* `std::deque` (double-ended queue) is optimized for **both ends**.
* `std::list` allows fast insertions anywhere but not as cache-friendly.

---

### ✅ **22. Duplicate Keys in `std::map`**

**Question:**
Which is **not** a feature of `std::map`?

**Answer:**
**C. Allows duplicate keys**

**Explanation:**

* `std::map` does **not** allow duplicate keys.
* Use `std::multimap` if you need duplicates.
* `std::map` is sorted and allows **O(log n)** search and insertion.

---

### ✅ **25. Dynamic Polymorphism**

**Question:**
Which of the following supports dynamic polymorphism?

**Answer:**
**B. Virtual functions**

**Explanation:**

* Virtual functions enable **runtime dispatch** based on the object's actual type.
* Templates and function overloading are **compile-time** (static polymorphism).

```cpp
class Base {
    virtual void print();
};
```

---

Would you like the above in a printable PDF or turned into a quiz app format?
