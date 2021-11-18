#include <iostream>

using namespace std;

template <class T>
struct stackData
{
    T data;
    stackData<T> *next;
};

template <class T>
class stackList
{

private:
    stackData<T> *head;

public:
    stackList()
    {
        head = NULL;
    }

    stackData<T>* getHead()
    {
        return head;
    }

    void Push(T element)
    {
        if (isempty())
        {
            //if stack was empty
            stackData<T> *temp = new stackData<T>;

            temp->data = element;
            temp->next = NULL;

            head = temp;
        }
        else
        {
            //if stack was empty
            stackData<T> *temp = new stackData<T>;

            temp->data = element;
            temp->next = head;

            head = temp;
        }
    }

    T Pop()
    {
        T toreturn;

        if (isempty())
        {
            cout << "\n\t\t Stack is empty --- no element " << endl;
            return -1;
        }
        else
        {

            //if stack was empty
            stackData<T> *temp = head;

            head = head->next;
            toreturn = temp->data;
            delete temp;

            return toreturn;
        }
    }

    bool isempty()
    {
        if (head == NULL)
        {
            return true; //empty
        }

        return false; //not empty
    }

    void clear()
    {
        while (!isempty())
        {
            Pop();
        }
    }

    void Peak()
    {

        if (isempty())
        {
            cout << "\n\t\t Stack is empty --- no element " << endl;
        }
        else
        {

            cout << "\n\t\t Value at head is : " << head->data << endl;
        }
    }
};

void bracketChecker();

int main()
{

    bracketChecker();
    cout << endl;

    return 0;
}

void bracketChecker()
{

    stackList<char> bracketStack;

    //for taking the input
    char expression[100];

    //taking the input
    cout << "\n\t\t Enter the expression : ";
    cin.get(expression, 100, '\n');

    //push braces to stack
    for (int i = 0; i < 100 && expression[i] != '\0'; i++)
    {
        //checking opening braces and pushing them only
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            bracketStack.Push(expression[i]);
        }
    }

    char comparewith;
    char fromstack;
    bool correct = 1;

    //after pushing all now checking on the each closing in the expression
    for (int i = 0; i < 100 && expression[i] != '\0'; i++)
    {
        //checking opening braces and pushing them only
        if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if (!bracketStack.isempty())
            {

                //finding the corresponding opening braces
                if (expression[i] == ')')
                {
                    comparewith = '(';
                }

                if (expression[i] == '}')
                {
                    comparewith = '{';
                }

                if (expression[i] == ']')
                {
                    comparewith = '[';
                }

                if (bracketStack.Pop() == comparewith)
                {

                    continue;
                }
                else
                {
                    correct = 0;
                    cout << "\n\t\t Expression misses the bracket --- Invalid expression " << endl;
                    break;
                }
            }
            else
            {
                correct = 0;
                cout << "\n\t\t Expression misses the bracket --- Invalid expression  " << endl;
            }
        }
    }

    if(!bracketStack.isempty())
    {
        correct = 0;
        cout << "\n\t\t Expression misses the bracket --- Invalid expression  " << endl;
            
    }

    if (correct == 1)
    {
        cout << "\n\t\t Expression is valid " << endl;
    }

    bracketStack.clear();
}


