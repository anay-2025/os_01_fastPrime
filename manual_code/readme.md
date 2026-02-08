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

## 🧠 Core Concepts

### Workload Distribution

The full numeric range is split into smaller segments depending on the number of running processes. Each process receives its own portion of the interval so that all workers operate concurrently and efficiently.

---

### Process Execution Flow

1. The parent process reads the input range.  
2. Available logical CPUs are detected automatically.  
3. The program increases the number of worker processes step by step.  
4. Child processes are created for computation.  
5. Each child searches for primes in its assigned segment.  
6. Results are appended to a shared output file.  
7. The parent waits for all children before recording execution time.  

---

### Prime Checking Strategy

Each number is tested only up to its square root for divisibility, reducing unnecessary operations and improving performance.

---

## 🧪 Experimental Setup

### Input Ranges Tested

| Experiment | Range          |
| ---------- | -------------- |
| Small      | 1000 – 10000   |
| Large      | 50000 – 100000 |

---

## 📊 Results & Plots

This section presents the experimental results obtained by running the program on Linux systems with different input ranges and varying numbers of child processes.

Range : [1k-10k]

📊 [Plot 1](https://github.com/anay-2025/os_01_fastPrime/blob/main/screenshots/graphs/1k-10k.png)
📊 [Plot 2](https://github.com/anay-2025/os_01_fastPrime/blob/main/screenshots/graphs/1k-10k2.png)
📊 [Plot 3](path/to/file)

Range : [50k-100k]

📊 [Plot 1](path/to/file)
📊 [Plot 2](path/to/file)
📊 [Plot 3](path/to/file)

---

🧪 Sample Output 

🖼️ [Output for range 1k-10k](path/to/file)

🖼️ [Output for range 50k-100k](path/to/file)

---

## 📊 Performance Behavior

- Increasing processes initially reduces runtime.  
- Beyond the CPU core limit, performance gains decrease.  
- Excess processes introduce context-switching overhead.  
- Simultaneous file writing creates I/O contention.  
- Output order is not guaranteed due to parallel execution.  

---

## ⚠️ Limitations

* *Unordered Output:* Since multiple processes write to the same file concurrently, the prime numbers may not appear in sequential order.  
* *Timing Accuracy:* The program uses CPU time for measurement, which does not perfectly reflect real wall-clock performance.  
* *I/O Overhead:* Heavy concurrent file writes can slow down execution as the number of processes increases.  
* *No Synchronization:* There is no locking mechanism to coordinate file access between processes.  

---

## 👤 Contributors

1) Bharath Reddy  
2) Aman Das  
3) Samam Roy  
4) Saumya Kumari  
5) Rinika Banarjee  
6) Pedenla Bhutia  
7) Sruthi Vaddadhi  
8) Anay Bhattacharya (Group Leader)  
9) Dhrub Sah  

**Operating Systems Project — NIT Durgapur**
