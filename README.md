# Assignment-02-Binary-Search-and-Recursive
The difference between iterative and recursive.
# Binary Search Iterative
+Have a sorted array and a target.
+Look at middle. If target is bigger, throw away the left half. If smaller, throw away the right half.
+While Loop 

Time: O(1)

Space:O(1)

Requires Sorted:yes

# Binary Search Recursive
+Have a sorted array and a target.
+Look at middle. If target is bigger, throw away the right half. If smaller, throw away the left half. 
+In this case instead of a loop, the function calls itself.

Time: O(1)

Space: O(log n)

Requires Sorted:yes

# Linear Search
+Have an array that is or isn't sorted along with a target.
+Check each element one by one from left to right. If it matches = stop, and if you run out elements = not there. 
+For loop

Time: O(1)

Space:O(1)

Requires Sorted:no
