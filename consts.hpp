#ifndef CONSTS_HPP
#define CONSTS_HPP

const int S_W {800};
const int S_H {600};

enum class Move_direction {UP, DOWN, LEFT, RIGHT, NONE};



//enum class object_position {UP, CENTER, DOWN, EMPTY};
enum class hero_position {UP, CENTER, DOWN};
const int SHIP_SPEED {5};
const int UPSHIP {0};
const int CENTERSHIP {1};
const int DOWNSHIP {2};

typedef struct 
{
    int x;
    int y;
}plot_type;


// BORDER
const int LEFT_BORDER  {0};
const int RIGHT_BORDER {S_W};
const int UP_BORDER    {0};
const int DOWN_BORDER  {S_H};

//STAR
enum class Star_kind {FAST_STAR, SLOW_STAR};
const int SLOW_STAR {5};
const int FAST_STAR {5};
const int SLOW_STAR_SPEED {1};
const int FAST_STAR_SPEED {3};


//BULLET

//Напревление выстрела
enum class Bullet_direction {LEFT, RIGHT, COMPLEX, NONE};
const int BULLET_SPEED {5};
const int BULLET_START_X_SHIFT {3};
//HERO BULLET
//enum class Hero_bullet_kind {BLUE_BULLET, RED_BULLET, GREEN_BULLET};


//GAME_HISTORY_COUNT
 const int GAME_HISTORY {3};
 enum class GAME_HISTORY_NAMES {FIRST, SECOND, THIRD, ALL};

#endif
