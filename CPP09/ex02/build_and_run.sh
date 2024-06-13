#!/bin/bash

# Compile the program
clear
make

# Run the program with different inputs
echo "Running program with different inputs:"
echo "---------------------------------------"

# Run with non-integer input
echo "./PmergeMe 3 4 5 6 +"
./PmergeMe 3 4 5 6 +
echo ""

# Run with non-integer input
echo "./PmergeMe 3 4 5 6 2e2"
./PmergeMe 3 4 5 6 2e2
echo ""

# Run with empty arguments
echo "./PmergeMe \"\""
./PmergeMe ""
echo ""

# Run with negative integer
echo "./PmergeMe 3 4 5 6 -7"
./PmergeMe 3 4 5 6 -7
echo ""

# Run with sorted integer
echo "./PmergeMe 3 4 5 6 7"
./PmergeMe 3 4 5 6 7
echo ""

# Run with subject integer
echo "./PmergeMe 3 5 9 7 4"
./PmergeMe 3 5 9 7 4
echo ""

# Run with dup integer
echo "./PmergeMe 11 5 9 7 4 6 4 4 4"
./PmergeMe 11 5 9 7 4 6 4 4 4
echo ""


# Run with 3000 integer
# echo "./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`"
./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
echo ""


./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
echo ""

echo "./PmergeMe "-1" "2""
./PmergeMe "-1" "2"
echo ""

make fclean
