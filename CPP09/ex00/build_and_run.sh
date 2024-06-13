#!/bin/bash

# Compile the program
clear
make

# Run the program with different inputs
echo "Running program with different inputs:"
echo "---------------------------------------"

# Run with correct
echo './btc"'
./btc
echo ""

# Run with correct
echo './btc inpu.txt"'
./btc inpu.txt
echo ""

# Run with correct
echo './btc inpu.txt xx"'
./btc inpu.txt xx
echo ""

# Run with correct
echo './btc input.csv"'
./btc input.csv
echo ""

# Run with correct
echo './btc input.txt"'
./btc input.txt
echo ""

make fclean