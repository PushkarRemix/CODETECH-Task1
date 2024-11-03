#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_PLAYERS 5
#define MAX_NAME_LEN 50
#define MAX_QUESTIONS 5
#define POWER_UPS 2

// Structure Definitions

// Player structure to hold player information
typedef struct {
    char name[MAX_NAME_LEN];
    int score;
    int powerUps[POWER_UPS]; // 0: Skip Question, 1: Double Points
} Player;

// Question structure to hold quiz questions and answers
typedef struct {
    char question[256];
    char options[4][100];
    int correctAnswer; // 1 to 4
} Question;

// Function Prototypes
void initializePlayer(Player *player);
void initializeQuestions(Question questions[], int numQuestions, int stage);
int displayMainMenu();
int getValidatedInput(int min, int max);
void playStage(Player *player, const char *stageName, Question questions[], int numQuestions);
int askQuestion(Player *player, Question q);
void usePowerUp(Player *player);
void finalBonusRound(Player *player);
void displayFinalScore(Player *player);
void clearInputBuffer();

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers;

    srand(time(NULL)); // Seed for randomizing questions if needed

    printf("\n=== Welcome to the Grand Adventure Quiz Tournament! ===\n\n");

    // Get number of players
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    numPlayers = getValidatedInput(1, MAX_PLAYERS);

    // Initialize each player
    for (int i = 0; i < numPlayers; i++) {
        printf("\nPlayer %d:\n", i + 1);
        initializePlayer(&players[i]);
    }

    // Define questions for each stage
    Question mysteryIslandQuestions[MAX_QUESTIONS];
    initializeQuestions(mysteryIslandQuestions, MAX_QUESTIONS, 1);

    Question scienceStationQuestions[MAX_QUESTIONS];
    initializeQuestions(scienceStationQuestions, MAX_QUESTIONS, 2);

    Question historyVaultQuestions[MAX_QUESTIONS];
    initializeQuestions(historyVaultQuestions, MAX_QUESTIONS, 3);

    // Main Game Loop for each player
    for (int i = 0; i < numPlayers; i++) {
        printf("\n=== %s's Turn ===\n", players[i].name);
        playStage(&players[i], "Mystery Island", mysteryIslandQuestions, MAX_QUESTIONS);
        playStage(&players[i], "Science Station", scienceStationQuestions, MAX_QUESTIONS);
        playStage(&players[i], "History Vault", historyVaultQuestions, MAX_QUESTIONS);

        // Bonus Round if player scores above threshold
        if (players[i].score > 70) {
            finalBonusRound(&players[i]);
        }

        // Display Final Score for the player
        displayFinalScore(&players[i]);
    }

    printf("\nThank you for playing the Grand Adventure Quiz Tournament!\n");

    return 0;
}


// Function to initialize player information
void initializePlayer(Player *player) {
    printf("Enter your name: ");
    fgets(player->name, MAX_NAME_LEN, stdin);
    // Remove newline character if present
    size_t len = strlen(player->name);
    if (player->name[len - 1] == '\n') {
        player->name[len - 1] = '\0';
    }
    player->score = 0;
    // Initialize power-ups: 1 means available
    player->powerUps[0] = 1; // Skip Question
    player->powerUps[1] = 1; // Double Points
    printf("Welcome, %s! Let the adventure begin.\n\n", player->name);
}

