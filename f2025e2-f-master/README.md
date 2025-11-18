# cs429-mastery-assignment
# You MUST Answer the following questions:
**Git**:
1. Paste exactly the output of `git remote -v` (10 words max)

**Makefile**:
1. What target compiles mini_ci with sufficient debug flags? (1 word max)
2. Which target verifies your output is identical to the given reference? (1 word max)

**Linux CLI**:
1. At least one testcase in the testcases file fails, paste a full, single  command that runs a failing testcase: (5 words max)

**GDB**:
1. When running a failing testcase, what line does the program segfault at in its given state? Paste the line.(20 characters max)
2. What is the call stack when the program segfaults in its given state? Paste the call stack output by GDB. (20 words max)

**C**:
1. What logic error caused the program to segfault? (10 words max) Note, "dereferencing null" is not sufficient.
2. Directly following this bug, how did you resolve the error? (10 words max)

## [IMPORTANT] After you SSH into a lab machine: Note that
- **ALL git commands must be in the command line.**
- **ALL gdb debugging must be in the command line.**
- **ALL file system actions (eg. creating a file, navigating a file, etc) must be in the command line**

You are allowed to utilize the terminal of your choice for these actions, but they must be accomplished in-terminal.

*Note: SSHing and opening *this* repo via VS Code or another GUI is acceptable provided that the above actions are then accomplished via a terminal therein.*

# What this repo contains:
- `stringbuilder.c` and its corresponding header files, and precompiled .o files in bin/.
- A Makefile
- Some testcases in the `testcases` folder
- a reference executable called `ref_sb`

# What this code does:
The given code takes in an input file where actions are given line by line.
Each line specifies an action for a stringbuilder object, the id of the object, and the required arguments for the action.
The program then performs the function and writes some output confirming that the action was completed.
The core of this action logic happens in `stringbuilder.c`, unfortunately, some of this logic is wrong.
It is up to you to fix it. 

# Instructions:
1. ssh into your favorite UTCS lab machine
2. Clone this repository
3. Read then use the Makefile
4. Debug the test cases using gdb; you must use gdb to pass this assessment.
5. To the best of your ability, ensure your output matches the reference exactly.
6. Write the outputs of the `history` command to a file in this repo called `shell_logs.txt`
7. Commit and push your changes. Do not forget to add `shell_logs.txt` to git.
8. Delete your local copy of this repository (you will need to use the r and f flags). If this results in any errors, please notify your proctor before leaving the room.
9. Please do not leave before your proctors tell you to do so. 
