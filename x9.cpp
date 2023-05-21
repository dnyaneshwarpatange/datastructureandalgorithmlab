#include <iostream>
#include <string.h>
using namespace std;

class dict
{
private:
    string s1, s2;
    dict *root, *left, *right;

public:
    dict()
    {
        root = NULL;
        left = NULL;
        right = NULL;
    }
    void input();
    void createRoot(dict *, dict *);
    void checkSame(dict *, dict *);
    void inputDisplay();
    void display(dict *);
    void inputRemove();
    dict *remove(dict *, string);
    dict *findMin(dict *);
    void inputFind();
    dict *find(dict *, string);
    void inputUpdate();
    dict *update(dict *, string);
};

void dict::input()
{
    dict *node = new dict;
    cout << "\nEnter the keyword: ";
    cin >> node->s1;
    cout << "Enter the meaning of the keyword: ";
    cin.ignore();
    getline(cin, node->s2);
    createRoot(root, node);
}

void dict::createRoot(dict *tree, dict *node)
{
    int result = node->s1.compare(tree->s1);
    checkSame(tree, node);
    if (root == NULL)
    {
        root = node;
        cout << "\nRoot node created successfully" << endl;
        return;
    }
    if (result > 0)
    {
        if (tree->left != NULL)
        {
            createRoot(tree->left, node);
        }
        else
        {
            tree->left = node;
            node->left = NULL;
            node->right = NULL;
            cout << "Node added to the left of " << tree->s1 << "\n";
            return;
        }
    }
    else if (result < 0)
    {
        if (tree->right != NULL)
        {
            createRoot(tree->right, node);
        }
        else
        {
            tree->right = node;
            node->left = NULL;
            node->right = NULL;
            cout << "Node added to the right of " << tree->s1 << "\n";
            return;
        }
    }
}

void dict::checkSame(dict *tree, dict *node)
{
    if (tree->s1 == node->s1)
    {
        cout << "The word you entered already exists.\n";
    }
    else if (tree->s1 > node->s1)
    {
        if (tree->left != NULL)
        {
            checkSame(tree->left, node);
        }
    }
    else if (tree->s1 < node->s1)
    {
        if (tree->right != NULL)
        {
            checkSame(tree->right, node);
        }
    }
}

void dict::inputDisplay()
{
    if (root != NULL)
    {
        cout << "The words entered in the dictionary are:\n\n";
        display(root);
    }
    else
    {
        cout << "\nThere are no words in the dictionary.\n";
    }
}

void dict::display(dict *tree)
{
    if (tree == NULL)
    {
        return;
    }
    display(tree->left);
    cout << tree->s1 << " = " << tree->s2 << "\n\n";
    display(tree->right);
}

void dict::inputRemove()
{
    if (root != NULL)
    {
        string keyword;
        cout << "\nEnter a keyword to be deleted: ";
        cin >> keyword;
        root = remove(root, keyword);
    }
    else
    {
        cout << "\nThere are no words in the dictionary.\n";
    }
}

dict *dict::remove(dict *tree, string keyword)
{
    if (tree == NULL)
    {
        cout << "\nWord not found.\n";
        return tree;
    }
    int result = keyword.compare(tree->s1);
    if (result < 0)
    {
        tree->left = remove(tree->left, keyword);
    }
    else if (result > 0)
    {
        tree->right = remove(tree->right, keyword);
    }
    else
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            delete tree;
            tree = NULL;
        }
        else if (tree->left == NULL)
        {
            dict *temp = tree;
            tree = tree->right;
            delete temp;
        }
        else if (tree->right == NULL)
        {
            dict *temp = tree;
            tree = tree->left;
            delete temp;
        }
        else
        {
            dict *temp = findMin(tree->right);
            tree->s1 = temp->s1;
            tree->s2 = temp->s2;
            tree->right = remove(tree->right, temp->s1);
        }
    }
    return tree;
}

dict *dict::findMin(dict *tree)
{
    while (tree->left != NULL)
    {
        tree = tree->left;
    }
    return tree;
}

void dict::inputFind()
{
    if (root != NULL)
    {
        string keyword;
        cout << "\nEnter the keyword to be searched: ";
        cin >> keyword;
        dict *result = find(root, keyword);
        if (result != NULL)
        {
            cout << "Word found.\n";
            cout << result->s1 << ": " << result->s2 << "\n";
        }
    }
    else
    {
        cout << "\nThere are no words in the dictionary.\n";
    }
}

dict *dict::find(dict *tree, string keyword)
{
    if (tree == NULL)
    {
        cout << "\nWord not found.\n";
        return tree;
    }
    int result = keyword.compare(tree->s1);
    if (result == 0)
    {
        return tree;
    }
    else if (result < 0)
    {
        return find(tree->left, keyword);
    }
    else
    {
        return find(tree->right, keyword);
    }
}

void dict::inputUpdate()
{
    if (root != NULL)
    {
        string keyword;
        cout << "\nEnter the keyword to be updated: ";
        cin >> keyword;
        dict *result = find(root, keyword);
        if (result != NULL)
        {
            cout << "\nEnter the updated meaning of the keyword: ";
            cin.ignore();
            getline(cin, result->s2);
            cout << "\nThe meaning of '" << keyword << "' has been updated.\n";
        }
    }
    else
    {
        cout << "\nThere are no words in the dictionary.\n";
    }
}

int main()
{
    int ch;
    dict d;
    do
    {
        cout << "\n==========================================\n"
             << "\n********DICTIONARY***********:\n"
             << " 1. Add new keyword.\n"
             << " 2. Display the contents of the Dictionary.\n"
             << " 3. Delete a keyword.\n"
             << " 4. Find a keyword.\n"
             << " 5. Update the meaning of a keyword.\n"
             << " 6. Exit.\n"
             << "==========================================\n";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            d.input();
            break;
        case 2:
            d.inputDisplay();
            break;
        case 3:
            d.inputRemove();
            break;
        case 4:
            d.inputFind();
            break;
        case 5:
            d.inputUpdate();
            break;
        default:
            cout << "\nPlease enter a valid option!\n";
            break;
        }
    } while (ch != 6);

    return 0;
}
