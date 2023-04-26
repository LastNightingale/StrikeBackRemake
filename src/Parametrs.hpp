#pragma once
#include <sfml/Graphics.hpp>

struct GameParametrs
{
	static constexpr float ScreenHeight = 950.f;
	static constexpr float ScreenWidth = 1400.f;
	static constexpr float HitPoints = 100.f;
	static constexpr float Hit = 10.f;
	static constexpr int ColorAmount = 5;
	static constexpr int Unmovables = 6;
};

struct PlayerParametrs
{
	static constexpr float PlayerSpeed = 500.f;
	static constexpr float PlayerSize = 75.f;
	static constexpr float PlayerPositionX = 280.f;
	static constexpr float PlayerPositionY = 450.f;
};

struct EnemyParametrs
{
	static constexpr float EnemySpeed = -400.f;
	static constexpr float EnemySize = 75.f;
};

struct BulletParametrs
{
	static constexpr float BulletSpeed = 1000.f;
	static constexpr float BulletSize = 10.f;
};

struct BackStrikeParametrs
{
	static constexpr float BackStrikeSpeed = 500.f;
	static constexpr float BackStrikeSize = 40.f;
};

struct WallParametrs
{
	static constexpr float WallSizeX = 75.f;
	static constexpr float WallSizeY = 10.f;
	static constexpr float TopWallPositionY = 100.f;
	static constexpr float BotWallPositionY = 900.f;
	static constexpr float WallPositionX = 242.5;
};

struct SpawnerParametrs
{
	static constexpr float SpawnerSizeX = 10.f;
	static constexpr float SpawnerSizeY = 762.5;
	static constexpr float SpawnerPositionX = 1400.f;
	static constexpr float SpawnerPositionY = 137.5;
};

struct DestroyerParametrs
{
	static constexpr float DestroyerSizeX = 10.f;
	static constexpr float DestroyerSizeY = 800.f;
	static constexpr float DestroyerPositionX = 307.5;
	static constexpr float DestroyerPositionY = 100.f;
};

struct BlockParametrs
{
	static constexpr float InnerBlockSize = 50.f;
	static constexpr float OuterBlockSize = 100.f;	
	static constexpr int OuterBlockThickness = 3;	
	static constexpr float BlockZonePositionX = 140.f;
	static constexpr float BlockZonePositionY = 50.f;
	static constexpr float BlockZoneSizeY = 900.f;
	static constexpr float BlockZoneGap = 50.f;
};

struct BarParametrs
{
	static constexpr int BarOutlineThickness = 3;
	static constexpr float HealthBarSizeX = 400.f;
	static constexpr float HealthBarSizeY = 50.f;
	static constexpr float HealthBarPositionX = 200.f;
	static constexpr float HealthBarPositionY = 10.f;
	static constexpr float HealthBarSegmentSizeX = 20.f;
	static constexpr float HealthBarMaxNumber = 20.f;
};