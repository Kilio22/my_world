# My_World

- **Binary name:** my_world [*.world]
- **Group members:**  
  - [@Kilio22](https://github.com/Kilio22)
  - [@HeyShafty](https://github.com/HeyShafty)
- **Mark:** 100%

# Subject

For this project you will create your own terraformer program.

> :bulb: Pick up some ideas from Tycoon Terrain for Unity3D.

Your challenge is to display a map and edit it at runtime.
The map is a wireframed map with tiles that are squares having all the same size.
The ground must be altered by raising, lowering or tilting tiles.

> :bulb: Tools will be provided to apply different effects and modifications upon the map.

> :warning: Having a pleasant user interface and intuitive interactions is the key to a good editing
tool. This project is the occasion for you to try your best on that topic.

## Requirements

### Mandatory
The following features are **mandatory** (if your project is missing one of them, it will not be evaluated further):
- the window can be closed using events,
- the game manages the input from the mouse click and keyboard,
- animations in your program are frame rate independent.

### Must

- The map **must** be displayed using a 3D projection (whether isometric or parallel),
- the tiles and their corners **must** be selected using the mouse,
- at least 3 effects (including the modification of altitude) **must** be implemented and selectable with a
toolbar in the window (e.g. reinitialization of the tiles’ altitudes, modification of the size of the area of
effect, switching between “tiles selectable” and “corners selectable”)

### Should

- Your window **should** stick between 800x600 pixels and 1920x1080 pixels,
- the size of the map **should** be selected using editable textboxes in the window,
- help boxes **should** appear as the mouse hovers elements in the toolbar(s),
- the buttons **should** have at least 3 visual states : idle, hover, and clicked,
- tiles **should** have a texture,
- the format of saved maps **should** be in a .legend file,
- moving around on the map **should** be done with arrow keys and/or by positionning the mouse cursor
on the edges of the window,
- zooming up and down **should** be done with keyboard and/or the scrolling button of the mouse.

### Could

- The program **could** save the map in a file at the end of the program in the terminal,
- the program **could** save the map in a file at runtime using buttons and tools,
- the program **could** load a map at the beginning of the program in the terminal (argument or stdin),
- the program **could** load a map at runtime using buttons and tools,
- the name of the saved files **could** be chosen at runtime,
- tools can be selected using keyboard shortcuts,
- sounds **could** be played on user actions,
- textures of the tiles **could** change depending on the direction of their slope,
- elements (e.g. buildings, roads) **could** be added on the map in compliance with the landforms,
- water areas **could** be added.

## Language use
- C
- CSFML

## Authorized functions

- CSFML Library:
    - Every
- Math library:
    - Every
- Libc:
    - malloc
    - free
    - memset
    - (s)rand
    - getline
    - (f)open
    - (f)read
    - (f)close
    - (f)write
    - opendir
    - readdir
    - closedir
    
## What does it look like ?
![alt text](https://raw.githubusercontent.com/Kilio22/MUL_my_world_2018/master/demo1.png)
![alt text](https://raw.githubusercontent.com/Kilio22/MUL_my_world_2018/master/demo2.png)
