# LFX Mentorship Coding Challenge: Creating an Execution-Driven Version of Olympia

**Author:** Sohail Raj Satapathy

A modular C++ solution to the describe_object coding challenge. This implementation uses a registration based factory pattern to ensure the main program remains completely agnostic to specific object types. Adding a new object type only requires implementing the interface (in shapes.hpp and shapes.cpp) and registering it using the simple macro `REGISTER_OBJECT(ClassName, name)`.

## Build and Run

### Requirements
* C++17 compatible compiler (tested with clang++ 21.1.6 and g++ 15.2.1)
* GNU Make

### Build
```bash
make
```
This produces the executable: `describe_object`

### Run
`./describe_object <object_type> [parameters...]`

### Examples:
```bash
./describe_object circle 5
Circle with radius 5:
- Circumference: 31.4159
- Area: 78.5398

./describe_object rect
A rectangle has 4 sides broken into 2 side pairs of equal length and are parallel.
If the user provides the length of each pair:
"./describe_object rect <length side 1> <length side 2>"
The program can calculate: perimeter, area.