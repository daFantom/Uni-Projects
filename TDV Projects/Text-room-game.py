"""
This project was made by Emanuel Baciu.
Do not repost without permission.
"""

# Here go the imports.

import arcade

# End of imports

# Classes go here.
class Room:
    def __init__(self, description:str="",north=0,south=0,east=0,west=0):
        self.description = description
        self.north = north
        self.south = south
        self.east = east
        self.west = west
# End of Classes.

# Function definition.
def main():
    room_list = []
    room1 = Room("You encounter yourself at the Hallway. You have 1 passage to the north and south, 1 to the east and 1 to the west.",7,4,2,5) # Hallway has 5 rooms it can enter.
    room_list.append(room1)
    room2 = Room("You're in the Bathroom, best to take a shower sooner than later! You have 2 entrances, south and east.",None,3,1,None) # Bathroom would be at the top left side of the map.
    room_list.append(room2)
    room3 = Room("Welcome to the Master Bedroom, best you don't do dirty things. You have 2 exits, north and east.",2,None,1,None) # Master bedroom would be below the Bathroom.
    room_list.append(room3)
    room4 = Room("You happen to enter the Storage Room... However nothing is there, too bad! You have only one exit, east.",None,None,1,None) # Storage room only accessible from the Hallway.
    room_list.append(room4)
    room5 = Room("Your chef instincts rush you to the Kitchen, what will you prepare today? You can exit from the south or west",None,1,None,6) # Kitchen will be on the top right side of the map.
    room_list.append(room5)
    room6 = Room("You enter the Dining room, there's nothing but a table. What are the devs on about? You have 2 exits, north and west.",1,None,None,1) # Dining Room will have access from Hallway and Kitchen.
    room_list.append(room6)
    room7 = Room("The fresh air from the Balcony takes you back to your grandpa's house, good times eh? You can only exit from the south.",None,1,None,None) # Balcony only has access from the Hallway.
    room_list.append(room7)
    current_room = 0
    done = False
    while not done:
        print(room_list[current_room].description)
        print("\n")
        next_step =input("What is your next move?")
        if(next_step.lower())=="north":
            next_room = room_list[current_room].north
            if None == next_room:
                print("You cannot go that way, you don't have NoClip dummy!")
            else:
                current_room = next_room


# End of functions.

# Variables go here.

# End of variables.

# Main program
main()



