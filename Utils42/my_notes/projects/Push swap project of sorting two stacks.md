>objective : The objective is to sort Stack A in ascending order (smallest element at the top) using the fewest operation possible, with Stack B empty at the end. 

Push Swap is a classic algorithm project from the 42 School curriculum, designed to deepen your understanding of sorting algorithms, data structures, and optimization techniques. The goal is to sort a stack of integers using a limited set of operations and two stacks, Stack A and Stack B, with the fewest moves possible. This project challenges you to think critically about algorithm efficiency, not in terms of computational time but in terms of minimizing the number of operations.

---
## Understanding the Push Swap Problem
The project restricts you to a specific set of operations to manipulate the stacks:
![[test.webp]]
- **sa** (swap a): Swap the first two elements at the top of Stack A.
- **sb** (swap b): Swap the first two elements at the top of Stack B.
- **ss**: Perform sa and sb simultaneously.
- **pa** (push a): Take the top element from Stack B and push it to the top of Stack A. Do nothing if Stack B is empty.
- **pb** (push b): Take the top element from Stack A and push it to the top of Stack B. Do nothing if Stack A is empty.
- **ra** (rotate a): Shift all elements of Stack A up by one, with the top element becoming the last.
- **rb** (rotate b): Shift all elements of Stack B up by one, with the top element becoming the last.
- **rr**: Perform ra and rb simultaneously.
- **rra** (reverse rotate a): Shift all elements of Stack A down by one, with the last element becoming the first.
- **rrb** (reverse rotate b): Shift all elements of Stack B down by one, with the last element becoming the first.
- **rrr**: Perform rra and rrb simultaneously.

## constraints
- The input is  a space separated list of unique integers (e.g., `./push_swap 3 1 2 4`)
- The program must handle any valid input, including negative numbers and duplicate are not allowed
- The goal is to minimize the number of operations. For evaluation at 42 school, specific threshold exist : 
	- For 3 numbers : <= 3 operations
	- for 5 numbers: <= 12 operations
	- for 100 nnumbers <= 700 operations for the highest score
	- for 500 numbers: <= 5,500 operations for the highest score
## Checker program
Alongside `push_swap` , we typically write a `checker` program that verifies if the output operations correctly sort the stack. The checker takes the same input integers and reads the operations from standard input, then outputs "OK" if the stack is sorted and "KO" otherwise.

## Designing the Push Swap Algorithm
### Data structure
For efficiency, I recommend to implement either a **circular buffer** (an array-based structure) rather than a linked list. A circular buffer allows faster access and manipulation of elements, which is critcical when debugging and testing with large inputs. The stack structure should include:
- An array to store integers
- A size variable to track the number of elements
- A top index to indicate the top of stack.

For example in C:
```c
typedef struct s_stack
{
	int *data;
	int size;
	int top;
}
```
This structure is efficient for operations like  **push, pop, rotate, swap** as it avoids the overhead of dynamic memory allocation in  `linked lists`. 
> [!NOTE]
> don't do like me, i used different structure for different algorithms, creating redundancy, spaguetty code and increase confusion into lecture. If I had more time I would clean all of those confusions...

### My Vision
The Push swap project will redirect everyonne who try out to comply this project to try different algorithm...
In my campus, I tend to see different solution but just one by project. When you ask if they thought to other solutions. They almost always respond : "yes, but they weren't not efficient enough so I removed it...". 
So I decided to give an example enoughly modularized to implement any agorithm we might think to this problem... Of cousrse it's just an organization of code usign different data structure to call what you might need to compile--....
Here is the logic of my `Compiler-distributed algoritm Dispatcher` using a jump_table..
This approach leverages precompiled logic to dispatch algorithms.. with the flexibility to switch algorithms using the `-D` preprocessorj flag during compilation

> This section of the documentation explains the design, implementation, and benefits with different sorting strategies while ensuring optimal performance for various input sizes...

### Spirit of this dispatcher
The dispatcher reflects this spirit by providing a clean, performant, extend by adding new algorithms to the jump table..
provide:
- modularity
- optimize performance
- enable flexibility
- facilitate debugging and testing
- promote reusability

