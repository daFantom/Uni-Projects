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
#Change in bg color
        arcade.set_background_color(arcade.color.DARK_GRAY)

# On draw function
    def on_draw(self):
        self.clear()
        self.YTBLoadScreen.draw_ytb_bg()
        self.YTBLoadScreen.draw_loading_arc()

# on_update function to update the objects who are inside this function at the same tine.
    def on_update(self, delta_time):
        self.YTBLoadScreen.on_update()


# on_key_press function (Detects when a key is pressed.)
    def on_key_press(self, key, modifiers):
        if key == arcade.key.A:
            self.YTBLoadScreen.change_x =  -MOV_SPEED
        elif key == arcade.key.D:
            self.YTBLoadScreen.change_x = MOV_SPEED
        elif key == arcade.key.W:
            self.YTBLoadScreen.change_y = MOV_SPEED
        elif key == arcade.key.S:
            self.YTBLoadScreen.change_y = -MOV_SPEED

# on_key_release function (Detects when a key is release)
    def on_key_release(self, key, modifiers: int):
        if key == arcade.key.A or key == arcade.key.D:
            self.YTBLoadScreen.change_x = 0
        elif key == arcade.key.W or key == arcade.key.S:
            self.YTBLoadScreen.change_y = 0



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
        arcade.draw_rectangle_filled(self.pos_x,self.pos_y, self.width-50, self.height-50, color=arcade.color.BLACK)
        arcade.draw_rectangle_filled(self.pos_x, self.pos_y-100, self.width-50, self.height-340, color=arcade.color.GRAY)
        arcade.draw_circle_filled(self.pos_x-150, self.pos_y-100, self.ball_radius, color=arcade.color.RED)



# Function that makes the loading semicircle from YouTube video reproducer.
    def draw_loading_arc(self):
        arcade.draw_arc_outline(self.pos_x, self.pos_y, 100, 100, border_width=10, color=arcade.color.GRAY, start_angle=45,end_angle=198, tilt_angle=57)


# on_update function(changes for every update event whenever it happens).

    def on_update(self):
# Move the object with WASD
        self.pos_x += self.change_x
        self.pos_y += self.change_y
# Check if it hits screen border
        if self.pos_x > SCREEN_WIDTH - (self.width/2):
            self.pos_x = SCREEN_WIDTH - (self.width/2)
        elif self.pos_x < self.width/2:
            self.pos_x = self.width/2
        if self.pos_y > SCREEN_HEIGHT - (self.height/2):
            self.pos_y = SCREEN_HEIGHT - (self.height/2)
        elif self.pos_y < self.height/2:
            self.pos_y = self.height/2


# Detects if it hits the edge of the screen.





# --- Function definitions ---
def main():
    window = MyGame(900,600,"La pantalla de shutú se mueve con el uvedoble a ese de")
    arcade.run()


# Main program.
main()