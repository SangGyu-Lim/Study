#include "User.h"
#include "ConstantDefine.h"

CUser::CUser()
{
	Init();
}

CUser::~CUser()
{
	Release();
}

void CUser::Init()
{
	cout << "This is User Scene" << endl;
}

void CUser::Update()
{

}

void CUser::Release()
{

}

