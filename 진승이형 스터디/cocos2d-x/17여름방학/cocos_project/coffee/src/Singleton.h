#ifndef __SINGLETON_H__
#define __SINGLETON_H__

//template<typename T>
//class Singleton
//{
//public:
//	static T* GetInstance();
//	static void destroy();
//
//private:
//
//	Singleton(Singleton const&) {};
//	Singleton& operator=(Singleton const&) {};
//
//protected:
//	static T* m_instance;
//
//	Singleton() { m_instance = static_cast <T*> (this); };
//	~Singleton() {  };
//};
//
//template<typename T>
//typename T* Singleton<T>::m_instance = 0;
//
//template<typename T>
//T* Singleton<T>::GetInstance()
//{
//	if (!m_instance)
//	{
//		Singleton<T>::m_instance = new T();
//	}
//
//	return m_instance;
//}
//
//template<typename T>
//void Singleton<T>::destroy()
//{
//	delete Singleton<T>::m_instance;
//	Singleton<T>::m_instance = 0;
//}










//
//template <typename T>
//class Singleton
//{
//public:
//	static T * GetInstance()
//	{
//		if (!m_instance) m_instance = new T;
//		return m_instance;
//	};
//	static void DestroyInstance()
//	{
//		delete m_instance;
//		m_instance = 0;
//	};
//
//private:
//	static T * m_instance;
//};
//
//template<typename T> T* Singleton<T>::m_instance = 0;
//
//#define GETINSTANCE(CLASSNAME)			Singleton<CLASSNAME>::GetInstance()

#endif // !__SINGLETON_H__