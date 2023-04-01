
import java.util.Stack;

class Solution {
    public Stack<Character> my_stack = new Stack<>();

    public boolean isValid(String s) {
        for (int i = 0; i < s.length(); i++) {
            char cur = s.charAt(i);
            if (!my_stack.isEmpty() && ((cur == ')' && my_stack.peek() == '(') || (cur == ']' && my_stack.peek() == '[')
                    || (cur == '}' && my_stack.peek() == '{')))
                my_stack.pop();
            else 
                my_stack.push(cur);

        }
        return my_stack.isEmpty();
    }
}
