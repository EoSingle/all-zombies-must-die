#include "TextPop.hpp"

TextPop::TextPop(sf::Font &font, std::string txt, sf::Vector2f pos, sf::Color color, float duration)
{
    this->done = false;

    this->text.setFont(font);
    this->text.setString(txt);
    this->text.setCharacterSize(25);
    this->text.setFillColor(color);
    this->text.setPosition(pos);

    this->counter = 0.f;
    this->duration = duration;
}

TextPop::~TextPop()
{
}

sf::Text TextPop::getText() { return this->text; }

bool TextPop::isDone() { return this->done; }

void TextPop::update()
{
    float fadePercent = counter / duration;

    this->text.setFillColor(sf::Color(text.getFillColor().r, text.getFillColor().g, text.getFillColor().b, 255 - int(fadePercent * 255)));
    this->text.move(0.f, -0.4f);

    counter += 0.1f;
    if (counter >= duration)
    {
        done = true;
    }
}

void TextPop::render(sf::RenderTarget *target)
{
    target->draw(this->text);
}