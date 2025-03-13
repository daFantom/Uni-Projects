# Library imports
import arcade
import random

# Constant Variables
SPRITE_SCALING_PLAYER = 2
SPRITE_SCALING_HEART = 1.5
SPRITE_SCALING_ANCHOR = 1.5
SPRITE_SCALING_WALL = 2
HEART_COUNT = 20
ANCHOR_COUNT = HEART_COUNT+random.randint(0,10)
MOVSPEED = 3
# Screen constants
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600


# ----- Classes -----
# Player class
class Player(arcade.Sprite):
    def __init__(self,filename,sprite_scaling):
        super().__init__(filename,sprite_scaling)
        self.change_x = 0
        self.change_y = 0
    def on_update(self):
        self.center_x +=self.change_x
        self.center_y +=self.change_y
# Check if it hits screen border
        if self.left < 5:
            self.center_x = 5
        elif self.center_x > SCREEN_WIDTH-5:
            self.center_x = SCREEN_WIDTH-5
        if self.center_y < 5:
            self.center_y = 5
        elif self.center_y > SCREEN_HEIGHT-5:
            self.center_y = SCREEN_HEIGHT-5
# Anchor Class
class Anchor(arcade.Sprite):
    def __init__(self,filename,sprite_scaling):
        super().__init__(filename,sprite_scaling)
        self.change_x=0
        self.change_Y=0
    def update(self):
# Move the anchor
        self.center_x += self.change_x
        self.center_y += self.change_y


# If out of bounds, rebound
        if self.left<5:
            self.change_x *=-1
        if self.right>SCREEN_WIDTH-5:
            self.change_x*=-1
        if self.bottom<5:
            self.change_y*=-1
        if self.top>SCREEN_HEIGHT-5:
            self.change_y*=-1

# Heart class
class Heart(arcade.Sprite):
    def __init__(self,filename,sprite_scaling):
        super().__init__(filename,sprite_scaling)
        self.change_x = 0
        self.change_y = 0
        self.center_x = 70
        self.center_y = 70

    def update(self):
        # Move the heart
        self.center_x += self.change_x
        self.center_y += self.change_y


        # If we're out-of-bounds, then 'bounce'
        if self.left<0:
            self.change_x *=-1
        if self.right>SCREEN_WIDTH:
            self.change_x*=-1
        if self.bottom<0:
            self.change_y*=-1
        if self.top>SCREEN_HEIGHT:
            self.change_y*=-1



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
        self.anchor_list = None
        self.wall_list = None
# Player info
        self.player_sprite = None
        self.physics_engine = None
        self.score = 0
# Setting bg color.
        arcade.set_background_color(arcade.color.BLACK)
# Changing the position of the sprite
        self.change_x = 0
        self.change_y = 0
# Hiding mouse
        self.set_mouse_visible(False)

    def setup(self):
        """Set up the game and initialize the variables."""

#Sprite lists
        self.player_list = arcade.SpriteList()
        self.heart_list = arcade.SpriteList()
        self.anchor_list = arcade.SpriteList()
        self.wall_list = arcade.SpriteList()

# Score
        self.score = 0


# --- Set up the player
# Character image from kenney.nl
        self.player_sprite = Player("Sprites Folder/kenney1-spritespack1/Tiles/Transparent/tile_0241.png", SPRITE_SCALING_PLAYER)
        self.player_list.append(self.player_sprite)
# --- Set up the walls
        for x in range(0,80,16):
            wall = arcade.Sprite("Sprites Folder/kenney1-spritespack1/Tiles/Transparent/tile_0009.png", SPRITE_SCALING_WALL)

            wall.center_x = x
            wall.center_y = 200
            self.wall_list.append(wall)

        for y in range(0,80,16):
            wall = arcade.Sprite("Sprites Folder/kenney1-spritespack1/Tiles/Transparent/tile_0009.png",SPRITE_SCALING_WALL)

            wall.center_x = 465
            wall.center_y = y
            self.wall_list.append(wall)

        self.physics_engine = arcade.PhysicsEngineSimple(self.player_sprite,self.wall_list)
# Randomize pos of hearts
        for i in range(HEART_COUNT):
# Create a Heart instance
# Heart image from Kenney.nl
            heart = Heart("Sprites Folder/kenney1-spritespack1/Tiles/Transparent/tile_0041.png",SPRITE_SCALING_HEART)

# Position of the hearts
            heart.center_x = random.randrange(SCREEN_WIDTH-10)
            heart.center_y = random.randrange(SCREEN_HEIGHT-10)
            heart.change_x = random.randrange(-3,4)
            heart.change_y = random.randrange(-3,4)
# Add hearts to the lists
            self.heart_list.append(heart)
# --- Set up the anchors
# Randomize pos for Anchors
        for j in range(ANCHOR_COUNT):
# Create an Anchor instance
# Anchor image from Kenney.nl
            anchor = Anchor("Sprites Folder/kenney1-spritespack1/Tiles/Transparent/tile_0006.png", SPRITE_SCALING_ANCHOR)
# Pos for the anchors
            anchor.center_x = random.randrange(SCREEN_WIDTH-10)
            anchor.center_y = random.randrange(SCREEN_HEIGHT-10)
            anchor.change_x = random.randrange(-2,3)
            anchor.change_y = random.randrange(-2,3)
# Add the anchor to its list.
            self.anchor_list.append(anchor)



# on_draw function
    def on_draw(self):
# This command must be done before drawing
        self.clear()

# Draw all the sprites
        self.heart_list.draw()
        self.player_list.draw()
        self.anchor_list.draw()
        self.wall_list.draw()
# Draw the score
        output = f"Score: {self.score}"
        arcade.draw_text(output,10,20,arcade.color.WHITE,14)


# on_key_press and on_key_release functions to move the sprite with WASD.
    def on_key_press(self, key, modifiers: int):
        if key == arcade.key.W:
            self.player_sprite.change_y = MOVSPEED
        elif key == arcade.key.S:
            self.player_sprite.change_y = -MOVSPEED
        elif key == arcade.key.A:
            self.player_sprite.change_x = -MOVSPEED
        elif key == arcade.key.D:
            self.player_sprite.change_x = MOVSPEED
    def on_key_release(self, key, modifiers: int):
        if key == arcade.key.W or key == arcade.key.S:
            self.player_sprite.change_y = 0
        elif key == arcade.key.A or arcade.key.D:
            self.player_sprite.change_x = 0


# on_update function.
    def on_update(self, delta_time):
        """Movement and game logic"""

        # Call update on all heart and anchor sprites(The sprites don't do much in our example though
        self.heart_list.update()
        # Generate a list of all heart sprites that collided with the player
        hearts_hit_list = arcade.check_for_collision_with_list(self.player_sprite,self.heart_list)

        # Loop through each colliding sprite, remove it, and add to the score.
        for heart in hearts_hit_list:
            heart.remove_from_sprite_lists()
            self.score+=1

# Generate a list of all anchor sprites that collided with the player.
        self.anchor_list.update()
        anchor_hit_list = arcade.check_for_collision_with_list(self.player_sprite,self.anchor_list)

        # Loop through each colliding sprite, remove it, and decrement the score
        for anchor in anchor_hit_list:
            anchor.remove_from_sprite_lists()
            self.score-=1
            
        self.physics_engine.update()

        if len(self.heart_list)==0:
            if self.score>=0:
                print(f"You won with {self.score} points!")
                arcade.exit()
            else:
                print("You lost!")
                arcade.exit()
# Functions

def main():
    """Main method."""
    window = MyGame()
    window.setup()
    arcade.run()

# Main program
main()