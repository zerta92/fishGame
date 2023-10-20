# Fish Game

A “Warcraft” style game in which you can control a marine ecosystem based on keyboard commands

## Build Instructions

### Prerequisites

Make sure you have the following tools installed on your system:

- C++ Compiler (e.g., GCC, Clang)
- Make (optional, if you use a Makefile)
- Visual Studio Code (optional, for editing and running tasks)

### Building the Project

1. **Open a Terminal:**
    -If you're using Visual Studio Code, open the integrated terminal (View > Terminal or `Ctrl` + `backtick`).

2. **Navigate to the Project Directory:**
   ```bash
   cd /path/to/project

   ##If you have a Makefile:
    make
   ##If you are using a custom build command
    g++ -g -std=c++11 PA4.cpp GameCommands.cpp CartPoint.cpp CartVector.cpp Cave.cpp CoralReef.cpp Fish.cpp GameObject.cpp Model.cpp Shark.cpp Sharknado.cpp Tuna.cpp View.cpp -o PA4
    ```

### Running the Project
1. **Open a Terminal:**
- If you're using Visual Studio Code, open the integrated terminal (View > Terminal or `Ctrl` + `backtick`).

2. **Navigate to the Executable Directory:**
```bash
cd /path/to/project
```
   3. **Run excutable:**
```bash
   ./main
```

  