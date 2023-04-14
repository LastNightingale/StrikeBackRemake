#pragma once
#include <sfml/Graphics.hpp>
#include <vector>
#include <unordered_map>

struct RenderList
{
	std::vector<sf::RectangleShape> Rects;
};

enum class Consequenses
{
	NO_CONSEQUENCE = 0,
	GET_HIT = 1,
	WRONG_COLOR = 2
};

struct CollisionConsequence
{
	bool toDestroyObject;
	Consequenses typeConsequence;
};


class GameObject
{
public:
	virtual void Update(float dt) {};
	virtual void AddToRenderList(RenderList& list) = 0;
	virtual CollisionConsequence Collision(GameObject* other) { return { false, Consequenses::NO_CONSEQUENCE }; }
	virtual sf::FloatRect GetGlobalBounds() { return sf::FloatRect(); }

	/*template <typename Type>
	bool IsA<Type>() const { return dynamic_cast<const Type*>(this); }*/
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