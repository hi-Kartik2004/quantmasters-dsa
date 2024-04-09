# Solution for Brute force string matching (Ouput Based Question - 1)

How many `comparisons` (both successful and unsuccessful) will be made by the brute-force algorithm in searching for each of the following patterns in the `binary text of one thousand zeros`? Explain along answer

a. 00001

b. 10000

c. 01010

## A) 00001

In brute force string matching, we would have to compare every character of the pattern with the text starting from being aligned with the left most bit and keep moving towards the right with step wise increments of 1.

at any stage if a bit mismatches then break and align to the next bit.

```
Text
00000000000....
00001 -> 1st alignment, Number of comparisons = 5,
00000000000....
 00001 -> 2nd alignment, Number of comparisons = 5,

So for thousand zeros
the comparisons will the alignment will continue till 1000-4 = 996*5 = 4980 (Worst case)
0000000..................00000
		996th bit
```

## B) 10000

```
Text
000000000000....00000000 (thousand zeros)
10000 -> 1st alignment, comparisons = 1, cuz break after first bit mismatch.
so 996*1 = 996 comparisons.
```

## C) 01010

```
Text
000000000000.....0000000(thousand zeros)
01010 -> 1st aligment, comparisons = 2, cuz break after 2nd bit mismatch.
so 996\*2 = 1992 comparisons
```
