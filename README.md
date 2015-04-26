# JONES_CSCI2270_FinalProject
Crossword Puzzle where user first decodes encrypted clues to the correct words in the puzzle

Project Summary
This program uses a 2-D array to store characters which spell out words. Depending on which crossword "theme" the user selects, a different text file will be pulled with the correct word, its position in the matrix, the clue for the word, and an 'a' or 'd' for across or down. This information is then sorted into a vector of objects with each object being a different word with all of its properties. The setPos() function takes the string of the first character's position in the matrix and converts it to actually be placed on the matrix. 




How to Run
Program first prompts user for which puzzle to solve. Once the user selects a crossword "theme", the program will display an empty crossword with the different questions that help the user reveal which word to guess. If the user is stuck after having tried multiple guesses, an option for a hint will appear where the user will then be able to correctly answer the question.




Dependencies
This program requires the inlcuded text file that holds the 'key' or all the information about the crossword puzzle. 




System Requirements
No system requirements


Group Members


Contributors


Open issues/bugs
Changing how the crossword is printed out, certain spacing is sometimes off.
