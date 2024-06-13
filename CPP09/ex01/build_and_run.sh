#!/bin/bash

# Compile the program
clear
make

# Run the program with different inputs
echo "Running program with different inputs:"
echo "---------------------------------------"

# Run with correct
echo './RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"'
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo ""

# Run with correct
echo './RPN "7 7 * 7 - "'
./RPN "7 7 * 7 - "
echo ""

# Run with correct
echo './RPN "1 2 * 2 / 2 * 2 4 - +"'
./RPN "1 2 * 2 / 2 * 2 4 - +"
echo ""

# Run with error (
echo './RPN "(1 + 1)"'
./RPN "(1 + 1)"
echo ""

# Run with overflow
echo './RPN "2222222222222222222222 2 *"'
./RPN "2222222222222222222222 2 *"
echo ""

# Run with no space
echo './RPN "1 2-2 * 2 / 2 * 2 4 - +"'
./RPN "1 2-2 * 2 / 2 * 2 4 - +"
echo ""

# Run with no space
echo './RPN "1 2e2 * 2 / 2 * 2 4 - +"'
./RPN "1 2e2 * 2 / 2 * 2 4 - +"
echo ""

make fclean