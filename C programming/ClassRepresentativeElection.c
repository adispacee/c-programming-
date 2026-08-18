#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50

// Function to display results recursively
void displayResults(char **names, int *votes, int n, int index)
{
    if (index > n)
        return;

    printf("%s : %d votes\n", names[index], votes[index]);

    displayResults(names, votes, n, index + 1);
}

// Function to find the winner
int findWinner(int *votes, int n)
{
    int winner = 1;

    for (int i = 2; i <= n; i++)
    {
        if (votes[i] > votes[winner])
            winner = i;
    }

    return winner;
}

int main()
{
    int students, candidates;
    int choice;

    // Input number of students
    printf("Enter number of students (voters): ");
    scanf("%d", &students);

    // Input number of candidates
    printf("Enter number of candidates: ");
    scanf("%d", &candidates);

    /*
       votes[0] is reserved for foul votes.
       Therefore, we need candidates + 1 integers.
    */
    int *votes = (int *)calloc(candidates + 1, sizeof(int));

    if (votes == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    /*
       Dynamically allocate array of strings.
       Each candidate gets MAX_NAME characters.
    */
    char **names = (char **)calloc(candidates + 1, sizeof(char *));

    if (names == NULL)
    {
        printf("Memory allocation failed!\n");
        free(votes);
        return 1;
    }

    // Allocate memory for each candidate name
    for (int i = 1; i <= candidates; i++)
    {
        names[i] = (char *)calloc(MAX_NAME, sizeof(char));

        if (names[i] == NULL)
        {
            printf("Memory allocation failed!\n");

            for (int j = 1; j < i; j++)
                free(names[j]);

            free(names);
            free(votes);

            return 1;
        }
    }

    // Input candidate names
    printf("\nEnter candidate names:\n");

    for (int i = 1; i <= candidates; i++)
    {
        printf("Candidate %d: ", i);
        scanf(" %49[^\n]", names[i]);
    }

    // Faculty initiates voting
    printf("\n----------------------------------\n");
    printf("Faculty: Press 1 to start voting: ");
    scanf("%d", &choice);

    if (choice != 1)
    {
        printf("Voting process not started.\n");

        for (int i = 1; i <= candidates; i++)
            free(names[i]);

        free(names);
        free(votes);

        return 0;
    }

    printf("\n========== VOTING STARTED ==========\n");

    // Voting process
    for (int i = 1; i <= students; i++)
    {
        printf("\nStudent %d, enter candidate number (1-%d): ",
               i, candidates);

        scanf("%d", &choice);

        if (choice >= 1 && choice <= candidates)
        {
            votes[choice]++;
            printf("Vote recorded successfully! *Beep*\n");
        }
        else
        {
            votes[0]++;
            printf("Invalid candidate! Foul vote recorded. *Beep*\n");
        }
    }

    // Display results
    printf("\n\n========== ELECTION RESULTS ==========\n");

    displayResults(names, votes, candidates, 1);

    printf("\nFoul votes : %d\n", votes[0]);

    // Find winner
    int winner = findWinner(votes, candidates);

    printf("\nWinner: %s\n", names[winner]);
    printf("Votes received: %d\n", votes[winner]);

    // Free allocated memory
    for (int i = 1; i <= candidates; i++)
    {
        free(names[i]);
    }

    free(names);
    free(votes);

    return 0;
}
