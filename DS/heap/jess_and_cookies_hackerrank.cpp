#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

vector<string> split_string(string);

void printQ(priority_queue<int, vector<int>, greater<int>>& pQ) {
    while (pQ.empty() == false)
    {
        cout << pQ.top() << " ";
        pQ.pop();
    }
}
/*
 * Complete the cookies function below.
 */
int cookies(int k, vector<int> A) {
    priority_queue<int, vector<int>, greater<int>> pQ;
    for(int &a: A)
        pQ.push(a);

   /* while (pQ.empty() == false)
    {
        cout << pQ.top() << " ";
        pQ.pop();
    } */


    int size = pQ.size();
    bool notPossible = true;
    int nop, min, secMin, sweetness;
    nop = min = secMin = sweetness = 0;
    while(--size) {
        min = pQ.top();
        pQ.pop();
        if (min < k) {
            secMin =  pQ.top();
            sweetness = min*1 + secMin*2;
            pQ.pop();
            pQ.push(sweetness);
            size = pQ.size();
            nop++;
        } else {
            notPossible = false;
            break;
        }
    }
    cout << "total ops" << nop << "pq Size" << pQ.size() << endl;

    return (notPossible ? -1 : nop);/*
     * Write your code here.
     */

}

int main()
{
   // ofstream fout(getenv("OUTPUT_PATH"));

    std::ifstream nameFileout;

    nameFileout.open("name2.txt");
    string nk_temp;
    getline(nameFileout, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string A_temp_temp;
    getline(nameFileout, A_temp_temp);

    vector<string> A_temp = split_string(A_temp_temp);

    vector<int> A(n);

    for (int A_itr = 0; A_itr < n; A_itr++) {
        int A_item = stoi(A_temp[A_itr]);

        A[A_itr] = A_item;
    }

    int result = cookies(k, A);
    cout << result << endl;

    //fout << result << "\n";

    //fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

