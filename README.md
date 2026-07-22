*This project has been created as part of the 42 curriculum by aunoguei, ppousser.*

# PUSH SWAP

## Description

Push_swap is a sorting project that arranges a list of integers in ascending order using:
- Only two stacks (A and B)
- A restricted set of allowed operations

The program outputs to standard output the sequence of Push_swap operations required to sort the integers passed as arguments.

The main objective of this project is to explore:
- Algorithmic time and space complexity
- How algorithm choice dramatically impacts performance

### Implementation

**Team Work Distribution :**

ppousser
- Input validation
- Makefile

aunoguei
- Stack initialization
- Input normalization
- Rules / operations implementation (ra, pb, etc.)

Joint Work :

- Project architecture
- Program skeleton (algorithm dispatcher)
- Design and implementation of sorting algorithms

**Program Behavior**

If no parameters are provided, the program must display nothing and return the prompt.

In case of error, the program must print Error to standard error, followed by a newline.

Errors include:
- Non-integer arguments
- Integers outside the valid range
- Duplicate values


## Instructions

**Compilation**

- make
- make re
- make clean
- make fclean

**Strategy Selection**

The program includes optional strategy selectors:
--simple → Forces the use of the O(n²) algorithm.
--medium → Forces the use of the O(n√n) algorithm.
--complex → Forces the use of the O(n log n) algorithm.
--adaptive → Uses the adaptive strategy based on disorder (default behavior).

If no selector is provided, the program automatically uses --adaptive.

**Benchmark Mode**

When the --bench flag is enabled, the program must display (to stderr, not stdout):
- The computed disorder (percentage with two decimals)
- The selected strategy and its theoretical complexity class
- The total number of operations
- The count of each operation:
sa, sb, ss
pa, pb
ra, rb, rr
rra, rrb, rrr

Benchmark output only appear when --bench is explicitly provided.

**Disorder Metric**

We define disorder as the number of inversions:
disorder = (# of inversions) / (n(n − 1) / 2)
This produces a value between 0 and 1, where:
- 0 → Already sorted
- 1 → Reverse sorted

**Threshold Rationale**

We use the following thresholds:
- Low disorder: < 0.2
- Medium disorder: 0.2 ≤ disorder < 0.5
- High disorder: ≥ 0.5

Why these thresholds?

When disorder < 0.2, the list is nearly sorted.
In this case, insertion-based strategies approach O(n) performance.

Between 0.2 and 0.5, disorder is moderate.
A bucket-based strategy reduces cross-stack movements.

When disorder ≥ 0.5, the list behaves similarly to a random permutation.
A radix-based strategy guarantees O(n log n) operations.

## Explanation and justification of the algorithms

Special cases (in case of adaptive only):
- 3 numbers → Hardcoded sorting (6 possible permutations) → O(1)
- 5 numbers → Push smallest elements to stack B, sort remaining 3, then restore → approximately O(n)

### Low Disorder – Insertion Strategy

If disorder < 0.2:

- Move each element from stacks A to stacks B while maintaining B in sorted order, keeping the element maximum at the top.
- Each element from A is sorted into its correct position in B using rotations. 
- Finally, the elements are moved back to stack A, resulting in an ascending order.

Total operations: O(n²)

### Medium Disorder – Bucket Strategy

If 0.2 ≤ disorder < 0.5:

- Divide the normalized index range into √n buckets
- Push elements from stack A to stack B bucket by bucket
- Once A is empty, push elements back to A in sorted order
- Each element moves between stacks at most O(√n) times.

Total operations: O(n√n)

### High Disorder – Radix Sort (Binary LSD)

If disorder ≥ 0.5:

- Use normalize values into indices
- Perform binary radix sort (Least Significant Bit first)
- For each bit (≈ log n bits), process all n elements

Total operations: O(n log n)

This guarantees predictable performance even for highly disordered inputs.

### Data Structures

A linked list is used to represent stacks, allowing:
- Efficient insertion
- Efficient deletion
- Constant-time stack operations

Compared to arrays, linked lists are better suited for frequent push operations.

## Resources
- https://www.bigocheatsheet.com/
- https://www.w3schools.com/dsa/dsa_algo_insertionsort.php
- https://www.geeksforgeeks.org/dsa/radix-sort/
- https://www.geeksforgeeks.org/dsa/implement-quicksort-with-first-element-as-pivot/
