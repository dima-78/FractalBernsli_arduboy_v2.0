FractalBernsly v2
This is a fractal generation simulation on the Arduboy platform. The fractal pattern is created using the Barnsley Fern algorithm, which produces a visually striking fractal resembling a fern leaf.

Features:
Fractal Generation: Generates a fractal pattern based on the Barnsley Fern algorithm.
Interactive Controls:
UP: Increases the number of iterations for generating the fractal.
DOWN: Decreases the number of iterations.
LEFT: Reduces the scale factor, making the fractal more compact.
RIGHT: Increases the scale factor, expanding the fractal.
A: Flips the screen vertically.
B: Flips the screen horizontally.
Customization: The fractal can be zoomed in or out by adjusting the scale factor, and the number of iterations can be increased for more detailed patterns.
Smooth Performance: Designed for smooth visual performance on the Arduboy with a frame rate of 60 FPS.
Controls:
UP: Increase iterations.
DOWN: Decrease iterations.
LEFT: Decrease scale factor.
RIGHT: Increase scale factor.
A: Toggle vertical screen flip.
B: Toggle horizontal screen flip.
Fractal Algorithm:
The fractal is generated using a set of transformation rules that are randomly applied to generate points that create the Barnsley Fern. The main transformations are:

Rule 1: A small transformation that moves the point towards the top-left.
Rule 2: A transformation that generates the largest part of the fern shape.
Rule 3: A transformation that slightly bends the fern to the right.
Rule 4: A transformation that causes the fern to curve back to the left.
The result is a fractal that becomes more complex and detailed as the number of iterations increases.

Installation:
Clone or download the repository.
Open the .ino file in the Arduino IDE.
Upload to your Arduboy device.
Customization:
You can modify the number of iterations and scale factor to adjust the appearance of the fractal. Play around with the controls to generate various fern-like patterns.

Created by:
Author: dima-78
Date: 2023_09_19
Feel free to edit this description according to yo