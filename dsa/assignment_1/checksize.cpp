
void SLList::checksize()
{
	if(this->head==nullptr)
	{
		cout<<"Empty";
		return;
	}
	int n=this->head->data;
	Node* temp=this->head;
	int l=0;
	
	while(temp!=nullptr)
	{
		temp=temp->next;
		l++;
	}
	
	if(l!=n)
		throw l;
	
	return;
}

void DLList::checksize()
{
	if(this->first==nullptr)
	{
		cout<<"Empty";
		return;
	}
	int n=this->first->data;
	Node* temp=this->first;
	int l=0;
	
	while(temp!=nullptr)
	{
		temp=temp->next;
		l++;
	}
	
	if(l!=n)
		throw l;
	
	return;
}