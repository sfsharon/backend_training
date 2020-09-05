#include <iostream>
#include <typeinfo>

class Context;

class State 
{
protected:
    Context* m_context;

public: 
    virtual ~State() { }

    void set_context(Context* context)
    {
        m_context = context;
    }

    virtual void Handle1() = 0;
    virtual void Handle2() = 0;
};

class Context 
{
private:
    State* m_state;

public:
    Context(State* state) : m_state(NULL)
    {
        TransitionTo(state);
    }

    ~Context() 
    {
        delete m_state;
    }

    void TransitionTo(State* state)
    {
        
    }
};




int main()
{
    std::cout <<"Hello !\n";

    return 0;
}