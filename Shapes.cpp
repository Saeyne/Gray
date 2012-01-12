#include "Containers.h"
#include <math.h>

namespace base
{
#pragma region Vector2I

	Vector2I operator+(const Vector2I& v1, const Vector2I& v2)
	{
		return Vector2I(v1.X + v2.X, v1.Y + v2.Y);
	}

	Vector2I operator+(const Vector2I& v1, const Vector2F& v2)
	{
		return Vector2I(v1.X + v2.X, v1.Y + v2.Y);
	}

	Vector2I operator-(const Vector2I& v1, const Vector2I& v2)
	{
		return Vector2I(v1.X - v2.X, v1.Y - v2.Y);
	}

	Vector2I operator-(const Vector2I& v1, const Vector2F& v2)
	{
		return Vector2I(v1.X - v2.X, v1.Y - v2.Y);
	}

	Vector2I operator*(const Vector2I& v, int c)
	{
		return Vector2I(v.X * c, v.Y * c);
	}

	Vector2I operator/(const Vector2I& v, int c)
	{
		return Vector2I(v.X / c, v.Y / c);
	}

	Vector2I& Vector2I::operator=(const Vector2I& source)
	{
		this->X = source.X;
		this->Y = source.Y;
		return *this;
	}

	int Vector2I::Length()
	{
		return (int)sqrt((float)(X*X + Y*Y));
	}

	void Vector2I::Normalize()
	{
		int length = Length();
		X /= length;
		Y /= length;
	}

	int Vector2I::DotProduct(Vector2I otherVector)
	{
		return (X*otherVector.X + Y*otherVector.Y);
	}

	int Vector2I::CrossProduct(Vector2I otherVector)
	{
		return (X*otherVector.Y - Y*otherVector.X);
	}

	Vector2I Vector2I::Projection(Vector2I otherVector)
	{
		//projecting ONTO otherVector

		int dotProduct = DotProduct(otherVector);

		//check for zero length first
		if (dotProduct == 0)
			return Vector2I(0, 0);

		int x = (dotProduct / (otherVector.X*otherVector.X + otherVector.Y*otherVector.Y)) * otherVector.X;
		int y = (x / otherVector.X) * otherVector.Y;

		return Vector2I(x, y);
	}

	Vector2I Vector2I::ProjectedLength(Vector2I otherVector)
	{
		Vector2I temp = this->Projection(otherVector);
		return Vector2I(abs(temp.X), abs(temp.Y));
	}

	Vector2I Vector2I::Normal()
	{
		return Vector2I(-Y, X);
	}

	Vector2I Vector2I::UnitDirection()
	{
		Vector2I temp = Vector2I(this->X, this->Y);
		temp.Normalize();
		return temp;
	}

#pragma endregion

#pragma region Vector2F

	Vector2F operator+(const Vector2F& v1, const Vector2I& v2)
	{
		return Vector2F(v1.X + v2.X, v1.Y + v2.Y);
	}

	Vector2F operator+(const Vector2F& v1, const Vector2F& v2)
	{
		return Vector2F(v1.X + v2.X, v1.Y + v2.Y);
	}

	Vector2F operator-(const Vector2F& v1, const Vector2I& v2)
	{
		return Vector2F(v1.X - v2.X, v1.Y - v2.Y);
	}

	Vector2F operator-(const Vector2F& v1, const Vector2F& v2)
	{
		return Vector2F(v1.X - v2.X, v1.Y - v2.Y);
	}

	Vector2F operator*(const Vector2F& v, int c)
	{
		return Vector2F(v.X * c, v.Y * c);
	}

	Vector2F operator/(const Vector2F& v, int c)
	{
		return Vector2F(v.X / c, v.Y / c);
	}

	Vector2F& Vector2F::operator=(const Vector2F& source)
	{
		this->X = source.X;
		this->Y = source.Y;
		return *this;
	}

	float Vector2F::Length()
	{
		return sqrt(X*X + Y*Y);
	}

	void Vector2F::Normalize()
	{
		float length = Length();
		X /= length;
		Y /= length;
	}

	float Vector2F::DotProduct(Vector2F otherVector)
	{
		return (X*otherVector.X + Y*otherVector.Y);
	}

	float Vector2F::CrossProduct(Vector2F otherVector)
	{
		return (X*otherVector.Y - Y*otherVector.X);
	}


	Vector2F Vector2F::Projection(Vector2F otherVector)
	{
		//projecting ONTO otherVector

		float dotProduct = DotProduct(otherVector);

		//check for zero length first
		if (dotProduct == 0)
			return Vector2F(0, 0);

		float x = (dotProduct / (otherVector.X*otherVector.X + otherVector.Y*otherVector.Y)) * otherVector.X;
		float y = (x / otherVector.X) * otherVector.Y;

		return Vector2F(x, y);
	}

	Vector2F Vector2F::ProjectedLength(Vector2F otherVector)
	{
		Vector2F temp = this->Projection(otherVector);
		return Vector2F(abs(temp.X), abs(temp.Y));
	}

	Vector2F Vector2F::Normal()
	{
		return Vector2F(-Y, X);
	}

	Vector2F Vector2F::UnitDirection()
	{
		Vector2F temp = Vector2F(this->X, this->Y);
		temp.Normalize();
		return temp;
	}

#pragma endregion

#pragma region Vector3I

	Vector3I operator+(const Vector3I& v1, const Vector3I& v2)
	{
		return Vector3I(v1.X + v2.X, v1.Y + v2.Y, v1.Z + v2.Z);
	}

