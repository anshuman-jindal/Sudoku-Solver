# Sudoku-Solver
A sudoku is a 9x9 square grid consisiting of subgrids of dimensions 3x3 each. The objective is to fill the each square such that every row, every column and every subgrid has exactly all the numbers from 1 to 9. A partially filled grid is given as an input and the algorithm backtracks and outputs the first one that fulfills the above criteria, or reports that the sudoku is not solvable. An empty square has to be indicated by a 0 in the input instance of the puzzle

### What is different in this implementation?
The C++ file contains 2 variables N (preset value 9) and M (preset value 3). The user can change M to any other natural number and set N=M*M and solve the instance.