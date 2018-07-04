
#include "QueueArray.h"

template <typename DataType>
QueueArray<DataType>::QueueArray(int maxNumber)
{
	maxSize = maxNumber;
	dataItems = new DataType[maxSize];
	front = -1;
	back = -1;
}

template <typename DataType>
QueueArray<DataType>::QueueArray(const QueueArray& other)
{
	int cursor = 0;	
	dataItems = new DataType[maxSize];
	front = -1;
	back = -1;
	
	while (other.back != other.front)
	{
		dataItems[cursor] = other.dataItems[cursor];
		cursor++;
	}

}

template <typename DataType>
QueueArray<DataType>& QueueArray<DataType>::operator=(const QueueArray& other)
{
	int cursor = 0;
	front = -1;
	back = -1;
	dataItems = new DataType[maxSize];
	while (cursor != other.back)
	{
		dataItems[cursor] = other.dataItems[cursor];
		cursor++;
	}
	return this;
}

template <typename DataType>
QueueArray<DataType>::~QueueArray()
{
	delete[] dataItems;
}


template <typename DataType>
void QueueArray<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
	if (isFull())
		throw logic_error("List is Full");

	if (isEmpty())
		front = back = 0;
	else
		back = (back + 1) % maxSize;

	dataItems[back] = newDataItem;

}

template <typename DataType>
DataType QueueArray<DataType>::dequeue() throw (logic_error)
{
	DataType temp;

	if (isEmpty())
		throw logic_error("List is empty");
	else if (front == back)
		back = front = -1;
	else
	{
	
		temp = dataItems[front];
		front = (front + 1) % maxSize;
	}	
	return temp;
}

template <typename DataType>
void QueueArray<DataType>::clear()
{
	front = back = -1;
}

template <typename DataType>
bool QueueArray<DataType>::isEmpty() const
{

	if (front == -1 && back == -1)
		return true;
	else
		return false;
}

template <typename DataType>
bool QueueArray<DataType>::isFull() const
{
	return (back + 1) % maxSize == front ? true : false;
}

template <typename DataType>
void QueueArray<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
	if (isEmpty())
		throw logic_error("List is Empty");	

	dataItems[front] = newDataItem;
	
}
template <typename DataType>
DataType QueueArray<DataType>::getRear() throw (logic_error)
{
	if (isEmpty())
		throw logic_error("This is Empty");
	DataType temp;
	temp = dataItems[back];
	return temp;
}

template <typename DataType>
int QueueArray<DataType>::getLength() const
{
	int count;
	for (int i = front; i <= back; i++)
	{
		count++;
	}
	return count;
}

//--------------------------------------------------------------------

template <typename DataType>
void QueueArray<DataType>::showStructure() const
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
	int j;   // Loop counter

	if (front == -1)
		cout << "Empty queue" << endl;
	else
	{
		cout << "Front = " << front << "  Back = " << back << endl;
		for (j = 0; j < maxSize; j++)
			cout << j << "\t";
		cout << endl;
		if (back >= front)
			for (j = 0; j < maxSize; j++)
				if ((j >= front) && (j <= back))
					cout << dataItems[j] << "\t";
				else
					cout << " \t";
		else
			for (j = 0; j < maxSize; j++)
				if ((j >= front) || (j <= back))
					cout << dataItems[j] << "\t";
				else
					cout << " \t";
		cout << endl;
	}
}