	Vector3I operator+(const Vector3I& v1, const Vector3F& v2)
	{
		return Vector3I(v1.X + v2.X, v1.Y + v2.Y, v1.Z + v2.Z);
	}

	Vector3I operator-(const Vector3I& v1, const Vector3I& v2)
	{
		return Vector3I(v1.X - v2.X, v1.Y - v2.Y, v1.Z - v2.Z);
	}

	Vector3I operator-(const Vector3I& v1, const Vector3F& v2)
	{
		return Vector3I(v1.X - v2.X, v1.Y - v2.Y, v1.Z - v2.Z);
	}

	Vector3I operator*(const Vector3I& v, int c)
	{
		return Vector3I(v.X * c, v.Y * c, v.Z * c);
	}

	Vector3I operator/(const Vector3I& v, int c)
	{
		return Vector3I(v.X / c, v.Y / c, v.Z / c);
	}

	Vector3I& Vector3I::operator=(const Vector3I& source)
	{
		this->X = source.X;
		this->Y = source.Y;
		this->Z = source.Z;
		return *this;
	}

	int Vector3I::Length()
	{
		return (int)sqrt((float)(X*X + Y*Y + Z*Z));
	}

	void Vector3I::Normalize()
	{
		int length = Length();
		X /= length;
		Y /= length;
		Z /= length;
	}

#pragma endregion

#pragma region Vector3F

	Vector3F operator+(const Vector3F& v1, const Vector3I& v2)
	{
		return Vector3F(v1.X + v2.X, v1.Y + v2.Y, v1.Z + v2.Z);
	}

	Vector3F operator+(const Vector3F& v1, const Vector3F& v2)
	{
		return Vector3F(v1.X + v2.X, v1.Y + v2.Y, v1.Z + v2.Z);
	}

	Vector3F operator-(const Vector3F& v1, const Vector3I& v2)
	{
		return Vector3F(v1.X - v2.X, v1.Y - v2.Y, v1.Z - v2.Z);
	}

	Vector3F operator-(const Vector3F& v1, const Vector3F& v2)
	{
		return Vector3F(v1.X - v2.X, v1.Y - v2.Y, v1.Z - v2.Z);
	}

	Vector3F operator*(const Vector3F& v, int c)
	{
		return Vector3F(v.X * c, v.Y * c, v.Z * c);
	}

	Vector3F operator/(const Vector3F& v, int c)
	{
		return Vector3F(v.X / c, v.Y / c, v.Z / c);
	}

	Vector3F& Vector3F::operator=(const Vector3F& source)
	{
		this->X = source.X;
		this->Y = source.Y;
		this->Z = source.Z;
		return *this;
	}


	float Vector3F::Length()
	{
		return sqrt(X*X + Y*Y + Z*Z);
	}

	void Vector3F::Normalize()
	{
		int length = Length();
		X /= length;
		Y /= length;
		Z /= length;
	}


#pragma endregion

#pragma region Rectangle

	Rectangle::Rectangle(Vector2F topLeftPoint, Vector2F size)
	{
		TopLeftPoint = topLeftPoint;
		Size = size;

		//InitPolygon();
	}

	Rectangle::Rectangle(float leftX, float topY, float width, float height)
	{
		TopLeftPoint.X = leftX;
		TopLeftPoint.Y = topY;
		Size.X = width;
		Size.Y = height;

		//InitPolygon();
	}

	void Rectangle::InitPolygon()
	{
		//polygon.AddPoint(TopLeftPoint.X, TopLeftPoint.Y, sf::Color::Red, sf::Color::Red);
		//polygon.AddPoint(TopLeftPoint.X + Size.X, TopLeftPoint.Y, sf::Color::Red, sf::Color::Red);
		//polygon.AddPoint(TopLeftPoint.X + Size.X, TopLeftPoint.Y + Size.Y, sf::Color::Red, sf::Color::Red);
		//polygon.AddPoint(TopLeftPoint.X, TopLeftPoint.Y + Size.Y, sf::Color::Red, sf::Color::Red);

		polygon = sf::Shape::Rectangle(TopLeftPoint.X, TopLeftPoint.Y, Size.X, Size.Y, sf::Color::Red, 2, sf::Color::Red);

		polygon.SetOutlineThickness(10);
		polygon.EnableFill(false);
		polygon.EnableOutline(true);

		Debug = true;
	}

	void Rectangle::Render(sf::RenderWindow *rw)
	{
		if (this->Debug)
			rw->Draw(polygon);
	}

	bool Rectangle::IntersectsRectangle(Rectangle& otherRect)
	{
		return ((this->LeftX() < otherRect.RightX()) && (this->RightX() > otherRect.LeftX()) &&
				(this->TopY() < otherRect.BottomY()) && (this->BottomY() > otherRect.TopY()));
	}

#pragma endregion

#pragma region Square

	Square::Square(Vector2F topLeftPoint, float size)
		: Rectangle(topLeftPoint, Vector2F(size, size))
	{

	}

	Square::Square(float leftX, float topY, float size)
		: Rectangle(Vector2F(leftX, topY), Vector2F(size, size))
	{

	}

#pragma endregion

#pragma region Circle

	Circle::Circle(Vector2F center, float radius)
	{
		Center = center;
		Radius = radius;
	}

	Circle::Circle(float x, float y, float radius)
	{
		Center.X = x;
		Center.Y = y;
		Radius = radius;
	}

#pragma endregion

#pragma region Triangle

	Triangle::Triangle(Vector2F point1, Vector2F point2, Vector2F point3)
	{
		Point1 = point1;
		Point2 = point2;
		Point3 = point3;
	}

#pragma endregion

}