// List
// Two Sum problem

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> two_sum(vector<int> arr, int target){
    unordered_map<int, int> m;
    vector<int> ret;

    for (int i=0; i < arr.size(); i++){
        if (m.find(target - arr[i]) != m.end()){
            ret.push_back(i);
            ret.push_back(m[target - arr[i]]);
            return ret;
        }
        else {
            m[target-arr[i]] = i
        }
    }
    ret.push_back(-1);
    ret.push_back(-1);

    return ret;
}


vector<int> merge_sorted_array(vector<int> arr1, vector<int> arr2){
    int i1 = 0;
    int i2 = 0;
    vector<int> arr3;

    while(i1 < arr1.size() && i2 < arr2.size()){
        int a1 = arr1[i1];
        int a2 = arr2[i2];
        if (a1 <= a2){
            arr3.push_back(a1);
            i1+=1;
        }
        else{
            arr3.push_back(a2);
            i2+=1;
        }
    }

    if (i1 == arr1.size()){
        for (int i = i1; i< arr2.size(); i++){
            arr3.push_back(arr2[i]);
        }
    } else{
        for (int i = i2; i< arr1.size(); i++){
            arr3.push_back(arr1[i]);
        }

    }

    return arr3;

}

// String
// String to integer

int atoi(string str){
    int result = 0;
    int sign =1;
    string processed_str = str;

    char first_char = str[0];
    if (first_char == '-'){
        sign = -1;
        processed_str = str.substr(1);
    }
    if (first_char == '+'){
        processed_str = str.substr(1);
    }

    for (int i=0; i< processed_str.size(); i++){
        char c = processed_str[i];
        if (~ '0'<= c <= '9'){
            return -1;
        }
        int ci = c -'0';
        result = result*10 + ci;
    }
    return result * sign;

}

//Revert a string
string reverse_string(string s){
    string ret_str = "";
    for (int i =0; i< s.size(); i++){
        char c = s[i];
        ret_str = c + ret_str;
    }
    return ret_str;
}



// Hash Map
// Longest substring without repeated characters

int longest_substrig_wo_repeated_chars(string str){
    int ans =1;
    for (int j=0; j < str.size(); j++){
        unordered_set<char> j_set;
        for (int i=0; i< j; i++){
            if (j_set.find(str[i]) == j_set.end()){
                j_set.insert(str[i]);
            }
            else{
                ans = max(ans, j-i+1);
            }
        }
    }
    return ans;
}


//Single memmber

int single_number(vector<int> arr){
    unordered_map<int, int> m;

    for (int i=0; i< arr.size(); i++){
        if (m.find(arr[i]) != m.end()){
            m[arr[i]] +=1;
        } else{
            m[arr[i]] = 1;
        }
    }

    for (int i=0; i< arr.size(); i++){
        if (m.find(arr[i]) ==1){
            return i;
        }
    }

}

//set

void subsets(unordered_set<int> sub_set, vector<int> num, int pos){
    if (pos >= num.size()){
        for (auto it = sub_set.begin(); it != sub_set.end(); ++it){
            cout << *it;
        }
        cout<<endl;
        return ;
    }
    subsets(sub_set, num, pos+1);
    sub_set.insert(num[pos]);
    subsets(sub_set, num, pos+ 1);
    sub_set.erase(num[pos]);
}


//Linked List

// Definition for singly-linked list.

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//Reverse a Linked List

ListNode* reverse_linked_list(ListNode* head){

    ListNode* j = NULL;
    ListNode* k = head;

    while (k){
        ListNode*  temp = k->next;
        k->next = j;

        j = k;
        k = temp;

    }
    return j;
}


int main(){
    return 0;
}