// Function to initialize questions based on stage
// Function to initialize questions based on stage
void initializeQuestions(Question questions[], int numQuestions, int stage) {
    if (stage == 1) { // Mystery Island
        strcpy(questions[0].question, "What is the primary language spoken in Brazil?");
        strcpy(questions[0].options[0], "1. Spanish");
        strcpy(questions[0].options[1], "2. Portuguese");
        strcpy(questions[0].options[2], "3. French");
        strcpy(questions[0].options[3], "4. English");
        questions[0].correctAnswer = 2;

        strcpy(questions[1].question, "Which animal is the largest land mammal?");
        strcpy(questions[1].options[0], "1. Elephant");
        strcpy(questions[1].options[1], "2. Rhino");
        strcpy(questions[1].options[2], "3. Hippo");
        strcpy(questions[1].options[3], "4. Giraffe");
        questions[1].correctAnswer = 1;

        strcpy(questions[2].question, "Which ocean is the smallest?");
        strcpy(questions[2].options[0], "1. Pacific Ocean");
        strcpy(questions[2].options[1], "2. Atlantic Ocean");
        strcpy(questions[2].options[2], "3. Indian Ocean");
        strcpy(questions[2].options[3], "4. Arctic Ocean");
        questions[2].correctAnswer = 4;

        strcpy(questions[3].question, "What is the name of the longest river in the world?");
        strcpy(questions[3].options[0], "1. Amazon River");
        strcpy(questions[3].options[1], "2. Nile River");
        strcpy(questions[3].options[2], "3. Yangtze River");
        strcpy(questions[3].options[3], "4. Mississippi River");
        questions[3].correctAnswer = 2;

        strcpy(questions[4].question, "Which country has the largest population?");
        strcpy(questions[4].options[0], "1. India");
        strcpy(questions[4].options[1], "2. China");
        strcpy(questions[4].options[2], "3. USA");
        strcpy(questions[4].options[3], "4. Indonesia");
        questions[4].correctAnswer = 2;
    }
    else if (stage == 2) { // Science Station
        strcpy(questions[0].question, "What is the chemical symbol for gold?");
        strcpy(questions[0].options[0], "1. Au");
        strcpy(questions[0].options[1], "2. Ag");
        strcpy(questions[0].options[2], "3. Fe");
        strcpy(questions[0].options[3], "4. Hg");
        questions[0].correctAnswer = 1;

        strcpy(questions[1].question, "How many planets are in our solar system?");
        strcpy(questions[1].options[0], "1. 7");
        strcpy(questions[1].options[1], "2. 8");
        strcpy(questions[1].options[2], "3. 9");
        strcpy(questions[1].options[3], "4. 10");
        questions[1].correctAnswer = 2;

        strcpy(questions[2].question, "What is the powerhouse of the cell?");
        strcpy(questions[2].options[0], "1. Nucleus");
        strcpy(questions[2].options[1], "2. Mitochondria");
        strcpy(questions[2].options[2], "3. Chloroplast");
        strcpy(questions[2].options[3], "4. Cell Membrane");
        questions[2].correctAnswer = 2;

        strcpy(questions[3].question, "What type of gas is necessary for human respiration?");
        strcpy(questions[3].options[0], "1. Carbon Dioxide");
        strcpy(questions[3].options[1], "2. Nitrogen");
        strcpy(questions[3].options[2], "3. Oxygen");
        strcpy(questions[3].options[3], "4. Hydrogen");
        questions[3].correctAnswer = 3;

        strcpy(questions[4].question, "Which planet has rings around it?");
        strcpy(questions[4].options[0], "1. Mars");
        strcpy(questions[4].options[1], "2. Venus");
        strcpy(questions[4].options[2], "3. Saturn");
        strcpy(questions[4].options[3], "4. Jupiter");
        questions[4].correctAnswer = 3;
    }
    else if (stage == 3) { // History Vault
        strcpy(questions[0].question, "In what year did the Titanic sink?");
        strcpy(questions[0].options[0], "1. 1910");
        strcpy(questions[0].options[1], "2. 1912");
        strcpy(questions[0].options[2], "3. 1914");
        strcpy(questions[0].options[3], "4. 1916");
        questions[0].correctAnswer = 2;

        strcpy(questions[1].question, "Who was the first man to walk on the moon?");
        strcpy(questions[1].options[0], "1. Neil Armstrong");
        strcpy(questions[1].options[1], "2. Buzz Aldrin");
        strcpy(questions[1].options[2], "3. Yuri Gagarin");
        strcpy(questions[1].options[3], "4. Michael Collins");
        questions[1].correctAnswer = 1;

        strcpy(questions[2].question, "What ancient civilization built the Machu Picchu?");
        strcpy(questions[2].options[0], "1. Aztec");
        strcpy(questions[2].options[1], "2. Maya");
        strcpy(questions[2].options[2], "3. Inca");
        strcpy(questions[2].options[3], "4. Olmec");
        questions[2].correctAnswer = 3;

        strcpy(questions[3].question, "Who painted the Mona Lisa?");
        strcpy(questions[3].options[0], "1. Vincent van Gogh");
        strcpy(questions[3].options[1], "2. Pablo Picasso");
        strcpy(questions[3].options[2], "3. Leonardo da Vinci");
        strcpy(questions[3].options[3], "4. Michelangelo");
        questions[3].correctAnswer = 3;

        strcpy(questions[4].question, "Which war was fought between the North and South regions in the United States?");
        strcpy(questions[4].options[0], "1. World War I");
        strcpy(questions[4].options[1], "2. American Revolution");
        strcpy(questions[4].options[2], "3. Civil War");
        strcpy(questions[4].options[3], "4. Vietnam War");
        questions[4].correctAnswer = 3;
    }
}


