# push_swap – Multi-Strategy Stack Sorting (Skeleton Project)

*This project has been created as an educational skeleton for the 42 `push_swap`-style project by Orgito.*

## Overview

This repository provides a **clean, extensible C implementation skeleton** for the classic `push_swap` challenge, organized to support **multiple sorting strategies** and an **adaptive mode**.

The goal of `push_swap` is to sort a list of integers using two stacks (`a` and `b`) and a limited set of operations:

- `sa`, `sb`, `ss`
- `pa`, `pb`
- `ra`, `rb`, `rr`
- `rra`, `rrb`, `rrr`

Only the **operations** are counted, and the objective is to **minimize the number of moves**.

This skeleton is designed to be:

- Easy to read and modify
- Ready to host **four different strategies** (simple, medium, complex, adaptive)
- Cleanly split into modules (parsing, stacks, operations, strategies, benchmarking)

> ⚠️ Note: The “medium” and “complex” strategies are intentionally left as TODOs. You are expected to implement your own algorithms there.

## Build

```bash
make
```

This will build the `push_swap` binary.

Clean object files:

```bash
make clean
```

Clean everything (including binary):

```bash
make fclean
```

Rebuild from scratch:

```bash
make re
```

## Usage

Basic usage:

```bash
./push_swap 2 1 3 6 5 8
```

With strategy and benchmark flags:

```bash
./push_swap --simple 3 2 1
./push_swap --medium --bench 4 67 2 -5 0
./push_swap --adaptive 5 4 3 2 1
```

### Flags

- `--simple`   → O(n²) style selection-based strategy
- `--medium`   → Intended for O(n√n) chunk-based strategy (**TODO**)
- `--complex`  → Intended for O(n log n) radix/index-based strategy (**TODO**)
- `--adaptive` → Adaptive strategy (default) choosing based on disorder metric
- `--bench`    → Print disorder and performance info to `stderr` (basic example included)

If no strategy flag is provided, `--adaptive` is used by default.

### Exit conditions

- On invalid input (non-int, overflow, etc.), the program prints `Error` to `stderr` and exits with a non-zero status.
- If the list is already sorted, **no operations** are printed.

## Project Structure

```text
.
├── Makefile
├── README.md
├── include
│   └── push_swap.h
└── src
    ├── bench.c
    ├── disorder.c
    ├── main.c
    ├── ops_push.c
    ├── ops_rev_rotate.c
    ├── ops_rotate.c
    ├── ops_swap.c
    ├── parse_args.c
    ├── stack.c
    ├── strategy_adaptive.c
    ├── strategy_complex.c
    ├── strategy_medium.c
    ├── strategy_simple.c
    └── utils.c
```

- `main.c` – program entry point, argument handling and strategy dispatch
- `parse_args.c` – flag parsing and integer validation
- `stack.c` – doubly-linked list stack implementation
- `ops_*.c` – all stack operations (`sa`, `pb`, `ra`, `rra`, etc.)
- `disorder.c` – calculation of the **disorder metric** (0–1)
- `strategy_*.c` – placeholders for the various algorithms
- `bench.c` – basic benchmarking output (extend with op counts)
- `utils.c` – helper functions (`ps_atoi`, sorted check, env init/clear)

## Algorithms (High-Level)

The project is structured around four strategies:

1. **Simple (O(n²))** – Already implemented as a selection/min-extraction strategy:
   - Repeatedly find the minimum in stack `a`, rotate it to the top, push to `b`.
   - Then push everything back to `a`.

2. **Medium (O(n√n))** – Suggested design (TODO):
   - Use **value normalization** (indices 0..n-1).
   - Process elements by **chunks** of size ~√n.
   - Push current-chunk elements to `b` using minimal rotations.
   - Reconstruct sorted `a` from `b`.

3. **Complex (O(n log n))** – Suggested design (TODO):
   - Compress values to indices 0..n-1.
   - Use a **radix sort** on bits (LSB to MSB).
   - For each bit:
     - If bit is 0 → `pb`
     - Else → `ra`
   - Then `pa` everything back.

4. **Adaptive** – Basic implementation included:
   - Computes a **disorder metric** (fraction of inverted pairs).
   - Chooses between simple/medium/complex based on thresholds.
   - You can refine thresholds and logic as desired.

## Resources & AI Usage

This skeleton was co-designed with the help of an AI assistant to:

- Propose a clean module breakdown
- Provide initial boilerplate for stack operations and argument parsing
- Outline recommended algorithmic strategies

Algorithmic details, final optimizations, and any additional logic should be implemented and documented by you.

Recommended resources to deepen your understanding:

- Articles and blog posts on 42 `push_swap` strategies (chunking, radix sort, LIS-based methods)
- Classic algorithm references on sorting and complexity analysis
- Data structure tutorials on linked lists and stacks in C

## License

You can adapt, extend, or reuse this skeleton for your own learning and personal projects.  
If you use it publicly (e.g., on GitHub), consider adding attribution to the original author and clearly documenting your own contributions.
