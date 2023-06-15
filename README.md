# Blaze Language
Foundationally created via reading / studying the book [**Crafting Interpreters** by **Robert Nystrom**](https://craftinginterpreters.com/).

Will be extended to be switched into the Blaze Language.

## Language Breakdown (in lang.blaze)
```kotlin

// Single-Line Comment
//

// Data Types
45          // Numbers
"foo"       // Strings
nil         // Null
true false  // Booleans
[]          // Lists

// Arithmetic Operations
+ - * /

// Comparison Operations
< <= > >= == and or

// Variable Declaration
var foo;
var bar = "foo";

// Variable Assignment
foo = 69;

// Lists
var list = [1, "apple", true, nil];
list[0]     // Access an index of a list
list[-1]    // Access an index from the negative range (-1 = last item in the list)

// User-Defined Functions
fun foo() {
    var bar = true;
    
    return bar;     // Return Statements
}

// Nested User-Defined Functions
fun foo() {
    var test = true;

    // Nested Scopes
    fun bar() {
        return test;
    }

    var resultOfTest = bar();
    return resultOfTest;
}

// Conditionals
if (10 > 10) {
    var a = 10;
} else if (10 == 10) {
    var a = 11;
} else {
    var a = 0;
}

// For Loops
for (var i = 0; i < 10; i = i + 1) {

}

// While Loops
while (true) {

}

// Classes
class Foo {
    // Constructor
    init() {
        // Class Variables
        this.bar = true;
    }

    // User-Defined Methods
    method() {
        return 69;
    }
}

// Inheriting Classes
class Bar < Foo {
    init() {
        this.bubbles = super.method();
    }
}

// Built-In Functions
print "value";          // Print a value to the console
clock();                // Returns the current time in seconds (number)

// List Built-In Functions
append(list, value)             // Appends a value to a list
remove(list, index)             // Removes a value at a specified index of the list
slice(list, start, end, step)   // Slices the current list and returns a new one.


```
