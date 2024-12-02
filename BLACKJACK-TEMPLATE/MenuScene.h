#pragma once

#include "Game.h"
#include "Scene.h"
#include "GameConfiguration.h"
#include "KeyboardEvent.h"
#include "MouseEvent.h"
#include "UserEvent.h"
#include "Image.h"
#include "Button.h"
#include "LevelScene.h"

class MenuScene : public Scene
{
	public:
		MenuScene(std::string id, Camera* c, World* w);
		~MenuScene() = default;

		void update(float delta);
		void render();

		void onEnter();
		void onExit();

		void onKeyDown(const KeyboardEvent& e);

		void onButtonPressed(const UserEvent& e);

		void displayButtons(bool p);

	private:
		Game* game;

		Image* bg;
		Image* logo;

		Button* playBtn;
		Button* quitBtn;

		float width = 1224, height = 768;
};