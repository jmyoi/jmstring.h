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
- [ ] destructor

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
- [x] at
  + get character in string
- [x] back
  + access last character
- [x] front
  + access first character

## Modifiers
- [ ] append
  + append to string
- [ ] push\_back
  + append character to string
- [ ] assign
  + assign content to string
- [ ] insert
  + insert into string
- [ ] erase
  + erase characters from string
- [ ] replace
  + replace portion of string 
- [ ] swap
  + swap string values
- [x] pop\_back
  + delete last character

## String Operations
- [ ] data
  + get string data
- [ ] find
  + find content in string
- [ ] rfind
  + find last occurrence of content in string
- [ ] find\_first\_of
  + find character in a string
- [ ] find\_last\_of
  + find character in a string from the end 
- [ ] find\_first\_not\_of
  + find absence of character in a string
- [ ] find\_last\_not\_of 
  + find absence of character in a string from the end 
- [ ] substr
  + generate substring
- [ ] strtok
  + generate tokens from the string 
- [ ] compare
  + compare strings
