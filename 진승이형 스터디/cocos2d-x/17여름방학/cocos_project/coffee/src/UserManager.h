#ifndef __USER_MANAGER_H__
#define __USER_MANAGER_H__

#include "cocos2d.h"

typedef struct
{
	int Gold;
	int SurvivalDay;
}USER_INFORMATION, *LPUSER_INFORMATION;

class UserManager
{
public:	
	static UserManager* GetInstance();
	static void destroy();

private:

	static UserManager* m_instance;

	UserManager(UserManager const&) {};
	UserManager& operator=(UserManager const&) {};

	UserManager() { m_instance = static_cast <UserManager*> (this); }
	~UserManager() {  };

public:

private:
	USER_INFORMATION userInformation;

public:

	void InitUserManager();

	void InitUserInformation();

	inline int GetGold() { return userInformation.Gold; }
	inline bool IsEnoughGold(int gold) { return (userInformation.Gold >= gold); }
	inline void AddGold(int gold) { userInformation.Gold += gold; }
	inline void MinusGold(int gold) { userInformation.Gold -= gold; }
	
	inline int GetSurvivalDay() { return userInformation.SurvivalDay; }
	inline void AddSurvivalDay() { userInformation.SurvivalDay += 1; }


};

#endif // !__USER_MANAGER_H__
