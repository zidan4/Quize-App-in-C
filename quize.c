

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 5

// Structure to hold a question
typedef struct {
    char question[256];
    char options[4][100];
    char correctOption;
} Question;

void displayQuestion(Question q, int questionNumber) {
    printf("Question %d: %s\n", questionNumber, q.question);
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, q.options[i]);
    }
}

int main() {
    // Array of questions
    Question questions[MAX_QUESTIONS] = {
        {
            "What is the capital of France?",
            {"Berlin", "Madrid", "Paris", "Rome"},
            'C'
        },
        {
            "Which planet is known as the Red Planet?",
            {"Earth", "Mars", "Jupiter", "Venus"},
            'B'
        },
        {
            "Who wrote 'Hamlet'?",
            {"Charles Dickens", "William Shakespeare", "Mark Twain", "Jane Austen"},
            'B'
        },
        {
            "What is the largest ocean on Earth?",
            {"Atlantic Ocean", "Indian Ocean", "Pacific Ocean", "Arctic Ocean"},
            'C'
        },
        {
            "Which element has the chemical symbol 'O'?",
            {"Oxygen", "Gold", "Silver", "Helium"},
            'A'
        }
    };

    int score = 0;
    char userAnswer;

    printf("Welcome to the Quiz App!\n\n");

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        displayQuestion(questions[i], i + 1);

        printf("Enter your answer (A, B, C, D): ");
        scanf(" %c", &userAnswer);

        if (toupper(userAnswer) == questions[i].correctOption) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer was %c.\n\n", questions[i].correctOption);
        }
    }

    printf("Quiz over! You scored %d out of %d.\n", score, MAX_QUESTIONS);

    return 0;
}
