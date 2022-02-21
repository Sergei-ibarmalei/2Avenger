#include "score.hpp"

Score::Score(mySDL& mysdl, int text_size_, const SDL_Color& col)
{
    text_size = text_size_;
    dec_digit_text = new DeckTexture[SCORE_LENGTH];
    int count = 0;
    auto ptr = &dec_digit_text[0];
    for (;;ptr++, count++)
    {
        if (ptr == &dec_digit_text[SCORE_LENGTH]) break;
        ptr->getKind() = Kind_of_texture::TEXT;
        ptr->Color() = col;
        ptr->SetRenderer(mysdl.gRenderer);
        ptr->loadMediaText(text_size);
        if (ptr->getFont()) ptr->loadFromFile("0");
        if (!ptr->get_Ltexture_status())
        {
            mysdl.all_init_ok = false;
            break;
        }  
        ptr->UpLeftCorner() = {SCORE_START_X + 100 + (count * (ptr->get_mTexture_w() + 5)), SCORE_START_Y};      
    }

}

void Score::draw_score(const mySDL& mysdl)
{
    auto ptr = &dec_digit_text[0];
    for (;;ptr++)
    {
        if (ptr == &dec_digit_text[SCORE_LENGTH]) break;
        ptr->render(ptr->UpLeftCorner().x, ptr->UpLeftCorner().y);
    }
    SDL_RenderPresent(mysdl.gRenderer);    
}

void Score::all_score_to_null(mySDL& mysdl)
{
    auto ptr = &dec_digit_text[0];
    for (;;ptr++)
    {
        if (ptr == &dec_digit_text[SCORE_LENGTH]) break;
        ptr->loadFromFile("0");
        if (!ptr->get_Ltexture_status())
        {
            mysdl.all_init_ok = false;
            std::cout << "\nCould not reset score to 0, abort.\n";
        }
    }   
}

void Score::Increment_score(const int inc, mySDL& mysdl)
{
    if (inc < 0) return;
    score += inc;
    if (score > MAX_SCORE)
    {
        score = 0;
        all_score_to_null(mysdl);
    }
}

void Score::make_text_of_score(mySDL& mysdl)
{
    bool tens          { (score >= 10) && (score < 100)};
    bool hundreds      { (score >= 100) && (score <= 990)};
    bool thouthand     { (score >= 1000) && (score <= 9'990)};
    bool ten_thouthand { (score >= 9'990) && (score <= 99'990)};

    int int_tens, int_hundreds, int_thouthand, int_ten_thouthand;
    int tmp_1, tmp_2, tmp_3;

    if (tens)
    {
        int_tens = score / 10;
        digit_string = getStringFromInt(int_tens);
        put_string_digit(mysdl, digit_name::TENS);
        return;
    }
    if (hundreds)
    {
        int_hundreds = score / 100;
        tmp_1 = score % 100;
        int_tens = tmp_1 / 10;
        digit_string = getStringFromInt(int_hundreds);
        put_string_digit(mysdl, digit_name::HUNDR);
        digit_string = getStringFromInt(int_tens);
        put_string_digit(mysdl, digit_name::TENS);
        return;
    }
    if (thouthand)
    {
        int_thouthand = score / 1000;
        tmp_1 = score % 1000;
        int_hundreds = tmp_1 / 100;
        tmp_2 = tmp_1 % 100;
        int_tens = tmp_2 / 10;
        digit_string = getStringFromInt(int_thouthand);
        put_string_digit(mysdl, digit_name::THOUS);
        digit_string = getStringFromInt(int_hundreds);
        put_string_digit(mysdl, digit_name::HUNDR);
        digit_string = getStringFromInt(int_tens);
        put_string_digit(mysdl, digit_name::TENS);
        return;
    }
    if (ten_thouthand)
    {
        int_ten_thouthand = score / 10'000;
        tmp_1 = score % 10'000;
        int_thouthand = tmp_1 / 1'000;
        tmp_2 = tmp_1 % 1000;
        int_hundreds = tmp_2 / 100;
        tmp_3 = tmp_2 % 100;
        int_tens = tmp_3 / 10;
        digit_string = getStringFromInt(int_ten_thouthand);
        put_string_digit(mysdl, digit_name::TENTH);
        digit_string = getStringFromInt(int_thouthand);
        put_string_digit(mysdl, digit_name::THOUS);
        digit_string = getStringFromInt(int_hundreds);
        put_string_digit(mysdl, digit_name::HUNDR);
        digit_string = getStringFromInt(int_tens);
        put_string_digit(mysdl, digit_name::TENS);
        return;         
    }


}

Score::~Score()
{
    delete[] dec_digit_text;
    dec_digit_text = nullptr;
}

string Score::getStringFromInt(const int digit)
{
    string tmp;
    switch (digit)
    {
        case 1: tmp = "1"; break;
        case 2: tmp = "2"; break;
        case 3: tmp = "3"; break;
        case 4: tmp = "4"; break;
        case 5: tmp = "5"; break;
        case 6: tmp = "6"; break;
        case 7: tmp = "7"; break;
        case 8: tmp = "8"; break;
        case 9: tmp = "9"; break;
        default: tmp = "0"; break;
    }
    return tmp;    
}

void Score::put_string_digit(mySDL& mysdl, const digit_name name)
{
    dec_digit_text[static_cast<int>(name)].loadFromFile(digit_string);
    if (!dec_digit_text[static_cast<int>(name)].get_Ltexture_status()) mysdl.all_init_ok = false;
}