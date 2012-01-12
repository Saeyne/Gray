#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <SFML\Graphics.hpp>

#include <vector>
#include <algorithm>

namespace base
{
	class Sprite;		//sprite class that contains a texture and any info needed to render it
	class SpriteBatch;	//container class for sorting sprites by their draw order before rendering
	class Vector2I;		//2 dimensional container of integers
	class Vector2F;		//2 dimensional container of floats
	class Vector3I;		//3 dimensional container of integers
	class Vector3F;		//3 dimensional container of floats
	class Rectangle;	//class representing a rectangle
	class Square;		//class representing a square
	class Circle;		//class representing a circle
	class Triangle;		//class representing a triangle

	//a sprite class that inherits the sfml sprite
	//with our own added benefits
	class Sprite: public sf::Sprite
	{
	private:
	public:
		float DrawLayer;
		Sprite() { }
		Sprite(sf::Sprite sfSprite);
		~Sprite();
		void Render(sf::RenderWindow *rw);
	};

	//holds a vector of sprites, and lets us
	//sort them before drawing them
	class SpriteBatch
	{
	private:
		std::vector<base::Sprite*> Sprites;
	public:
		SpriteBatch();
		~SpriteBatch();
		void AddSprite(Sprite* sprite);
		void Sort();
		void Render(sf::RenderWindow *rw);
	};

	//2d vector using integers
	class Vector2I
	{
	public:
		int X, Y;
		
		Vector2I() { }
		Vector2I(int x, int y) { X = x; Y = y;}
		~Vector2I() { }
		friend Vector2I operator+(const Vector2I& v1, const Vector2I& v2);
		friend Vector2I operator+(const Vector2I& v1, const Vector2F& v2);
		friend Vector2I operator-(const Vector2I& v1, const Vector2I& v2);
		friend Vector2I operator-(const Vector2I& v1, const Vector2F& v2);
		friend Vector2I operator*(const Vector2I& v, int c);
		friend Vector2I operator/(const Vector2I& v, int c);
		Vector2I& operator=(const Vector2I& source);

		int Length();
		void Normalize();
		int DotProduct(Vector2I otherVector);
		int CrossProduct(Vector2I otherVector);
		Vector2I Projection(Vector2I otherVector);
		Vector2I ProjectedLength(Vector2I otherVector);
		Vector2I Normal();
		Vector2I UnitDirection();
	};

	//2d vector using floats
	class Vector2F
	{
		public:
			float X, Y;
			Vector2F() { }
			Vector2F(float x, float y) { X = x; Y = y;}
			~Vector2F() { }
			friend Vector2F operator+(const Vector2F& v1, const Vector2F& v2);
			friend Vector2F operator+(const Vector2F& v1, const Vector2I& v2);
			friend Vector2F operator-(const Vector2F& v1, const Vector2F& v2);
			friend Vector2F operator-(const Vector2F& v1, const Vector2I& v2);
			friend Vector2F operator*(const Vector2F& v, int c);
			friend Vector2F operator/(const Vector2F& v, int c);
			Vector2F& operator=(const Vector2F& source);

			float Length();
			void Normalize();
			float DotProduct(Vector2F otherVector);
			float CrossProduct(Vector2F otherVector);
			Vector2F Projection(Vector2F otherVector);
			Vector2F ProjectedLength(Vector2F otherVector);
			Vector2F Normal();
			Vector2F UnitDirection();
	};

	//3d vector using integers
	class Vector3I
	{
	public:
		int X, Y, Z;
		Vector3I() { }
		Vector3I(int x, int y, int z) { X = x; Y = y; Z = z;}
		~Vector3I() { }
		friend Vector3I operator+(const Vector3I& v1, const Vector3I& v2);
		friend Vector3I operator+(const Vector3I& v1, const Vector3F& v2);
		friend Vector3I operator-(const Vector3I& v1, const Vector3I& v2);
		friend Vector3I operator-(const Vector3I& v1, const Vector3F& v2);
		friend Vector3I operator*(const Vector3I& v, int c);
		friend Vector3I operator/(const Vector3I& v, int c);
		Vector3I& operator=(const Vector3I& source);

		int Length();
		void Normalize();
	};

	//3d vector using floats
	class Vector3F
	{
	public:
		float X, Y, Z;
		Vector3F() { }
		Vector3F(float x, float y, float z) { X = x; Y = y; Z = z; }
		~Vector3F() { }
		friend Vector3F operator+(const Vector3F& v1, const Vector3I& v2);
		friend Vector3F operator+(const Vector3F& v1, const Vector3F& v2);
		friend Vector3F operator-(const Vector3F& v1, const Vector3I& v2);
		friend Vector3F operator-(const Vector3F& v1, const Vector3F& v2);
		friend Vector3F operator*(const Vector3F& v, int c);
		friend Vector3F operator/(const Vector3F& v, int c);
		Vector3F& operator=(const Vector3F& source);

		float Length();
		void Normalize();
	};

	class Rectangle
	{
	private:
		
		void InitPolygon();
	public:
		bool Debug;
		sf::Shape polygon;
		Vector2F TopLeftPoint, Size;
		float Rotation;
		Rectangle() { }
		Rectangle(Vector2F topLeftPoint, Vector2F size);
		Rectangle(float leftX, float topY, float width, float height);
		float Width() { return Size.X; }
		float Height() { return Size.Y; }
		float LeftX() { return TopLeftPoint.X; }
		float RightX() { return TopLeftPoint.X + Size.X; }
		float TopY() { return TopLeftPoint.Y; }
		float BottomY() { return TopLeftPoint.Y + Size.Y; }
		~Rectangle() { }
		
		void Render(sf::RenderWindow *rw);
		bool IntersectsRectangle(Rectangle& otherRect);
	};

	class Square : Rectangle
	{
		public:
			Square();
			Square(Vector2F topLeftPoint, float size);
			Square(float leftX, float topY, float size);
			~Square();
	};

	class Circle
	{
		public:
			Vector2F Center;
			float Radius;
			Circle();
			Circle(Vector2F center, float radius);
			Circle(float x, float y, float radius);
			~Circle();
	};

	class Triangle
	{
	public:
		Vector2F Point1, Point2, Point3;
		Triangle();
		Triangle(Vector2F point1, Vector2F point2, Vector2F point3);
		~Triangle();
	};
}

#endif