![[data migration facility]]
## Algorithm strategies
## Permutations
Before diving into code or writing sorting strategies, we can do small individual and reusable sorting algorithms. We need to discover all the edge cases of the exchange between stacks...
#### Why permutations matter in push swap ?
when  we pick 2 or 3 elements inside stack A and want to sort them:
- Were really looking at all possible permutations of those elements..
- Why ?  because each permutations represents a different starting `order` , so potentialy  a different sequences of moves..
if we don't analyze all the permutations, we might miss one special case that needs a specific move combo.
#### How to calculate that ?!
here is the formula : 
$$
P(n, r) = \prod_{k=0}^{r-1} (n - k) \implies \frac{n!}{(n -r)!} \implies {n ·(n - 1) · (n - 2) \dots(n- (r - 1))}
$$

| Size of subsequence | possible permutation | expression | Result |
| ------------------- | -------------------- | ---------- | ------ |
| 2                   | P(2,2) = 2!          | 2 * 1      | `2`    |
| 3                   | P(3,3) = 3!          | 3 * 2 *1   | `6`    |
| 4                   | P(4,4) = 4!          | 4 ·3·2·1   | `24`   |
| 5                   | P(5,5) = 5!          | 5·4·3·2·1  | `120`  |
|                     |                      |            |        |
flet's track down all possibilities for 3 elementss.
           
| Original | Permutations |
| -------- | ------------ |
| `a b c`  | `a b c`      |
| `a c b`  | `b a c`      |
| `b c a`  | `c a b`      |
| `c b a`  | ` b c a`     |
| `c a b`  | `a c b`      |
Each of these permutations need different subssequences of moves in `Push_swap`
You're makng sure your sorting algorithm can solve each of these cases correctly

so we've understood that for push_swap development it is insane to try more than 4 permutaitions algorithm 

look at the table and see how it scales fast !

if we don't systematically list and handlle each permutation, our algorithm might randomly break on specific inputs.

![[permutations_state]]

### How to create this logic into algorithms ??

