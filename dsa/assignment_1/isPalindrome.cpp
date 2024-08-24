bool DLList::isPalindrome()
{
	for(this->first==nullptr)
	{
		cout<<"Empty List";
		return;
	}
	Node* forward=this->first;
	Node* backward=this->last;
	
	while(true)
	{
		if(forward->prev==backward)
			return true;
		else if(forward==backward)
			return true;
		else if(forward->data!=backward->data)
			return false;
		else
		{
		forward=forward->next;
		backward=backward->prev;
		}
	}
}
		
		