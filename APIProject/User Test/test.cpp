#include "pch.h"
#include "../APIProject/Vector2D.h"
#include "../APIProject/Vector2D.cpp"

//User Test

TEST(Vector, CheckNormalOfImpact)
{
	Vector2D<int> player(6, 4);
	Vector2D<int> enemy(7, 4);
	enemy -= player;
	enemy.Normalize();
	EXPECT_EQ(enemy.GetX(), 1);
	//Launch enemy to the right
}

TEST(Vector, CalculateDistance)
{
	Vector2D<int> human(7, 0);
	Vector2D<int> bird(0, 7);

	EXPECT_EQ(Distance(human, bird), 9);
	//IF(DISTANCE < 10)
	//{
		//Poop on human
	//}
}

