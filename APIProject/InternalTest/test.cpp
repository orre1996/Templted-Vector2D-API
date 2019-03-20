#include "pch.h"
#include <string>
#include "../APIProject/Vector2D.h"
#include "../APIProject/Vector2D.cpp"
#include "gtest/gtest.h"

using namespace ::testing;

// Internal test

TEST(Vector, Constructors)
{
	Vector2D<int> a(1, 5);
	EXPECT_EQ(a.GetX(), 1);
	EXPECT_EQ(a.GetY(), 5);

	Vector2D<int> b(-1, -5);
	EXPECT_EQ(b.GetX(), -1);
	EXPECT_EQ(b.GetY(), -5);

	Vector2D<float> c(1.0f, 5.0f);
	EXPECT_EQ(c.GetX(), 1.0f);
	EXPECT_EQ(c.GetY(), 5.0f);

	Vector2D<float> d(-1.0f, -5.0f);
	EXPECT_EQ(d.GetX(), -1.0f);
	EXPECT_EQ(d.GetY(), -5.0f);

	Vector2D<double> e(1.0, 5.0);
	EXPECT_EQ(e.GetX(), 1.0);
	EXPECT_EQ(e.GetY(), 5.0);

	Vector2D<double> f(-1.0, -5.0);
	EXPECT_EQ(f.GetX(), -1.0);
	EXPECT_EQ(f.GetY(), -5.0);

	Vector2D<long> g(1, 5);
	EXPECT_EQ(g.GetX(), 1);
	EXPECT_EQ(g.GetY(), 5);

	Vector2D<long> h(-1, -5);
	EXPECT_EQ(h.GetX(), -1);
	EXPECT_EQ(h.GetY(), -5);

}

TEST(Vector, Compare)
{
	Vector2D<int> a(1, 5);
	Vector2D<int> i(2, 6);
	EXPECT_TRUE(a.GetX() < i.GetX());
	EXPECT_TRUE(a.GetX() != i.GetX());
	EXPECT_TRUE(i.GetX() > a.GetX());
	i.Set(1, 5);
	EXPECT_TRUE(a.GetX() == i.GetX());

	Vector2D<int> b(-1, -5);
	Vector2D<int> j(-2, -6);
	EXPECT_TRUE(b.GetX() > j.GetX());
	EXPECT_TRUE(b.GetX() != j.GetX());
	EXPECT_TRUE(j.GetX() < b.GetX());
	j.Set(-1, -5);
	EXPECT_TRUE(b.GetX() == j.GetX());

	Vector2D<float> c(1.0f, 5.0f);
	Vector2D<float> k(2.0f, 6.0f);
	EXPECT_TRUE(c.GetX() < k.GetX());
	EXPECT_TRUE(c.GetX() != k.GetX());
	EXPECT_TRUE(k.GetX() > c.GetX());
	k.Set(1.0f, 5.0f);
	EXPECT_TRUE(c.GetX() == k.GetX());

	Vector2D<float> d(-1.0f, -5.0f);
	Vector2D<float> l(-2.0f, -6.0f);
	EXPECT_TRUE(d.GetX() > l.GetX());
	EXPECT_TRUE(d.GetX() != l.GetX());
	EXPECT_TRUE(l.GetX() < d.GetX());
	l.Set(-1.0f, -5.0f);
	EXPECT_TRUE(d.GetX() == l.GetX());

	Vector2D<double> e(1.0, 5.0);
	Vector2D<double> m(2.0, 6.0);
	EXPECT_TRUE(e.GetX() < m.GetX());
	EXPECT_TRUE(e.GetX() != m.GetX());
	EXPECT_TRUE(m.GetX() > e.GetX());
	m.Set(1.0f, 5.0f);
	EXPECT_TRUE(e.GetX() == m.GetX());

	Vector2D<double> f(-1.0, -5.0);
	Vector2D<double> n(-2.0, -6.0);
	EXPECT_TRUE(f.GetX() > n.GetX());
	EXPECT_TRUE(f.GetX() != n.GetX());
	EXPECT_TRUE(n.GetX() < f.GetX());
	n.Set(-1.0f, -5.0f);
	EXPECT_TRUE(f.GetX() == n.GetX());

	Vector2D<long> g(1, 5);
	Vector2D<long> o(2, 6);
	EXPECT_TRUE(g.GetX() < o.GetX());
	EXPECT_TRUE(g.GetX() != o.GetX());
	EXPECT_TRUE(o.GetX() > g.GetX());
	o.Set(1, 5);
	EXPECT_TRUE(g.GetX() == o.GetX());

	Vector2D<long> h(-1, -5);
	Vector2D<long> p(-2, -6);
	EXPECT_TRUE(h.GetX() > p.GetX());
	EXPECT_TRUE(h.GetX() != p.GetX());
	EXPECT_TRUE(p.GetX() < h.GetX());
	p.Set(-1, -5);
	EXPECT_TRUE(h.GetX() == p.GetX());
}

