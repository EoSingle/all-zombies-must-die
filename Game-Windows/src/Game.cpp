#include "Game.hpp"

/// @brief Private Functions
///
/// Initialize the game resources


void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "all zombies must die",
                                        sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initVariables()
{
    this->points = 0;
    this->pause = false;
    this->gameOverStatus = false;
}

void Game::initFonts()
{
    if (!this->font.loadFromFile("assets/Fonts/pixelart.ttf"))
    {
        throw("ERROR::GAME::INITFONTS::Could not load font");
    }
}

void Game::initTextures()
{
    this->textures["BULLET"] = new sf::Texture();
    this->textures["BULLET"]->loadFromFile("assets/Textures/bullet.png");
    this->textures["PISTOL"] = new sf::Texture();
    this->textures["PISTOL"]->loadFromFile("assets/Textures/Pistol.png");
    this->textures["P90"] = new sf::Texture();
    this->textures["P90"]->loadFromFile("assets/Textures/p90.png");
    this->textures["M4A1"] = new sf::Texture();
    this->textures["M4A1"]->loadFromFile("assets/Textures/m4a4.png");
    this->textures["AWP"] = new sf::Texture();
    this->textures["AWP"]->loadFromFile("assets/Textures/awp.png");
}

void Game::initGUI()
{
    this->hpText.setFont(this->font);
    this->hpText.setCharacterSize(12);
    this->hpText.setFillColor(sf::Color::White);
    this->hpText.setPosition(10.f, 570.f);
    this->hpText.setString("HP");

    this->playerHpBar.setPosition(5.f, 590.f);
    this->playerHpBar.setSize(sf::Vector2f(300.f, 5.f));
    this->playerHpBar.setFillColor(sf::Color::Red);
    this->playerHpBarBack.setPosition(3.f, 588.f);
    this->playerHpBarBack.setSize(sf::Vector2f(304.f, 9.f));
    this->playerHpBarBack.setFillColor(sf::Color::Black);

    this->pointsText.setFont(this->font);
    this->pointsText.setCharacterSize(20);
    this->pointsText.setFillColor(sf::Color::White);
    this->pointsText.setPosition(10.f, 10.f);
    this->pointsText.setString("");

    this->currentWave.setFont(this->font);
    this->currentWave.setCharacterSize(20);
    this->currentWave.setFillColor(sf::Color::Green);
    this->currentWave.setPosition(400.f, 10.f);
    this->currentWave.setString("");

    this->selectedGun.setFont(this->font);
    this->selectedGun.setCharacterSize(20);
    this->selectedGun.setFillColor(sf::Color::White);
    this->selectedGun.setPosition(500.f, 570.f);
    this->selectedGun.setString("");

    this->currentAmmo.setFont(this->font);
    this->currentAmmo.setCharacterSize(20);
    this->currentAmmo.setFillColor(sf::Color::White);
    this->currentAmmo.setPosition(700.f, 570.f);
    this->currentAmmo.setString("");
}

void Game::initWorld()
{
    if (!this->worldBackgroundTex.loadFromFile("assets/Textures/background.png"))
    {
        throw("ERROR::GAME::INITWORLD::Could not load background texture");
    }

    this->worldBackground.setTexture(this->worldBackgroundTex);
}

void Game::initPlayer()
{
    this->player = new Player();

    this->guns.push_back(new Gun("Glock", 27, 4, 3, 0.2f, 1.5f, 12.f, 5.f));
    this->guns.push_back(new Gun("Desert Eagle", 7, 8, 6, 0.2f, 3.f, 18.f, 5.f));
    this->guns.push_back(new Gun("Double Barrel", 2, 12, 2, 0.1f, 3.5f, 20.f, 5.f));
    this->guns.push_back(new Gun("P90", 50, 1, 3, 0.05f, .5f, 12.f, 6.f));
    this->guns.push_back(new Gun("M4A1", 25, 8, 3, 0.05f, 0.9f, 12.f, 6.f));
    this->guns.push_back(new Gun("AWP", 5, 10, 10, 0.1f, 5.f, 20.f, 7.f));
    this->player->setGun(guns[0]);

    this->gunSprite.setTexture(*this->textures["PISTOL"], true);
    this->gunSprite.setPosition(this->player->getPos());
    this->gunScale = 2.f;
    this->gunSprite.setScale(this->gunScale, this->gunScale);
}