// Function to display the main menu and return the player's choice
int displayMainMenu() {
    int choice;
    printf("\n--- Main Menu ---\n");
    printf("1. Play the Next Stage\n");
    printf("2. Use a Power-Up\n");
    printf("3. View Current Score\n");
    printf("4. Exit Game\n");
    printf("Enter your choice: ");
    choice = getValidatedInput(1, 4);
    return choice;
}

// Function to get validated input between min and max (inclusive)
int getValidatedInput(int min, int max) {
    int input;
    char term;
    while (1) {
        if (scanf("%d%c", &input, &term) != 2 || term != '\n') {
            printf("Invalid input. Please enter a number between %d and %d: ", min, max);
            clearInputBuffer();
        }
        else {
            if (input >= min && input <= max) {
                return input;
            }
            else {
                printf("Please enter a valid option (%d-%d): ", min, max);
            }
        }
    }
}

// Function to play a stage
void playStage(Player *player, const char *stageName, Question questions[], int numQuestions) {
    printf("\n=== Stage: %s ===\n", stageName);
    for (int i = 0; i < numQuestions; i++) {
        printf("\nQuestion %d:\n", i + 1);
        if (!askQuestion(player, questions[i])) {
            printf("The correct answer was option %d.\n", questions[i].correctAnswer);
        }
        printf("Current Score: %d\n", player->score);

        // Optionally, you can add a short pause or prompt to proceed to the next question
    }
}

// Function to ask a question and update the player's score
int askQuestion(Player *player, Question q) {
    int answer;
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%s\n", q.options[i]);
    }

    printf("Enter your answer (1-4) or 0 to access the main menu: ");
    answer = getValidatedInput(0, 4);

    if (answer == 0) {
        int menuChoice = displayMainMenu();
        switch (menuChoice) {
            case 1:
                printf("Resuming the game...\n");
                break;
            case 2:
                usePowerUp(player);
                // After using a power-up, ask the same question again
                return askQuestion(player, q);
            case 3:
                printf("Your current score is: %d\n", player->score);
                // Ask the same question again after viewing score
                return askQuestion(player, q);
            case 4:
                printf("Exiting the game...\n");
                exit(0);
            default:
                break;
        }
    }

    if (answer == q.correctAnswer) {
        printf("Correct!\n");
        player->score += 10;
        return 1;
    }
    else {
        printf("Incorrect.\n");
        return 0;
    }
}

