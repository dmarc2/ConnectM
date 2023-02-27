# ConnectM
This is a implementation of the game ConnectM, which was created to demonstrate the use of search algorithms to create an agent program. The user plays against an A.I. player which will try to win the game.
 
Setup and Compilation 
1. Download and unzip the submission from eLearning / github on a Linux box. 
2. The submission includes: 
Makefile
connectM.hpp
connectM.cpp
main.cpp
README.md (this file)
Report.pdf
 
3. Environment: This program has been tested in a linux environment.
 
4. Compiling. To compile type the command "make" or "make connectM"
 
Running the program. To run the program type the command "./connectM N M H"

User input: The program requires 3 cmdline inputs defined as follows:
N - The width x height of the board (NxN)
M - The number of pieces to have in a row for a win (M <= N)
H - H is 1 if the Human goes first, else H is 0 inferring the computer goes first

Output: The board will display and update after each move from both players. If there's a win or draw,
the text will be displayed to the screen.