TEST(Vector, Size)
{
	Vector2D<int> a(1, 5);
	EXPECT_TRUE(a.Magnitude() == 5);
	EXPECT_TRUE(a.Magnitude() != 2);

	Vector2D<int> b(-1, -5);
	EXPECT_TRUE(b.Magnitude() == 5);
	EXPECT_FALSE(b.Magnitude() != 5);

	Vector2D<float> c(1.0f, 5.0f);
	EXPECT_TRUE(c.Magnitude() > 5.0f);
	EXPECT_FALSE(c.Magnitude() == 2.0f);

	Vector2D<float> d(-1.0f, -5.0f);
	EXPECT_TRUE(d.Magnitude() > 5.0f);
	EXPECT_FALSE(d.Magnitude() == 2.0f);

	Vector2D<double> e(1.0, 5.0);
	EXPECT_TRUE(e.Magnitude() != 1);
	EXPECT_TRUE(e.Magnitude() < 10);

	Vector2D<double> f(-1.0, -5.0);
	EXPECT_FALSE(f.Magnitude() < 4.0);
	EXPECT_FALSE(f.Magnitude() == 2);

	Vector2D<long> g(1, 5);
	EXPECT_TRUE(g.Magnitude() == 5);
	EXPECT_FALSE(g.Magnitude() == 2);

	Vector2D<long> h(-1, -5);
	EXPECT_TRUE(h.Magnitude() == 5);
	EXPECT_FALSE(h.Magnitude() == 2);
}

TEST(Vector, Normalize)
{
	Vector2D<int> a(1, 5);
	a.Normalize();
	EXPECT_EQ(a.GetX(), 0);
	EXPECT_EQ(a.GetY(), 1);

	Vector2D<int> b(-1, -5);
	b.Normalize();
	EXPECT_FALSE(b.GetX() == 4);
	EXPECT_FALSE(b.GetY() == 3);

	Vector2D<float> c(1.0f, 5.0f);
	c.Normalize();
	EXPECT_TRUE(c.GetX() < 0.2f);
	EXPECT_FALSE(c.GetX() > 0.2f);

	Vector2D<float> d(-1.0f, -5.0f);
	d.Normalize();
	EXPECT_TRUE(d.GetY() < 0.0f);
	EXPECT_FALSE(d.GetX() == 2.0f);

	Vector2D<double> e(1.0, 5.0);
	e.Normalize();
	EXPECT_TRUE(e.GetX() != 1);
	EXPECT_TRUE(e.GetY() < 10);

	Vector2D<double> f(-1.0, -5.0);
	f.Normalize();
	EXPECT_FALSE(f.GetX() > 0.0);
	EXPECT_TRUE(f.GetY() < 2);

	Vector2D<long> g(1, 5);
	g.Normalize();
	EXPECT_FALSE(g.GetX() == 5);
	EXPECT_FALSE(g.GetY() == 2);

	Vector2D<long> h(-1, -5);
	h.Normalize();
	EXPECT_TRUE(h.GetX() < 1);
	EXPECT_FALSE(h.GetY() > 0);
}

