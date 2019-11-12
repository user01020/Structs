#include <iostream>
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
			cout << "input elements\n";
			int elem;
			while(is)
			{
				is >> elem;
				cout << elem << endl;
				this->push(elem);
			}	
		}
		queue(int arr[], int n)
		{
			for(int i = 0; i < n; i++)
			{
				this->push(arr[i]);
			}	
		}
		int printWithDelete()
		{
			int elem = EMPTY_ELEM;
			while((elem = this->pop()) != EMPTY_ELEM)
				cout << elem << endl;
			return 0;
		}
		int print()
		{
			int buf_uL = uL;
			if(this->printWithDelete())
				return 1;
			uL = buf_uL;
			return 0;
		}
		void clean()
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
			if(uL == uR + 1 || uR == uL + 1)	
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
			a[uL--] = elem;
			uL = (Size + uL) % Size;
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
			int elem = a[uR--];
			uL = (Size + uL) % Size;
			return elem;
		}
		int countOfElem()
		{
			return (Size + (uR - uL)) % Size;
		}
		void clean()
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
		}
		deque(int arr[], int n)
		{
			for(int i = 0; i < n; i++)
			{
				pushR(arr[i]);
			}
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
}