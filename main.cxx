#include "graphics.h"
#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node()
    {
        data = 0;
        next = NULL;
    }

};
    
class Stack
{
public:
    Node* top;

    Stack()
    {
        top = NULL;
    }
    bool is_Empty()
    {
        return (top == NULL);
    }
    void push(int x)
    {
        Node* nn = new Node();
        nn->data = x;
        nn->next = top;
        top = nn;
    }
    int pop()
    {
        if (is_Empty())
        {
            cout << "Stack is Empty\n";
            return false;
        }
        else
        {
            int x = 0;
            Node* temp = top;
            x = top->data;
            top = top->next;

            delete temp;
            temp = NULL;
            return x;
        }
    }
    void display()
    {
        Node* temp = top;

        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;

    }
};

class Queue
{
public:

    Node* front;
    Node* rear;

    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    bool is_empty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int x)
    {
        Node* nn = new Node();
        nn->data = x;
        nn->next = NULL;

        if (is_empty())
        {
            front = nn;
            rear = nn;
        }
        else
        {
            rear->next = nn;
            rear = nn;
        }
    }
    bool dequeue(int& x)
    {
        if (is_empty())
        {
            return false;
        }
        else
        {
            Node* temp = front;
            x = front->data;
            if (front->next == NULL)
            {
                rear = NULL;
                front = NULL;
                return 0;
            }
            temp = front->next;
            delete front;
            front = temp;

            return true;
        }
    }
    void display()
    {
        Node* curr = front;
        while (curr != NULL)
        {
            cout << curr->data << "  ";
            curr = curr->next;
        }
    }
    void makeNull()
    {
        int x = 0;
        while (!is_empty())
        {
            dequeue(x);
        }
    }
    ~Queue()
    {
        makeNull();
    }

};

class TreeNode
{
public:

    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:

    TreeNode* root;
    int curr_wid;

    //right sub tree coordinates movement
    int movementx;
    int movementy;
    int movelinex;
    int moveliney;

    //left sub tree coordinates movement
    int L_movementx;
    int L_movementy;
    int L_movelinex;
    int L_moveliney;
    int L_movetextx;
    int L_movetexty;
    int R_movetextx;
    int R_movetexty;


    BST(int x)
    {
        root = NULL;
        curr_wid = x;
        movementx =700;
        movementy = 90;
        movelinex = 100;
        moveliney = 50;
        L_movementx = 400;
        L_movementy = 100;
        L_movelinex = 0;
        L_moveliney = 0;
        L_movetextx = 380;
        L_movetexty = 100;
        R_movetextx = 680;
        R_movetexty = 100;
    }


    bool is_empty()
    {
        return (root == NULL);
    }

