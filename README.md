*This project has been created as part of the 42 curriculum by adeestev.*


## Description

C++ Module 06 dives into the intricacies of C++ type casting. Moving away from implicit C-style casts, this module explores strict, specific casting operators introduced in C++98: static_cast, reinterpret_cast and , dynamic_cast. The exercises focus on converting scalar types, serializing data pointers into raw integer representations, and utilizing Run-Time Type Information (RTTI) to safely identify object types at runtime.


## Exercises Overview

* **Exercise 00: Scalar Converter**

	Requires the implementation of a static ScalarConverter class that takes a string representation of a C++ literal (char, int, float, or double) and converts it to the other three scalar types. The program must handle edge cases gracefully, including non-displayable characters, overflow limits, and pseudo-literals (e.g., -inff, +inf, nan).

* **Exercise 01: Serialization**

	Focuses on reinterpret_cast. It implements a static Serializer class with methods to convert a pointer to a Data structure into an unsigned integer type (uintptr_t), and vice-versa. The goal is to prove that the raw memory address remains completely intact and accessible after serialization and deserialization.

* **Exercise 02: Identify real type**

	Explores dynamic_cast and RTTI. The program randomly instantiates one of three derived classes (A, B, or C) that inherit from a virtual base class. It then attempts to identify the object's true type using both pointers (which return NULL upon a failed cast) and references (which throw an exception upon failure).


## Instructions

Each exercise is isolated in its own directory (ex00 to ex02) and must be compiled independently.

* **Compiler:** c++

* **Compilation Flags:** -Wall -Wextra -Werror -std=c++98

* **Execution:** Run make inside the respective directory to build the executable and run the generated binary (with appropriate argument for Exercise 00). Memory leaks are strictly forbidden.


## Resources

* **Documentation:** C++98 standard references for type casting (static_cast, dynamic_cast, reinterpret_cast).
