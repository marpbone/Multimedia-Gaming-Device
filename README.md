# Introduction

The Media Center project is built using the MCB1700 board, revolving around three main components: a photo gallery, a USB-based MP3 player, and a game library. The first two features offer only minimal room for customization because of the requirements being very straightforward and direct. As a result, most of the development effort was focused on making the menus smooth, and building the game library. Throughout the project, several design choices were revisited and refined as we gained a better understanding of the board’s hardware and how its components interacted. These changes are discussed in detail in the design section. The system is designed to be user-friendly and uses  the joystick, potentiometer, LCD, and LEDs, with software developed in C using the Keil uVision Integrated Development Environment.

# Methodology

The methodology for the project revolved around having a separate UI (basically a menu) for each feature. Selections can be made in each section by moving the joystick in their respective areas, and selection by pressing it. The menus were given a rework to highlight the current option an integer “selection” was on, to display where the user is. This was done due to the highlighting functions malfunctioning on random occasions with a blinking like effect occurring. 
The pictures were to display the respective images which can be selected depending on the same selection logic within a picture select menu. The same logic was used for displaying the game options.
The audio player, however, did not need to have a separate menu due to there being just an audio player, but quality of life features were implemented like the LED lights changing depending on the potentiometer readings, which controlled the volume.
The games, tic tac toe, and chess puzzle implemented similar quality of life features using the LEDs to signify the number of turns. The design of the project follows the same architecture as the interim report, with just the change of the second game, chess (puzzle), being added.


Figure 1: Block diagram of architecture of the project.

# Design & Results

The most relevant and important aspect of the project was the joystick’s selection logic and the GLCD screen’s rework depending on the joysticks actions performed.
The menus use a continuous loop checking for changes made on the joystick by utilising the KBD functions for up, down, left, right, and select. This joystick logic in a continuous loop is used for every menu of the project, utilizing an if case block to process what input is received, and changing the selection accordingly. The menus involved the selection logic by utilizing an int value that changes based on the joystick movement. Upon KDB_Select, the current int value for the selector was implemented, calling the respective functions as displayed on the screen.
The int selector value played a vital role in the display of the GLCD, which would change the backcolour of the selector value that the user is at, displaying a highlight-like effect on the board.

### Menu
The menu of the project used the above mentioned logic to call on its relative functions. The menu options lets the user select between Photos, Play Audio, and Game Menu.

### Photos
When the user selects the Photo Gallery option, the program calls a dedicated function, photo_gallery(), which handles both the gallery interface and image display. This gallery behaves much like the main menu system: the user can scroll through the three available images and choose one to view. Once an image is selected, it is rendered on the LCD using the appropriate display function, and LEDs 1–3 illuminate based on which image is currently shown. To move back to the gallery menu, the user pushes the joystick left. Returning to the main menu occurs through the “Return to Home” option, after which the photo_gallery() function hands control back to the main C file.
Displaying custom images on the MCB1700 required several steps. The image was first opened in GIMP (GNU Image Manipulation Program), rotated 180° (because the board renders bitmaps upside down) and resized to fit the boards 320x240 pixel size to fit the screen properly. It was then exported as a C source file and added to the project directory. To make use of this file, it needed to be included in whichever source file was responsible for drawing the image. The final rendering was done using GLCD_Bitmap(x_pos, y_pos, width, height).


Figure 3: Picture Menu


Figure 4: Picture 1, just a rat.


Figure 5: Picture 2, Fred Again, the most talented EDM producer.


Figure 6: Picture 3, Martin Luther King Jr.

### Audio
When the user selects the audio option, the program calls the audio_player() function, which streams audio from the PC to the board over USB. This allows the board to play sound; such as music from a YouTube video, through its built-in speakers. The potentiometer is used to control volume: rotating it counter-clockwise raises the volume, while rotating it clockwise lowers it. An additional feature was added so that the eight onboard LEDs act as a visual volume indicator. As the potentiometer value increases, more LEDs light up; as the value decreases, the LEDs turn off. This behavior was implemented by reading the potentiometer’s analog value and mapping specific ranges to different LED states.
When audio playback begins, the board takes over as the system’s active audio output device by enabling the USB connection and routing the PC’s sound through the MCB1700 speakers. To stop audio playback, the user presses the joystick left, which triggers NVIC_SystemReset(). This function performs a soft reset via the AIRCR register, effectively reinitializing the system and restoring the default audio routing. Once the reset occurs, the audio_player() function exits and control returns to the main menu.


