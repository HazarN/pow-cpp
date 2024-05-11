# Logarithmic Time Power Function

This repository contains an implementation of a logarithmic time power function written in C++. This function efficiently calculates the power of a given base to a specified exponent using a logarithmic time complexity approach.

## Introduction

The power function `power(double a, int n)` in this repository computes \( a^n \) where \( a \) is the base and \( n \) is the exponent. The implementation is optimized for performance, achieving logarithmic time complexity (\( O(\log n) \)).

## Features

- Efficient computation of power with logarithmic time complexity.
- Support for both positive and negative exponents.
- Handles edge cases such as \( n = 0 \) and \( n = 1 \) for quick termination.
- Minimal space complexity.

## Usage

To use the power function in your C++ project, follow these steps:

1. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/your-username/logn-time-pow.git

2. Transfer to the file's directory:

   ```bash
   cd ./pow-cpp

3. Run the program:

   ```
   g++ main.cpp -o output ; ./output
