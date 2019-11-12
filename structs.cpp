#include <iostream>
#include <limits>

#define N 100
#define EMPTY_ELEM 0
using namespace std;
	//Круговая модель очереди
class queue{
	private:
		int a[N];
		int uL = 0, uR = 0;
		int Size = N;
	public:
		int isEmpty()
		{
			if(uL == uR)
				return 1;
			else
				return 0;
		}
		int push(int elem)
		{
			if(uL == (uR + 1) % Size)
			{
				cout << "queue overflow\n";
				return 1;
			}
			a[uR++] = elem;
			return 0;
		}
		int read()		//чтение конца очереди
		{
			if(this->isEmpty())
			{
				cout << "queue is empty\n";
				return EMPTY_ELEM;
			}
			return a[uL];
		}
		int pop()
		{
			int elem = this->read();
			uL++;
			return elem;
		}
		queue(){}
		queue(istream &is)
		{
			cout << "input queue\n";
			int elem;
			while(is)
			{
				is >> elem;
				this->push(elem);
			}
        //отчистка потока
			cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //отчистка потока
		}
		queue(int arr[], int n)
		{
			for(int i = 0; i < n; i++)
			{
				this->push(arr[i]);
			}
		}
		void printWithDelete()
		{
			int elem = EMPTY_ELEM;
			while((elem = this->pop()) != EMPTY_ELEM)
				cout << elem << endl;
		}
		int print()
		{
			int buf_uL = uL;
			this->printWithDelete();
			uL = buf_uL;
		}
		void clear()
		{
			uL = uR = 0;
		}
};
class deque{
	private:
		int a[N];
		int uL = 0, uR = 0;
		int Size = N;
		bool Empty = 1, Overflow = 0; //предупреждение о теущем или предстоящем пустоте/переполнении
		void setFlagEmpty() //определяет возможную пустоту в будущем
		{
			if(uL == (uR + 1) % Size || uR == (uL + 1) % Size)
				Empty = 1;
			else
				Empty = 0;
		}
		void setFlagOverflow() //определяет возможное переполнение в будущем
		{
			if(uL == uR + 1 || uR == uL + 1)
				Overflow = 1;
			else
				Overflow = 0;
		}
	public:
		int isEmpty()
		{
			if(Empty && uL == uR)
			{
				Overflow = 0;
				return 1;
			}
			setFlagEmpty();
			return 0;
		}
		int isOverflow()
		{
			if(Overflow && uL == uR)
			{
				Empty = 0;
				return 1;
			}
			setFlagOverflow();
			return 0;
		}

		int pushL(int elem)
		{
			if(this->isOverflow())
			{
				cout << "deque overflow\n";
				return 1;
			}
			--uL;
			uL = (Size + uL) % Size;
            a[uL] = elem;
		}
		int pushR(int elem)
		{
			if(this->isOverflow())
			{
				cout << "deque overflow\n";
				return 1;
			}
			a[uR++] = elem;
			uR = uR % Size;
		}
		int popL()
		{
			if(this->isEmpty())
			{
				cout << "qeque is empty\n";
				return EMPTY_ELEM;
			}
			int elem = a[uL++];
			uL = uL % Size;
			return elem;
		}
		int popR()
		{
			if(this->isEmpty())
			{
				cout << "qeque is empty\n";
				return EMPTY_ELEM;
			}
			--uR;
			uR = (Size + uR) % Size;
            int elem = a[uR];
			return elem;
		}

		int countOfElem()
		{
			return (Size + (uR - 1 - uL)) % Size;
		}
		void clear()
		{
			uL = uR = 0;
		}
		deque(){}
		deque(istream &is)
		{
			int elem;
			cout << "input deque (from left to right)\n";
			while(is)
			{
				is >> elem;
				pushR(elem);
			}
        //отчистка потока
			cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //отчистка потока

		}
		deque(int arr[], int n)
		{
			for(int i = 0; i < n; i++)
			{
				pushR(arr[i]);
			}
		}
		void printWithDelete()
		{
		    int elem;
		    while((elem = popL()) != EMPTY_ELEM)
            {
                cout << elem << endl;
            }
		}
		void print()
		{
		    cout << "uL = " << uL << endl <<
                    "uR = " << uR << endl;
		    int buf_uL = uL;
		    printWithDelete();
		    uL = buf_uL;
		}
};
int main()
{
	queue queue1(cin);
	queue queue2(cin);
	cout << "queue1:\n";
	queue1.print();
	cout << "queue2:\n";
	queue2.print();
/////////////////////////////////////////////////////
    /*deque deque1(cin);
    cout << "deque:\n";
    deque1.print();

    int n = deque1.countOfElem();
    cout << "count of elem = " << n << endl;

    deque1.clear();
    cout << "deque after clear:";
    deque1.print();*/
    deque deque1;
    int exit = 0;
    while(exit == 0)
    {
        cout << "demonstrathion function pushL(), pushR(), popL(), popR():\n";
        cout << "1)pushL()" << endl;
        cout << "2)pushR()" << endl;
        cout << "3)popL()" << endl;
        cout << "4)popR()" << endl;
        cout << "5)print deque" << endl;
        cout << "6)clear()" << endl;
        cout << "7)exit" << endl;

        cout << "input number:";
        int var;
        cin >> var;
        int elem;
        switch(var){
            case 1: cout << "input element:";
                    cin >> elem;
                    cout << elem << endl;
                    deque1.pushL(elem);
                    break;
            case 2: cout << "input element:";
                    cin >> elem;
                    cout << elem << endl;
                    deque1.pushR(elem);
                    break;
            case 3: elem = deque1.popL();
                    cout << "element = " << endl;
                    break;
            case 4: elem = deque1.popR();
                    cout << "element = " << endl;
                    break;
            case 5: cout << "deque:" << endl;
                    deque1.print();
                    break;
            case 6: deque1.clear();
                    break;
            case 7: exit = 1;
                    break;
        }
    }
}
