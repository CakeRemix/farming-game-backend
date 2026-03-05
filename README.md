# AgriTopia 🌱

A text-based farming simulation game written in C++. Buy plants, tend your greenhouse, wait for harvests, and sell produce to build your wealth — all from the command line.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Build with CMake](#build-with-cmake)
  - [Build with Make](#build-with-make)
  - [Build Manually (g++)](#build-manually-g)
- [How to Play](#how-to-play)
  - [Menu Commands](#menu-commands)
  - [Plant Types](#plant-types)
  - [Economy](#economy)
- [Class Hierarchy](#class-hierarchy)
- [Tech Stack](#tech-stack)
- [Contributing](#contributing)
- [License](#license)

---

## Overview

AgriTopia is a C++ OOP project that simulates a greenhouse farming experience. The player starts with a small budget, purchases a greenhouse, and must strategically buy, grow, and sell plants to accumulate wealth. The game demonstrates core OOP principles including inheritance, polymorphism, and dynamic memory management.

---

## Features

- **Plant hierarchy** — Abstract base `plant` class extended by `fruit`, `tree`, `bush`, and `flower`
- **4×4 greenhouse grid** — Visual representation of currently planted crops
- **Time simulation** — Plants mature after a cooldown period; use `wait` to advance time
- **Economy system** — Earn EGP by selling harvested produce or eating fruits directly
- **Storage** — Harvested plants are stored for later sale
- **Interactive CLI** — Menu-driven interface with input validation throughout

---

## Project Structure

```
farming-game-backend/
├── include/
│   ├── plant.h        # Plant class hierarchy declarations
│   └── game.h         # Game & utility function declarations
├── src/
│   ├── main.cpp       # Entry point
│   ├── plant.cpp      # Plant method implementations
│   └── game.cpp       # Game logic (menu, buy, sell, eat, wait, help)
├── CMakeLists.txt     # CMake build configuration
├── Makefile           # GNU Make build configuration
├── .gitignore
└── README.md
```

---

## Getting Started

### Prerequisites

| Tool | Minimum Version |
|------|----------------|
| g++ / clang++ | C++17 support |
| CMake *(optional)* | 3.15+ |
| GNU Make *(optional)* | 4.0+ |

---

### Build with CMake

```bash
cmake -S . -B build
cmake --build build
./build/bin/AgriTopia
```

---

### Build with Make

```bash
make
./AgriTopia
```

---

### Build Manually (g++)

```bash
g++ -std=c++17 -I include src/main.cpp src/plant.cpp src/game.cpp -o AgriTopia
./AgriTopia
```

On Windows (MinGW / MSVC):
```powershell
g++ -std=c++17 -I include src/main.cpp src/plant.cpp src/game.cpp -o AgriTopia.exe
.\AgriTopia.exe
```

---

## How to Play

1. Launch the game and type `hi` to start the intro.
2. Enter your name when prompted.
3. Purchase the greenhouse (the only affordable option).
4. Use the main menu to manage your farm.

### Menu Commands

| Command | Description |
|---------|-------------|
| `buy` | Purchase a plant and place it on the 4×4 grid |
| `sell` | Sell harvested produce from your storage |
| `eat` | Immediately consume planted fruits for instant money |
| `wait` | Advance time in seconds so plants can mature |
| `show plants` | Display the current state of the greenhouse grid |
| `show money` | Display current balance in EGP |
| `help` | Show command descriptions |
| `quit` | Exit the game |

### Plant Types

| Plant | Category | Symbol | Price |
|-------|----------|--------|-------|
| Banana | Tree (Fruit) | `B` | 1 EGP |
| Apple | Tree (Fruit) | `A` | 1 EGP |
| Gooseberry | Bush (Fruit) | `G` | 1 EGP |
| Strawberry | Bush (Fruit) | `S` | 1 EGP |
| Rose | Flower | `R` | 1 EGP |
| Tulip | Flower | `T` | 1 EGP |

### Economy

- Plants require **30 seconds** of in-game wait time to mature.
- Each sold or eaten plant yields **2 EGP**.
- Starting balance: **1 EGP** (use `hack` as username for 999,999 EGP).

---

## Class Hierarchy

```
plant  (base)
├── fruit
│   ├── tree   (banana, apple)
│   └── bush   (gooseberry, strawberry)
└── flower     (rose, tulip)
```

- `plant` — Manages growth timer, type, and decrement/harvest logic.
- `fruit` — Intermediate class for edible plants; overrides `eat()`.
- `tree` / `bush` — Concrete fruit types with specific `eat()` behaviour.
- `flower` — Non-edible plant; cannot be eaten but can be sold after harvest.

---

## Tech Stack

- **Language:** C++17
- **Paradigm:** Object-Oriented Programming (OOP)
- **Build Systems:** CMake 3.15+, GNU Make
- **Standard Library:** `<bits/stdc++.h>` (GCC extension)

---

## Contributing

1. Fork the repository
2. Create a feature branch: `git checkout -b feature/your-feature`
3. Commit your changes: `git commit -m "feat: add your feature"`
4. Push to the branch: `git push origin feature/your-feature`
5. Open a Pull Request

---

## License

This project is for educational purposes at GIU. All rights reserved.
