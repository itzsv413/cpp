#include <iostream>
using namespace std;
#define SIZE 20
struct BTNODE
{
    BTNODE*lc;
    char data;
    BTNODE*rc;
};
class STACK
{
   int top;
   BTNODE*stk[SIZE];
   public:
   STACK(){top=-1;}
   void push(BTNODE*temp);
   BTNODE* pop(void);
};
void STACK::push(BTNODE*temp)
{
    stk[top++]=temp;
}
BTNODE* STACK::pop(void)
{
    return(stk[top--]);
}
class BT;
class Expression
{
	char exp[50];
	int len;
	public:
	Expression(){len=0;}
	friend class BT;
	void accept(void)
	{
		cout<<"Enter Expression:";
		cin>>exp;
	}
	void display(void)
	{
		cout<<"Expression is:"<<exp;
	}
};
class BT
{
	BTNODE*root;
	public:
	BT(){root=NULL;}
	void createexptree(Expression &E);
	void preorder(BTNODE* node)
    	{
        if (node)
        {
            cout << node->data << " ";
            preorder(node->lc);
            preorder(node->rc);
        }
    	}
    	void inorder(BTNODE* node)
    	{
        if (node)
        {
            inorder(node->lc);
            cout << node->data << " ";
            inorder(node->rc);
        }
    	}
    	void postorder(BTNODE* node)
    	{
        	if (node)
        	{
            	postorder(node->lc);
            	postorder(node->rc);
           	 cout << node->data << " ";
        	}
    	}
	void traverse(void)
	{
		preorder(root);
		inorder(root);
		postorder(root);
	}
};
void BT::createexptree(Expression &E)
{
	STACK s;
	BTNODE*newnp;
	for(int i=0;i<E.len;i++)
	{
		newnp = new BTNODE;
		newnp->data=E.exp[i];
		newnp->lc=newnp->rc=NULL;
		if(isalpha(E.exp[i]))
			{s.push(newnp);}
		else
		{
			newnp->rc=s.pop();
			newnp->lc=s.pop();
			s.push(newnp);
		}
	}
	root=s.pop();
}
int main()
{
	Expression E;
    	E.accept();
    	BT T;
    	T.createexptree(E);
    	T.traverse();
    	E.display();
    	return 0;
 }
		
