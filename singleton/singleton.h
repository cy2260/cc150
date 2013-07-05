template<class T>
class Singleton 
{ 
private: 
    Singleton()  { } 
    Singleton( const Singleton& s ); //don't implement 
    void operator=( const Singleton& s); 

public: 
    static T* getInstance() { 
        static T instance; 
        return &instance; 
    } 
};
