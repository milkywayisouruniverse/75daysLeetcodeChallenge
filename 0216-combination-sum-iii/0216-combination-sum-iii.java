class Solution {
    int a[]={1,2,3,4,5,6,7,8,9};
    List<List<Integer>> res=new ArrayList<>();
    public List<List<Integer>> combinationSum3(int k, int n) {
        backtrack(new ArrayList<>(),k,n,0,0);
        return res;
    }
    public void backtrack(ArrayList<Integer> al,int k,int n,int i,int sum)
    {
        if(sum==n && al.size()==k)
        {
            res.add(new ArrayList<Integer>(al));
            return ;
        }
        if(i==a.length || sum>n)
            return;
        al.add(a[i]);
        backtrack(al,k,n,i+1,sum+a[i]);
        al.remove(al.size()-1);
        backtrack(al,k,n,i+1,sum);
    }
}