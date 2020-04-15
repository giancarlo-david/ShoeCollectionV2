# ShoeCollectionV2
 Upgraded Shoe Collection program written in C++
 
 A personal project I undertook that was inspired for my passion for shoes and my collection.
 The program keeps track of the users collection by holding the collection in a list and being able to save the collection via text tile
 
 ## Improvements from V1:
  * Made a class for shoe instead of holding the properties with three different arrays
  * Used vectors to hold the list as opposed to dynamic array to make importing, adding, and removing easier
  * More functionality since vectors are a lot easier to work with
  
 ## What I learned on this project
  * Learned how to work with vectors and be comfortable using the functionalities that they provide
  * Got more experience using a class as I was a bit confused with them before
  * Overall understand Object Oriented Programming a lot better now as I got to practice with it
  
 ## A look inside
 
### _Main Menu_
![Main Menu](https://github.com/giancarlo-david/ShoeCollectionV2/blob/master/Pictures/Main%20Menu.JPG)
 * Provides options for the user to either create a collection or import a previously saved collection
	
### _Creating a collection_
![Create Collection](https://github.com/giancarlo-david/ShoeCollectionV2/blob/master/Pictures/Create%20New%20Collection.JPG)
 * Prompts user for how many shoes they want to adding
 * Gets user input for brand, model, and colorway of the shoe
 * Prompts input verification prior to moving on to next shoe
 * Displays editing menu after user is finished adding shoes
	
### _Importing a collection_
![Import Collection](https://github.com/giancarlo-david/ShoeCollectionV2/blob/master/Pictures/Import%20Collection.JPG)
 * Asks user for the file name of the previously saved txt file
 * Displays the shoes that were saved within that txt file
	
### _Editing Menu_
![Editing Menu](https://github.com/giancarlo-david/ShoeCollectionV2/blob/master/Pictures/Editing%20Menu.JPG)
 * Displays user options after creating a collection or importing a collection
  ** Add shoe lets user add more shoes to the collection
  ** Remove shoe asks the user which shoe they want removed using the index and removes shoe based on selection
  ** Show collection displays current collection in alphabetical order
  ** Save Collection prompts user to name the txt file they want the collection saved under
  ** Exit, self explanatory
