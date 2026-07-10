# TicTacToe-HeuristicAI

A console-based Tic-Tac-Toe game in C++ featuring an AI opponent that plays **tactically** — not randomly. Instead of brute-force search (like Minimax), the AI uses a custom heuristic engine to detect winning opportunities and block the player's threats in real time.

## Features

- 🎮 **Two Game Modes** — Multiplayer (Player vs Player) and Singleplayer (Player vs AI)
- 🧠 **Heuristic AI Engine** — scans rows, columns, and both diagonals to find and act on 2-in-a-row patterns
- 🛡️ **Offense-first, Defense-second logic** — AI always checks if it can win before checking if it needs to block
- 🎲 **Random fallback** — if no tactical opportunity exists, the AI picks a smart random empty cell
- 🏗️ **Clean OOP Design** — separated into `Board`, `Player`, and `Game` classes
- ✅ **Full win detection** — rows, columns, and both diagonals

## How the AI Works

The AI doesn't evaluate the entire game tree like Minimax does. Instead, on every turn it runs through a priority-ordered set of checks:

1. **Can I win right now?** — `Row_Searcher`, `Col_Searcher`, `Diagonal_Searcher`, and `Sec_Diagonal_Searcher` scan the board for any line where the AI (`'O'`) already occupies 2 cells with 1 empty cell remaining. If found, it completes the line and wins.
2. **Can the opponent win next turn?** — If the AI can't win immediately, it runs the same scan looking for the player's (`'X'`) 2-in-a-row patterns and blocks that cell.
3. **No threats found?** — Falls back to picking a random open cell via `Random()`.

This priority order (`Win → Block → Random`) is what makes the AI feel "smart" without the computational cost of a full search algorithm.

## Project Structure

```
TicTacToe-HeuristicAI/
├── TicTacToe.cpp              # Main game logic and AI implementation
├── Tic-Tac-Toe-Game.sln       # Visual Studio solution file
├── Tic-Tac-Toe-Game.vcxproj   # Visual Studio project file
└── .gitignore
```

### Class Overview

| Class | Responsibility |
|---|---|
| `Board` | Stores the 3x3 grid and handles display/rendering |
| `Player` | Stores player name and player number, handles name input |
| `Game` | Core game engine — move validation, win checking, AI logic, and turn management |

## Getting Started

### Prerequisites
- A C++ compiler (MSVC / g++ / clang)
- Visual Studio (recommended, since project files are included) — or any C++ IDE

### Build & Run (Visual Studio)
1. Clone the repo:
   ```bash
   git clone https://github.com/Mabdullahrabbani/TicTacToe-HeuristicAI.git
   ```
2. Open `Tic-Tac-Toe-Game.sln` in Visual Studio
3. Build and run (F5)

### Build & Run (g++)
```bash
g++ TicTacToe.cpp -o TicTacToe
./TicTacToe
```

## How to Play

1. Choose **Multiplayer (1)** or **Singleplayer (2)** at launch
2. Enter your name
3. On your turn, enter a row (1-3) and column (1-3) to place your mark
4. First to align 3 marks in a row, column, or diagonal wins!

## Possible Future Improvements

- [ ] Replace heuristic AI with Minimax for a truly unbeatable opponent
- [ ] Add a difficulty selector (Easy = random, Hard = heuristic/minimax)
- [ ] Cross-platform screen clearing (currently uses `system("cls")`, Windows-only)
- [ ] GUI version using SFML or Qt

## Author

**Muhammad Abdullah Rabbani**
[GitHub](https://github.com/Mabdullahrabbani)

---
*Built as a hands-on exercise in OOP design and game AI logic in C++.*
