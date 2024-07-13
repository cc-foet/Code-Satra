class ListNode{
    int data;
    ListNode next;
    ListNode(int a){
        data=a;
    }
}

class TreeNode{
    int data;
    TreeNode left;
    TreeNode right;
    TreeNode(int a){
        data=a;
    }
}

class Day_11{
    public static void main(String args[]){
        ListNode node=new ListNode(1);
        node.next=new ListNode(2);
        node.next.next=new ListNode(3);
        node.next.next.next=new ListNode(4);
        node.next.next.next.next=new ListNode(5);
        node.next.next.next.next.next=new ListNode(6);
        node.next.next.next.next.next.next=new ListNode(7);        
        TreeNode root=convertToBST(node);
        System.out.print("The preorder traversal of the binary search tree is: ");
        preorder(root);
        System.out.println();
    }

    static void preorder(TreeNode root){
        if(root!=null){
            System.out.print(root.data+" ");
            preorder(root.left);
            preorder(root.right);
        }
    }

    static TreeNode convertToBST(ListNode node){
        if(node==null){
            return null;
        }
        ListNode temp=node;
        int n=0;
        while(temp!=null){
            n++;
            temp=temp.next;
        }
        if(n==1){
            return new TreeNode(node.data);
        }
        ListNode ltree=new ListNode(node.data);
        ListNode ltemp=ltree;
        for(int i=0;i<n/2-1;i++){
            node=node.next;
            ltemp.next=new ListNode(node.data);
            ltemp=ltemp.next;
        }        
        node=node.next;
        TreeNode root=new TreeNode(node.data);
        node=node.next;
        ListNode rtree=null;
        if(node!=null){
            rtree=new ListNode(node.data);
            ListNode rtemp=rtree;
            node=node.next;
            while(node!=null){
                rtemp.next=new ListNode(node.data);
                rtemp=rtemp.next;
                node=node.next;
            }
        }
        root.left=convertToBST(ltree);
        root.right=convertToBST(rtree);
        return root;
    }  
}