#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(std::string s) 
    {
        int len = s.length();
        char* stack = new char[len];
        int top = 0;
        for (char c : s) 
        {
            if (c == '(' || c == '[' || c == '{') 
            {
                stack[top++] = c;
            } 
            else if (c == ')' || c == ']' || c == '}') 
            {
                if (top == 0 || !isValidPair(stack[--top], c)) 
                {
                    delete[] stack;
                    return false;
                }
            }
        }
        bool result = (top == 0);
        delete[] stack;
        return result;
    }

private:
    bool isValidPair(char open, char close) 
    {
        return (open == '(' && close == ')') ||
               (open == '[' && close == ']') ||
               (open == '{' && close == '}');
    }
};

int main() {
    Solution solution;
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";

    cout << solution.isValid(s1) << endl;  // Output: 1 (True)
    cout << solution.isValid(s2) << endl;  // Output: 1 (True)
    cout << solution.isValid(s3) << endl;  // Output: 0 (False)

    return 0;
}







// JAVA

public class Solution {
    public boolean isValid(String s) {
        int len = s.length();
        char[] stack = new char[len];
        int top = 0;
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stack[top++] = c;
            } else if (c == ')' || c == ']' || c == '}') {
                if (top == 0 || !isValidPair(stack[--top], c)) {
                    return false;
                }
            }
        }
        return top == 0;
    }

    private boolean isValidPair(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '[' && close == ']') ||
               (open == '{' && close == '}');
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s1 = "()";
        String s2 = "()[]{}";
        String s3 = "(]";

        System.out.println(solution.isValid(s1));  // Output: true
        System.out.println(solution.isValid(s2));  // Output: true
        System.out.println(solution.isValid(s3));  // Output: false
    }
}
