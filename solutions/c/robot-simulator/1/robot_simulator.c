#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
    robot_status_t new;
    new.direction = direction;
    new.position.x = x;
    new.position.y = y;
    return new;
}

void robot_move(robot_status_t *robot, const char *commands) {
    if(!commands) return;
    robot_position_t info[4] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    while(*commands) {
        if(*commands == 'R') {
            robot->direction = (robot->direction < 3) 
                                ? robot->direction + 1 
                                : 0;
        } else if(*commands == 'L') {
            robot->direction = (robot->direction > 0)
                                ? robot->direction - 1
                                : 3;
        } else if(*commands == 'A') {
            robot->position.x += info[robot->direction].x;
            robot->position.y += info[robot->direction].y;
        } 
        commands++;
    }
}
    