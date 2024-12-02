#include "pch.h"
#include "MenuScene.h"

MenuScene::MenuScene(std::string id, Camera* c, World* w) : Scene(id, c, w)
{
    game = Game::getInstance("config/config.json");

    bg = new Image("bg", "images/bg.png", 0.0f, 0.0f);
    logo = new Image("logo", "images/logo.png", ((width - 918) / 2), ((height - 600) / 2));

    playBtn = new Button("play", "images/buttons.png", ((width - 134) / 2), ((height + 148) / 2), 1, 7);
    quitBtn = new Button("quit", "images/buttons.png", ((width - 134) / 2), ((height + 348) / 2), 1, 7);

    playBtn->addFrame("play", 0, 134, 48, 1, 7);
    quitBtn->addFrame("quit", 1, 134, 48, 1, 7);
}

void MenuScene::onEnter()
{
    addGameObject(bg, 0);
    addGameObject(logo, 1);
    addGameObject(playBtn, 2);
    addGameObject(quitBtn, 2);

    addEventListener(KeyboardEvent::KEYDOWN, this, &MenuScene::onKeyDown);
    addEventListener(Button::PRESSED, this, &MenuScene::onButtonPressed);

    displayButtons(true);
}

void MenuScene::onExit()
{
    removeAllGameObjects();
    removeEventListener(KeyboardEvent::KEYDOWN, this, &MenuScene::onKeyDown);
    removeEventListener(Button::PRESSED, this, &MenuScene::onButtonPressed);
}

void MenuScene::update(float delta)
{
    Scene::update(delta);
}

void MenuScene::render()
{
    Scene::render();
}

void MenuScene::onKeyDown(const KeyboardEvent& e)
{
    if (e.key.code == Key::Code::Q)
    {
        Game::stop();
    }
}

void MenuScene::onButtonPressed(const UserEvent& e)
{
    std::string* buttonType = static_cast<std::string*>(e.getData1());

    if (*buttonType == "play" && playBtn->isVisible())
    {
        LOG_INFO("PLAY Pressed");
        onExit();
        game->removeScene();
    }
    else if (*buttonType == "quit" && quitBtn->isVisible())
    {
        LOG_INFO("QUIT Pressed");
        Game::stop();
    }
}

void MenuScene::displayButtons(bool p)
{
    playBtn->setVisible(p);
}