| #   | order | Operations |
| --- | ----- | ---------- |
| 1   | 1 2 3 | \0         |
| 2   | 1 3 2 | sa         |
| 3   | 2 1 3 | sa         |
| 4   | 2 3 1 | ra & sa    |
| 5   | 3 1 2 | ra         |
| 6   | 3 2 1 | rra        |
Case 1: `first > second && second  < third && fist < third
	sa(2 1 3)-> 1 2 3
Case 2: `first > second && second && second > third`
case3:: `first < second && second  > third  && third < 1`

### Chunk sort
#### Vision 
The algorithm's vision is to **divide and conquer** by breaking the sorting problem into manageable chunks, distributing them accros two stacks and recursively sorting smaller sub-chunks. Key aspect of the vision include:
1. **Chunk-based Partitionning** 
	- Instead of sorting the entire stack at once, the algorithm splits it into smaller chunks based on value ranges.
	- This reduces complexity by working with smaller, more manageable subsets of numbers.
2. Two Stack utilization:
	- Stack A is used to build the sorted seqeunce (typically in ascending order from bottom to top)
	- Stack B holds temporary chunks or partially sorted sub-chunks, allowing parallel processing of different value ranges.
3. Pivot-based splitting:
	- By using two pivots, the algorithm divides a chunk into three sub-chunks (`min` , `mid`, `max`), which balances the workload across recursive calls
	- The pivots are chosen to create roughly equal-sized sub-chunks, optimizing the number of operations.
4. Recursive Sorting:
	- Each sub-chunk is recursively split until its size is `<= 3` , at which point simple sorting functions (`sort_three`, `sort_two` , `sort_one`) are used.
	- The recursion ensures that smaller chunks are fully sorted before merging back into the main stack
5. optimization:
	- `the chunk_to_the_top` function ensures are in optimial positions reducing unnecessary rotations. 
6. Scalability:
	- the algorithm is designed to handle large inputs efficiently by keeping the number of operatoions low through strategic chunking and merging...

Divide the input into chunks (e.g., groups of 20-50 numbers based on their value ranges). Push each chunk to Stack B in a way that maintains partial order, then merge back to Stack A optimally.. This requires careful cost analysis to minimize rotations and pushes.
#### How it splits stack into sub-chunks
The algorithm splits a chunk into three sub-chunks (`min`, `mid`, `max`) and distributes them across Stack A and stack B. Here's how it effectively "cuts the two stacks into four stacks" (though it's more about logical partitioning within the two physical stacks):
#### initial  Setup
- start with a chunk in Stack (e.g., `to->sort->loc = TOP_A`, size = `n`)
- Stack b is typically empty or contains previously processed chunks.
#### Split Process
- **pivots**: calculate `pivot 1` (2/3 of size) and `pivot 2` (1/3 of size) based on the chunk size
- **value ranges**:
	- `max` : values in the top third (largest values, `> max_value - pivot 2`)
	- `mid` : values int the middle third (`max_value - pivot 1 < value <= max_value - pivot2)`
	- `min` : Values in the bottom third (smallest values, `<= max_value - pivot 1` )
- **Movement**:
	- Elements are moved using `move_from_to`, which may involve `pb` (push to B), `pa` (push to A), `ra`, `rb` etc...
	-  The `set_split_loc` function determines where each sub-chunk goes:
		- For `TOP_A` : `max` -> `BOTTOM_A` , mid, ->`TOP_B`, `min` -> `BOTTOM_b`
		- This creates logical partitions: `BOTTOM_A` and `TOP_A` in Stack A , `TOP_B` and `BOTTOM_B` in stack B
- **Result** the original chunk is split into three sub-chunks, distributed across the two stacks, effectively creating four logical `stacks` (two regions in Stack A, two in Stack B)
#### Recursive Processing
Each sub-chunk (`max`, `mid` ,`min`) is processed recursively.
1. max is sorted firs, often staying in Stack A to build the sorted sequence
2. `mid` and `min` are processed next, typically in Stack B, and eventually moved back to Stack A
3. The recursion continues until all chunks are sorted.


### Greedy sort (solving problem approach)

#### What is a decision optimal ?
This will depend on the problem... 

For instance, if we are choosing some elements and the problem  and the problem want us to find the maximum sum of elements we take, the given a choice betweeen two number, it is 0**optimal** to take the larger one.

#### What makes a decision `local`
A decision is local when it considers only the available options at teh current step. It is based on the information it has at the time, and doesn't consider any consequences that may happen in the future from this decision..

> [!NOTE]
  most Greedy problem  will be asking for the maximum or minimum of something, but not always.

Imagine we're at a party , and there's this HUGE **jar of different candies**.. Some candies are big,, some are tiny, but they all have littlle stickers on them saying how many calories they are worth.
You want to eat as much canndy as possible without going over 500 calories
BUT....
you're impatient you don't plan ahead. You just pick the smallest **calorie cand availabe each time**
the logic:
- "Oh, this one's only 10 calories? I’ll take it."
    
- "Nice, here’s a 12-calorie one, I’ll take it."
    
- "This one’s only 5 calories? Easy choice!"  
    And you keep going like that until you're close to the limit.
at the end, maybe you ate more pieces... but someone who planned ahead could have eaten **fewer candies but more total calories worth of better, yummier candies **
we were just greedier for the smallest calories in the moment - not looking for the bigger picture.

> [!NOTE]
  globally implementing a greedy is easy, the hardest part is that finding the more  optimized algorithm that can really work.

#### why is this `greedy` 
because at each step::
- we pick what it's best right now.
- we don't think about how those choices affect the final result
The algorithm is called greedy because it makes locally optimal choices at each step (e.g., choosing the element with the lowest cost to move) with the goall of achieving a globally eficient solution. It contrasts with the previously discussed `rec_chunk_sort`, which uses a recursive divide-and-conquer approach with chunk splitting. The greedy approach is simpler and often more intuitive, though it may not always produce the absolute minimum number of operation compared to chunk-based sort

- `greedy_sort` : The main entry point, orchestrating the three phases of the algorithm.
- `greedy_push_to_b` : moves element form stack A to Stack B, reducing stack A to 3 elemments and organizing Stack B
- `greedy_push_back_to_a`: Moves elements back from Stack B to Stack A, choosing the cheapest move each time.
- `greedy_final_rotation` : Rotates Stack A to place the smallest element at the top.
- Helper Functions:
	- `greedy_push_element_strategically` : Decides how to push elements to stack B on their value
	- `greedy_calculate_costs`: Computes the cost of moving each element from Stack B to its target position in Stack A.
- `greedy_find_cheapest`: Identifies the element in Stack B with the lowest movement cost.
- `greedy_execute_move`: Performs the rotations and push to move an element from Stack B to Stack A.
- `greedy_find_target_position`: Finds the optimal position in Stack A for an element from Stack B.
- `greedy_rotate_to_top`: Rotates Stack A to position the smallest element at the top.

```c
void greedy_sort(t_ps *data)
{
    if (!data || data->total_size <= 3)
    {
        if (data->total_size == 3)
            sort_three_simple(data);
        else if (data->total_size == 2
            && get_stack_element_at_position(&data->a, 1)
            > get_stack_element_at_position(&data->a, 2))
            sa(data);
        return;
    }
    if (verify_stack_is_sorted(data))
        return;
    data->algo_ctx.ctx.greedy.phase = 0;
    greedy_push_to_b(data);
    data->algo_ctx.ctx.greedy.phase = 1;
    greedy_push_back_to_a(data);
    greedy_final_rotation(data);
}

