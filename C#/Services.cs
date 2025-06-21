
public class Service 
{
   public string ReversePrefixString(string word, char c)
   {
      var i = word.IndexOf(c);  
      return string.Join("", word.Substring(0,i+1).ToCharArray().Reverse()) + word.Substring(i+1); 
   }

   public static IList<TreeNode> GenerateTrees(int n)
   {
      if (n == 0) return new List<TreeNode>();
      var root = new TreeNode(1);
      var temp = root;
      var response = new List<TreeNode>();
      
      for (int i = 2; i <= n; i++)
      {
         temp.right = new TreeNode(i);
         temp = temp.right;
      }

      response.Add(root);

      Change(root, response);
      return response; 
   }

   public static TreeNode Change(TreeNode root, List<TreeNode> response) {
      if (root.right is null && root.left is null) return root;

      TreeNode aux;
      if (root?.left is not null) {
         aux = root.left;
         root.left = aux.left; 
         if (root.left.val < aux.val) 
            root.left.left = new TreeNode(aux.val); 
         else
            root.left.right = new TreeNode(aux.val);
      }
      else {
         aux = root.right;
         root.right = aux.right; 
         if (aux.val < root.right.val) {
            root.right.left = new TreeNode(aux.val); 
         }
         else{
            root.right.right = aux;
         }
      }

      if (!response.Any(x => x == root))
         response.Add(root);
      root.right = Change(root.right, response); 
      root.left = Change(root.left, response);
      return root;
   }



}

public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}