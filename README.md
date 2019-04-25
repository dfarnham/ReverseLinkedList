# ReverseLinkedList
Reversing a Linked List

```
$ make test
rm -f revlist.o
rm -f revlist
gcc -O2 -Wall   -c -o revlist.o revlist.c
gcc -O2 -Wall revlist.o -o revlist
-~-~-~-~-~-~-~-~TEST~-~-~-~-~-~-~-~-~-~-
original:
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> null
-----------
reversed:
9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> null
```
