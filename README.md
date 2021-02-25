
This repository is a test toolbox for Scilab. It requires "thirdparty" directory which can be downloaded as "external-library.zip" file from the page: https://scilab.in/fossee-scilab-toolbox. The "thirdparty" directory contains compiled library for a simple "multiplication" function written in C. After copying the "thirdparty" directory to the toolbox directory, on the scilab console run "exec builder.sce" to build the toolbox and then run "exec loader.sce" to load the toolbox. Type "help" in the scilab console and browse through the help content of "test_toolbox". The external-library.zip file also contains separate instructions to work with MinGW on Windows OS.

  

This toolbox overall demonstrates

1. How to add a function defined in C in scilab

2. How to add a function defined in Scilab in Scilab

3. How to write help for the added functions

4. How to create a toolbox out of the above functions.

  

## Transpose Task
How to Run:
1. Clone the repo `git clone https://github.com/Detailer/Scilab6-Test-Toolbox`
2. cd into the test directory `cd Scilab6-Test-Toolbox/test`
3. Make run script executable `chmod +x run.sh`
4. Run the script `./run.sh`
5. Copy the created thirdparty folder in test directory to root directory
6. In scilab, navigate  to the too root toolbox folder and run `exec builder.sce` to build the toolbox
7. Load the toolbox by `exec loader.sce`
8. Test the function by `y = transpose(A);` where A is a real matrix.

How to unload the toolbox:

1.  In scilab, at the root directory, run exec `unloader.sce` followed by `ulink`
