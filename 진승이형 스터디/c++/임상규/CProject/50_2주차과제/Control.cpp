#include "stdafx.h"
#include "Control.h"

CControl::CControl()
{
	
}

CControl::~CControl()
{
	
}

bool CControl::MoveGameObject( CGameObject *pGameObject )
{
	int key;

	if(kbhit())
	{
		key = getch();

		switch(key)
		{
		case UP:
			{
				if( pGameObject->GetPositionY() > MINIMUM )
					pGameObject->SetPositionY( pGameObject->GetPositionY() - 1 );
			} break;
		case LEFT:
			{
				if( pGameObject->GetPositionX() > MINIMUM )
					pGameObject->SetPositionX( pGameObject->GetPositionX() - 2 );
			} break;
		case RIGHT:
			{
				if( pGameObject->GetPositionX() < MAX_X )
					pGameObject->SetPositionX( pGameObject->GetPositionX() + 2 );
			} break;
		case DOWN:
			{
				if( pGameObject->GetPositionY() < MAX_Y )
					pGameObject->SetPositionY( pGameObject->GetPositionY() + 3 );
			} break;
		case ESC:
			{
				return false;
			} break;
		}
	}

	return true;
}