    void insert(int x)
    {
        TreeNode* nn = new TreeNode();
        nn->data = x;
        nn->left = nn->right = NULL;

        if (root == NULL)
        {
            root = nn;
            setcurrentwindow(curr_wid);
            setcolor(BLACK);
            circle(600, 30, 30);
            setcolor(RED);
            settextstyle(6, 0, 2);
            bgiout << nn->data << endl;
            outstreamxy(580, 20);
            //getch();
        }
        else
        {
            TreeNode* curr = root;
            while (true)
            {
                if (curr->data == x)
                {
                    initwindow(500, 250, "ALERT", 200,30);
                    readimagefile("dup.jpg", 0, 0, 500, 250);
                    cout << "Duplicate Nodes are not allowed!!\n";
                    getch();  
                    closegraph();
                    return;
                }
                else if (curr->data > x && curr->left == NULL)
                {
                    setcurrentwindow(curr_wid);
                  //setcolor(RED);
                  //line(520 + movelinex, 10 + moveliney, 570 + movelinex, 50 + moveliney);
                    setcolor(BLACK);
                    circle((L_movementx), (L_movementy), 30);
                    setcolor(RED);
                    settextstyle(6, 0, 2);
                    bgiout << nn->data << endl;
                    outstreamxy((L_movetextx), (L_movetexty));
                    L_movementx -= 200;
                    L_movementy += 100;
                    L_movetextx -= 200;
                    L_movetexty += 100;
                    /*movelinex -= 100;
                    moveliney -= 40;*/
                    curr->left = nn;
                    return;
                }
                else if (curr->data > x)
                {
                    curr = curr->left;
                }
                else if (curr->data < x && curr->right == NULL)
                {
                    setcurrentwindow(curr_wid);
                    setcolor(RED);
                  //  line(520 - movelinex, 10 - moveliney, 570 - movelinex, 50 - moveliney);
                    setcolor(BLACK);
                    circle((movementx), (movementy), 30);
                    setcolor(RED);
                    settextstyle(6, 0, 2);
                    bgiout << nn->data << endl;
                    outstreamxy((movementx), (movementy));
                    curr->right = nn;
                    movementx += 200;
                    movementy += 100;
                    R_movetextx += 200;
                    R_movetexty += 100;
                    movelinex += 100;
                    moveliney += 40;
                    return;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
    }

    void inorder(TreeNode* p)
    {
        if (p == NULL)
        {
            return;
        }
        inorder(p->left);
        cout << p->data << "  ";
        inorder(p->right);
    }
    void preorder(TreeNode* p)
    {
        if (p == NULL)
        {
            return;
        }
        cout << p->data << "  ";
        preorder(p->left);
        preorder(p->right);
    }
    void postorder(TreeNode* p)
    {
        if (p == NULL)
        {
            return;
        }
        postorder(p->left);
        postorder(p->right);
        cout << p->data << "  ";
    }
    TreeNode* Search(int key)
    {
        if (is_empty())
        {
            cout << "Tree is empty\n";
            return root;
        }
        else
        {
            TreeNode* temp = root;

            while (temp != NULL)
            {
                if (temp->data == key)
                {
                    return temp;
                }
                else if (temp->data < key)
                {
                    temp = temp->right;
                }
                else
                {
                    temp = temp->left;
                }
            }
            cout << "Node is not found!!\n";
            return NULL;
        }
    }
    TreeNode* getRoot()
    {
        return root;
    }

};


int main(void)
{
    //variables
    int choice = 0, ch_stack = 0, ch_queue = 0, val_stack = 0, index = 0, qx = 0;
    int stack_count = 0, queue_count = 0, push_count = 0, enqueue_count = 0, temp_q = 1;

    int ch_bst = 0;
    int stackarr[5];
    int queuearr[5];
    int treearr[10];
    char opt_stack;
    int move = 20;
    Queue q1;
    Stack s1;


jmp_menu:
    initwindow(1200, 650,"Main Menu");


    readimagefile("finalM.jpg", 0, 0, 1195, 650); //displaying menu
    cin >> choice;
    closegraph();
    if (choice == 1)
    {
        initwindow(1300, 650,"STACK Menu");
        readimagefile("Stack.jpg", 0, 0, 1300, 650);

        initwindow(1000, 650);         //stack visualizing window
        line(400, 200, 400, 600);
        line(600, 200, 600, 600);
        line(400, 600, 600, 600);
    }
    else if (choice == 2)
    {
        initwindow(1300, 650,"QUEUE Menu");
        readimagefile("Queue.jpg", 0, 0, 1300, 650);

        initwindow(1000, 650);         //stack visualizing window
        line(400, 200, 400, 500);
        line(600, 200, 600, 500);
    }


    if (choice == 1)
    {
        do
        {
            cin >> ch_stack;

            switch (ch_stack)
            {
            case 1:
                if (index == 5) //overflow error
                {
                    initwindow(1300, 650);
                    readimagefile("Stack.jpg", 0, 0, 1300, 650);
                    cout << "Stack is FULL!!!\n";
                    break;
                }

                cout << "Enter Value to be pushed: ";
                cin >> val_stack;
                move *= 2;
                stackarr[index] = val_stack;
                s1.push(val_stack);
                push_count++;

                for (int i = 0; i < 500; i++) //motion loop 
                {
                    setcolor(YELLOW);
                    settextstyle(6, 0, 4);
                    bgiout << val_stack << endl;
                    delay(0.7);
                    outstreamxy(i, (20 + i) - move);
                }




                setcolor(WHITE);
                line(400, 200, 400, 600);
                index++;
                break;
            case 2:
                stack_count++;
                index = 0;
                move = 20;
                if (stack_count < 5)
                {
                    initwindow(1000, 650);         //stack visualizing window
                    line(400, 200, 400, 600);
                    line(600, 200, 600, 600);
                    line(400, 600, 600, 600);

                    do
                    {
                        move *= 2;
                        val_stack = stackarr[index];
                        for (int i = 0; i < 500; i++)
                        {
                            setcolor(YELLOW);
                            settextstyle(6, 0, 4);
                            bgiout << val_stack << endl;
                            delay(0.7);
                            outstreamxy(i, (20 + i) - move);
                        }
                        setcolor(WHITE);
                        line(400, 200, 400, 600);
                        index++;

                    } while (index < (push_count - stack_count));
                    closegraph();
                }

                break;
            case 3:
                closegraph();
                goto jmp_menu;
                break;
            default:
                cout << "Inavlid Choice\n";
                break;
            }

            cout << "Are you want to continue operations(Y/N): ";
            cin >> opt_stack;

        } while (opt_stack == 'Y' || opt_stack == 'y');

        goto jmp_menu;
        closegraph();
    }
    else  if (choice == 2)
    {
        index = 0;
        do
        {
            cin >> ch_queue;

            switch (ch_queue)
            {
            case 1:
                if (index == 5) //overflow error
                {
                    initwindow(1300, 650);
                    readimagefile("Queue.jpg", 0, 0, 1300, 650);
                    cout << "Queue is FULL!!!\n";
                    break;
                }

                cout << "Enter Value to be Enqueue: ";
                cin >> val_stack;
                move *= 2;
                queuearr[index] = val_stack;
                q1.enqueue(val_stack);


                for (int i = 0; i < 500; i++) //motion loop 
                {
                    setcolor(YELLOW);
                    settextstyle(6, 0, 4);
                    bgiout << val_stack << endl;
                    delay(0.7);
                    outstreamxy(i, (20 + i) - move);
                }
                setcolor(WHITE);
                line(400, 200, 400, 500);
                index++;
                enqueue_count++;
                break;
            case 2:
                queue_count++;
                index = temp_q;
                temp_q++;
                move = 20;

                if (queue_count < 5)
                {
                    q1.dequeue(qx);
                    initwindow(1000, 650);         //stack visualizing window
                    line(400, 200, 400, 600);
                    line(600, 200, 600, 600);
                   // line(400, 600, 600, 600);

                    do //loop to printing all other enqueued values
                    {
                        move *= 2;
                        val_stack = queuearr[index];
                        for (int i = 0; i < 500; i++)
                        {
                            setcolor(YELLOW);
                            settextstyle(6, 0, 4);
                            bgiout << val_stack << endl;
                            delay(0.7);
                            outstreamxy(i, (20 + i) - move);
                        }
                        setcolor(WHITE);
                        line(400, 200, 400, 500);
                        index++;

                    } while (index < enqueue_count);
                    closegraph();

                }

                break;
            case 3:
                closegraph();
                goto jmp_menu;
                break;
            default:
                cout << "Inavlid Choice\n";
                break;
            }

            cout << "Are you want to continue operations(Y/N): ";
            cin >> opt_stack;

        } while (opt_stack == 'Y' || opt_stack == 'y');

        goto jmp_menu;

        closegraph();
    }
    else  if (choice == 3)
    {
        int curr_wid = 0;

        curr_wid = initwindow(1200, 600, "Tree Visualizer");
        setbkcolor(15);
        setfillstyle(SOLID_FILL, 15);
        floodfill(1, 1, 15);

        BST b1(curr_wid);
        int count = 0;
        do
        {
            initwindow(1300, 650, "BST Menu");
            readimagefile("bst.jpg", 0, 0, 1300, 650);
           // getch();
            //closegraph();
            cin >> ch_bst;
            
            switch (ch_bst)
            {
            case 1:
                cout << "Enter Value: ";
                cin >> val_stack;
                treearr[count] = val_stack;
                b1.insert(val_stack);
                break;
            case 2:
               
                break;
            case 3:
                cout << "Enter Value to be seached: ";
                cin >> val_stack;
                for (int i = 0; i < 10; i++)
                {
                    if (val_stack == treearr[i])
                    {
                        cout << "Node found!\n";
                    }
                }
                
                break;
            case 4:
                cout << "preorder: ";
                b1.inorder(b1.root);
                cout << endl;
                break;
            case 5:
                cout << "postorder: ";
                b1.inorder(b1.root);
                cout << endl;
                break;
            case 6:
                cout << "inorder: ";
                b1.inorder(b1.root);
                cout << endl;
                break;

            default:
                break;
            }

            cout << "Are you want to continue operations(Y/N): ";
            cin >> opt_stack;

        } while (opt_stack == 'Y' || opt_stack == 'y');

        goto jmp_menu;
    }
    else  if (choice == 4)
    {
            /*AVL*/
    }
    else  if (choice == 5)
    {
        cout << "\n\nThank You!\n";

    }

    
    closegraph();
    getch();

    return 0;

}