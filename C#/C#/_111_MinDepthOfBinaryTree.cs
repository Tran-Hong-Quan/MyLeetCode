using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class _111_MinDepthOfBinaryTree
    {

        public class TreeNode
        {
            public int val;
            public TreeNode left;
            public TreeNode right;
            public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
            {
                this.val = val;
                this.left = left;
                this.right = right;
            }
        }


        public int MinDepth(TreeNode root)
        {
            if(root == null) return 0;
            if(root.left == null || root.right == null) return 1;

            int l = MinDepth(root.left);
            int r = MinDepth(root.right);

            return (int)MathF.Min(l,r);
        }
    }
}