Figure 7: Audio with an indication of volume level with LEDs.

### Game Menu

This section has 3 sub sections: Game Menu, Tic Tac Toe (Game Menu), and Chess (Game 2). When the user selects “Game Menu” from the main menu, the function game_menu is called, implementing the same logic as the other mentioned menus. This menu has a tic tac toe, chess, and return to main menu options, as shown in figure 8. 


Figure 8: Game menu with a guest appearance from the ceiling lights again.

### Tic Tac Toe

Selecting Tic-Tac-Toe calls on the tic_tac_toe function, which implements a similar logic to the menus for the joystick selections. Tic Tac Toe is a turn based game, which was achieved by having a function being called at every move, that either added or subtracted 1 from an integer “c”. This integer was used to identify the player whose turn it is. 
The board was split into nine sections, starting from the value y=1, x=5 for top left, and y=7,x=13 for bottom right. Since the screen is divided into 20 columns and 10 rows, we could utilise more screen for horizontal movements. This gave the x value increments of 4, and y increments of 3 to move the cursor. 	
The cursor was made to be 1 row lower than the location of X and O, as to not interfere with the values saved at the relative pixels, keeping the score consistent.
A two-dimensional array was used to keep track of the placement of each tic-tac-toe piece. This array functions like a grid made up of rows and columns. When the array is declared, its dimensions are set to match all valid coordinate positions on the game board. At the start of every new game, the entire array is filled with zeros to represent an empty board.
Whenever a player places a piece on the screen, the program stores that move in the array using the same x and y coordinates, assigning a value greater than zero. Player 1 is represented by the value 1, and Player 2 by 2. These stored values serve two purposes: they record that a move has been made at that location and identify which player made it.
With this setup, the program can easily check whether a position is already taken by examining whether the array cell contains a 1 or 2. If so, the spot is considered occupied, preventing either player from placing a new piece on top of an existing one.
The easiest way to check the win condition was with an if statement checking all 8 possibilities of winning at every move. 
To record each player’s score, two variables, P1 & P2 were created and initialized to zero at the start of the program. Player 1’s score is displayed in the top-left corner of the game screen, while Player 2’s score appears in the top-right corner. Whenever a player wins a round, their corresponding score variable is incremented by one. In the case of a tie, neither value changes. Because these variables are stored globally, the scores persist for the entire duration of the program and only reset when the board’s physical reset button is pressed.


Figure 9: Tic Tac Toe logic plus co-ordinates for each value.


Figure 10: Display of Tic tac toe being played.


Figure 11: Winning screen after the game has ended.


Figure 12: Demonstration of Player 1 having score from last game.

### Chess puzzle

The game revolves around a famous knight puzzle, where you have to reach every square on the board using a knight, without landing on the same square more than one time. This game requires the board to have more than 5 squares. Having 5 squares would be too space consuming given our limitation of only 10 rows, without leaving space for drawing the grid. 
A 3x3 grid was then implemented, with the knight starting at the top left, and having visited every square except the central within 7 moves. The game was made harder by the knight not marking the squares that have already been visited, as the 3x3 grid did not issue much of a challenge on its own.
The puzzle follows the same coordinate system as tic tac toe. 

The logic of the game follows functions being named for every side and corner coordinate. Each of these functions follow an if else block that allows only the legal knight moves to be moved. The blocks are checked by temporary x and y values, compared with the if else block for legality, and updated with the main x and y values if the move is executed. Since each non center square has only 2 given legal moves at any given point, it prints an error message at every other square. 
If moved, the square is marked as moved, and the control is passed back to the main loop to check for which square is next selected by the user. On completion of 7 moves, the game ends, and if all non center squares are marked as moved, the puzzle is completed.


Figure 13: A very rough design of the game logic.


Figure 14: Start of the knight game without the grid drawing.


Figure 15: Invalid move being displayed.


Figure 16: Completion of chess puzzle.

# Conclusion

The Media Center was also an excellent opportunity to explore just how customizable the LPC1700 development boards can be. It highlighted the creative side of software development by showing how much functionality can be expanded beyond what is provided in the starter files. Discovering the many sections of the course code that could be extended or modified helped build intuition about how existing systems work and how to make the most out of the tools and templates given.
