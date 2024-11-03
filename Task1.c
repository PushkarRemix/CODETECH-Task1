#include <stdio.h>
#include <stdlib.h>

int askQuestion(const char *question, const char *option1, const char *option2, const char *option3, const char *option4, int correctAnswer);
void displayMenu();
void displayInstructions();
void displayScore(int score);

int main() {
    int choice;
    int score = 0;

    // Display the main menu
    do {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Start Quiz
                printf("\n*** Starting the Quiz! ***\n");
                
                // Question 1
                score += askQuestion(
                    "1. What is the capital of France?",
                    "1) London", "2) Paris", "3) Berlin", "4) Madrid",
                    2
                );

                // Question 2
                score += askQuestion(
                    "2. What is 5 + 3 * 2?",
                    "1) 11", "2) 13", "3) 16", "4) 10",
                    1
                );

                // Question 3
                score += askQuestion(
                    "3. Who wrote 'To be, or not to be'?",
                    "1) William Shakespeare", "2) Charles Dickens", "3) J.K. Rowling", "4) Mark Twain",
                    1
                );

                // Question 4
                score += askQuestion(
                    "4. What is the largest planet in our solar system?",
                    "1) Earth", "2) Mars", "3) Jupiter", "4) Saturn",
                    3
                );

                // Question 5
                score += askQuestion(
                    "5. What is the square root of 64?",
                    "1) 6", "2) 7", "3) 8", "4) 9",
                    3
                );

                // Display the final score
                displayScore(score);
                score = 0;  // Reset score for a new game
                break;

            case 2:
                // Show instructions
                displayInstructions();
                break;

            case 3:
                // Quit
                printf("\nThank you for playing! Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("\n=================================\n");
    printf("        Welcome to Quiz Game\n");
    printf("=================================\n");
    printf("1. Start Quiz\n");
    printf("2. Instructions\n");
    printf("3. Quit\n");
    printf("=================================\n");
}

// Function to display the instructions
void displayInstructions() {
    printf("\nInstructions:\n");
    printf("1. The quiz consists of 5 multiple-choice questions.\n");
    printf("2. For each question, type the number of the correct answer and press Enter.\n");
    printf("3. Each correct answer gives you 1 point.\n");
    printf("4. Your score and feedback will be displayed at the end.\n\n");
}

// Function to ask a question and return 1 if the answer is correct, otherwise 0
int askQuestion(const char *question, const char *option1, const char *option2, const char *option3, const char *option4, int correctAnswer) {
    int answer;
    printf("\n%s\n", question);
    printf("%s\n", option1);
    printf("%s\n", option2);
    printf("%s\n", option3);
    printf("%s\n", option4);
    printf("Your answer: ");
    scanf("%d", &answer);

    if (answer == correctAnswer) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect! The correct answer was %d.\n", correctAnswer);
        return 0;
    }
}

// Function to display the score and feedback
void displayScore(int score) {
    printf("\n=============================\n");
    printf("         Quiz Complete\n");
    printf("=============================\n");
    printf("Your total score: %d out of 5\n", score);

    if (score == 5) {
        printf("Outstanding! You got a perfect score!\n");
    } else if (score >= 3) {
        printf("Great job! You scored well.\n");
    } else if (score >= 1) {
        printf("You got some correct answers. Keep practicing!\n");
    } else {
        printf("Better luck next time. Give it another try!\n");
    }
    printf("=============================\n");
}
