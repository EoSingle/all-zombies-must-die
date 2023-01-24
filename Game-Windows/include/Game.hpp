#pragma once

#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Spawner.hpp"
#include "TextPop.hpp"
#include "MusicPlayer.hpp"
#include "Menu.hpp"
#include "PauseMenu.hpp"
#include "GameOver.hpp"

/// @brief Game class
///
/// This class is like a game engine, it's responsible for the game logic
class Game
{
private:
    // Window
    sf::RenderWindow *window;

    // Music Player
    MusicPlayer inGameMusic;

    // Mouse positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    // Resources
    std::map<std::string, sf::Texture *> textures;
    std::vector<Bullet *> bullets;
    int points;

    // World
    sf::Texture worldBackgroundTex;
    sf::Sprite worldBackground;

    // Player
    Player *player;
    std::vector<Gun *> guns;
    sf::Sprite gunSprite;
    float gunScale;
    sf::Vector2f gunOffset;
    sf::Vector2f bulletOffset;

    // Player GUI
    sf::Font font;
    sf::Text hpText;
    sf::Text pointsText;
    sf::Text currentWave;
    sf::Text selectedGun;
    sf::Text currentAmmo;

    std::vector<TextPop *> dmgPops;
    std::vector<TextPop *> infoPops;

    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;

    // Enemies
    Spawner *spawner;
    std::vector<Enemy *> enemies;

    // Main menu
    Menu *mainMenu;
    bool start;

    // Pause menu
    bool pause;
    PauseMenu *pauseMenu;

    // Game over
    GameOver *gameOverScreen;
    bool gameOverStatus;

    // Private functions
    void initWindow();
    void initVariables();
    void initFonts();
    void initTextures();
    void initGUI();
    void initWorld();
    void initPlayer();
    void initEnemies();
    void initGameMusic();
    void initMainMenu();
    void initPauseMenu();
    void initGameOverScreen();

    sf::Vector2f GetEnemySpawn();
    void returnToMainMenu();

    void setGunSprite(std::string filePath);

public:
    // Constructor / Destructor
    Game();
    ~Game();

    // Main Menu
    void startGame();
    const bool isStart() const;

    // Pause game
    void pauseGame();
    const bool isPaused() const;

    // Game over
    void gameOver();
    const bool isGameOver() const;

    // Functions
    void run();

    void updatePollEvents();
    void updateInput();
    void updateMousePositions();
    void updateGunSprite();
    void updateCollision();
    void updateBullets();
    void updateEnemies();
    void updateCombat();
    void updateGUI();
    void update();
    void renderWorld();
    void renderGUI();
    void renderMenu();
    void renderPauseMenu();
    void renderGameOverScreen();
    void render();
};
