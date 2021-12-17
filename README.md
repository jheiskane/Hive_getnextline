# Get next line
Project to create a function that reads the next line from a file descriptor, just like the name suggests. Just like other projects in Hive there is quite a few restrictions
on what you can use to create this function. The buffer size is adjustable from the header file and the function is able to be called multiple times within a loop, for example.
The function also supports multiple file descriptors without losing track of each.

## Restrictions and rules

Due to strict rules and restrictions the following were mandatory in the creation of the function:

- One function is limited to maximum of 25 lines
- Only the following libc functions were allowed : read(), malloc(3), free(3).
  and their usage were restricted. This creates the actual challenge of creating the function.
- The function have to abide with the 'Norme' (https://cdn.intra.42.fr/pdf/pdf/733/norme.en.pdf). Which is a set of rules and guidelines to keep the code clear
  and readable.
  
  
