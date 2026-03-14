# Pong game implemented in c++ and using raylib library

- Two playes can play one with (w,s) and another with (arrowup,arrowdown)

# features
 - [x] Two Players
 - [x] Scoring 
 - [ ] Game Screen
 - [ ] Vs computer
 - [ ] Game Over Loop
 - [ ] Startup Screen
 - [ ] Infinite Music
 - [ ] Game Sounds


# Clone the repo
```
git clone https://github.com/coffinggx/pong-raylib
```

# dependencies
- Dependencies needed to run raylib are included in [Raylib](https://github.com/raysan5/raylib)

# Building (Simpler Linux)
 - Works Out of box if raylib is installed in linux
```
cd pong-raylib
chmod +x ./build.sh
./buid.sh
```

# Preferred build (Cmake)
- Make sure cmake is installed
- For linux
```
sudo pacman -S cmake #arch
sudo apt install cmake #ubuntu

```
```
cd pong-raylib
mkdir build
cd build
cmake ..
make
./pong-raylib
```


