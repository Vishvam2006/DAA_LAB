#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int v)
    {
        data = v;
        next = NULL;
    }
};

Node *addFront(Node *head, int v)
{
    Node *temp = new Node(v);
    temp->next = head;
    return temp;
}

Node *removeZero(Node *head)
{
    while (head && head->data == 0 && head->next)
        head = head->next;
    return head;
}

void show(Node *head)
{
    if (!head)
        return;
    show(head->next);
    cout << head->data;
}

Node *addList(Node *a, Node *b)
{
    Node *head = NULL;
    Node *tail = NULL;
    int carry = 0;
    while (a || b || carry)
    {
        int sum = carry;
        if (a)
        {
            sum += a->data;
            a = a->next;
        }
        if (b)
        {
            sum += b->data;
            b = b->next;
        }
        Node *temp = new Node(sum % 10);
        carry = sum / 10;
        if (!head)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

int compareList(Node *a, Node *b)
{
    int len1 = 0, len2 = 0;
    Node *p = a;
    Node *q = b;
    while (p)
    {
        len1++;
        p = p->next;
    }
    while (q)
    {
        len2++;
        q = q->next;
    }
    if (len1 > len2)
        return 1;
    if (len1 < len2)
        return -1;
    p = a;
    q = b;
    while (p && q)
    {
        if (p->data > q->data)
            return 1;
        if (p->data < q->data)
            return -1;
        p = p->next;
        q = q->next;
    }
    return 0;
}

Node *subtractList(Node *a, Node *b)
{
    Node *head = NULL;
    Node *tail = NULL;
    int borrow = 0;
    while (a)
    {
        int diff = a->data - borrow;
        if (b)
        {
            diff = diff - b->data;
            b = b->next;
        }
        if (diff < 0)
        {
            diff = diff + 10;
            borrow = 1;
        }
        else
            borrow = 0;
        Node *temp = new Node(diff);
        if (!head)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
        a = a->next;
    }
    return removeZero(head);
}

Node *multiplyList(Node *a, Node *b)
{
    Node *result = new Node(0);
    Node *pb = b;
    int shift = 0;
    while (pb)
    {
        Node *temp = NULL;
        Node *tail = NULL;
        for (int i = 0; i < shift; i++)
        {
            Node *zero = new Node(0);
            if (!temp)
                temp = tail = zero;
            else
            {
                tail->next = zero;
                tail = zero;
            }
        }   
        Node *pa = a;
        int carry = 0;
        while (pa || carry)
        {
            int prod = carry;
            if (pa)
            {
                prod += pa->data * pb->data;
                pa = pa->next;
            }
            Node *node = new Node(prod % 10);
            carry = prod / 10;
            if (!temp)
                temp = tail = node;
            else
            {
                tail->next = node;
                tail = node;
            }
        }
        result = addList(result, temp);
        pb = pb->next;
        shift++;
    }
    return removeZero(result);
}

Node *powerList(Node *base, int exp)
{
    Node *ans = new Node(1);
    for (int i = 0; i < exp; i++)
        ans = multiplyList(ans, base);
    return ans;
}

Node *build(string s)
{
    Node *head = NULL;
    for (int i = 0; i < s.length(); i++)
        head = addFront(head, s[i] - '0');
    return head;
}

int main()
{
    string a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    Node *n1 = build(a);
    Node *n2 = build(b);
    cout << "Addition: ";
    show(addList(n1, n2));
    cout << endl;
    cout << "Subtraction: ";
    if (compareList(n1, n2) >= 0)
    {
        show(subtractList(n1, n2));
    }
    else
    {
        cout << "-";
        show(subtractList(n2, n1));
    }
    cout << endl;
    cout << "Multiplication: ";
    show(multiplyList(n1, n2));
    cout << endl;
    int e;
    cout << "Enter exponent: ";
    cin >> e;
    cout << "Power: ";
    show(powerList(n1, e));
    cout << endl;
    return 0;
}
