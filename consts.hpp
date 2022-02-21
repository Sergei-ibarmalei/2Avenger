#ifndef CONSTS_HPP
#define CONSTS_HPP

constexpr int S_W {800};
constexpr int S_H {600};

enum class Move_direction {UP, DOWN, LEFT, RIGHT, NONE};

constexpr int HERO_LIVES {3};

//enum class object_position {UP, CENTER, DOWN, EMPTY};
enum class hero_position {UP, CENTER, DOWN};
constexpr int SHIP_SPEED {5};
constexpr int UPSHIP {0};
constexpr int CENTERSHIP {1};
constexpr int DOWNSHIP {2};

constexpr int HERO_INTRO_PATH {300};

typedef struct 
{
    int x;
    int y;
}plot_type;

//DECKA

constexpr int DECKA_HEIGHT {100};

// BORDER
constexpr int LEFT_BORDER  {0};
constexpr int RIGHT_BORDER {S_W};
constexpr int UP_BORDER    {0};
constexpr int DOWN_BORDER  {S_H - DECKA_HEIGHT};

//DECKA

constexpr int SCORE_START_X {RIGHT_BORDER - 300};
constexpr int SCORE_START_Y {S_H - DECKA_HEIGHT + 18};
constexpr int MAX_SCORE {99'990};


//STAR
enum class Star_kind {FAST_STAR, SLOW_STAR};
constexpr int SLOW_STAR {5};
constexpr int FAST_STAR {5};
constexpr int SLOW_STAR_SPEED {1};
constexpr int FAST_STAR_SPEED {3};


//BULLET

//Напревление выстрела
enum class Bullet_direction {LEFT, RIGHT, COMPLEX, NONE};
constexpr int BULLET_SPEED {5};
constexpr int BULLET_START_X_SHIFT {3};
//HERO BULLET


//GAME_HISTORY_COUNT
 constexpr int GAME_HISTORY {3};
 enum class GAME_HISTORY_PART {FIRST, SECOND, THIRD, ALL};


 //TEXT
 constexpr int TEXT_PAUSE_HEIGHT {50};

#endif
