"""
This project was made by Emanuel Baciu.
Do not repost without permission.
"""

# Here go the imports.

import arcade

# End of imports

# Classes go here.
class Room:
    def __init__(self, description:str,north:int,south:int,east:int,west:int):
        self.description = description
        self.north = north
        self.south = south
        self.east = east
        self.west = west
# End of Classes.

# Function definition.
def main():
    room_list = []
    room1 = Room("You encounter yourself at the Hallway. You have 1 passage to the north, 2 to the east and 2 to the west.",1,0,2,2) # Hallway has 5 rooms it can enter.
    room_list.append(room1)
    room2 = Room("You're in the Bathroom, best to take a shower sooner than later! You have 2 entrances, south and east.",0,1,1,0) # Bathroom would be at the top left side of the map.
    room_list.append(room2)
    room3 = Room("Welcome to the Master Bedroom, best you don't do dirty things. You have 2 exits, north and east.",1,0,1,0) # Master bedroom would be below the Bathroom.
    room_list.append(room3)
    room4 = Room("You happen to enter the Storage Room... However nothing is there, too bad! You have only one exit, east.",0,0,1,0) # Storage room only accessible from the Hallway.
    room_list.append(room4)
    room5 = Room("Your chef instincts rush you to the Kitchen, what will you prepare today? You can exit from the south or west",0,1,0,1) # Kitchen will be on the top right side of the map.
    room_list.append(room5)
    room6 = Room("You enter the Dining room, there's nothing but a table. What are the devs on about? You have 2 exits, north and west.",1,0,0,1) # Dining Room will have access from Hallway and Kitchen.
    room_list.append(room6)
    room7 = Room("The fresh air from the Balcony takes you back to your grandpa's house, good times eh? You can only exit from the south.",0,1,0,0) # Balcony only has access from the Hallway.
    room_list.append(room7)
    current_room = 0
    print(room_list[current_room].description)

# End of functions.

# Variables go here.

# End of variables.

# Main program
main()



