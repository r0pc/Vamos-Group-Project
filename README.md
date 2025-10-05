# Group Name: Vamos

*Do Not Touch gitignore or CMakeLists.txt (will either not compile or not commit).* 
Also do not try to commit (upload) any binaries (.exe), it will not work.

## Tools Needed
### Software
- [Git](https://git-scm.com/downloads)
- [CMake](https://cmake.org/download/)
- [Compiler](https://code.visualstudio.com/docs/cpp/config-mingw) 
- [VSCode](https://code.visualstudio.com/download)
  
### Vscode Extensions
- CMake Tools
- C/C++
- gitlens (install if you dont want to use commands for git)

## Commands for git if you don't have gitlense
### git clone cmd to get repo to pc

``` bash
git clone https://github.com/r0pc/Vamos-Group-Project.git
```

### to get new version on local pc

```bash
git pull
```

### to commit using cmd

``` bash
git add .
git commit -m "msg"
```

## Commands to build using cmake
### cmd to build / compile if using mingw and cmake
Top command is to only be run once. Afterwards Always run only 2nd command. (.exe) file will be inside build directory.
``` bash
cmake -G "MinGW Makefiles" -B build
cmake --build build
```


## Tasks:
- Filing (Both .txt & .csv)
- Tokenizer
- ~~Hashmap (For Toxic words dataset)~~ 
- QuickSort
- Data Analysis (top 10 toxic words, avg word lenght, ....)
- GUI / TUI 