<p align="center">
  <img src="https://imgur.com/xYIkU3l" alt="Push_swap Logo">
</p>

# push_swap

Welcome to the *Push Swap* project! This repository contains a sorting algorithm challenge designed for the 42 School curriculum. The objective is to sort a stack of random numbers in ascending order using two stacks (A and B) and a limited set of operations, striving for the **minimum number of actions**. This project enhances **algorithmic thinking** and **efficiency skills** while providing a deeper understanding of **data structures** and **sorting algorithms**.
## requirements to pass the project

To pass *push_swap*, we had to create an algorithm that sorts elements in fewer operations than the specified limits, using only the allowed commands.

## Allowed Commands:

pa (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
pb (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
sa (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
sb (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
ss: sa and sb at the same time.
ra (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
rb (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
rr: ra and rb at the same time.
rra (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
rrb (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.

---

### **Performance Requirements:**

For **100 elements**:
- **Score 5:** Less than 700 operations.
- **Score 4:** Less than 900 operations.
- **Score 3:** Less than 1100 operations.
- **Score 2:** Less than 1300 operations.
- **Score 1:** Less than 1500 operations (baseline to pass).

For **500 elements**:
- **Score 5:** Less than 5500 operations.
- **Score 4:** Less than 7000 operations.
- **Score 3:** Less than 8500 operations.
- **Score 2:** Less than 10,000 operations.
- **Score 1:** Less than 11,500 operations (baseline to pass).

---

## **Choice of Algorithm**

I experimented with different algorithms to find the one that works best for the project. My initial attempt used a **greedy algorithm**—repeatedly finding the minimum value, pushing it to the top of `stack_a`, and then pushing it to `stack_b`. After sorting, I pushed the maximum value from `stack_b` back to `stack_a`. However, this resulted in **over 5000 operations for 100 elements**.

Other available algorithms, such as **Radix Sort**, **Quicksort**, and **Turk's Element**, were options some of my colleagues used.

---

### **My Approach: Chunk-and-Conquer Algorithm**

I decided to create my own approach, which I call **Chunk-and-Conquer**:
- The input elements are divided into **chunks**.
- Each chunk is partially sorted and processed separately.
- Smaller elements are pushed to the bottom of the stack, while larger elements remain at the top.
- Once `stack_a` is empty, I use `pa` to push elements back from `stack_b` to `stack_a`, always pushing the **largest** value first (since the largest values are already at the top of `stack_b`).

This approach significantly reduced the number of operations.

---

## **Implemented Sorting Functions**

To meet the project requirements, I created three sorting functions:

1. **`sort_three()`:** Sorts 3 elements or fewer.
2. **`sort_five()`:** Sorts 5 elements or fewer (calls `sort_three()` internally).
3. **`sort_large()`:** Sorts any number of elements by dividing them into chunks and merging them efficiently.

The reason I created three functions is that the project requirements specified:
- **3 elements:** Must be sorted in fewer than **3 operations**.
- **5 elements:** Must be sorted in fewer than **12 operations**.

--------

## **Example Walkthrough of the Algorithm**

**Initial State:**
- **Stack A:** `3 - 8 - 20 - 193 - 39 - 0 - 199 - 38 - 24`
- **Stack B:** `NULL`

### **Step 1: Divide Stack A into Chunks**

The input elements are divided into smaller **chunks**.

### **Step 2: Push Elements from `stack_a` to `stack_b`**

1. **Chunk 1:** `0 - 3 - 8`  
   Push `0`, `3`, and `8` to `stack_b`:
   - **Stack A:** `20 - 193 - 39 - 199 - 38 - 24`
   - **Stack B:** `8 - 3 - 0`
   - Continue pushing all elements from subsequent chunks to `stack_b` until `stack_a` is empty.

### **Step 3: Push Elements from `stack_b` to `stack_a`**

Push the **largest values first**:
- **Stack A:** `0 - 3 - 8 - 20 - 24 - 38 - 39 - 193 - 199`
- **Stack B:** `NULL`

-------

## **Compiling and Running the `push_swap` Program**

1. **Clone the Repository:**  
   Clone the repository to your local machine and navigate to the project folder.

2. **Compile the Program:**  
   Use `make` to compile the program.

3. **Run the Program:**  
   You can test the program using the following formats:
   - With multiple arguments: `./push_swap 3 2 1`
   - With a single string of numbers: `./push_swap "3 2 1"`

---

### **Program Capabilities:**
- Handles both **positive** and **negative** integers.
- Works with numbers in the range of **INT_MIN** to **INT_MAX**.
- Accepts **unique numerical values only**.
  
---

### **Error Cases:**
The program will display an error message if:
- **Duplicate values** are provided.
- Non-numeric input (e.g., letters) is entered.
- Numbers exceed the range of **INT_MIN** to **INT_MAX**.
- Special characters (e.g., @, #, !, etc.) are included.

### Conclusion: 

The push_swap project was very challenging at first, but once I dove into the code and experimented with different algorithms to find the one that worked best for me, everything started to make sense. In the end, it was simply a new concept that I needed to grasp. This project was an excellent opportunity to practice algorithms and improve my understanding of stack manipulation.