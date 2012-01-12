#include "Interface.h"
#include "Collision.h"
#include "Containers.h"

namespace base
{
	InterfaceManager::InterfaceManager()
	{
		HasCursor = false;
	}

	InterfaceManager::~InterfaceManager()
	{

	}

	void InterfaceManager::Initialize()
	{
		
	}

	void InterfaceManager::Update()
	{
		//update each individual control that is enabled
		for (int i = 0; i < Controls.size(); i++)
		{
			if (Controls[i]->Enabled)
				Controls[i]->Update();
		}

		//check if the mouse is over any link labels to highlite them
		for (int k = 0; k < LinkLabels.size(); k++)
		{
			if (LinkLabels[k]->Enabled && Cursor->BoundingRect.IntersectsRectangle(LinkLabels[k]->BoundingRect))
				LinkLabels[k]->HasFocus = true;
			else
				LinkLabels[k]->HasFocus = false;
		}

		//if the left mouse button is being pushed, check if any enabled buttons or linlabels overlap with it
		if (HasCursor && sf::Mouse::IsButtonPressed(sf::Mouse::Button::Left))
		{
			for (int j = 0; j < Buttons.size(); j++)
				if (Buttons[j]->Enabled && Cursor->BoundingRect.IntersectsRectangle(Buttons[j]->BoundingRect))//&& Cursor->OverlapRect.Intersects(Buttons[j]->OverlapRect))// && Collision::SpriteCollision(*Cursor, *Buttons[j]))
					Buttons[j]->Push();
			for (int m = 0; m < LinkLabels.size(); m++)
				if (LinkLabels[m]->Enabled && LinkLabels[m]->HasFocus)
					LinkLabels[m]->Activate();
		}
	}
	
	void InterfaceManager::Render(sf::RenderWindow *rw)
	{
		//render each individual control that is visible
		for (int count = 0; count < Controls.size(); count++)
		{
			if (Controls[count]->Visible)
				Controls[count]->Render(rw);
		}

		//render our cursor last
		if (HasCursor)
			Cursor->Render(rw);

	}

	void InterfaceManager::AddControl(base::Control& control)
	{
		//add the control to our list of controls
		Controls.push_back(&control);
	}

	void InterfaceManager::AddPictureBox(base::PictureBox& picturebox)
	{
		//add the picture box to our list of controls
		Controls.push_back(&picturebox);
	}

	void InterfaceManager::AddCursor(base::Cursor& cursor)
	{
		//designate our cursor
		Cursor = &cursor;

		HasCursor = true;
	}

	void InterfaceManager::AddButton(base::Button& button)
	{
		//add the button to our list of buttons and controls
		Buttons.push_back(&button);
		Controls.push_back(&button);
	}

	void InterfaceManager::AddLinkLabel(base::LinkLabel& linkLabel)
	{
		//adds the link label to our list of link labels and controls
		LinkLabels.push_back(&linkLabel);
		Controls.push_back(&linkLabel);
	}
}