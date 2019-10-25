# muistring
Implementing C++ style string class in C.

Main file: `muistring.h`

helpers: 
 - `capacity.h`
 - `element_access.h`
 - `modifiers.h`
 - `strops.h`

# Functions
- [x] newstr (constructor)
- [] destructor

## Capacity 
- [x] size
  + return length of string
- [x] length
  + return length of string
- [x] resize
  + resize string
- [x] capacity
  + return size of allocated storage
- [x] reserve
  + request a change in capacity
- [x] clear
  + clear string
- [x] isEmpty
  + test if string is empty
- [x] shrink_to_fit
  + shrink the storage to fit string

## Element Access
- [] at
  + get character in string
- [] back
  + access last character
- [] front
  + access first character

## Modifiers
- [ ] append
  + append to string
- [] push_back
  + append character to string
- [] assign
  + assign content to string
- [] pop_back
  + delete last character

## String Operations
- [] c_str
  + get C string equivalent
- [] find
  + find content in string
- [] substr
  + generate substring
- [] compare
  + compare strings
