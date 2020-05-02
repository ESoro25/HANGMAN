# HANGMAN
Evan Soroken for UML COMP II

If you just run the ./string_driver you will notice the segfault.
The location of this segfault was determined in gdb with a breakpoint on line 56.
Running the game sequence y/20/j, and skipping to the third iteration of the breakpoint, the program attemps to run:
"if(balanceFactor > 1 && (my_string_compare(key, node->rightChild->key) < 0)) return leftRotation(node);"

However a rightChild has never been initialized because according to the prior my_string_compare returns -1, indicating that
the key belongs in the left node, contradicting the attempt to balance.

There might be some memory leaks; because of the segfault many of the destroy functions never had the opportunity to call.
