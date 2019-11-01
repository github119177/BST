#include<iostream>

using namespace std;

class BST
{
public:

    struct Node
    {
        int data;
        Node* left;
        Node* right;
    };


public:
    Node* root=NULL;
    BST()
    {
        left=new Node();
        right=new Node();
    }


    void Delete(Node* root,int v)
    {

        Node* currentNode=new Node();
        Node* parentNode=new Node();
        currentNode=root;
        parentNode=NULL;
        while(currentNode!=NULL)
        {

            if(v==currentNode->data)
            {
                if(currentNode->left==NULL && currentNode->right==NULL)
                {
                    delete currentNode;
                    if(v<parentNode->data)
                    {
                        parentNode->left=NULL;
                    }
                    else
                    {
                        parentNode->right=NULL;
                    }
                    return root;

                }
                else if(currentNode->left!=NULL && currentNode->right==NULL)
                {
                    if(v<parentNode->data)
                    {
                        parentNode->left=currentNode->left;
                    }
                    else
                    {
                        parentNode->right=currentNode->right;
                    }
                    delete currentNode;
                    return root;
                }

                else if(currentNode->left==NULL && currentNode->right!=NULL)
                {
                    if(v<parentNode->data)
                    {
                        parentNode->left=currentNode->left;
                    }
                    else
                    {
                        parentNode->right=currentNode->right;
                    }
                    delete currentNode;
                    return root;
                }
                else if(currentNode->left!=NULL && currentNode->right!=NULL)
                {
                    Node* cheakNode=new Node();
                    cheakNode=currentNode->right;
                    Node* successor=new Node();
                    Node* parent=new Node();

                    if(cheakNode->left==NULL)
                    {
                        currentNode->data=cheakNode->data;
                        currentNode->right=cheakNode->right;
                        delete cheakNode;
                        return root;
                    }
                    successor=cheakNode->left;
                    parent=cheakNode;

                    while(successor->left!=NULL)
                    {

                        parent=successor;
                        successor=successor->left;


                    }


                    currentNode->data=successor->data;
                    parent->left=successor->right;

                    delete successor;
                    return root;

                }

            }

            parentNode=currentNode;
            if(v<currentNode->data)
            {
                currentNode=currentNode->left;
            }
            else
            {
                currentNode=currentNode->right;
            }
        }
        return root;

    }

    Node* Insert(int v,Node* root)
    {

        Node* temp=new Node();
        temp->data=v;
        temp->left=NULL;
        temp->right=NULL;
        if(root==NULL)
        {
            root=temp;
        }
        else

        {
            Node* currentNode=new Node();
            Node* parentNode=new Node();
            currentNode=root;
            parentNode=NULL;
            while(currentNode!=NULL)
            {
                parentNode=currentNode;
                if(currentNode->data>=v)
                {

                    currentNode=currentNode->left;
                }

                else
                {
                    currentNode=currentNode->right;
                }
            }

            if(v<=parentNode->data)
            {
                parentNode->left=temp;
            }
            else
            {
                parentNode->right=temp;
            }


        }

        return root;
    }

    void Inorder(Node* root)
    {
        if(root==NULL)
        {
            return;
        }
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }

    void Search(int v)
    {

    }
};

int main()

{
    Node bst;
    Node* root=NULL;
    bst.Insert(20,root);
    cout<<"1.Insert"<<endl;
    cout<<"2.Delete"<<endl;
    cout<<"3.Inorder"<<endl;
    cout<<"4.Search"<<endl;
    cout<<"5.FindMax"<<endl;
    cout<<"6.FindMin"<<endl;
    cout<<"7.Preorder"<<endl;
    cout<<"8.Postorder"<<endl;



    while(1)
    {
        cout<<"choice:: "<<endl;

        int c;

        cin>>c;

        if(c==1)
        {
            int v;
            cout<<"Inserting value enter"<<endl;
            cin>>v;

            root=bst.Insert(v,root);
        }
        else if(c==2)
        {
            cout<<"Delete value:"<<endl;
            int x;
            cin>>x;

            root=bst.Delete(root,x);
        }
        else if(c==3)
        {
            if(root!=NULL)
            {
                cout<<"data of root "<<root->data<<endl;

            }
            bst.Inorder(root);
            cout<<endl;
        }
    }
    return 0;
}
