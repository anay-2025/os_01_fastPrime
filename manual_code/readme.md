## 📝 Implementation Note

This project is **entirely written and implemented manually** by the contributors as part of an academic Operating Systems assignment. No code generators, frameworks, or automated tools were used — all logic, process management, and benchmarking mechanisms were designed and coded by hand to better understand Linux process-level parallelism.

---


# Parallel Prime Search: Linux Process Management

This project is a Linux-based C application that demonstrates **parallel computation using multiple processes**. It evaluates how efficiently prime numbers can be calculated when the workload is distributed across increasing numbers of child processes and how performance scales with available CPU resources.

---

## 🚀 Project Overview

The application computes all prime numbers within a user-defined range by dividing the task among several processes created using the `fork()` system call. By progressively increasing the number of worker processes, the program benchmarks execution time and studies the impact of process-level parallelism on performance.

All calculated primes and timing results are written to an output file for later analysis.

---

## ✨ Key Features

- Automatic detection of logical CPU cores  
- Parallel computation using multiple processes  
- Balanced distribution of work across workers  
- Benchmarking of execution time for different process counts  
- Persistent storage of results in a file  

---
