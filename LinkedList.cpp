// LinkedList.cpp

// tom bailey   0745  5 oct 2010
// Definition of methods for the List class.

#include "LinkedList.h"

#include <utility>


List::List()
	: first_(NULL)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}

const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}

/*bool List::operator==(const List &rhs){
    if(size() == 0 && rhs.size() == 0){return true;}//both empty
    if(size() != rhs.size()){return false;}//sizes not the same

    Node * lptr = this->next_;
    Node * rptr = rhs->next_;
		Double lEntry = lptr->entry_;
    Double rEntry = rptr->entry_;
		while (lptr != NULL && rptr != NULL)
		{
      if(lEntry != rEntry){
        return false;
      }
      lptr = lptr->next_;
      rptr = rptr->next_;
      lEntry = lptr->entry_;
      rEntry = rptr->entry_;
		}

  	return true;
}*/


bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(BigFloat x)
{
	first_ = new Node(x, first_);
}


BigFloat List::removeFirst()
{
	BigFloat item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}

//This is the start of my code.
BigFloat List::size()
{
	BigFloat count = 1;

	if (!empty())
	{
		Node * ptr = first_->next_;

		while (ptr != NULL)
		{
			ptr = ptr->next_;
			count = count + 1;
		}
	}
	else
	{
		count = 0;
	}
	return count;
}

BigFloat List::sum()
{
	BigFloat sum = 0;

	if (!empty())
	{
		Node * ptr = first_;

		while (ptr != NULL)
		{
			sum = sum + ptr->entry_;

			ptr = ptr->next_;
		}
	}
	else
	{
		sum = 0;
	}
	return sum;
}

void List::insertAsLast(BigFloat x)
{
	if (empty())
	{
		first_ = new Node(x, first_);
	}
	else
	{
		Node * ptr = first_->next_;

		while (ptr->next_ != NULL)
		{
			ptr = ptr->next_;
		}
		ptr->next_ = new Node(x, NULL);
	}
}

BigFloat List::max()
{
	BigFloat tempValue = 0;
	if (!empty())
	{
		Node * ptr = first_;

		while (ptr != NULL)
		{
			if (tempValue < ptr->entry_)
			{
				tempValue = ptr->entry_;
			}
			ptr = ptr->next_;
		}
		return tempValue;
	}
	else
	{
		cout << "No values. Unable to compute max." << endl;
		return 0;
	}
}

BigFloat List::min()
{
	if (!empty())
	{
		Node * ptr = first_;
		BigFloat tempValue = first_->entry_;
		while (ptr != NULL)
		{
			if (tempValue > ptr->entry_)
			{
				tempValue = ptr->entry_;
			}
			ptr = ptr->next_;
		}
		return tempValue;
	}
	else
	{
		cout << "No values. Unable to compute min." << endl;
		return 0;
	}
}

// Insert the values of the list calling the function into
// the list in the parameter.
// Ex: list1.insert(list2) means
// the information in list1 goes into list2.
void List::insert(List & other)
{
	if (!empty())
	{
		Node * ptr = first_;

		while (ptr != NULL)
		{
			other.insertAsFirst(ptr->entry_);
			ptr = ptr->next_;
		}
	}
	else
	{
		cout << "No values. Unable to insert." << endl;
	}
}
//This is the end of my code.

// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}
