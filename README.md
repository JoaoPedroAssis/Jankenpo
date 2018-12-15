# Jankenpo
Repository destined to contain and distribute versions of the game Jankenpo. Probably, this code will not be further updated, but if we feel like adding some features, it will be done.

This project is inspired on the classical _Rock, Paper, Scisors_ game, that we all know and love. It's original name is Jokenpo, but we changed it just a bit so that it can fit an inside joke.

## Developers

* João Pedro Assis
* Pedro Augusto Duarte
* Waliff Cordeiro
* Ariel Batista
* Guilherme Lodron

This game is part of the final project of the "Methods of Programming" discipline and was developed by students of the University of Brasília (UnB) - Brazil.

## Dependencies

This game depends on a series of libraries to compile. In every commit we will provide a compiled version of the game (compiled in linux) so that some people can run it just afeter cloning the repository. If you want to make some changes, install the following packages :

* SDL
* SDL_image
* SDL_ttf
* SDL_mixer

## Compiling and Running Instructions

After installing the dependencies, go to the main directory and type *make*. It will create and executable file called **Jankenpo**. If you navigate to the source folder, it will have another Makefile. In this project we used the Test Driven Development, and the tests are still here. You can run *make* again and then run the **tests** file. If you wish to clean your work, just type *make clean* inside the directories mentioned above.

## Game Instructions

This is a very easy game to play, but it is important to understand the following statements:

* Your Goal is to attack and destroy the enemy Castle (the red one).
* Your resources (money, gravel, cellulose and metal) will appear in the top left corner, and the CPU's on the top right. The icons should be self explanatory.
* Each type of construction has a cost in resourses, money or both.
* The HeadQuarters are used to deploy your units and the Factorys are used to collect resources.
* Each building can only perform actions related to it's type. The type is specifyed on the icons.
* To purchase a construction, click on the icon placed in the bottom left corner. Then, select a position **within the 2 first left columns** to place it.
* Each Factory generates a fixed ammount of resources over time. You can increase this number by clicking in the icon on the bottom right corner and then clicking on the Factory that you want to upgrade.
* You can also upgrade the HeadQuartes, but the maximum level is 3 (you can only upgrade it 2 times)
* To place your units, click on the HeadQuarters that will deploy it and then click on the position in the field that you wish the unit to start. **You can only deploy units in your half of the field (between the second and the seventh column).**
* Each HeadQuarters will only deploy a unit that match it's type.
* Good Luck

## Extra comments

* This game was developed in Portuguese, so most of the code is in this language. We think the code is simple enough so that y'all can understand it. If you don't like it, i think google translator will do the work for you.