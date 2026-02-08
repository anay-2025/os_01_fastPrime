## 📝 Implementation Note

This part of the project was developed using prompt-based AI tools to support an experimental comparison. The AI-generated code was produced under defined constraints, then reviewed, tested, and integrated by the contributors to evaluate performance and correctness against the manually implemented version.

# Parallel Prime Search: LINUX Process Management

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
### Execution Time Analysis (Different Ranges)

<p align="center">
  <img src="screenshots/outputs/output(1-10k).png" width="45%" />
  <img src="screenshots/outputs/output(50-100k).png" width="45%" />
</p>

<p align="center">
  <b>Left:</b> 1k–10k range &nbsp; | &nbsp;
  <b>Right:</b> 50k–100k range
</p>


## 📊 Performance Observations

Based on experiments conducted across different Linux environments:

* *The Scaling Effect:* Adding processes significantly reduces execution time for large ranges (e.g., 50,000–100,000).
* *The Threshold:* Once the number of processes exceeds the physical/logical core count, execution time often *increases* due to the OS overhead of managing process states and file I/O contention.
* *I/O Bottleneck:* Since all processes write to a single file (prime.txt), disk I/O becomes a secondary bottleneck at high process counts.


## 🛠️ Installation & Usage

### Prerequisites

* Linux OS (Ubuntu/Debian/Fedora)
* GCC Compiler

### Compilation

Open your terminal and run:

bash
gcc code.c -o code -lm



### Execution

bash
./code



1. Enter the lower range (e.g., 1000).
2. Enter the upper range (e.g., 10000).
3. View the live execution times in the terminal or check prime.txt for the full dataset.


├── code.c
├── prime.txt
├── screenshots/
│   ├── graphs/
│   │   ├── 1k-10k.png
│   │   ├── 1k-10k2.png
│   │   ├── 1k-10k3.png
│   │   ├── 50k-100k.png
│   │   ├── 50k-100k2.png
│   │   └── 50k-100k3.png
│   └── outputs/
│       ├── output(1-10k).png
│       └── output(50-100k).png
└── README.md


## ⚠️ Limitations

* *Race Conditions:* Multiple processes use O_APPEND to write to the same file. While Linux handles this, the order of primes in the file is non-sequential.
* *Precision:* Uses clock(), which measures total CPU time. Future versions will implement CLOCK_MONOTONIC for wall-clock accuracy.


## 👤 Author

1)RAMATATAGARI BHARATH KUMAR REDDY
2)AMAN DAS
3)SAMAM ROY
4)SAUMYA KUMARI
5)RINIKA BANARJEE
6)PEDENLA BHUTIA
7)SRUTHI VADDADHI
8)ANAY BHATTACHARYA (Group Leader)
9)DHRUB SAH

Operating Systems Project NIT DURGAPUR

