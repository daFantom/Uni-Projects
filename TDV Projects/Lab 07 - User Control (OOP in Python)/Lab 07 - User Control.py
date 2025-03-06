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
SCREEN_WIDTH = 900
SCREEN_HEIGHT = 600

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
        self.YTBLoadScreen = YTBLoadingScreen()
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



# Youtube Loading Screen Class



class YTBLoadingScreen:
    def __init__(self, pos_x:int=SCREEN_WIDTH/2, pos_y:int=SCREEN_HEIGHT/2):
        # Message shown after creating the object.
        print("Say hello to the ominous Youtube loading screen!")
        # Variables
        self.pos_x = pos_x
        self.pos_y = pos_y

# Function that creates the bg from the YouTube video reproducer.
    def draw_ytb_bg(self):
        arcade.draw_rectangle_filled(self.pos_x, self.pos_y, 550, 350, color=arcade.color.DARK_BLUE_GRAY)
        arcade.draw_rectangle_filled(self.pos_x,self.pos_y, 500, 300, color=arcade.color.BLACK)
        arcade.draw_rectangle_filled(self.pos_x, self.pos_y-100, 500, 10, color=arcade.color.GRAY)
        arcade.draw_circle_filled(self.pos_x-230, self.pos_y-100, 10, color=arcade.color.RED)



# Function that makes the loading semicircle from YouTube video reproducer.
    def draw_loading_arc(self):
        arcade.draw_arc_outline(self.pos_x, self.pos_y, 100, 100, border_width=10, color=arcade.color.GRAY, start_angle=45,end_angle=198, tilt_angle=57)




# --- Function definitions ---
def main():
    window = MyGame(900,600,"Drawing Example")
    arcade.run()


# Main program.
main()