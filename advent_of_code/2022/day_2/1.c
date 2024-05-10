/* Day 2: Rock Paper Scissors */
/* Solution by antirez */

#include <stdio.h>
#include <stdlib.h>

/* given a game with me using shape 'me' and the opponent using
 * shape 'opp' (both 'A', 'B' or 'C') return the total score. */
int game_score(int me, int opp) {
    /* 0 = rock, 1 = paper, 2 = scissor. */
    int m = me-'A';
    int o = opp-'A';

    /* each entry represents the outcome of the game */
    int scoremap[3][3] = {
        {1+3, 1+0, 1+6},
        {2+6, 2+3, 2+0},
        {3+0, 3+6, 3+3}
    };

    return scoremap[m][o];
}

int main(void) {
    char buf[64];

    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("opening input file");
        exit(1);
    }

    long score = 0;
    while(fgets(buf,sizeof(buf),fp) != NULL) {
        int opp = buf[0];
        int me = buf[2]-'X' + 'A';
        score += game_score(me, opp);
    }
    fclose(fp);
    printf("%ld\n", score);
    return 0;
}
