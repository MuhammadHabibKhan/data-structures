#include "stack.h"
#include <map>
#include <string.h>

map<char, int> operators {
      {'+', 1},
      {'-', 1},
      {'*', 2},
      {'/', 2},
      {'^', 3},
      {'(', -1},
      {')', -1}
    };

void infix_to_postfix(string exp){
    string final_exp;

    for (int i=0; i<exp.length(); i++){
        char e = exp[i];

        // if variables scanned, then simply add to final postfix expression 
        if (e >= 'a' && e <= 'z'){
            final_exp += e;
        }
        // when first bracket scanned push it to stack
        // dealing brackets diff as they have different behaviour not relating to common precedence logic
        else if(e == '('){
            push(e);
            }
        // if last bracket comes then keep putting top node's data in final expression
        // and then popping it until the starting bracket is scanned
        else if(e == ')'){
            while (top->data != '('){
                final_exp += top->data;
                pop();
            }
            pop(); // popping the '(' bracket as condition skips it
        }
        // nomral condition of operator being scanned then checking for precedence
        else{
            // if not empty and scanned operator has precedence less than or equal to top of stack
            while(top != 0 && operators.at(exp[i]) <= operators.at(top->data)){
                // if ^ operator met then 2 conditions as it has R-->L associativity
                if (e == '^' && top->data != '^'){
                    // as ^ is of highest precedence other than (), so if stack does not have a '^'
                    // it will simply break loop and go to line 49: push(e) to push ^ on stack, no pop
                    break;
                    // if not true then below else block takes and operates normally based on precedence
                    // of '^' i.e 3
                }
                else{
                // final expression gets operator added & then popped out of stack to discard
                // until a lower or equal precedence operator is met. 
                final_exp += top->data;
                pop();
                }
            }
        
            // this push works for different scenarios hence placement is crucial
            // 1) Above defined R-->L associativity of ^ causing direct push on stack after break
            // 2) if empty stack then condition top!=0 is false, loop skipped & directly push to stack
            // 3) Normal popping until precedence is met then push the operator to stack
            push(e);
    }
    }
    // end of for loop
    // after all is done, pop out everything from stack
    while(top != 0){
        final_exp += top->data;
        pop();
    }

    cout << final_exp << endl;
}


int main(){
    //push();
    //cout << operators.at(test_string[2]) << endl;
    //cout << operators.at('-') << endl;
    //if (operators.at('+') == operators.at('-') ){
        //cout << "wubba lubba dub dub" << endl;
    //}

    //string test_string = "k+l-m*n+(o^p)";
    string test_string = "a+b*d-*c^p";
    infix_to_postfix(test_string);
    return 0;
}
// power only working inside bracket, started working for all then afterwards??
// usage of tokenization for multiple characters/digits, use delimiters
// 