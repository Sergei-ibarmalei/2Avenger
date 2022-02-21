#ifndef SCORE_HPP
#define SCORE_HPP

#include "Ltexture.hpp"
#include "mysdl.hpp"

using std::string;

const int SCORE_LENGTH {5};
enum class  digit_name  {TENTH, THOUS, HUNDR, TENS, ED, ALL};


class Score
{
    DeckTexture* dec_digit_text = nullptr;
    int score = 0;
    int text_size = 0;
    string digit_string;
    void all_score_to_null(mySDL& mysdl);
    string getStringFromInt(const int digit);
    void put_string_digit(mySDL& mysdl, const digit_name name);

    public:
    Score(mySDL& mysdl, int text_size_, const SDL_Color& col);
    ~Score();
    Score(const Score&) {}

    void make_text_of_score(mySDL& mysdl);
    void draw_score(const mySDL& mysdl);
    int& Score_() {return score;}
    void Increment_score(const int inc, mySDL& mysdl);


};



#endif