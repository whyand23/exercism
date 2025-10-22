#include "queen_attack.h"


attack_status_t can_attack(position_t queen_1, position_t queen_2) {

    if (queen_1.column == queen_2.column && queen_1.row == queen_2.row){
        return INVALID_POSITION;
    } 
    else if (queen_1.column > 7 || queen_1.row > 7|| queen_2.column > 7|| queen_2.row > 7){
        return INVALID_POSITION;
    }
          
    // on same row or cols scans
    if(queen_1.column == queen_2.column || queen_1.row == queen_2.row) {
        return CAN_ATTACK;
    } 

    // diagonal (wrong can only scan one block away)
    /*
    if(queen_2.column == queen_1.column + 1 && queen_2.row == queen_1.row + 1){
        return CAN_ATTACK;
    } else if(queen_2.column == queen_1.column - 1 &&  queen_2.row == queen_1.row - 1) {
        return CAN_ATTACK;
    } else if (queen_2.column == queen_1.column + 1 && queen_2.row == queen_1.row - 1) {
        return CAN_ATTACK;
    } else if(queen_2.column == queen_1.column - 1 &&  queen_2.row == queen_1.row + 1) {
        return CAN_ATTACK;
    } else {
        return 0;
    }
    */

    // diagonal scan
    for(int i = 1; i < 8; i++) {
        if(queen_2.column == queen_1.column + i && queen_2.row == queen_1.row + i){
        return CAN_ATTACK;
        } else if(queen_2.column == queen_1.column - i &&  queen_2.row == queen_1.row - i) {
            return CAN_ATTACK;
        } else if(queen_2.column == queen_1.column + i && queen_2.row == queen_1.row - i) {
            return CAN_ATTACK;
        } else if(queen_2.column == queen_1.column - i &&  queen_2.row == queen_1.row + i) {
            return CAN_ATTACK;
        } 
    }
    
     return 0;
    
}