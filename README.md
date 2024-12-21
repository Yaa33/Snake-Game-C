Snake Game with SDL2 in C

This is a Snake Game implementation in C using SDL2, with the snake data structure
implemented as a doubly linked list and a queue used to render the snake’s body as it turns. The
game features smooth snake movement, apple eating, collision detection, and basic menus.


Project Structure

collision.c: Contains collision detection logic using AABB (for snake collisions with itself, and apples) also ut of frame func.
game.c: Contains the core game logic, including snake movement , and collision detection.
input.c: Handles user input (key presses for snake movement).
main.c: Entry point of the game, initializing everything and managing the game loop.
menu.c: Manages the game menu (start ,quit and best score options).
render.c: Handles all rendering (drawing the snake, apples).
texture.c: Loads textures (images for the snake and apple) using SDL2's image functions.
assets/: Contains image files used for the game (snake body, apple, background). 
snake asset:https://opengameart.org/content/snake-game-assets
gras asstes: https://opengameart.org/content/blended-textures-of-dirt-and-grass
arcade font: https://www.dafont.com/fr/arcade-pizzadude.font
include/: Contains header files (.h files) for all source file
lib/: all lib or .h files inlcuded


  

Requirements
    
To build and run this project, you need:  
SDL2 Library: The game uses SDL2 for rendering and input handling.
SDL2_image: For loading image assets (e.g., snake body, apple).
SDL2_ttf: For handling fonts and text rendering (if used).
C Compiler: A C compiler (like GCC) to compile the game.

Installing SDL2 and SDL2_image
On Linux (Ubuntu)

    sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev

On macOS (Using Homebrew)

    brew install sdl2 sdl2_image sdl2_ttf

On Windows

Download the SDL2, SDL2_image, and SDL2_ttf libraries from the official website and set them up in your project.
How to Build

Clone the repository:

    git clone https://github.com/yourusername/snake-game-sdl2.git
    cd snake-game-sdl2

Build the project:

The following command will compile and link the project files, using the appropriate include directories and libraries, and output the executable in the build/ folder:

    gcc -o build/game src/main.c src/game.c src/input.c src/collision.c src/render.c src/texture.c src/menu.c -Iinclude -I/usr/include/SDL2 -I/usr/include/SDL2_ttf -Ilib -lSDL2 -lSDL2_image -lSDL2_ttf && ./build/game

Breakdown of the build command:

-o build/game: Specifies the output directory and executable name (build/game)
src/*.c: Includes all the C source files that are part of the project.
-Iinclude: Includes the directory where your header files are stored (include/).
-I/usr/include/SDL2: Includes the SDL2 header files (adjust path for your system).
-I/usr/include/SDL2_ttf: Includes the SDL2_ttf header files (if used for fonts).
-Ilib: Includes additional libraries if you have any custom libraries.
-lSDL2: Links the SDL2 library.
-lSDL2_image: Links the SDL2_image library.
-lSDL2_ttf: Links the SDL2_ttf library (if you are using fonts).
&& ./build/game: After compiling, the ./build/game command runs the resulting executable.

Run the game:

After the game has been compiled, you can run it with the following command:

    ./build/game

  This will start the game and you can play!

Gameplay

Simple Snake Game: Control the snake using the arrow keys.
No Wall Limits: The game does not have walls
Apple Eating: Eat apples to grow the snake and increase your score and the snake body.

