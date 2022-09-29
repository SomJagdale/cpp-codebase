1	Design goals - 
  Maintain stability and compatibility with C++98 and possibly with C
  Prefer introducing new features via the standard library, rather than extending the core language
  

2	Extensions to the C++ core language
  2.1	Core language runtime performance enhancements
    2.1.1	Rvalue references and move constructors
      
    2.1.2	constexpr – Generalized constant expressions
        constexpr int get_five() {return 5;}
        int some_value[get_five() + 7]; // Create an array of 12 integers. Valid C++11
    2.1.3	Modification to the definition of plain old data
    
  2.2	Core language build-time performance enhancements
    2.2.1	Extern template
        C++03 has this syntax to oblige the compiler to instantiate a template:
        template class std::vector<MyClass>;
        C++11 now provides this syntax:
        extern template class std::vector<MyClass>;
        which tells the compiler not to instantiate the template in this translation unit.

  2.3	Core language usability enhancements
    2.3.1	Initializer lists
    2.3.2	Uniform initialization
    2.3.3	Type inference
    2.3.4	Range-based for loop
    2.3.5	Lambda functions and expressions
    2.3.6	Alternative function syntax
    2.3.7	Object construction improvement
    2.3.8	Explicit overrides and final
    2.3.9	Null pointer constant
    2.3.10	Strongly typed enumerations
    2.3.11	Right angle bracket
    2.3.12	Explicit conversion operators
    2.3.13	Template aliases
    2.3.14	Unrestricted unions

  2.4	Core language functionality improvements
    2.4.1	Variadic templates
    2.4.2	New string literals
    2.4.3	User-defined literals
    2.4.4	Multithreading memory model
    2.4.5	Thread-local storage
    2.4.6	Explicitly defaulted special member functions
    2.4.7	Explicitly deleted functions
    2.4.8	Type long long int
    2.4.9	Static assertions
    2.4.10	Allow sizeof to work on members of classes without an explicit object
    2.4.11	Control and query object alignment
    2.4.12	Allow garbage collected implementations
    2.4.13	Attributes

3	C++ standard library changes
  3.1	Upgrades to standard library components
  3.2	Threading facilities
  3.3	Tuple types
  3.4	Hash tables
  3.5	Regular expressions
  3.6	General-purpose smart pointers
  3.7	Extensible random number facility
  3.8	Wrapper reference
  3.9	Polymorphic wrappers for function objects
  3.10	Type traits for metaprogramming
  3.11	Uniform method for computing the return type of function objects

4	Improved C compatibility

5	Features originally planned but removed or not included

6	Features removed or deprecated