void Game::initEnemies()
{
    this->spawner = new Spawner(*this->window, *this->player, this->enemies);
}

void Game::initGameMusic()
{
    this->inGameMusic.setFilePath("assets/Music/track1.ogg");
    this->inGameMusic.openFromFile(this->inGameMusic.getFilePath());
    this->inGameMusic.setLoop(true);
    this->inGameMusic.setVolume(50.f);
    this->inGameMusic.play();
}

void Game::initMainMenu()
{
    this->mainMenu = new Menu(*this->window);

    this->start = false;
    this->gameOverStatus = false;
}

void Game::initPauseMenu()
{
    this->pauseMenu = new PauseMenu(*this->window);
    this->pauseMenu->setFont(this->font);
}

void Game::initGameOverScreen()
{
    this->gameOverScreen = new GameOver(*this->window);
    this->gameOverScreen->setFont(this->font);
    this->gameOverScreen->setPoints(this->points);
}

void Game::returnToMainMenu()
{
    this->mainMenu->playMusic();
    this->inGameMusic.stop();
    this->start = false;
    this->pause = false;
    this->gameOverStatus = false;
    this->points = 0;
    delete this->player;
    this->enemies.clear();
    this->bullets.clear();
}



/// @brief Constructor
///
/// Start the game in the main manu.


Game::Game()
{
    this->initWindow();   /// Initialize the window
    this->initFonts();    /// Initialize the fonts
    this->initMainMenu(); /// Initialize the main menu
}


/// @brief  Destructor
///
/// Delete all the pointers.
Game::~Game()
{
    this->inGameMusic.stop();
    delete this->mainMenu;

    if (this->isStart())
    {
        delete this->pauseMenu;
        delete this->gameOverScreen;
        delete this->window;
        delete this->player;
        delete this->spawner;

        // Delete textures
        for (auto &i : this->textures)
        {
            delete i.second;
        }

        // Delete guns
        for (auto *gun : this->guns)
        {
            delete gun;
        }

        // Delete bullets
        for (auto *i : this->bullets)
        {
            delete i;
        }

        // Delete enemies
        for (auto *i : this->enemies)
        {
            delete i;
        }

        // Delete damage popups
        for (auto *dmgPop : this->dmgPops)
        {
            delete dmgPop;
        }

        for (auto *infoPop : this->infoPops)
        {
            delete infoPop;
        }
    }
}

/// @brief Start the game
void Game::startGame()
{
    this->start = true;
    this->mainMenu->stopMusic();
    this->initVariables();
    this->initTextures();
    this->initGUI();
    this->initWorld();
    this->initPlayer();
    this->initEnemies();
    this->initGameMusic();
    this->initPauseMenu();
}

/// @brief Inform the engine if the game is started or not.
/// @return true if the game is started
const bool Game::isStart() const
{
    return this->start;
}

/// @brief Inform the engine if the game is paused or not.
/// @return true if the game is paused
const bool Game::isPaused() const
{
    return this->pause;
}

/// @brief Pause the music if the game is paused.
void Game::pauseGame()
{
    this->pause = !this->pause;
    if (isPaused())
    {
        this->inGameMusic.pause();
    }
    else
    {
        this->inGameMusic.play();
    }
}

/// @brief Inform the engine if the game is over or not.
/// @return true if the game is over
const bool Game::isGameOver() const
{
    return this->gameOverStatus;
}

/// @brief Init the game over screen, turn the music volume to 5 and turn pause to false.
void Game::gameOver()
{
    initGameOverScreen();
    this->gameOverStatus = true;
    this->inGameMusic.setVolume(5.f);
    this->pause = false;
}

/// @brief Call render and update functions while the window is open.
void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

