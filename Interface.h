#ifndef INTERFACE_H
#define INTERFACE_H

#include <SFML\Graphics.hpp>
#include "Utility.h"
#include "Containers.h"
#include "ResourceCache.h"


#include <vector>

namespace base
{
	class Control;			//standard control that each UI component inherits
	class InterfaceManager;	//container used to update and render controls
	class PictureBox;		//control that simple displays a texture
	class Cursor;			//specialized picturebox depicting mouse position
	class Button;			//2 part picturebox used to represent a button
	class Label;			//control used to display text
	class LinkLabel;		//label that can be used as a link

	class Control
	{
	public:
		bool HasFocus;
		bool Enabled;
		bool Visible;
		Control();
		~Control();
		virtual void Update() = 0;
		virtual void Render(sf::RenderWindow *rw) = 0;
	};

	class InterfaceManager
	{
	private:

		std::vector<base::Control*> Controls;		//holds references to all of the controls
	public:
		std::vector<base::Button*> Buttons;			//holds all of the buttons
		std::vector<base::LinkLabel*> LinkLabels;	//holds all the link labels
		base::Cursor* Cursor;						//a cursor for the interface
		bool HasCursor;
		InterfaceManager();
		~InterfaceManager();
		void Initialize();
		void Update();
		void Render(sf::RenderWindow *rw);
		void AddControl(base::Control& control);
		void AddPictureBox(base::PictureBox& pictureBox);
		void AddCursor(base::Cursor& cursor);
		void AddButton(base::Button& button);
		void AddLinkLabel(base::LinkLabel& linkLabel);
	};

	class PictureBox : public Control, public base::Sprite
	{
	private:
	public:
		base::Rectangle BoundingRect;
		PictureBox(base::Sprite sprite);
		~PictureBox() { }
		void Update();
		void Render(sf::RenderWindow *rw);
		void SetAsBackground(sf::RenderWindow *rw);
	};

	class Cursor : public PictureBox
	{
	private:
	public:
		Cursor(base::Sprite cursor);
		~Cursor();
		void Update(sf::Vector2f position);
		void Render(sf::RenderWindow *rw);
	};

	class Button: public Control, public base::Sprite
	{
	private:
		base::Timer timer;
		base::Vector2F size;
	public:
		base::Rectangle BoundingRect;
		bool Pushed;
		Button(base::Sprite Sprite);
		~Button();
		void Update();
		void Render(sf::RenderWindow *rw);
		void Push();
		void SetTimer(float time);
	};

	class Label: public Control
	{
	private:
	public:
		sf::Text Text;
		Label();
		Label(const std::string& s);
		~Label();
		void Update();
		void Render(sf::RenderWindow *rw);
	};

	class LinkLabel: public Control
	{
	private:
	public:
		bool Activated;
		base::Rectangle BoundingRect;
		sf::Color NormalColor, SelectedColor;
		sf::Text Text;
		LinkLabel();
		LinkLabel(const std::string& s);
		~LinkLabel();
		void Update();
		void Render(sf::RenderWindow *rw);
		void Activate();
	};
}

#endif