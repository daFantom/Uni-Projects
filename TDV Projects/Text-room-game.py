"""
This project was made by Emanuel Baciu.
Do not repost without permission.
"""

# Here go the imports.

import arcade
import random
# End of imports

# Classes go here.
class Room:
    def __init__(self, description:str="",north=0 ,south=0 ,east=0 ,west=0):
        self.description = description
        self.north = north
        self.south = south
        self.east = east
        self.west = west

# End of Classes.

# Function definition.

def main():

# Room list.

    room_list = []

# Room Quotes

    hallway_quotes = ["Welcome to the Hallway.....! Yeah, that's it. You can go anywhere but south.","You encounter yourself at the Hallway. You have 1 passage for north, east and west, good luck!", "Hallway, can't go south."]
    bathroom_quotes = ["You're in the Bathroom, best to take a shower sooner than later! You have 2 entrances, south and east.","And here's the bathroom! Do you happen to play league? If so, take a shower, or you can go to the south or east.","bath go splash splash, you can go south or east."]
    mb_quotes = ["Who puts a Master Bedroom after a Bathroom? You can go south or come back north","Welcome to the Master Bedroom, best you don't do anything dirty. You have 2 exits, north and south.","You did your bed? Honestly, it surprises me. You can go north or south."]
    sr_quotes = ["You happen to enter the Storage Room... However nothing is there, too bad! You have only one exit, north.","What's the purpose of an empty Storage Room? Like, really! You can exit from the north","Storage room but you have nothing to store... Interesting, do you have other plans? You can exit from the north."]
    kitchen_quotes = ["Your chef instincts rush you to the Kitchen, what will you prepare today? You can exit from the south or west","*'Frolic' by Luciano Michelini starts playing in the background* You can go west or south.","Mamma Mia! Who touch-a la pizza!!! (You can go west or south)"]
    dr_quotes = ["You enter the Dining room, there's nothing but a table. What are the devs on about? You have 1 exit, north", "Did you forget your prop table? You can go north.","IS THAT A MF TABLE????? You can only go north."]
    balcony_quotes = ["The fresh air from the Balcony takes you back to your grandpa's house, good times eh? You can only exit from the south.","It seems to be raining, you better come back or else you'll catch a cold. You can only go south.","Today seems to be a sunny day, cool! You can only go south."]

# Room instances


    room1 = Room(hallway_quotes[random.randint(0,2)],6,None,4,1) # Hallway has 3 rooms it can enter. Room 0 in list
    room_list.append(room1)
    room2 = Room(bathroom_quotes[random.randint(0,2)],None,2,0,None) # Bathroom would be at the top left side of the map. Room 1 in list
    room_list.append(room2)
    room3 = Room(mb_quotes[random.randint(0,2)],1,3,None,None) # Master bedroom would be below the Bathroom. Room 2 in list
    room_list.append(room3)
    room4 = Room(sr_quotes[random.randint(0,2)],2,None,None,None) # Storage room only accessible from the Hallway. Room 3 in list
    room_list.append(room4)
    room5 = Room(kitchen_quotes[random.randint(0,2)],None,5,None,0) # Kitchen will be on the top right side of the map. Room 4 in list
    room_list.append(room5)
    room6 = Room(dr_quotes[random.randint(0,2)],4,None,None,None) # Dining Room will have access from Hallway and Kitchen. Room 5 in list
    room_list.append(room6)
    room7 = Room(balcony_quotes[random.randint(0,2)],None,0,None,None) # Balcony only has access from the Hallway. Room 6 in list
    room_list.append(room7)

# Current room and whether the player is done or not.

    current_room = 0
    done = False

# Main travel program.

    while not done:
        print(room_list[current_room].description)
        print(" ")
        next_step =input("What is your next move?\n")
# Case North:
        if(next_step.lower())=="north":
            next_room = room_list[current_room].north
            if None == next_room:
                print("You cannot go that way, you don't have NoClip dummy!")
            else:
                current_room = next_room

# Case South:
        elif(next_step.lower())=="south":
            next_room = room_list[current_room].south
            if None == next_room:
                print("You cannot go that way, you don't have NoClip dummy!")
            else:
                current_room = next_room

# Case East:
        elif(next_step.lower())=="east":
            next_room = room_list[current_room].east
            if None == next_room:
                print("You cannot go that way, you don't have NoClip dummy!")
            else:
                current_room = next_room

# Case West:
        elif(next_step.lower())=="west":
            next_room = room_list[current_room].west
            if None == next_room:
                print("You cannot go that way, you don't have NoClip dummy!")
            else:
                current_room = next_room
        else:
            print("Huh? What do you mean? Learn to write.")
# Command in order to quit the game or not.

        isdone = input("Will you continue?\n")
        decided = False
        while not decided:
            if isdone.lower() == "yes" or isdone.lower() == "y":
                done = False
                decided = True
            elif isdone.lower()=="no" or isdone.lower()=="n":
                assure = int(input("Will you move to another room(0) or exit the game(1)?"))
                if assure==0:
                    done = False
                    decided = True
                elif assure==1:
                    print("Well then, see you again someday, traveler!")
                    done = True
                    decided = True
            else:
                print("what")
                decided = False
# End of functions.

# Variables go here.

# End of variables.

# Main program
main()



