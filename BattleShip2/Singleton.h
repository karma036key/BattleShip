#ifndef SINGLETON_H
#define SINGLETON_H



template< class T >
class Singleton
{

protected:
	Singleton() {}				
	virtual ~Singleton() {}		

private:
	// 自分自身のポインタ変数(自分自身の唯一の実態)
	static T* m_pInstance;			// *は外さない

public:
	// 実体を作る関数
	static void CreateInstance()
	{
		// すでに作られているなら新しく作らないことを保証
		if (m_pInstance == nullptr)
		{
			m_pInstance = new T();
		}
	}
	// 実体を破棄する関数
	static void DestroyInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}

	// 実体を取得する関数
	static T* GetInstance()
	{
		return m_pInstance;
	}

	// 実体が存在しないか確認する
	static bool IsNull()
	{
		return (m_pInstance == nullptr);
	}

};
// staticなメンバ変数を初期化
template<class T>
T* Singleton<T>::m_pInstance = nullptr;




#endif