/// @brief Keyboard events.
void Game::updatePollEvents()
{
    sf::Event ev;
    while (this->window->pollEvent(ev))
    {
        /// Close window
        if (ev.type == sf::Event::Closed)
            this->window->close();
        /// Close window when escape key is pressed
        if ((!isStart()) && (ev.type == sf::Event::KeyPressed &&
                             ev.key.code == sf::Keyboard::Escape))
            this->window->close();
        /// Pause game
        if ((isStart()) && (!isGameOver()) && (ev.type == sf::Event::KeyPressed &&
                            ev.key.code == sf::Keyboard::Tab))
            pauseGame();
        /// Start game
        if (!isStart())
        {
            if (ev.type == sf::Event::KeyPressed &&
                ev.key.code == sf::Keyboard::Enter)
                startGame();
        }
        /// Pause Menu
        if (isPaused())
        {
            if (ev.type == sf::Event::KeyPressed &&
                ev.key.code == sf::Keyboard::Up)
                this->inGameMusic.setVolume(this->inGameMusic.getVolume() + 10.f);
            if (ev.type == sf::Event::KeyPressed &&
                ev.key.code == sf::Keyboard::Down)
                this->inGameMusic.setVolume(this->inGameMusic.getVolume() - 10.f);
            if (ev.type == sf::Event::KeyPressed &&
                ev.key.code == sf::Keyboard::Escape)
                returnToMainMenu();
        }
        /// Game over
        if (isGameOver())
        {
            if (ev.type == sf::Event::KeyPressed &&
                ev.key.code == sf::Keyboard::Escape)
                returnToMainMenu();
        }
    }
}

