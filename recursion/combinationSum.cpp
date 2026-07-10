#include <iostream>
#include <vector>
using namespace std;
   void comb(int i , vector<int>&arr, int target , vector<int> &temp ) {
    if( i == arr.size()) {
            if(target == 0) {
                for( int j = 0 ; i < temp.size() ; j++) {
                    cout<< temp[j] ;
                }
            }
            return ;
    }

    if(arr[i] <= target) {
        temp.push_back(arr[i] );
        comb(i , arr , target- arr[i] , temp) ;
        temp.pop_back();
        comb (i+1 , arr , target, temp ) ;

    }
   }
int main() {
    int target = 8 ;

     vector<int> arr  = { 5 ,3, 6, 2 , 7} ;
     vector<int>temp ;
    comb( 0 , arr , target , temp  ) ;
}