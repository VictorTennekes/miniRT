# miniRT

> :warning: **This project is a work in progress**

This project is an introduction to the beautiful world of ray-tracing.
Once completed it will be able to render simple Computer-Generated-Images.

## Index
* [Installation](#installation)
* [Usage](#usage)
  * [Definitions](#definitions)
  * [Keybindings](#keybindings)

## Installation
Run `make` to compile the executable.

## Usage
The executable can be ran with a file: './minirt file.rt'.

Files have to meet the following requirements:
* one definition of both resolution and ambient lighting.
* one or more definition(s) for camera(s) and light(s).
* any amount of objects.

### Definitions

Resolution:	`R {width} {height}`
* x render size.
* y render size.

Ambient lighting:	`A {ratio} {color}`
* Ambient lighting ratio in range [0.0,1.0].
* R,G,B colors in range [0-255].

Camera:	`c {position} {orientation} {FOV}`
* X,y,z coordinates of the view point.
* A vector withe the x,y,z axis in the range [-1,1].
* Horizontal field of view in degrees in range [0,180].

Light:	`l {position} {ratio} {color}`
* X,y,z coordinates of the light point.
* The light brightness ratio in range [0.0,1.0].
* R,G,B colors in range [0-255].

Sphere:	`sp {position} {size} {color}`
* X,y,z coordinates of the sphere center.
* The sphere diameter.
* R,G,B colors in range [0-255].

Plane:	`pl {position} {orientation} {color}`
* x,y,z coordinates.
* A vector withe the x,y,z axis in the range [-1,1].
* R,G,B colors in range [0-255]

Triangle:	`tr {first point} {second point} {third point} {color}`
* x,y,z coordinates.
* x,y,z coordinates.
* x,y,z coordinates.
* R,G,B colors in range [0-255].

### Keybindings
There are a number of useful keybindings that are listed below.

**Exiting the application.**
To exit the application press `q` or `esc`. You can also click the red `x` in the top right of the window.

**Camera**
To move the camera you can use the `WASD` keys.
To rotate the camera you can use the `↑←↓→` keys.
To switch camera's you can use the `o`(previous) and `p`(next) keys.

## License

MIT © [Victor Tennekes](https://www.github.com/victortennekes)