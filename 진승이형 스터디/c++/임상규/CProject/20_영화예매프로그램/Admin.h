#ifndef __ADMIN_H__
#define __ADMIN_H__
#include "ConstantDefine.h"

class CAdmin
{
private:
	LPDATA_HEADER m_pDataHeader;
	LPMOVIE_LIST m_pMovieList;

public:
	CAdmin();
	~CAdmin();

	void Init();
	void Update();
	void Release();

	void MovieAdd();
	void MovieDelete();
	void MovieModify();
	void MovieView();
	int MovieDataLoad();
	void MovieDataSave();


protected:

};

#endif