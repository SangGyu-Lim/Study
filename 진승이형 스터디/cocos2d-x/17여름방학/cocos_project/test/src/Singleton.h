#ifndef __SINGLETON_H__
#define __SINGLETON_H__

//template<typename T>
class Singleton
{
public:
	static Singleton* GetInstance();
	static void destroy();

private:

	Singleton(Singleton const&) {};
	Singleton& operator=(Singleton const&) {};

protected:
	static Singleton* m_instance;

	Singleton() { m_instance = static_cast <Singleton*> (this); };
	~Singleton() {  };
};


Singleton* Singleton::m_instance = 0;

Singleton* Singleton::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new Singleton();
	}

	return m_instance;
}

void Singleton::destroy()
{
	delete m_instance;
	m_instance = 0;
}

#endif // !__SINGLETON_H__