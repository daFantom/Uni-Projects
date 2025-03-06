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
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600

# Class definitions.
class MyGame(arcade.Window):
    """ Custom Window Class"""
    def __init__(self):
        """Initializer"""
        # Calling the parent class(arcade.Window class) __init__
        super().__init__(SCREEN_WIDTH, SCREEN_HEIGHT,"Lab 7 - User Control")

    # On draw function