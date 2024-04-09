### Brainstorming Ideas around strstr() and if it could be used to solve problem of day-1

I think using strstr() might not be a good idea.

The function takes 2 null char terminating strings s1, s2 and then returns the first match character of substring s2 in s1.
however in our problem finding a key in a crossword puzzle/matrix (which isn't null char terminating) involves many directions.

for exmaple:
Matrix:

```
a b c d
e f g h
i j k l
m n o p

search string: cba -> must give true
search string: pkfa -> must give true
search string: mjgd -> must give true
search string: iea -> must give true
```

Hence, we must check each row traversing left and right
we must check each col traversing up and down
we must check all the 4 diagonals traversing up and down.

and using the strstr() would mean we would have to construct the strings from the matrix since the the strings which can be formed from cols and diagonals are not contigious, which would mean we would have to create new strings for all these cases.

```
New strings to be created = No.of cols*2 + No.of Rows (ignoring the forward traverse because you need not create a new string for that) + 8 (4 diagonals *2)
```

which in turn would not only incease the amount of time taken, but also increase the space complexity of the solution.