/// @brief Game keyboard events.
void Game::updateInput()
{
    /// Move player
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->player->move(-1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->player->move(1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->player->move(0.f, -1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->player->move(0.f, 1.f);
    }

    /// Reload
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        if (!this->player->getGun()->isReloading())
        {
            this->infoPops.push_back(new TextPop(this->font, "Reloading...", this->player->getPos(), sf::Color::Yellow, this->player->getGun()->getReloadTime()));
        }
        this->player->getGun()->reload();
    }

    /// Shoot
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->attack())
    {
        sf::Vector2f aimDir(mousePosView - this->player->getPos());
        this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos() + this->bulletOffset , aimDir, this->player->getDamage(), this->player->getGun()->getBulletSpeed()));
    }

    /// Switch Guns
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
    {
        if (this->player->getGun()->getName() != guns[0]->getName())
        {
            this->infoPops.push_back(new TextPop(this->font, this->guns[0]->getName(), this->player->getPos(), sf::Color::Black, guns[0]->getReloadTime()));
            player->setGun(guns[0]);
            player->getGun()->reload();
            this->gunSprite.setTexture(*this->textures["PISTOL"], true);
            this->gunScale = 2.f;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    {
        if (this->player->getGun()->getName() != guns[1]->getName())
        {
            this->infoPops.push_back(new TextPop(this->font, this->guns[1]->getName(), this->player->getPos(), sf::Color::Black, guns[1]->getReloadTime()));
            player->setGun(guns[1]);
            player->getGun()->reload();
            this->gunSprite.setTexture(*this->textures["PISTOL"], true);
            this->gunScale = 2.f;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
    {
        if (this->player->getGun()->getName() != guns[2]->getName())
        {
            this->infoPops.push_back(new TextPop(this->font, this->guns[2]->getName(), this->player->getPos(), sf::Color::Black, guns[2]->getReloadTime()));
            player->setGun(guns[2]);
            player->getGun()->reload();
            this->gunSprite.setTexture(*this->textures["AWP"], true);
            this->gunScale = 1.5f;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
    {
        if (this->player->getGun()->getName() != guns[3]->getName())
        {
            this->infoPops.push_back(new TextPop(this->font, this->guns[3]->getName(), this->player->getPos(), sf::Color::Black, guns[3]->getReloadTime()));
            player->setGun(guns[3]);
            player->getGun()->reload();
            this->gunSprite.setTexture(*this->textures["P90"], true);
            this->gunScale = 1.5f;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
    {
        if (this->player->getGun()->getName() != guns[4]->getName())
        {
            this->infoPops.push_back(new TextPop(this->font, this->guns[4]->getName(), this->player->getPos(), sf::Color::Black, guns[4]->getReloadTime()));
            player->setGun(guns[4]);
            player->getGun()->reload();
            this->gunSprite.setTexture(*this->textures["M4A1"], true);
            this->gunScale = 1.f;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
    {
        if (this->player->getGun()->getName() != guns[5]->getName())
        {
            this->infoPops.push_back(new TextPop(this->font, this->guns[5]->getName(), this->player->getPos(), sf::Color::Black, guns[5]->getReloadTime()));
            player->setGun(guns[5]);
            player->getGun()->reload();
            this->gunSprite.setTexture(*this->textures["AWP"], true);
            this->gunScale = 1.5f;
        }
    }
}

/// @brief Control gun sprite position on window.
void Game::updateGunSprite()
{
    sf::Vector2f aimDir(mousePosView - this->player->getPos());
    float norma = sqrt(aimDir.x * aimDir.x + aimDir.y * aimDir.y);
    aimDir.x /= norma;
    aimDir.y /= norma;
    float angle = (atan2(aimDir.x * -1.f, aimDir.y) * 180.f / 3.1415926) + 90.f;

    this->gunSprite.setRotation(angle);

    if (angle >= -90.f && angle <= 90.f)
    {
        gunOffset.x = 24.f;
        gunOffset.y = 30.f;
        bulletOffset.x = 30.f;
        bulletOffset.y = 10.f;
        gunSprite.setScale(this->gunScale, this->gunScale * -1.f);
        this->gunSprite.setPosition(player->getPos() + gunOffset);
        
    }
    else
    {
        gunOffset.x = 4.f;
        gunOffset.y = 30.f;
        bulletOffset.x = -20.f;
        bulletOffset.y = 10.f;
        gunSprite.setScale(this->gunScale, this->gunScale);
        this->gunSprite.setPosition(player->getPos() + gunOffset);
    }
}

/// @brief Window border collisions.
void Game::updateCollision()
{
    /// Left world collision
    if (this->player->getBounds().left < 0.f)
    {
        this->player->setPosition(0.f, this->player->getBounds().top);
    }
    /// Right world collision
    else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
    {
        this->player->setPosition(this->window->getSize().x -
                                      this->player->getBounds().width,
                                  this->player->getBounds().top);
    }
    /// Top world collision
    if (this->player->getBounds().top < 0.f)
    {
        this->player->setPosition(this->player->getBounds().left, 0.f);
    }
    /// Bottom world collision
    else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
    {
        this->player->setPosition(this->player->getBounds().left,
                                  this->window->getSize().y - this->player->getBounds().height);
    }
}

/// @brief Update the mouse position.
void Game::updateMousePositions()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

/// @brief Update the bullets in the game.
void Game::updateBullets()
{
    for (unsigned int i = 0; i < bullets.size(); i++)
    {
        bullets[i]->update();

        // Check if bullets are out of bounds
        if (bullets[i]->getBounds().top > window->getSize().y || bullets[i]->getBounds().top < -20 || bullets[i]->getBounds().left > window->getSize().x || bullets[i]->getBounds().left < -20)
        {
            delete this->bullets[i];
            this->bullets.erase(bullets.begin() + i);
        }
    }
}

/// @brief Update the enemies.
void Game::updateEnemies()
{
    /// Spawn enemies
    this->spawner->update();

    /// Update enemies
    for (unsigned int i = 0; i < this->enemies.size(); ++i)
    {
        enemies[i]->update();

        /// Bullet culling (top of screen)
        if (enemies[i]->getBounds().top > window->getSize().y + 20 || enemies[i]->getBounds().top < -20 || enemies[i]->getBounds().left > window->getSize().x + 20 || enemies[i]->getBounds().left < -20)
        {
            // Delete enemy
            delete enemies[i];
            this->enemies.erase(this->enemies.begin() + i);
            i--;
        }
        /// Enemy player collision
        else if (enemies[i]->getBounds().intersects(this->player->getBounds()))
        {
            this->player->getHealth()->loseHp(enemies[i]->getDamage());
            this->dmgPops.push_back(new TextPop(this->font, std::to_string(enemies[i]->getDamage()), this->enemies[i]->getPos(), sf::Color::Red, 4.f));

            delete enemies[i];
            this->enemies.erase(this->enemies.begin() + i);
            i--;
        }
    }
}

/// @brief Update the combat.
void Game::updateCombat()
{
    for (unsigned int i = 0; i < this->enemies.size(); ++i)
    {
        bool enemy_deleted = false;
        for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
        {
            if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
            {
                /// Determine damage, deal damage and make pop up damage text
                int damageDealt = this->bullets[k]->getDamage();
                this->enemies[i]->getHealth()->loseHp(damageDealt);
                this->dmgPops.push_back(new TextPop(this->font, std::to_string(damageDealt), this->enemies[i]->getPos(), sf::Color::White, 3.f));

                /// Check for enemy kill
                if (!enemies[i]->getHealth()->isAlive())
                {
                    this->points += enemies[i]->getPoints();

                    delete this->enemies[i];
                    this->enemies.erase(this->enemies.begin() + i);

                    enemy_deleted = true;
                }

                /// Bullet Impact
                if (this->player->getGun()->getName() != "AWP")
                {
                    delete this->bullets[k];
                    this->bullets.erase(this->bullets.begin() + k);
                }
                else
                {
                    bullets[k]->wallBang();
                }
            }
        }
    }
}

/// @brief Update the GUI.
void Game::updateGUI()
{
    /// Health bar
    this->playerHpBar.setSize(sf::Vector2f(
        static_cast<float>(this->player->getHealth()->getHp()) / this->player->getHealth()->getHpMax() * 300.f,
        this->playerHpBar.getSize().y));

    /// Points text
    std::stringstream ss;
    ss << "Points " << this->points;
    this->pointsText.setString(ss.str());

    /// Wave text
    this->currentWave.setString(std::to_string(this->spawner->waveNumber()));

    /// Weapon HUD
    this->selectedGun.setString(this->player->getGun()->getName());
    this->currentAmmo.setString(std::to_string(this->player->getGun()->getAmmo()) + " de " + std::to_string(this->player->getGun()->getMaxAmmo()));

    /// Damage pop ups
    for (unsigned int i = 0; i < dmgPops.size(); i++)
    {
        dmgPops[i]->update();

        if (dmgPops[i]->isDone())
        {
            delete this->dmgPops[i];
            this->dmgPops.erase(dmgPops.begin() + i);
            i--;
        }
    }

    /// Info pop ups
    for (unsigned int i = 0; i < infoPops.size(); i++)
    {
        infoPops[i]->update();

        if (infoPops[i]->isDone())
        {
            delete this->infoPops[i];
            this->infoPops.erase(infoPops.begin() + i);
            i--;
        }
    }
}

/// @brief Update the game.
void Game::update()
{
    this->updatePollEvents();

    if (isStart() && !isGameOver())
    {
        if (!isPaused())
        {

            this->updateInput();

            this->updateMousePositions();

            this->player->update();

            this->updateGunSprite();

            this->updateCollision();

            this->updateBullets();

            this->updateEnemies();

            this->updateCombat();

            this->updateGUI();

            if (!this->player->getHealth()->isAlive())
            {
                this->gameOver();
            }
        }
    }
}

/// @brief Render the background.
void Game::renderWorld()
{
    this->window->draw(this->worldBackground);
}

/// @brief Render the GUI.
void Game::renderGUI()
{
    this->window->draw(this->playerHpBarBack);
    this->window->draw(this->playerHpBar);
    this->window->draw(this->hpText);
    this->window->draw(this->pointsText);
    this->window->draw(this->currentWave);
    this->window->draw(this->currentAmmo);
    this->window->draw(this->selectedGun);

    for (auto *dmgPop : this->dmgPops)
    {
        dmgPop->render(this->window);
    }

    for (auto *infoPop : this->infoPops)
    {
        infoPop->render(this->window);
    }
}

/// @brief Render the menu.
void Game::renderMenu()
{
    this->mainMenu->render(this->window);
}

/// @brief Render the pause menu.
void Game::renderPauseMenu()
{
    this->pauseMenu->render(this->window, (int)this->inGameMusic.getVolume());
}

/// @brief Render the game over menu.
void Game::renderGameOverScreen()
{
    gameOverScreen->render(this->window);
}

/// @brief Render the game.
void Game::render()
{

    this->window->clear();

    if (!isStart())
    {
        this->renderMenu();
    }
    else
    {

        this->renderWorld();

        this->player->render(*this->window);
        this->window->draw(gunSprite);

        for (auto *bullet : this->bullets)
        {
            bullet->render(this->window);
        }

        for (auto *enemy : this->enemies)
        {
            enemy->render(this->window);
        }

        for (auto *enemy : this->enemies)
        {
            enemy->render(this->window);
        }

        this->renderGUI();

        if (this->isPaused())
        {
            this->renderPauseMenu();
        }

        if (this->isGameOver())
        {
            this->renderGameOverScreen();
        }
    }
    this->window->display();
}