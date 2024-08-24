class Queue
{
	Stack s1,s2;
	int rear;
	public:
	Queue()
	{
		rear=-1;
	}
	bool isEmpty()
	{
		return (rear==-1)
	}
	void push(int data)
	{
		s1.push(data);
		rear++;
	}
	int pop()
	{
		while(!s1.isEmpty())
		{
			s2.push(s1.pop());
		}
		int data=s2.pop();
		while(!s2.isEmpty())
		{
			s1.push(s2.pop());
		}
		rear--;
		return data;
	}
	int peek()
	{
		while(!s1.isEmpty())
		{
			s2.push(s1.pop());
		}
		int data=s2.peek();
		while(!s2.isEmpty())
		{
			s1.push(s2.pop());
		}
		return data;
	}
	
}

