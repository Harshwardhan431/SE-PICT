#include <iostream>
using namespace std;

class heap
{
private:
    int a[50];
    int n;

public:
    int input()
    {

        cout << "enter no of elements : " << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "enter element : " << endl;
            cin >> a[i];
        }

        return a[50];
    }
    void display()
    {
        cout << "heapsorted array is : " << endl;
        for (int i = 0; i < n; i++)
        {

            cout << a[i] << endl;
        }
    }

    void heapsort()
    {
        // non leaf node value n/2-1
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(i, n);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            swap(a[i], a[0]);

            heapify(0, i);
        }
    }
    void heapify(int i, int n)
    {

        int index = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && a[l] > a[index])
        {
            index = l;
        }
        if (r < n && a[r] > a[index])
        {
            index = r;
        }
        if (index != i)
        {
            swap(a[i], a[index]);
            heapify(index, n);
        }
    }
};

int main()
{
    heap h;
    h.input();
    h.heapsort();
    h.display();
    
    return 0;
}