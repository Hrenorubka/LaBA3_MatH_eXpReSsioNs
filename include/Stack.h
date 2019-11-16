#ifndef __STACK_H__
#define __STACK_H__

template <class ValType>
class Stack
{
private:
	ValType *stack;
	ValType *elem;
	int len_stack;
	void res_mem()
	{
		int dif = elem - stack;
		len_stack = len_stack + len_stack / 3 + 1;
		ValType *obl = new ValType[len_stack];
		for (int i = 0; i <= elem - stack; i++)
		{
			obl[i] = stack[i];
		}
		delete[] stack;
		stack = obl;
		elem = stack + dif;
	}
public:
	Stack()
	{
		len_stack = 9;
		stack = new ValType[len_stack];
		elem = NULL;
	}
	Stack(int len)
	{
		if (len < 1)
			throw 1;
		len_stack = len;
		stack = new ValType[len_stack];
		elem = NULL;
	}
	Stack(const Stack &s)
	{
		len_stack = s.len_stack;
		stack = new ValType[len_stack];
		elem = stack + (s.elem - s.stack);
		for (int i = 0; i <= elem - stack; i++)
		{
			stack[i] = s.stack[i];
		}
	}
	~Stack()
	{
		delete[] stack;
	}
	bool empty()
	{
		return (elem - stack < 0);
	}
	bool full()
	{
		return (elem - stack + 1 == len_stack);
	}
	int size()
	{
		if (elem == NULL)
			return 0;
		return elem - stack + 1;
	}
	ValType top()
	{
		if (elem - stack < 0)
			throw 1;
		return *elem;
	}
	void pop()
	{
		if (empty())
			throw 1;
		elem--;
	}
	void push(ValType inp)
	{
		if (full())
		{
			res_mem();
		}
		if (elem == NULL)
		{
			stack[0] = inp;
			elem = &stack[0];
		}
		else
		{
			elem++;
			*elem = inp;
		}

	}
};
#endif
