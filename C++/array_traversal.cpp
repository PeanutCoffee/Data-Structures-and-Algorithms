//Searching an element in an array
#include <iostream>
using namespace std;
int main(){
    int input[100], count, i, num;
    cin >> count;
    for(i = 0; i < count; i++){
        cin >> input[i];
    }
    cin >> num;
    for(i = 0; i < count; i++){
        if(input[i] == num){
            cout << "Element " << num << " Found At Position" << i;
            break;
        }
    }

    if(i == count){
        cout  << "Element Not Found\n";
    }
    return 0;
}
