class Solution {
    public boolean canFinish(int n, int[][] p) {
        HashMap<Integer,ArrayList<Integer>> map=new HashMap<>();
        for(int i=0;i<n;i++){
            map.put(i,new ArrayList<>());
        }
        for(int i=0;i<p.length;i++){
            int v1=p[i][0];
            int v2=p[i][1];
            map.get(v2).add(v1);
        }
       
        int[] vis=new  int[n];
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(dfs(vis,i,map)) return false;
            }
        }
        return true;


    }
    public static boolean dfs(int[] vis,int node,HashMap<Integer,ArrayList<Integer>> map){
        vis[node]=1;
        for(int nbrs:map.get(node)){
            if(vis[nbrs]==0){
               if( dfs(vis,nbrs,map)){
                   return true;
               }
            }
            else if(vis[nbrs]==1){
                return true;

            }
        }
        
        vis[node]=2;
        return false;
    }
}