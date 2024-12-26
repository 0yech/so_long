![image](https://github.com/user-attachments/assets/94e4623d-3937-405a-a29d-4ba0c27c78d6)
# so_long - Making a 2D Game

so_long is one of 42's first project including graphics (Rank02). It's about making a 2D game, run around collecting coins and reach the exit. You have some freedom on how the project works, but you'll need to use rectangular maps as .ber files.

## My Game
It's a tiny "Hedgehog" from the game Elsword, running around collecting pies. My version also includes holes, it means you can lose the game if you run into them.

https://github.com/user-attachments/assets/6cb93625-3659-4864-9e83-e9a0edd5138e
## What you'll learn

With so_long, you'll most likely learn about the following (as in the 42 cursus)

- Structs, pointers to structs and how to use them
- The concept of floodfill, useful for games
- Working with external libraries more efficiently
- Problem solving with the project's game and map rules

## Authorized external functions and tools

- ```open, close, read, write, malloc, free, perror, strerror, exit```
- ```Any tool from MiniLibX```
- ```ft_printf or any self made code```

**MiniLibX**

MiniLibX is a mini version of the LibX library. LibX allows for interactions with an "X Server", LibX is a Window System protocol that will act as a client with the X server, enabling the use of the X Protocol. It allows for features such as opening displays, work with geometry or even communicate with keyboard inputs and events. 

The MiniLibX is very small version of the LibX client. Within this project, there's only a few use for the library.

- Opening a window
- Converting and storing XPM files to pointers
- Listen for Events/Keyboard inputs
- Printing pixels

## Norm

42 projects are written under the [Norm V4](https://cdn.intra.42.fr/pdf/pdf/96987/en.norm.pdf)

42's Norm most notorious rules (just to name a few) implies things such as :

- No ```for``` loops.
- Max 25 lines per function.
- Max of one declaration or assignation per line.
- Strict indentation and formatting.
- No extra external functions or libraries.
- No Ternary operators.
- And many more.
