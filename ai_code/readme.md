# Parallel Prime Search: UNIX Process Management

A high-performance C program designed for Linux that demonstrates **parallel computing** using the `fork()` system call. This project explores the relationship between hardware concurrency (logical CPU cores) and software performance.

## 🚀 Project Overview

The program calculates all prime numbers within a user-defined range  by distributing the workload across multiple child processes. It systematically scales the number of processes to find the "sweet spot" of maximum performance before context-switching overhead begins to degrade execution time.

### Key Features

* **Dynamic Hardware Detection:** Automatically detects available logical CPUs using `lscpu`.
* **Load Balancing:** Evenly partitions the numerical range among active processes.
* **Performance Benchmarking:** Measures CPU execution time for configurations ranging from 1 to  processes.
* **Persistent Logging:** Results and timing data are logged to `prime.txt`.


## 🧠 Core Concepts

### 1. Workload Partitioning

The program divides the total range into "chunks." If  is the range and  is the number of processes:


### 2. The Multi-Process Lifecycle

1. **Parent** detects CPU count.
2. **Parent** enters a loop, incrementing the process count .
3. **Parent** calls `fork()`  times.
4. **Children** compute primes in their assigned sub-range and append to `prime.txt`.
5. **Parent** uses `wait(NULL)` to synchronize and ensure all children finish before measuring time.
---

## 📊 Graph Screenshots

### Execution Time vs Number of processes analysis


