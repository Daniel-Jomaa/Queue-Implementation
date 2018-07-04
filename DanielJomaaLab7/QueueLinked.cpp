
#include "QueueLinked.h"

template <typename DataType>
QueueLinked<DataType>::QueueNode::QueueNode(const DataType& nodeData, QueueNode* nextPtr)
{
	dataItem = nodeData;
	next = nextPtr;
}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(int maxNumber = Queue<DataType>::MAX_QUEUE_SIZE)
{
	front = 0;
	back = 0;
}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(const QueueLinked& other)
{
	QueueNode *newNode, *otherBack, *otherFront;
	front = otherFront = other.front;
	back = otherBack = other.back; 

	while (otherFront != otherBack)
	{
		newNode = new QueueNode(otherBack.dataItem, NULL);
		back->next = newNode;
		otherFront = otherFront->next;		
	}
}

template <typename DataType>
QueueLinked<DataType>& QueueLinked<DataType>::operator=(const QueueLinked& other)
{
	QueueNode *newNode, *otherBack, *otherFront;
	front = otherFront = other.front;
	back = otherBack = other.back;

	while (otherFront != otherBack)
	{
		newNode = new QueueNode(otherBack.dataItem, NULL);
		back->next = newNode;
		otherFront = otherFront->next;
	}
	return this;
}

template <typename DataType>
QueueLinked<DataType>::~QueueLinked()
{
	clear();
}

template <typename DataType>
void QueueLinked<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
	//no full logic error, list will never be full

	QueueNode *newNode;

	newNode = new QueueNode(newDataItem, NULL);

	if (isEmpty())
	{
		front = newNode;
		back = newNode;
	}
	else {
		back->next = newNode;
		back = newNode;
	}

}

template <typename DataType>
DataType QueueLinked<DataType>::dequeue() throw (logic_error)
{
	if (isEmpty())
		throw logic_error("List is empty");

	QueueNode *del;
	DataType temp;
	temp = front->dataItem;
	del = front;
	front = front->next;
	delete del;

	return temp;
}

template <typename DataType>
void QueueLinked<DataType>::clear()
{
	QueueNode *del, *temp;

	temp = front;
	
	while (temp != back)
	{
		del = temp;
		temp = temp->next;
		delete del;
	}
	front = 0;
	back = 0;
}

template <typename DataType>
bool QueueLinked<DataType>::isEmpty() const
{
	if (front == 0)
		return true;
	else
		return false;
}

template <typename DataType>
bool QueueLinked<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void QueueLinked<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
	if (isEmpty())
		throw logic_error("list is empty");
	QueueNode *newNode;

	newNode = new QueueNode(newDataItem, front);
	
	front = newNode;
		
}

template <typename DataType>
DataType QueueLinked<DataType>::getRear() throw (logic_error)
{
	if (isEmpty())
		throw logic_error("list is empty");

	DataType temp;
	temp = back->dataItem;
	return temp;
}

template <typename DataType>
int QueueLinked<DataType>::getLength() const
{
	QueueNode *temp;
	temp = front;
	int i;

	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return i;
}

template <typename DataType>
void QueueLinked<DataType>::showStructure() const
{
	QueueNode *p;   // Iterates through the queue

	if (isEmpty())
		cout << "Empty queue" << endl;
	else
	{
		cout << "Front\t";
		for (p = front; p != 0; p = p->next)
		{
			if (p == front)
			{
				cout << '[' << p->dataItem << "] ";
			}
			else
			{
				cout << p->dataItem << " ";
			}
		}
		cout << "\trear" << endl;
	}
}