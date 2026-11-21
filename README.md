*This project has been created as part of the 42 curriculum by aalrofat.*

# 🔄 push_swap

## 📝 Description
The **push_swap** project is a sorting program written in C that sorts a list of integers using two stacks (`stack a` and `stack b`) and a limited set of stack operations. The goal is to sort the numbers in ascending order using as few operations as possible while handling errors and invalid inputs safely. In this implementation, I used the **Radix sort algorithm** (bitwise sorting) to sort integers efficiently.

### 💡 What did I learn from the project
Working on **push_swap** improved my problem-solving skills and taught me how to design and optimize a sorting solution using the **Radix sort algorithm**. I also practiced working with stacks/linked lists, validating inputs, preventing memory leaks, and writing clean code that follows the Norminette.

## ⚙️ Instructions
1. `cd push_swap` (or navigate to the project directory)
2. `make` (compiles the program and creates `push_swap`)
3. **Run the program** with a list of integers:
   - `./push_swap 2 1 3 6 5 8`
4. **Useful Makefile rules**:
   - `make clean` : Removes object files (`.o`).
   - `make fclean` : Removes object files and `push_swap`.
   - `make re` : Rebuilds the program from scratch.

## 🛠️ Supported Operations
- **`sa` / `sb` / `ss`**: Swap the top two elements of stack `a`, stack `b`, or both.
- **`pa` / `pb`**: Push the top element from `b` to `a`, or from `a` to `b`.
- **`ra` / `rb` / `rr`**: Rotate stack `a`, stack `b`, or both up by one position (first element becomes last).
- **`rra` / `rrb` / `rrr`**: Reverse rotate stack `a`, stack `b`, or both down by one position (last element becomes first).

## 🔗 Resources
- [Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/)
- [push_swap Guide by Abdelhadi Salah](https://medium.com/@abdelhadi-salah/push-swap-42-e0abfe0e0fef)
- [push_swap: The least amount of moves with two stacks by A. Yogun](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

### 🤖 AI Usage
- **Bitwise Logic & Radix Walkthrough**: Used to double-check how bit shifting and stack rotations interact during Radix sort passes without losing track of indices.
- **Test Case Brainstorming**: Helped generate tricky input combinations (negative numbers, duplicates, out-of-range values, and large sets) to verify correctness.
- **Clarity & Tone**: Used to keep the explanations in this README concise, natural, and easy for any reader to scan.
