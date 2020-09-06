/*
Code based on :
https://refactoring.guru/design-patterns/state/cpp/example
*/

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
        std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
        if (m_state != NULL)
        {
            delete m_state;
        }
        m_state = state;
        m_state->set_context(this);
    }

    void Request1()
    {
        m_state->Handle1();
    }

    void Request2()
    {
        m_state->Handle2();
    }
};

// ---------------------------------------------------

class ConcreteStateA : public State
{
public:
    void Handle1() ;

    void Handle2()  
    {
        std::cout << "ConcreteStateA handles request2.\n";
    }
};

class ConcreteStateB : public State
{
public:
    void Handle1() 
    {
        std::cout << "ConcreteStateB handles request1.\n";
    }

    void Handle2()  
    {
        std::cout << "ConcreteStateB handles request2.\n";
        std::cout << "ConcreteStateB wants to change the state of the context.\n";
        m_context->TransitionTo(new ConcreteStateA);
    }
};



void ConcreteStateA::Handle1()
{
        std::cout << "ConcreteStateA handles request1.\n";
        std::cout << "ConcreteStateA wants to change the state of the context.\n";
        m_context->TransitionTo(new ConcreteStateB);
}

void ClientCode()
{
    Context* context = new Context(new ConcreteStateA);
    context->Request1();
    context->Request2();
    delete context;
}

int main()
{
    std::cout <<"Hello !\n";
    ClientCode();
    return 0;
}