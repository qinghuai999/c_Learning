#include <stdio.h>
/*
 * File: Card.c
 * Author: Kiki Su
 * Created: 2026-01-28 12:15
 * Description: Learn how to define an ENUM
 */
 typedef enum  PictureCard {
     JACK = 'J',
     QUEEN = 'Q',
     KING = 'K',
     ACE = 'A'
 } PictureCard;

void print_card(PictureCard card) {
    switch (card) {
        case JACK:
            printf("You chose a JACK card\n");
            break;
        case QUEEN:
            printf("You chose a QUEEN card\n");
            break;
        case KING:
            printf("You chose a KING card\n");
            break;
        case ACE:
            printf("You chose a ACE card\n");
            break;
        default:
            printf("Unknown card\n");
    }

}

int main() {
    PictureCard c1 = JACK;
    PictureCard c2 = KING;
    PictureCard c3 = ACE;

    print_card(c1);
    print_card(c2);
    print_card(c3);
    return 0;
}