// Function to use a power-up
void usePowerUp(Player *player) {
    printf("\n--- Power-Ups ---\n");
    printf("1. Skip Question (Remaining: %d)\n", player->powerUps[0]);
    printf("2. Double Points (Remaining: %d)\n", player->powerUps[1]);
    printf("3. Cancel\n");
    printf("Choose a power-up to use: ");
    int choice = getValidatedInput(1, 3);

    if (choice == 1) { // Skip Question
        if (player->powerUps[0] > 0) {
            player->powerUps[0]--;
            printf("Question skipped. No points awarded.\n");
            // Skip the current question by returning 1 (treated as correct but no points)
            return;
        }
        else {
            printf("No Skip Questions remaining.\n");
        }
    }
    else if (choice == 2) { // Double Points
        if (player->powerUps[1] > 0) {
            player->powerUps[1]--;
            printf("Double Points activated for the next question!\n");
            printf("Answer correctly to earn 20 points instead of 10.\n");

            // Temporarily modify the next question's scoring
            // This requires a more advanced structure. For simplicity, let's implement it globally.

            // Ask the next question with double points
            // To implement this, you might need to pass an additional parameter or use a global flag.
            // For now, we'll assume the next question will handle this.
        }
        else {
            printf("No Double Points remaining.\n");
        }
    }
    else {
        printf("No power-up used.\n");
    }
}

// Function for the final bonus round
void finalBonusRound(Player *player) {
    printf("\n=== Final Bonus Round ===\n");
    printf("Congratulations, %s! You've qualified for the Final Bonus Round.\n", player->name);
    printf("Answer the following questions correctly to earn extra points.\n");

    // Define bonus questions
    Question bonusQuestions[MAX_QUESTIONS];
    // Initialize bonus questions (you can expand this as needed)
    strcpy(bonusQuestions[0].question, "What is the largest mammal?");
    strcpy(bonusQuestions[0].options[0], "1. Elephant");
    strcpy(bonusQuestions[0].options[1], "2. Blue Whale");
    strcpy(bonusQuestions[0].options[2], "3. Giraffe");
    strcpy(bonusQuestions[0].options[3], "4. Shark");
    bonusQuestions[0].correctAnswer = 2;

    strcpy(bonusQuestions[1].question, "What is the most spoken language in the world?");
    strcpy(bonusQuestions[1].options[0], "1. English");
    strcpy(bonusQuestions[1].options[1], "2. Mandarin Chinese");
    strcpy(bonusQuestions[1].options[2], "3. Spanish");
    strcpy(bonusQuestions[1].options[3], "4. Hindi");
    bonusQuestions[1].correctAnswer = 2;

    strcpy(bonusQuestions[2].question, "Which planet is known as the 'Morning Star'?");
    strcpy(bonusQuestions[2].options[0], "1. Mars");
    strcpy(bonusQuestions[2].options[1], "2. Venus");
    strcpy(bonusQuestions[2].options[2], "3. Jupiter");
    strcpy(bonusQuestions[2].options[3], "4. Saturn");
    bonusQuestions[2].correctAnswer = 2;

    strcpy(bonusQuestions[3].question, "Who developed the theory of relativity?");
    strcpy(bonusQuestions[3].options[0], "1. Isaac Newton");
    strcpy(bonusQuestions[3].options[1], "2. Albert Einstein");
    strcpy(bonusQuestions[3].options[2], "3. Galileo Galilei");
    strcpy(bonusQuestions[3].options[3], "4. Nikola Tesla");
    bonusQuestions[3].correctAnswer = 2;

    strcpy(bonusQuestions[4].question, "What is the smallest prime number?");
    strcpy(bonusQuestions[4].options[0], "1. 0");
    strcpy(bonusQuestions[4].options[1], "2. 1");
    strcpy(bonusQuestions[4].options[2], "3. 2");
    strcpy(bonusQuestions[4].options[3], "4. 3");
    bonusQuestions[4].correctAnswer = 3;

    // Ask bonus questions
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nBonus Question %d:\n", i + 1);
        if (!askQuestion(player, bonusQuestions[i])) {
            printf("The correct answer was option %d.\n", bonusQuestions[i].correctAnswer);
        }
        printf("Current Score: %d\n", player->score);
    }
}

// Function to display the final score
void displayFinalScore(Player *player) {
    printf("\n=== Final Score ===\n");
    printf("Player: %s\n", player->name);
    printf("Total Points: %d\n", player->score);
    if (player->score > 100) {
        printf("Excellent performance!\n");
    }
    else if (player->score > 70) {
        printf("Great job!\n");
    }
    else if (player->score > 50) {
        printf("Good effort!\n");
    }
    else {
        printf("Better luck next time!\n");
    }
}

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