```
This is the entry point for the greedy algorithm,handling the entire sorting process.
**Steps**:

1. **Base Cases**:
    - If the input size is ≤ 3, sort directly:
        - For size = 3, call sort_three_simple to sort Stack A.
        - For size = 2, swap (sa) if the top two elements are out of order.
        - For size ≤ 1 or if Stack A is already sorted (verify_stack_is_sorted), return immediately.
2. **Phase 0: Push to Stack B**:
    - Set phase = 0 in the algorithm context and call greedy_push_to_b to move most elements to Stack B, leaving 3 elements in Stack A.
3. **Phase 1: Push Back to Stack A**:
    - Set phase = 1 and call greedy_push_back_to_a to move elements back to Stack A in the correct order.
4. **Final Rotation**:
    - Call greedy_final_rotation to ensure the smallest element is at the top of Stack A.


### Tag sort

### Radix sort
This is a popular choice for Push Swap because it's non-comparative and can be adapted to work with stacks, bur far from be good enough to get the highest score. 
Map the integers  to their ranks (e.g., 1024, 19, 42, -5119, becomes 4, 2, 3, 1) to simplify comparisons. Then, sort based on binary digits (LSB to MSB), pushing numbers to Stack B based on the current bit and rotating as needed This approach is efficient and can sort 500 operations with `6,500` movements.

![[radix_sort]]

## Optimizations strategies
### Longest increasing subsequences (LIS)
idetify the `LIS` in Stack A and leave those element in place, pushing others to Stack B This reduces the number of operations by keeping already sorted elements untouched.

### Operation merging:
Combine operations like `ra` and `rb` into `rr` when possible to reduce the total count

> [!NOTE]
  more the numbers movement variation is wide more we need those optimizations
  For example in radix_sort the variation is really little we don't have too much merge to do optimizatons..
### Rank Mapping
Debugging push swap is challenging because the output is  a sequence of operations, and it's hard to visualize the state of stacks.. This is where a visualizer becomes invaluable. Many exisiting visualizers are graphical (Godot...), but I've 
developed my version of algorithm

### Opportunistic Permutations or branch reduction / Pruning
This is about recognizing little opportunities of 2 or 3 numbers explicitly anymore. we're using these functions to handle the endgame of `sortng small chunks` 
we're bascally saying:

- it's looking at position `1` (top of A ususally)
- `chunk value(data, to_sort, 1) + 1` 
		this is checking if the `next logical number is on top` 
		- if yes -> `sort_one() handles placing it` 
	- same for `chunk_value(..., 2) + 1`;
###### Why ? 
because stacks can only do top-level operation. if our next element is no at the top, we rotate it or swap it into place.  This is about  making minimal permutations manuallly rather than writing a recursive `perm(3)`

#### 2 Easy_sort_second

## Terminal-Based WebP Visualizer for Debugging
Graphical visuallizers,, like those built with SFML, Godot, or web technologies, are powerful but have drawbacks:
- Setup complexity: They require installing dependencies, which can be cumbersome, especially on systems like 42
- Ressource Usage: Graphical interfaces consume more system ressources, slowing browser limiting accessibility.
- Portability: They often require specific environments or a browser, limiting accessibility.
- Learning curve : Undestanding and navigating a GUI can distract from debugging algortihm itself

To address these issues, i created a  `terminal-based visualizer` that generates a tow stacks and the movements of your algorithm highly effective for debugging.  

The visualizer is a program  that : 
- takes the `push_swap` executable and list of integers as input.
- render each stateas a simple ASCII-art representation in the terminal.


As you can see in this video 


### Summary of notions learnt

- Jump Table (or function pointer table) is a data structure that maps `identifiers` to function pointers.
- Machine State
- Data structures....
- Data Structure poymorphique
- Complexity Analysis
	- instead of traditional time complexity (O(n)), focused on minimizing the number of operations,a  unique metric for push_swap. We trace all the movements aiming for <=700 number for (100) numbers and <= 5500 movements for (500)
- terminal-based WebP visualizer
- greedy algorithm
- chunk algorithm
- divide and conquer  approach
- Permutations formula
- Pivot selection
- Trade-offs between simplicity and efficiency:
	- divide and conquer approach is more difficult to understand but more efficient for large inputs 
	- greedy is easier to  read but less optimal
- Two stack paradigm
- Circular buffer
- Dynamic partionning
- Algorithm context
- Code organization
- Compile-time Configuration
- Software engineering Principles (Modularity, Extensibility, Debugging and testing)
- backtracking
- pruning logic
- Memory management
- 

### In the Nutshell
the Push Swap project has been a rich learning experience, covering a wide range of computer science and software engineering concepts. From mastering  algorithms and data structures to designing a data migration facility and create visualization tool. I have gained practica skills in algorithm design,  optimization, debugging. These notions not only enabed me to meet the project's requirements but allso prepared me to tackle complex problems with a balance of creativity. efficiency, and clarity. 

By documenting these insights I hope to inspire others to approach similar challenges with a mindset of innovation, rigor, leveraging toold like the algorithm visualizer I've created.

## let's suppose this

## how pivots are chosen 
the **pivots are not chosen as "first", "last", or "random" elements**.  
Instead, the pivots are **calculated based on the values in the chunk**—specifically, as fractions of the maximum value in the chunk.

### How pivots are chosen

- The code computes two pivots: `pivot_1` and `pivot_2`.
- These are **not actual values from the stack**, but rather offsets from the maximum value:
    - `pivot_1` is typically around 1/2 or 2/3 of the chunk size (see `set_third_pivots`).
    - `pivot_2` is typically around 1/3 or 1/2 of the chunk size.
- For each value in the chunk:
    - If `value > max_value - pivot_2` → goes to **max** (top group)
    - Else if `value > max_value - pivot_1` → goes to **mid** (middle group)
    - Else → goes to **min** (low group)

So, **the pivots are thresholds** that split the chunk into three groups: high, middle, and low values.

### What does "top", "mid", "low" mean?

- **Top (max)**: Elements greater than `max_value - pivot_2` (the largest values in the chunk)
- **Mid**: Elements between `max_value - pivot_1` and `max_value - pivot_2` (middle values)
- **Low (min)**: Elements less than or equal to `max_value - pivot_1` (the smallest values)

These groups are used to recursively split and sort the stack, making the sorting process more efficient by working on smaller, more ordered subgroups.
### **Suppose the initial stack is:**

A = [15, 3, 22, 8, 25, 1, 18]

- 
- 
- 
- 

- `size = 7`
- `loc = TOP_A`

---

### **Step 1: Calculate pivots**

- `max_value = 25`
- For `TOP_A`, suppose (from your FSM and code):
    - `pivot_1_factor = 2` → `pivot_1 = 2 * size / 3 = 2 * 7 / 3 ≈ 4`
    - `pivot_2_factor = 3` → `pivot_2 = size / 3 = 7 / 3 ≈ 2`
- So:
    - `pivot_1 = 4`
    - `pivot_2 = 2`

---

### **Step 2: Compute thresholds**

- `max_value - pivot_2 = 25 - 2 = 23`
- `max_value - pivot_1 = 25 - 4 = 21`

---

### **Step 3: Partition each value**

For each value in the chunk, compare to thresholds:

|Value|>23? (max)|>21? (mid)|else (min)|Result|
|---|---|---|---|---|
|15|No|No|Yes|min|
|3|No|No|Yes|min|
|22|No|Yes||mid|
|8|No|No|Yes|min|
|25|Yes|||max|
|1|No|No|Yes|min|
|18|No|No|Yes|min|

---

### **Step 4: Resulting subchunks**

- **max**: [25]
- **mid**: [22]
- **min**: [15, 3, 8, 1, 18]

---

### **Step 5: Recursive splitting**

Now, each subchunk is processed recursively:

#### **A. max ([25])**

- Only one element, already sorted.

#### **B. mid ([22])**

- Only one element, already sorted.

#### **C. min ([15, 3, 8, 1, 18])**

- Size = 5, so repeat the process:
    - `max_value = 18`
    - `pivot_1 = 2 * 5 / 3 ≈ 3`
    - `pivot_2 = 5 / 3 ≈ 1`
    - `max_value - pivot_2 = 17`
    - `max_value - pivot_1 = 15`
    - Partition:
        - 15: No, Yes → mid
        - 3: No, No → min
        - 8: No, No → min
        - 1: No, No → min
        - 18: Yes → max
    - **max**: [18]
    - **mid**: [15]
    - **min**: [3, 8, 1]
- Continue recursively until all subchunks are size ≤ 3, then sort directly.

---

### **Step 6: Final sorted order**

After all recursive splits and direct sorts, the stack is sorted:

[1, 3, 8, 15, 18, 22, 25]

- 
- 
- 
- 

---

## **Summary Table**

|Step|Chunk|max_value|pivot_1|pivot_2|max threshold|mid threshold|max|mid|min|
|---|---|---|---|---|---|---|---|---|---|
|1|[15,3,22,8,25,1,18]|25|4|2|23|21|[25]|[22]|[15,3,8,1,18]|
|2|[15,3,8,1,18]|18|3|1|17|15|[18]|[15]|[3,8,1]|
|3|[3,8,1]|8|2|1|7|6|[8]|[3]|[1]|

Each subchunk of size ≤ 3 is sorted directly.

---


## **Initial State**

- Stack A: `[15, 3, 22, 8, 25, 1, 18]`
- Chunk: size=7, loc=TOP_A

---

## **Step 1: First Split**

### **Calculate pivots**

- `max_value = 25`
- `crt_size = 7`
- For `TOP_A`, let's assume:
    - `pivot_1_factor = 2` → `pivot_1 = 2 * 7 / 3 = 4` (rounded down)
    - `pivot_2_factor = 3` → `pivot_2 = 7 / 3 = 2` (rounded down)
- So:
    - `pivot_1 = 4`
    - `pivot_2 = 2`
- Thresholds:
    - `max_value - pivot_2 = 23`
    - `max_value - pivot_1 = 21`

### **Partition elements**

|Value|Compare to 23|Compare to 21|Goes to|
|---|---|---|---|
|15|15 > 23? No|15 > 21? No|min|
|3|3 > 23? No|3 > 21? No|min|
|22|22 > 23? No|22 > 21? Yes|mid|
|8|8 > 23? No|8 > 21? No|min|
|25|25 > 23? Yes||max|
|1|1 > 23? No|1 > 21? No|min|
|18|18 > 23? No|18 > 21? No|min|

- **max**: [25]
- **mid**: [22]
- **min**: [15, 3, 8, 1, 18]

### **Movements (using mig_chunk)**

- For each value, you call `mig_chunk(data, from, to)` to move it to the correct subchunk location.
- Let's assume:
    - min → stays in A (e.g., BOTTOM_A)
    - mid → goes to B (e.g., TOP_B)
    - max → goes to B (e.g., BOTTOM_B)

**Movements:**

1. 15: mig_chunk(TOP_A, BOTTOM_A) // stays in A
2. 3: mig_chunk(TOP_A, BOTTOM_A) // stays in A
3. 22: mig_chunk(TOP_A, TOP_B) // push to B
4. 8: mig_chunk(TOP_A, BOTTOM_A) // stays in A
5. 25: mig_chunk(TOP_A, BOTTOM_B) // push to B, then rotate B
6. 1: mig_chunk(TOP_A, BOTTOM_A) // stays in A
7. 18: mig_chunk(TOP_A, BOTTOM_A) // stays in A

---

## **Step 2: Recursively process each subchunk**

### **A. max ([25], BOTTOM_B)**

- Only one element, sorted.

### **B. mid ([22], TOP_B)**

- Only one element, sorted.

### **C. min ([15, 3, 8, 1, 18], BOTTOM_A)**

#### **Calculate pivots**

- `max_value = 18`
- `crt_size = 5`
- `pivot_1 = 2 * 5 / 3 = 3`
- `pivot_2 = 5 / 3 = 1`
- Thresholds:
    - `max_value - pivot_2 = 17`
    - `max_value - pivot_1 = 15`

#### **Partition elements**

| Value | Compare to 17 | Compare to 15 | Goes to |
| ----- | ------------- | ------------- | ------- |
| 15    | 15 > 17? No   | 15 > 15? No   | min     |
| 3     | 3 > 17? No    | 3 > 15? No    | min     |
| 8     | 8 > 17? No    | 8 > 15? No    | min     |
| 1     | 1 > 17? No    | 1 > 15? No    | min     |
| 18    | 18 > 17? Yes  |               | max     |

- **max**: [18]
- **mid**: []
- **min**: [15, 3, 8, 1]

#### **Movements**

- 15: mig_chunk(BOTTOM_A, BOTTOM_A) // stays in A
- 3: mig_chunk(BOTTOM_A, BOTTOM_A) // stays in A
- 8: mig_chunk(BOTTOM_A, BOTTOM_A) // stays in A
- 1: mig_chunk(BOTTOM_A, BOTTOM_A) // stays in A
- 18: mig_chunk(BOTTOM_A, BOTTOM_B) // to BOTTOM_B

---

### **Now process [15, 3, 8, 1]**

#### **Calculate pivots**

- `max_value = 15`
- `crt_size = 4`
- `pivot_1 = 2 * 4 / 3 = 2`
- `pivot_2 = 4 / 3 = 1`
- Thresholds:
    - `max_value - pivot_2 = 14`
    - `max_value - pivot_1 = 13`

#### **Partition elements**

|Value|Compare to 14|Compare to 13|Goes to|
|---|---|---|---|
|15|15 > 14? Yes||max|
|3|3 > 14? No|3 > 13? No|min|
|8|8 > 14? No|8 > 13? No|min|
|1|1 > 14? No|1 > 13? No|min|

- **max**: [15]
- **mid**: []
- **min**: [3, 8, 1]

#### **Movements**

- 15: mig_chunk(BOTTOM_A, BOTTOM_B) // to BOTTOM_B
- 3: mig_chunk(BOTTOM_A, BOTTOM_A) // stays in A
- 8: mig_chunk(BOTTOM_A, BOTTOM_A) // stays in A
- 1: mig_chunk(BOTTOM_A, BOTTOM_A) // stays in A

---

### **Now process [3, 8, 1]**

- Size = 3, so sort directly (e.g., sort_three).

---

## **Summary of Chunks and Movements**

- Each time, you split the chunk into three (max, mid, min) using pivots.
- You move elements to their new locations using `mig_chunk`.
- When a chunk is size ≤ 3, you sort it directly.

---

## **Final Sorted Stack**

After all recursive splits and direct sorts, the stack is sorted:

[1, 3, 8, 15, 18, 22, 25]

- 
- 
- 
- 

---

## **Trace Table**

| Step | Chunk               | Pivots | max  | mid  | min           | Movements (mig_chunk)            |
| ---- | ------------------- | ------ | ---- | ---- | ------------- | -------------------------------- |
| 1    | [15,3,22,8,25,1,18] | 4, 2   | [25] | [22] | [15,3,8,1,18] | pb+rb (25), pb (22), ra (others) |
| 2    | [15,3,8,1,18]       | 3, 1   | [18] | []   | [15,3,8,1]    | pb+rb (18), ra (others)          |
| 3    | [15,3,8,1]          | 2, 1   | [15] | []   | [3,8,1]       | pb+rb (15), ra (others)          |
| 4    | [3,8,1]             | -      | -    | -    | -             | sort_three (direct sort)         |

---

**Note:**

- The actual stack operations (pb, ra, rb, etc.) depend on your FSM and move table, but the above gives the general flow.
- Each recursive split reduces the chunk size, and all movements are tracked by `mig_chunk

### Acknowledgements
[javier]()
[MickeylandgelO]

[[radix_sort]]
[[k_sort]]
[[chunk_sort]]
[[partition_sort]]
[[pivot_sort]]
[[sort_greedy]]
[[tree sort]]
[[quick sort]]
[[intro sort]]
[[intro sort]]
[[hybrid sort]]
[[hybrid sort]]
[[hybrid sort]]
[[bucket sort]]
[[bucket sort]]
