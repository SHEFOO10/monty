

# 🐍 Monty Bytecode Interpreter

> Welcome to the world of **Monty 0.98** — a powerful, stack-based scripting language. This project is a **C language interpreter** that brings Monty bytecode files to life through a LIFO/FIFO stack implementation. Think of it as Python meets Assembly — but strictly stack.

---

## 📚 Table of Contents

* [Overview](#-overview)
* [Learning Objectives](#-learning-objectives)
* [Getting Started](#%EF%B8%8F-getting-started)
* [Monty Bytecode Language](#-monty-bytecode-language)
* [Implemented Opcodes](#-implemented-opcodes)
* [Usage](#%EF%B8%8F-usage)
* [Tech Specs](#-tech-specs)
* [Contributing](#-contributing)
* [License](#-license)

---

## 📌 Overview

This project is a **stack and queue interpreter** built in **C**, designed to parse and execute bytecode files written in the Monty language.
The interpreter reads Monty `.m` bytecode files and executes commands using a doubly-linked list to simulate a stack or queue structure.

---

## 🧠 Learning Objectives

By the end of this project, you should understand:

* What **LIFO** and **FIFO** mean
* When and why to use a **stack** vs. a **queue**
* Common use cases and implementations
* Proper use of **global variables**
* How to split logic across files using `extern`
* C compilation flags and **Betty code style**

---

## ⚙️ Getting Started

1. **Clone this repo**

   ```bash
   git clone https://github.com/SHEFOO10/monty.git
   cd monty
   ```

2. **Compile the interpreter**

   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
   ```

3. **Run it**

   ```bash
   ./monty bytecodes/filename.m
   ```

---

## 🐍 Monty Bytecode Language

Monty is a language that operates on a stack or queue with instructions like:

```monty
push 5
push 10
pall
```

Each line contains **one instruction**, and files can contain **comments (`#`)** and **blank lines**.

Example output:

```
10
5
```

---

## 📜 Implemented Opcodes

| Opcode  | Description                     |
| ------- | ------------------------------- |
| `push`  | Pushes value onto stack         |
| `pall`  | Prints all stack values         |
| `pint`  | Prints top value                |
| `pop`   | Removes top element             |
| `swap`  | Swaps top two elements          |
| `add`   | Adds top two elements           |
| `sub`   | Subtracts top from second       |
| `div`   | Divides second by top           |
| `mul`   | Multiplies top two elements     |
| `mod`   | Modulus of second by top        |
| `nop`   | Does nothing                    |
| `pchar` | Prints char at top of stack     |
| `pstr`  | Prints string from stack values |
| `rotl`  | Rotates top to bottom           |
| `rotr`  | Rotates bottom to top           |
| `stack` | Switches to stack (LIFO) mode   |
| `queue` | Switches to queue (FIFO) mode   |

---

## 🖥️ Usage

### Running the Interpreter

```bash
./monty file.m
```

### Error Handling

| Error Type        | Message Format                          |
| ----------------- | --------------------------------------- |
| Invalid arguments | `USAGE: monty file`                     |
| File not found    | `Error: Can't open file <filename>`     |
| Invalid opcode    | `L<line>: unknown instruction <opcode>` |
| Memory fail       | `Error: malloc failed`                  |
| Stack errors      | E.g. `can't pop`, `can't pint`, etc.    |

---

## 🧪 Tech Specs

* 🐧 Ubuntu 20.04 LTS
* 🧵 Written in **ANSI C (C89 standard)**
* 🛠️ Style: **Betty coding style**
* 📂 All prototypes in `monty.h`
* 🧱 Data structure: **doubly-linked list**

```c
typedef struct stack_s {
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s {
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

---

## 👥 Contributing

This was a collaborative effort by two developers as part of a systems programming curriculum. Contributions are welcome for expanding opcode support or optimizing the interpreter.

---

## 📜 License

This project is for educational purposes and is bound by the academic integrity policies of the program it was created under. **Plagiarism will result in disqualification.**

---

### 💡 Fun Fact

> “Monty” is named as a humorous reference to **Monty Python** — because coding can (and should) be fun.

