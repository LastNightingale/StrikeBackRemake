#pragma once
#include <sfml/Graphics.hpp>
#include <vector>
#include <unordered_map>

struct RenderList
{
	std::vector<sf::RectangleShape> Rects;
};

class GameObject
{
public:
	virtual void Update(float dt) {};
	virtual void AddToRenderList(RenderList& list) = 0;
	virtual bool Collision(GameObject* other) { return false; }
	virtual sf::FloatRect GetGlobalBounds() { return sf::FloatRect(); }
};

enum Colors
{
	YELLOW = 0,
	PURPLE = 1,
	GREEN = 2,
	WHITE = 3,
	CRIMSON = 4
};

static std::unordered_map< sf::Keyboard::Key, Colors> KeyBinds = {
	{sf::Keyboard::Key::Num1, YELLOW},
	{sf::Keyboard::Key::Num2, PURPLE},
	{sf::Keyboard::Key::Num3, GREEN},
	{sf::Keyboard::Key::Num4, WHITE},
	{sf::Keyboard::Key::Num5, CRIMSON}
};

static std::unordered_map< Colors, sf::Color> ColorBinds = {
	{YELLOW, {255, 255, 0}},
	{PURPLE, {75,0,130} },
	{GREEN, {34,139,34} },
	{WHITE, {255,218,185} },
	{CRIMSON, {128,0,0} }
};