**Name:** PUSHKAR KUMAR
**Company:** CODETECH IT SOLUTIONS
**ID:** CT08DS9647
**Domain:** C Programming
**Duration:** Oct to Nov 2024
**Mentor:** 





## Grand Adventure Quiz Game
## Overview
The Grand Adventure Quiz Game is a fun, interactive console-based quiz game for up to five players. Players journey through three themed stages—Mystery Island, Science Station, and History Vault—where they answer questions to accumulate points. Players can also use power-ups to skip questions or double their points, and those who perform exceptionally well can qualify for a Final Bonus Round to earn extra points.

### Features
####Multiplayer: Supports up to 5 players.
####Multiple Stages: Players journey through three stages, each with unique questions:
#####Mystery Island - General knowledge questions.
#####Science Station - Science-related questions.
#####History Vault - History-themed questions.
####Power-Ups:
#####Skip Question: Allows a player to skip a question without penalty.
#####Double Points: Doubles the points awarded for the next correct answer.
####Final Bonus Round: Players with scores above 70 qualify for a bonus round with additional questions and opportunities to earn points.
####Dynamic Feedback: Players receive feedback after each answer, including the correct answer if they were incorrect, and their score updates throughout.

### How to Play
####Start the Game:
#####Run the game, and enter the number of players (1 to 5).
#####Each player will enter their name, which will be used throughout the game.
####Stages:
#####Each player answers questions in three stages. At the start of each question, players can choose to:
#####Answer the question.
Use a power-up.
View their current score.
Exit the game.
Power-Ups:

Players start with two power-ups:
Skip Question: Allows skipping a question without losing points.
Double Points: Doubles the score for the next correct answer.
Final Bonus Round:

Players with scores over 70 points qualify for a bonus round with extra questions to further boost their score.
End of Game:

After all stages (and the bonus round, if qualified), each player’s final score is displayed, along with feedback based on their performance.
Code Structure
main.c: Main file containing the game flow.
Player and Question Structs: Defines the player data (name, score, power-ups) and question data (question text, options, and answer).
Game Functions:
initializePlayer() - Initializes each player’s information and power-ups.
initializeQuestions() - Sets up questions for each stage based on the theme.
displayMainMenu() - Provides options for players during the game.
playStage() - Runs through each stage of the game for a player.
askQuestion() - Displays a question, validates answers, and updates scores.
usePowerUp() - Allows players to use a power-up.
finalBonusRound() - Special round for players who score above 70.
displayFinalScore() - Shows the player’s final score with feedback.
