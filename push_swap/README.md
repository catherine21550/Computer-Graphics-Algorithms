# Push_swap — Sorting Algorithm

An algorithmic project to sort data on a stack with a limited set of instructions, using the lowest possible number of actions.

## 📊 Performance
- **100 numbers:** < 750 operations.
- **500 numbers:** < 6500 operations.

## 🛠️ The Challenge
The project requires sorting a random list of integers using two stacks (`a` and `b`) and a specific set of operations:
* **Push** (`pa`, `pb`)
* **Swap** (`sa`, `sb`, `ss`)
* **Rotate** (`ra`, `rb`, `rr`)
* **Reverse Rotate** (`rra`, `rrb`, `rrr`)

## 🧪 Testing & Tools
To ensure the reliability and performance of the algorithm, there is provided by 42 School checker program on the tools.

### Random Number Generator
I created a custom Bash script (`tools/random_gen.sh`) to generate unique random integers within the `INT_MIN` to `INT_MAX` range. It uses `openssl` to ensure high-quality randomness.

**Usage:**
```bash
# Generate 100 random numbers and run push_swap
ARG=$(bash tools/generator.sh 100); ./push_swap $ARG | wc -l

## 🏃 OR Run
```bash
make
./push_swap 3 2 5 1 4
