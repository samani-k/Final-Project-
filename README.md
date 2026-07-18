# Final-Project-

## Theme
### Mukbang City
The player begins as an aspiring mukbang content creator with limited resources and the help of their friend and manager, Mia. By exploring Mukbang City, creating content, upgrading equipment and restaurants, completing challenges, and competing against a rival creator, they must gain enough followers to earn a spot in the famous content creator house, "MukHouse", before applications close in 28 days.

## Goal
Gain 500,000 followers by the end of day 28 by navigating Mukbang City in order to apply for the MukHouse application. 

## How to compile and run
1. First paste:
g++ -Wall -Werror -Wpedantic Main.cpp Game.cpp Character.cpp Rival.cpp Food.cpp Item.cpp Player.cpp Restaurant.cpp -o Final-Project-.exe

2. Then paste
.\Final-Project-.exe

## How to play
Navigate the following tasks through the main menu display:
- Travel to different Restaurants
- Purchase Food Items 
- Create Content
- Unlock new foods and restaurants
- Upgrade Equipment
- Compete against rivals
- Buy from Shady Agency
- Pay Rent and Manager Fee

## Classes
1. Character — The general base class that stores a character’s name and role and provides a virtual talk() function.
2. Rival — A class derived from Character that represents competing mukbang creators with dialogue, skill levels, locations, and account status. Pulls from Rivals.txt in Game.cpp
3. Player — Stores and changes the player’s followers, money, Drama Points, actions, equipment, inventory, wins, and current location.
4. Restaurant — Represents each restaurant and stores its name, locked status, foods, competition day, and featured rival.
5. Food — Represents a food option with a price, follower unlock requirement, and content bonus.
6. Item — Represents inventory items such as equipment and competition badges using a name, type, and level.
7. Game — Controls the entire program, including menus, days, travel, content creation, stores, competitions, unlocks, expenses, and endings.

## Extra credit
Featured Mukbanger Rival System:  
Restaurants can only feature one creator at a time. The player can compete in a competition that occurs only once at every restaurant against the Featured Mukbanger for the badge title of "Featured Mukbanger". 

How to:
- Create a rival class 
- Every 5 days a competiton occurs
- 4 competitons, 1 competiton for each restaurant
- If player declines competiton or runs out of actions, the competition can not be replayed. 
- Badges help increase your competition score for future competitions.
- Last competition badge does not affect any variables.
- Competition score is based on followers, equipment, badges, and current drama points. 