# Pong Game in C++ with SFML

A classic Pong game implementation using SFML graphics library.

## Features
- Two-player gameplay (W/S vs Up/Down keys)
- Ball physics with collision detection
- Score boundaries
- Smooth 60 FPS gameplay
- Simple and clean graphics

## Controls
- **Left Paddle:** W (up), S (down)
- **Right Paddle:** Up Arrow (up), Down Arrow (down)
- **Close:** Click X or Alt+F4

## Technologies
- C++17
- SFML 2.6.2 (Simple and Fast Multimedia Library)
- Visual Studio 2022

## Build Instructions
1. Install SFML and set include/library paths
2. Build with Visual Studio (x64, Debug)
3. Copy SFML DLLs to executable directory

## Game Logic
- Ball bounces on paddles and top/bottom walls
- Ball resets when out of bounds
- Paddle movement with boundary checking

## What I Learned
- SFML basics (window, shapes, input)
- Game loop structure
- Collision detection
- Basic game physics
- Event handling in games
