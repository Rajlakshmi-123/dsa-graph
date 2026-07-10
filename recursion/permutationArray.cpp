#include <iostream>
#include <vector>
using namespace std; 
    void fun(vector<int> &arr , vector<int> &temp , vector<vector<int>>& ans , vector<int>&vis ) {
       if(temp.size() == arr.size()) {
           ans.push_back(temp) ;
           return ;
       }
        for ( int i = 0 ; i < arr.size() ; i++) {
            if(vis[i] == 0 ) {
                temp.push_back(arr[i]) ;
                vis[i] =1 ;
                fun(arr ,temp  ,ans , vis ) ;
                temp.pop_back() ;
                vis[i] = 0 ;
             }
        }
    }
int main() {
      vector<int> arr ={ 1 , 2  ,3} ;
      
      int n = arr.size() ;
      vector<vector<int >>ans ;
      vector<int>temp ;
      vector<int>vis(n , 0) ;
      fun( arr , temp , ans  , vis  ) ;
       for ( int i = 0 ; i < ans.size() ; i++) {
             for ( int  j = 0 ; j < ans.size() ; j++) {
                cout <<  ans[i][j]  ;
             }
               cout << endl ;
       }
    return  0 ;
}