﻿# Circular-Round-Robin-Process-Scheduler-in-C

 ## Overview
This project implements a simple round-robin CPU scheduler simulation in C. Processes are stored in a circular singly-linked list and each “time slice” is chosen randomly between 1 and 5 units. When a process’s remaining time reaches zero, it is removed from the list. The simulation continues until all processes finish.

## Features
- **Dynamic process management** using a circular linked list
- **Randomized execution times** (5–30 units) and **time slices** (1–5 units)
- **Real-time simulation** via `sleep()` to mimic CPU bursts
- **Detailed logging** of total elapsed time, current PID, slice length, and remaining time
- **Automatic removal** of completed processes and clean termination

## File Structure
- **utils.h**  
  Declares the `Processo` struct and prototypes for list operations.
- **utils.c**  
  Implements:
  - `cria_processo(pid)` – allocates a new process with random execution time  
  - `insere_fim(&head, &tail, p)` – inserts a process at the end of the circular list  
  - `remove_processo(&head, &tail, prev, cur)` – removes a completed process node
- **main.c**  
  - Initializes 20 processes with unique PIDs  
  - Runs the round-robin scheduling loop  
  - Logs each step and simulates CPU work with `sleep()`  

## Prerequisites
- A C compiler (GCC or compatible)
- Standard C library (stdlib.h, stdio.h, unistd.h)
- Linux, macOS, or Windows (with POSIX `sleep()` support or adjust to `Sleep()` on Windows)

## Build & Run

```bash
# Compile both source files
gcc -o scheduler main.c utils.c -lm

# Run the simulation
./scheduler
