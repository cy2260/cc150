template<class T>
class RefCount
{
private:

    T* objectPtr;
    int count;

public:

    RefCount(T* objPtr) 
    :    objectPtr(objPtr)
    ,    count(0)
    {}

    ~RefCount() { assert( count == 0 ); delete objectPtr; }

    T* operator*() { return objectPtr; }

    int increase() { ++count; return count; }
    int decrease() { --count; return count; }

};
