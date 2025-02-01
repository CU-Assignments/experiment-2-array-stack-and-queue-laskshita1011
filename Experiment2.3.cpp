//Problem Statement: Given a string path, which is an absolute path to a file or directory in a Unix-style file system, convert it to the simplified canonical path.
#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string temp;

        while (getline(ss, temp, '/')) { 
            if (temp == "" || temp == ".") 
                continue;  
            if (temp == "..") {  
                if (!st.empty()) 
                    st.pop(); 
            } else {
                st.push(temp); 
            }
        }

        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;  
    }
};

int main() {
    Solution solution;
    
    string path1 = "/home/";
    cout << solution.simplifyPath(path1) << endl;  

    string path2 = "/../";
    cout << solution.simplifyPath(path2) << endl;  

    string path3 = "/home//foo/";
    cout << solution.simplifyPath(path3) << endl;  

    string path4 = "/a/./b/../../c/";
    cout << solution.simplifyPath(path4) << endl; 

    return 0;
}
