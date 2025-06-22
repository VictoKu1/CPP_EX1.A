# Snowman ASCII Art Generator

## Task

Write a function that draws a snowman using ASCII art!

The function should take an 8-digit number as input and return a string representation of a snowman. Each digit represents a different part of the snowman (hat, nose, eyes, arms, torso, base). The detailed specification of input and output can be found at: https://codegolf.stackexchange.com/q/49671/12019

For a demonstration of how the function should work, see the attached [Demo.cpp](Demo.cpp) file.

## Solution

### Phase 1 Requirements

You need to write the following files so that the following commands work without compilation errors:

```bash
make demo
./demo
make test
./test
```

### Required Files

* **snowman.hpp** - Header file for the function declaration
* **snowman.cpp** - Basic implementation of the function (doesn't need to be complete - just needs to compile)
* **Test.cpp** - Unit tests in doctest format. Write detailed tests and handle edge cases
  * You can see an example of tests in the TestExample.cpp file, but you need to write many additional tests
  * In this course, we write tests before implementation, so most tests will fail initially - this is expected. The complete implementation will be written in part 2 of the assignment

### Code Quality

It's recommended to ensure the following command runs without warnings (requires clang-tidy installation):

```bash
make tidy
```

### Important Notes

* Do not modify existing files, only add new files
* The automatic testing system will overwrite all existing files on top of your submitted solution
* Therefore, any changes you make to existing files will be deleted

### Function Signature

```cpp
namespace ariel {
    std::string snowman(int dna);
}
```

The function takes an 8-digit integer where each digit represents a different snowman component and returns an ASCII art string representation of the snowman.

### Example Usage

```cpp
cout << ariel::snowman(11114411) << endl;
// Output:
// _===_
// (.,.)
// ( : )
// ( : )

cout << ariel::snowman(33232124) << endl;
// Output:
// _
// /_\
// \(o_O)
// (] [)>
// (   )
```

### Error Handling

The function should throw an exception for invalid input codes:

```cpp
try {
    cout << ariel::snowman(5) << endl; // Exception - not a valid code
} catch (exception &ex) {
    cout << "caught exception: " << ex.what() << endl; // should print "Invalid code '5'"
}
```

## Testing Framework

### Doctest Overview

This project uses **doctest**, a lightweight C++ testing framework that provides a simple and intuitive way to write unit tests. Doctest is a single-header library that requires no external dependencies and integrates seamlessly with your build system.

### Test Structure

Tests are written in the `Test.cpp` file using the doctest framework. Here's the basic structure:

```cpp
#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

TEST_CASE("Test case description") {
    // Test assertions here
    CHECK(condition);
    CHECK_EQ(actual, expected);
    CHECK_THROWS(function_call());
}
```

### Key Testing Macros

* **`CHECK(condition)`** - Asserts that a condition is true
* **`CHECK_EQ(actual, expected)`** - Asserts that two values are equal
* **`CHECK_THROWS(expression)`** - Asserts that an expression throws an exception
* **`CHECK_THROWS_AS(expression, exception_type)`** - Asserts that an expression throws a specific exception type
* **`CHECK_NOTHROW(expression)`** - Asserts that an expression doesn't throw an exception

### Test Categories

Your `Test.cpp` should include comprehensive tests covering:

1. **Valid Input Tests** - Test various valid 8-digit codes and verify correct ASCII art output
2. **Invalid Input Tests** - Test edge cases like:
   - Numbers with fewer than 8 digits
   - Numbers with more than 8 digits
   - Numbers containing invalid digits (0, 5-9)
   - Negative numbers
   - Zero
3. **Boundary Tests** - Test the minimum and maximum valid codes
4. **Exception Tests** - Verify that invalid inputs throw appropriate exceptions

### Test Helper Functions

The `TestExample.cpp` file provides a useful helper function:

```cpp
string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}
```

This function removes whitespace characters, making it easier to compare ASCII art strings that might have different formatting.

### Running Tests

```bash
make test    # Compile and run all tests
./test       # Run the test executable
```

## Code Quality Tools

### Clang-Tidy

**Clang-tidy** is a powerful static analysis tool that helps identify potential bugs, style violations, and performance issues in C++ code. It's integrated into the build system via the `make tidy` command.

#### What Clang-Tidy Checks

The project's clang-tidy configuration checks for:

* **Bug-prone patterns** - Common programming mistakes and anti-patterns
* **Clang analyzer** - Static analysis for potential runtime issues
* **C++ Core Guidelines** - Modern C++ best practices
* **High Integrity C++** - Safety and reliability guidelines
* **Performance issues** - Code that could be optimized
* **Portability** - Platform-specific code that might not work elsewhere
* **Readability** - Code style and formatting issues

#### Running Clang-Tidy

```bash
make tidy
```

This command will analyze your `snowman.cpp` file and report any issues found. The tool is configured to treat warnings as errors, ensuring high code quality standards.

#### Common Issues to Watch For

* Unused variables or parameters
* Potential null pointer dereferences
* Memory leaks
* Inefficient algorithms
* Non-portable code constructs
* Style violations

## Build System

### Makefile Overview

The project uses a **Makefile** to automate the build process, testing, and code quality checks. The Makefile provides several targets for different tasks.

### Available Make Targets

#### `make demo`
Compiles the demonstration program that shows how the `snowman` function should work.

**Dependencies**: `Demo.o`, `snowman.o`
**Output**: `demo` executable

#### `make test`
Compiles and links the test suite with your implementation.

**Dependencies**: `TestCounter.o`, `Test.o`, `snowman.o`
**Output**: `test` executable

#### `make tidy`
Runs clang-tidy static analysis on your code to check for potential issues.

**Target**: `snowman.cpp`
**Checks**: Multiple categories of static analysis

#### `make clean`
Removes all compiled object files and executables to ensure a clean build.

**Removes**: `*.o`, `demo`, `test`, `Test2.cpp`

### Build Configuration

The Makefile is configured with the following settings:

* **Compiler**: `clang++-9`
* **C++ Standard**: `C++2a`
* **Flags**: `-Werror` (treats warnings as errors)
* **Header**: `snowman.hpp`

### Build Process

1. **Object File Generation**: Each `.cpp` file is compiled to a `.o` object file
2. **Linking**: Object files are linked together to create executables
3. **Dependencies**: The build system automatically tracks dependencies between files

### Development Workflow

1. Write your implementation in `snowman.cpp`
2. Write comprehensive tests in `Test.cpp`
3. Run `make test` to compile and test your code
4. Run `make tidy` to check code quality
5. Run `make demo` to see your implementation in action
6. Use `make clean` when you need a fresh build

### Troubleshooting

* If compilation fails, check that all required files exist
* If tests fail, review your implementation against the test cases
* If clang-tidy reports issues, address them before submitting
* Use `make clean` followed by `make test` if you encounter build issues
