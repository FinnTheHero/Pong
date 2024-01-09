# Pong
Pong, a classic 2D game made with C++ and Raylib

![Icon](./public/extras/Icon.png)

> Assuming you already have Raylib installed on your device (You can see this [Link](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux) for instructions)

## Play

### From releases
Download the executable from the latest release, make sure you have Raylib installed, and run the game.

### Build Pong

1. Clone and cd into the project
    ```shell
    git clone -b linux-branch https://github.com/FinnTheHero/Pong.git && cd Pong
    ```

2. Make `build_prod.sh` executable and run it
    ```shell
    chmod +x build_prod.sh && ./build_prod.sh
    ```
   This will generate the executable in the root directory `/`

## Work on Pong
1. Clone and cd into the project
    ```shell
    git clone -b linux-branch https://github.com/FinnTheHero/Pong.git && cd Pong
    ```

2. Make `build_dev.sh` executable and run it
    ```shell
    chmod +x build_dev.sh && ./build_dev.sh
    ```

## About the Game
* The maximum score is 3
* Left side movement: `W` & `S`
* Right side movement: `Arrow Key Up` & `Arrow Key Down`
* `Escape` to return to the main menu
* `Delete` to quit the game

## Screenshots
> You can find screenshots in `/public/extras`

![Screenshot 1](./public/extras/Menu.png)
![Screenshot 2](./public/extras/Single_Player.png)
![Screenshot 3](./public/extras/Game_Over.png)