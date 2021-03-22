[![License][license-logo]][license-url]

<br />
<p align="center">
  <h2 align="center">Cub3d</h2>

  <p align="center">
    My first RayCaster with miniLibX
    <br />
    <a href="https://github.com/pabloocg/cub3d/tree/master/srcs"><strong>Explore the docs »</strong></a>
  </p>
</p>
<img src="record.gif" width="500" height="400" />

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#installation">Installation</a></li>
        <li><a href="#configuration">Configuration</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

---

## About The Project

This project is inspired by the world-famous eponymous 90’s game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be tomake a dynamic view inside a maze, in which you’ll have to find your way.

---

### Madatory Part

| Program name     	| cub3D                                                                       	|
|------------------	|-------------------------------------------------------------------------------------	|
| Makefile         	| yes                                                     	|
| External functs. 	| - open, close, read, write,malloc, free, perror,strerror, exit</br>- All functions of the math library (-lm man man 3 math)</br>- All functions of the MinilibX                              	|
| Libft authorized 	| yes                                                                                 	|
| Description      	| You must create a “realistic” 3D graphicalrepresentation of the inside of a maze from afirst person perspective.  You have to create thisrepresentation using the Ray-Casting principlesmentioned earlier	|

---

- The left and right arrow keys of the keyboard must allow you to look left and right in the maze.
- The W, A, S and D keys must allow you to move the point of view through the maze.
- Pressing ESC must close the window and quit the program cleanly.
- Clicking on the red cross on the window’s frame must close the window andquit the program cleanly.

The map must be composed of only 4 possible characters: **0** for an empty space, **1** for a wall, **2+** for an item and **N,S,E** or **W** for the player’s start position and spawning orientation. This is a simple valid map:
```
111111
100101
102001
1100N1
111111
```
- The map must be closed/surrounded by walls, if not the program must return an error.
- Except for the map content, each type of element can be separated by one or more empty line(s).

## Getting Started

### Installation

1. Clone the repository
    ```sh
    git clone https://github.com/pabloocg/cub3d.git
    ```
2. Enter the repository and run make
    ```sh
    cd cub3d && make
    ```

### Configuration

The program receives as argument a configuration file with the specifications to be launched. </br>
If no configuration file is offered, a default configuration file is taken. </br>
The main parameters to configure are:

1. Resolution
    ```
    R 1920 1080
    ```
    - identifier: R
    - x render size
    - y render size
2. North texture:
    ```
    NO ./path_to_the_north_texture
    ```
    - identifier: NO
    - path to the north texure
3. South texture:
    ```
    SO ./path_to_the_south_texture
    ```
    - identifier: SO
    - path to the south texure
4. West texture:
    ```
    WE ./path_to_the_west_texture
    ```
    - identifier: WE
    - path to the west texure
5. East texture:
    ```
    EA ./path_to_the_east_texture
    ```
    - identifier: EA
    - path to the east texure
6. Sprite texture:
    ```
    S ./path_to_the_sprite_texture
    ```
    - identifier: S
    - path to the sprite texure
7. Floor texture:
    ```
    F 220,100,0
    ```
    - identifier: F
    - R,G,B colors in range [0,255]:0, 255, 255
8. Ceilling texture:
    ```
    C 225,30,0
    ```
    - identifier: C
    - R,G,B colors in range [0,255]:0, 255, 255

You can see a example of a configuration file [here](https://github.com/pabloocg/cub3d/tree/master/maps).

## Usage in MacOS
- W, A, S, D to move the player
- The left and right arrow to look left and right
- SPACE to shot
- ESC or click red arrow to close the program

```
./cub3d maps/map.cub
```

The hearts in the game give you life.</br>
The gun gives you bullets.</br>
The aim is to catch all the stars of light.

## License

Distributed under the GNU GPLv3. See `LICENSE` for more information.

## Contact

Pablo Cuadrado García </br>
[Linkedin][linkedin-url] - pablocuadrado97@gmail.com

[license-logo]: https://img.shields.io/cran/l/devtools?style=for-the-badge
[license-url]: https://github.com/pabloocg/cub3d/LICENSE
[linkedin-url]: https://linkedin.com/in/pablo-cuadrado97

