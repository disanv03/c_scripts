/* In the game of cribbage you have 5 cards with rank numbers between 1 and 13. Here you must output the number of pairs of equal ranked cards.
 * 11557 => 2 pairs
 * */

#include <stdio.h>

int countPairs(int cards) {
    int ranks[14] = {0}; // Array to count occurrences of each rank (1-13), ignoring index 0
    int pairs = 0;

    // Count occurrences of each rank
    while (cards > 0) {
        int rank = cards % 10; // Get the last digit (rank)
        ranks[rank]++;
        cards /= 10; // Remove the last digit
    }

    // Count pairs for each rank
    for (int i = 1; i <= 13; i++) {
        pairs += ranks[i] / 2; 
    }

    return pairs;
}

int main() {
    int cards;

    printf("Enter a 5-digit number representing card ranks: ");
    scanf("%d", &cards);

    printf("Number of pairs: %d\n", countPairs(cards));

    return 0;
}
