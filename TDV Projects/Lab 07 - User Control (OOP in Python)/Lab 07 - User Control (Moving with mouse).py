"""
This project was made by Emanuel Baciu.
Do not repost without permission.
"""

"""
Here we will be using the Arcade Window class.
"""

# Imports.
import arcade

# --- Constant Variables ---
SCREEN_WIDTH = 900 # Added at the start of the program
SCREEN_HEIGHT = 600 # Added at the start of the program
MOV_SPEED = 3 # Added at 13:31, 06/03/2025

# --- Variables ---

# --- Class definitions ---
   # Window Class
class MyGame(arcade.Window):
    """ Custom Window Class"""
    def __init__(self, width:int=SCREEN_WIDTH, height:int=SCREEN_HEIGHT, title:str="Test Window"):
        """Initializer"""
# Calling the parent class(arcade.Window class) __init__
        super().__init__(width, height, title)
# Instant creation of the YTBLoadingScreen object.
        self.YTBLoadScreen = YTBLoadingScreen(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 0, 0, 550, 350, 10)
# Make the mouse not visible.
        self.set_mouse_visible(False)
#Change in bg color
        arcade.set_background_color(arcade.color.DARK_GRAY)

# On draw function
    def on_draw(self):
        self.clear()
        self.YTBLoadScreen.draw_ytb_bg()
        self.YTBLoadScreen.draw_loading_arc()

# On mouse motion (Detects mouse movement) function
    def on_mouse_motion(self, x: int, y: int, dx: int, dy: int):
        """Used to call our objects while the mouse is move. In other words,
        changes the position of our object to where our mouse is placed.
        Happens approx. 60 times per second(60 fps)."""
        self.YTBLoadScreen.pos_x = x
        self.YTBLoadScreen.pos_y = y
# Detects if it hits the edge of the screen.
        if self.YTBLoadScreen.pos_x > SCREEN_WIDTH-(self.YTBLoadScreen.width/2):
            self.YTBLoadScreen.pos_x = SCREEN_WIDTH-(self.YTBLoadScreen.width/2)
        elif self.YTBLoadScreen.pos_x < (self.YTBLoadScreen.width/2):
            self.YTBLoadScreen.pos_x = (self.YTBLoadScreen.width/2)
        if self.YTBLoadScreen.pos_y > SCREEN_HEIGHT - (self.YTBLoadScreen.height/2):
            self.YTBLoadScreen.pos_y = SCREEN_HEIGHT - (self.YTBLoadScreen.height/2)
        elif self.YTBLoadScreen.pos_y < (self.YTBLoadScreen.height/2):
            self.YTBLoadScreen.pos_y =  (self.YTBLoadScreen.height/2)

# Youtube Loading Screen Class



class YTBLoadingScreen:
    def __init__(self, pos_x, pos_y, change_x, change_y, width, height, ball_radius):
        # Message shown after creating the object.
        print("Say hello to the ominous Youtube loading screen!")
        # Variables
        self.pos_x = pos_x
        self.pos_y = pos_y
        self.change_x = change_x
        self.change_y = change_y
        self.width = width
        self.height = height
        self.ball_radius = ball_radius


# Function that creates the bg from the YouTube video reproducer.
    def draw_ytb_bg(self):
        arcade.draw_rectangle_filled(self.pos_x, self.pos_y, self.width, self.height, color=arcade.color.DARK_BLUE_GRAY)
        arcade.draw_rectangle_filled(self.pos_x, self.pos_y, self.width - 50, self.height - 50,color=arcade.color.BLACK)
        arcade.draw_rectangle_filled(self.pos_x, self.pos_y - 100, self.width - 50, self.height - 340,color=arcade.color.GRAY)
        arcade.draw_circle_filled(self.pos_x - 150, self.pos_y - 100, self.ball_radius, color=arcade.color.RED)



# Function that makes the loading semicircle from YouTube video reproducer.
    def draw_loading_arc(self):
        arcade.draw_arc_outline(self.pos_x, self.pos_y, 100, 100, border_width=10, color=arcade.color.GRAY, start_angle=45,end_angle=198, tilt_angle=57)





# --- Function definitions ---
def main():
    window = MyGame(900,600,"La pantalla de shutú se mueve con el maldito ratón")
    arcade.run()


# Main program.
main()