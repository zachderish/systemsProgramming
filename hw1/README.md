#factor.c
Write a program that takes a single integer nas a command-line argument and finds
its prime factors, excluding 1. The output should consist of a single line listing each
prime factor in non-decreasing order, separated by a space. If nis prime, just print
nitself. If there are repeat factors, print the factor as many times as it divides n.

#grep.c
Write a program that takes a string as a command-line argument and then reads
from stdin until the user closes stdin (with ctrl-d, written ^D below). It should print
every line that contains the given string. It should be case-sensitive by default, but
case-insensitive if the command line option -i is given before the string. Strings
may have arbitrary length.

#sort.c
Write a program that reads from stdin and sorts its input. If no command-line
option is given, it should use case-insensitive lexicographic sorting. If the -n option
is given, it should use numeric sorting (in this case, you can assume all inputs will
be valid integers). You can assume there won’t be any spaces in the input string.
There can be an arbitrary number of strings, of arbitrary length.

#uniq.c
Write a program that reads from stdin and filters out duplicate lines of input. It
should read lines from stdin, and then print each unique line along with a count of
how many times it appeared. Input is case-sensitive, so “hello” and “Hello” are not
duplicates. There can be an arbitrary number of strings, of arbitrary length.
Note that only adjacent duplicates count, so if the input were the lines “hello”,
“world”, and “hello” again, all three would be treated as unique.

#monster.c
This program is a game of a player and monster moving on a 2D grid. The player
has a goal to reach. The monster wants to reach the player.
In each turn, the player moves one square, then the monster moves towards the
player. If either reaches their target, the game ends immediately. If the player
reaches the goal, it prints “player wins!”. If the monster reaches the player, it prints
“monster wins!”.
The player’s moves (N, W, S, or E) are read from stdin, one per line. If the move
is invalid (e.g., the player tries to move off the board, print “invalid move” and read
a new move). If the player intentionally moves into the monster’s square, it counts
as the monster winning.

The board is specified by command-line parameters:
./monster boardX boardY plrX plrY goalX goalY monX monY
