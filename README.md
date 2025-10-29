[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/pAwGQi_N)

# PA4 Skeleton Code
We expect a fully functioninig command line REPL application for an inventory querying system. Feel free to modify the skeleton code as you see fit.

### How to run the current skeleton code
`make` will compile and execute the skeleton code

Feel free to modify Makefile as you see fit.

CSV Cleanup: I removed all quotation marks from fields as they were included inconsistantly, I also replaced every missing field with NA (not just missing categories).

Test cases: For the insert and find test, i chose a normal insertion case to start off, ran find on its key and tested to make sure the return was correct, i then added a product with a duplicate key to and ran find on that key to test the insertion and finding with seperate chaining (used for catagory map), and finally I inserted and found a third product which had a unique key to make sure it was inserted and found correctly independently of intentional seperate chaining. For the resize I added just enough elements to constitute one resizing operation and made sure all elements still existed in the table with correct key, value, and rehashed index.