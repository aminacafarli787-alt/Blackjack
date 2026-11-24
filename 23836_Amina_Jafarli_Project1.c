#include <stdio.h> 
#include <stdlib.h>   
#include <time.h>     


int draw_card(int card) {
        if (card == 11) {
            printf(" J\n");
            return 10;
        } else if (card == 12) {
            printf(" Q\n");
            return 10;
        } else if (card == 13) {
            printf(" K\n");
            return 10;
        } else if (card == 1) {
            printf(" A\n");
            return 1;
        } 
        printf(" %d\n", card);
        return card;
}

int random_card() {
    return rand() % 13 + 1;
}

int main() { 

    int player_total = 0;
    int dealer_total = 0;

    srand(time(NULL));
    printf("=== SIMPLIFIED BLACKJACK ===\n\nPLAYER TURN\n");
    printf("You draw:");
    
    int card = random_card();  
    player_total+=draw_card(card);
    printf("Your total: %d\n",player_total);
 
    while (player_total <= 21) {
        int i;
        printf("1. Hit\n2. Stand\nChoice: ");
        scanf("%d", &i);
 
        if (i == 1) {
            printf("\nYou draw:");
            int card = random_card();
            player_total+=draw_card(card);
            printf("Your total: %d\n",player_total);
        } else if (i == 2) {
                break;
        } else {
            printf("Invalid choice, try again\n");
        }
    }


    if (player_total>21) {
        printf("\nBUST! Your total is above 21.\nDealer wins!\n\n");
        printf("[The dealer does not take a turn.]\n");
    } else {
        printf("\nDEALER TURN\n");

        while (dealer_total < 17) {
            int card = random_card(); 
            printf("Dealer draws:");

            dealer_total+=draw_card(card);
            printf("Dealer total: %d\n", dealer_total);
        }
        if (dealer_total>21) {
            printf("\nDealer busts!\nYou win!\n");
        }
        else {
            printf("Dealer stands.\n\n");
            printf("Player total: %d\nDealer total: %d\n",player_total, dealer_total);
            
            if (player_total>dealer_total) {
                printf("You win!\n");
            } else if (player_total<dealer_total) {
                printf("You lose!\n");
            } else {
                printf("Draw!");
            }
        }
    }
}