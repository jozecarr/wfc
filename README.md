# Wave Function Collapse (WFC) Algorithm

## Overview

This project implements the **Wave Function Collapse (WFC)** algorithm, a procedural generation technique used to generate tile-based grids based on a sample of input tiles. The algorithm is mostly used in creating maps and textures for games and simulations, where generated grids follow specific local patterns derived from the input.

This implementation allows you to generate tile-based grids with constraints, meaning tiles will automatically adjust to ensure valid adjacency based on predefined rules.

This is a work in progress, something to do whilst I look for a job.

Currently this is only working for windows, but a linux implementation will be available.

## Table of Contents

1. [Features](#features)
2. [How It Works](#how-it-works)
3. [Installation & Usage](#installation)

## Features

- **Procedural Tile Generation**: Automatically generates grids with specific tile patterns.
- **Adjacency Rules**: Tiles are placed respecting adjacency constraints derived from a tileset.
- **Entropy-Based Collapse**: Selects the most uncertain tile to collapse first.
- **Backtracking**: Handles contradictions and invalid states with backtracking.
- **Flexible Grid Sizes**: Generate grids of any size based on the input configuration.
- **Customizable Tile Set**: Allows for defining your own tiles and adjacency rules.

## How It Works

The **Wave Function Collapse** algorithm works by:

1. **Initializing the grid**: A grid is initialized with each cell holding a superposition of all possible tiles from the tile set.
2. **Tile Collapse**: The algorithm collapses the most uncertain cell (the one with the least possible tiles) into a single tile.
3. **Propagation**: Once a cell collapses, the neighboring cells' possible tiles are updated according to adjacency rules.
4. **Repeat**: The algorithm repeats the collapse and propagation steps until all cells are collapsed into one specific tile.
5. **Contradictions**: If no valid tile can be placed in a cell (a contradiction), the algorithm backtracks and tries a different configuration.

The goal of the algorithm is to generate a grid where local tile patterns are consistent with the input, but the overall grid can be unique and large, and follows adjacency rules.

My implementation uses c++ with [raylib](https://github.com/raysan5/raylib) to simulate and render the grid. 

### Installation

1. **Clone the repository**:
   
   Via SSH:
   ```bash
   git clone git@github.com:jozecarr/wfc.git
   ```
   Or via HTTPS:
   ```bash
   git clone https://github.com/jozecarr/wfc.git
   ```
   
3. **Build the project**: Use ```g++``` to compile the code:

   ```
   cd wfc
   g++ src/*.cpp -o wfc.exe -I ./libs/raylib -L ./libs/raylib -lraylib -lopengl32 -lgdi32 -lwinmm
   ```
   Alternatively, the repo contains a ```.vscode``` folder, so if you're using vscode, just do ```Ctrl + Shift + B```
   
   (or do ```Ctrl + Shift + P``` and search for ```Tasks: Run Build Task``` and click that).

   
4. **Run the executable**

   ```
   ./wfc.exe
   ```
