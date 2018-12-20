#include <iostream>
#include <vector>
using namespace std;

vector<int> result;

// totalWeight = w1 + w2 + w3 + ... + wn
// find all the solution
void backpack(int array[], int startIndex, int endIndex, int totalWeight)
{
    if (totalWeight == 0)
    {
        for (std::vector<int>::iterator i = result.begin(); i != result.end(); ++i)
        {
            cout << (*i) << " ";
        }
        cout << endl;
        return;
    }
    else if (totalWeight < 0)
        return;

    for (int i = startIndex; i <= endIndex; ++i)
    {
        result.push_back(array[i]);
+        backpack(array, i+1, endIndex, totalWeight-array[i]);
        result.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    int buffer[100] = {0};
    int temp = 0;

    int i = 0;
    cout << "Please enter the weights: (end with 0)" << endl;
    while (true)
    {
        cin >> temp;
        if (temp)
            buffer[i] = temp;
        else
            break;
        ++i;
    } 

    int total = 0;
    cout << "Please enter the totalWeight:" << endl;
    cin >> total;

    cout << "Result:" << endl;
    backpack(buffer, 0, i, total);

    return 0;
}