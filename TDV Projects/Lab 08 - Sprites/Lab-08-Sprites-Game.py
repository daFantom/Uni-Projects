# Library imports
import arcade
import random

# Constant Variables
SPRITE_SCALING_PLAYER = 0.5
SPRITE_SCALING_HEART = 0.2
HEART_COUNT = 50
# Screen constants
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600


# ----- Classes -----


# Arcade Window Class
class MyGame(arcade.Window):
    """Custom window class."""

    def __init__(self):
        """Initializer (starts when object is summoned)"""
        # Call the parent class __init__:
        super().__init__(SCREEN_WIDTH,SCREEN_HEIGHT,"Sprite Example")

# Variables which will hold sprite lists.
        self.player_list = None
        self.heart_list = None
# Player info
        self.player_sprite = None
        self.score = 0
# Setting bg color.
        arcade.set_background_color(arcade.color.BLACK)
    def setup(self):
        """Set up the game and initialize the variables."""

#Sprite lists
        self.player_list = arcade.SpriteList()
        self.heart_list = arcade.SpriteList()

# Score
        self.score = 0

# Set up the player
# Character image from kenney.nl
        self.player_sprite = arcade.Sprite("Sprites Folder/kenney1-spritespack1/Tiles/Transparent/tile_0241.png")
        self.player_sprite.center_x = 50
        self.player_sprite.center_x = 50
        self.player_list.append(self.player_sprite)

        for i in range(HEART_COUNT):
# Create a Heart instance
# Heart image from Kenney.nl
            heart = arcade.Sprite("Sprites Folder/kenney1-spritespack1/Tiles/Transparent/tile_0041",SPRITE_SCALING_HEART)

# Position of the hearts
            heart.center_x = random.randrange(SCREEN_WIDTH)
            heart.center_y = random.randrange(SCREEN_HEIGHT)

# Add hearts to the lists
            self.heart_list.append(heart)
    def on_draw(self):
        self.clear()
# Draw the sprite lists here. Typically, sprites are divided into
# different groups. Other game engines might call these "sprite layers"
# or "sprite groups." Sprites that don't move should be drawn in their
# own group for the best performance, as Arcade can tell the graphics
# card to just redraw them at the same spot.
# Try to avoid drawing sprites on their own, and not in a layer.
# There are many performance improvements to drawing in a layer.
        self.coin_list.draw()
        self.player_list.draw()
    def on_key_press(self, key, modifiers: int):

    def on_key_release(self, key, modifiers: int):


# Functions

def main():
    """Main method."""
    window = MyGame()
    arcade.run()

    if __name__ == "__main__":
        main()