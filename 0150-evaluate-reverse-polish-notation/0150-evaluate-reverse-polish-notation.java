class Solution {
    public int evalRPN(String[] tokens) {
        Stack<String> stk = new Stack<>();

        for(int i = 0 ; i < tokens.length ; i++){
            String s = tokens[i];
            char ch = s.charAt(s.length() - 1);
            // boolean pop = false ;

            if(ch == '+' || ch == '-' || ch=='*' || ch=='/'){
                if( !stk.isEmpty() ){
                    // pop=true;
                    int n2 = Integer.valueOf(stk.pop());
                    if(!stk.isEmpty()){
                        int n1 =  Integer.valueOf(stk.pop()) ;
                        if(ch == '+'){
                            String op = Integer.toString(n1+n2); 
                            stk.push(op);
                        }else if(ch == '-'){
                            String op = Integer.toString(n1-n2); 
                            stk.push(op);
                        }else if(ch == '*'){
                            String op = Integer.toString(n1*n2); 
                            stk.push(op);
                        }else{
                            String op = Integer.toString(n1/n2); 
                            stk.push(op);
                        }
                    } 
                }
            }else{
                stk.push(s);
            }

        }

        return Integer.valueOf(stk.pop());
    }
}