TEST(Vector, Direction)
{
	Vector2D<int> a(2, 1);
	EXPECT_TRUE(a.Direction() != 100.0f);
	EXPECT_EQ(a.Direction(), 26);

	Vector2D<int> b(-2, -1);
	EXPECT_TRUE(b.Direction() != 100.0f);
	EXPECT_EQ(b.Direction(), 207);

	Vector2D<float> c(2.0f, 1.0f);
	EXPECT_TRUE(c.Direction() != 100.0f);
	EXPECT_FALSE(c.Direction() == 27.0f);

	Vector2D<float> d(-2, -1);
	EXPECT_TRUE(c.Direction() != 100.0f);
	EXPECT_FALSE(c.Direction() == 206.565048f);

	Vector2D<long> e(1, 1);
	EXPECT_TRUE(e.Direction() != 100.0f);
	EXPECT_EQ(e.Direction(), 45);

	Vector2D<long> f(-1, -1);
	EXPECT_TRUE(f.Direction() != 100.0f);
	EXPECT_EQ(f.Direction(), 225);

	Vector2D<float> g(1.0f, 1.0f);
	EXPECT_TRUE(g.Direction() != 100.0f);
	EXPECT_EQ(g.Direction(), 45);

	Vector2D<float> h(-1.0f, -1.0f);
	EXPECT_TRUE(h.Direction() != 100.0f);
	EXPECT_EQ(h.Direction(), 225);
}

TEST(Vector, DotProduct)
{
	Vector2D<int> a(2, 1);
	Vector2D<int> b(1, 2);
	EXPECT_TRUE(DotProduct(a, b) != 100);
	EXPECT_EQ(DotProduct(a, b), 4);

	Vector2D<int> c(-2, -1);
	Vector2D<int> d(-2, -1);
	EXPECT_EQ(DotProduct(c, d), 5);
	EXPECT_FALSE(DotProduct(c, d) == 3);

	Vector2D<float> e(2.0f, 1.0f);
	Vector2D<float> f(2.0f, 1.0f);
	EXPECT_TRUE(DotProduct(e, f) != 100.0f);
	EXPECT_TRUE(DotProduct(e, f) == 5.0f);

	Vector2D<float> g(-2.0f, -1.0f);
	Vector2D<float> h(-2.0f, -1.0f);
	EXPECT_TRUE(DotProduct(g, h) != 100.0f);
	EXPECT_TRUE(DotProduct(g, h) == 5.0f);

	Vector2D<long> i(1, 1);
	Vector2D<long> j(1, 1);
	EXPECT_TRUE(DotProduct(i, j) != 100);
	EXPECT_EQ(DotProduct(i, j), 2);

	Vector2D<long> k(-1, -1);
	Vector2D<long> l(-1, -1);
	EXPECT_TRUE(DotProduct(k, l) != 100.0f);
	EXPECT_EQ(DotProduct(k, l), 2);

	Vector2D<double> m(1.0, 1.0);
	Vector2D<double> n(1.0, 1.0);
	EXPECT_TRUE(DotProduct(m, n) != 100.0f);
	EXPECT_EQ(DotProduct(m, n), 2.0);

	Vector2D<double> o(1.0, 1.0);
	Vector2D<double> p(1.0, 1.0);
	EXPECT_TRUE(DotProduct(o, p) != 100.0f);
	EXPECT_EQ(DotProduct(o, p), 2.0);
}

TEST(Vector, Distance)
{
	Vector2D<int> a(8, 2);
	Vector2D<int> b(-2, -16);
	EXPECT_EQ(Distance(a, b), 20);
	EXPECT_TRUE(Distance(a, b) == 20);
	EXPECT_FALSE(Distance(a, b) == 23);

	Vector2D<float> c(8.0f, 2.0f);
	Vector2D<float> d(-2.0f, -16.0f);
	EXPECT_TRUE(Distance(c, d) < 21.0f);
	EXPECT_TRUE(Distance(c, d) != 20.0f);
	EXPECT_FALSE(Distance(c, d) > 23.0f);

	Vector2D<long> e(8, 2);
	Vector2D<long> f(-2, -16);
	EXPECT_EQ(Distance(e, f), 20);
	EXPECT_TRUE(Distance(e, f) == 20);
	EXPECT_FALSE(Distance(e, f) == 23);

	Vector2D<double> g(8.0f, 2.0f);
	Vector2D<double> h(-2.0f, -16.0f);
	EXPECT_TRUE(Distance(g, h) < 21.0);
	EXPECT_TRUE(Distance(g, h) != 20.0);
	EXPECT_FALSE(Distance(g, h) > 23.0);
}



