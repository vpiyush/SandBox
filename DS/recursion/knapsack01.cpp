#include <iostream>
#include <vector>
using namespace std;

class item {
    public:
        int wt;
        int price;
    item(int w, int p):wt(w), price(p) {};
};

vector <item> itemVec;
int knapsack( int i,  int allowedWeight, int totW) {

    // base case, nothin in the bag or weight crossed the total limit
    if (i >= itemVec.size()  or totW > allowedWeight) {
        return 0;
    }

    int totPrice1 = 0;
    int totPrice2 = 0;
    bool picked = false;
    // choose first item, run knapsack on the remaining bag
    if (itemVec[i].wt <= (allowedWeight - totW)) {
        picked = true;
//        totW += itemVec[i].wt;
        cout << itemVec[i].price << " "  << totW+itemVec[i].wt<< endl;
        totPrice1 = itemVec[i].price + knapsack( i+1, allowedWeight, totW+itemVec[i].wt);
    }

    // don't choose this item, run knapsack on the remaining bag
 //   if (picked)
//        totW -= itemVec[i].wt;
    totPrice2 = knapsack( i+1, allowedWeight, totW);
//    cout << totPrice2 << endl;

    return max(totPrice1, totPrice2);
}

int main() {
    itemVec.push_back(item(1,40));
    itemVec.push_back(item(2,20));
    itemVec.push_back(item(3,30));
    itemVec.push_back(item(5,100));
    int totW = 0;
    cout << knapsack(0, 10, totW) << endl;
}
