package DSA;

public class BiST 
{
   

        Ben head;
    
    
        class Ben 
        {
            int data;
            Ben next;
    
            Ben (int data) 
            {
                this.data = data;
                this.next = null;
            }
        }
    
        static class TreeRoot 
        {
            TreeRoot left;
            int data;
            TreeRoot right;
        
            TreeRoot (int data) 
            {
                this.data = data;
                this.left = null;
                this.right = null;
            }
        }
    
        public void insertion(int data) 
        {
            Ben Node = new Ben(data);
            if (head == null)
             {
                head = Node;
            } 
            else 
            {
                Ben last = head;
                while (last.next != null)
                 {
                    last = last.next;
                }
                last.next = Node;
            }
        }
    
        public static int[] convertToBST(Ben head)
         {
            if (head == null) 
            {
                return new int[0];
            }
               
            int count = 0;
            Ben temp = head;
            while (temp != null) 
            {
                count++;
                temp = temp.next;
            }
               
            int[] traversal = new int[count];
               
            int[] arr = new int[count];
            temp = head;
            for (int i = 0; i < count; i++) {
                arr[i] = temp.data;
                temp = temp.next;
            }
               
            TreeRoot root = con(arr, 0, count - 1);
            
            preorderTraversal(root, traversal, 0);
            
            return traversal;
        }
    
        private static TreeRoot con(int[] arr, int start, int end) {
            if (start > end) {
                return null;
            }
            
            int mid = (start + end) / 2;
            
            TreeRoot root = new TreeRoot(arr[mid]);
            
            root.left = con(arr, start, mid - 1);
            root.right = con(arr, mid + 1, end);
            
            return root;
        }
    
        private static int preorderTraversal(TreeRoot TreeRoot, int[] preorder, int index) {
            if (TreeRoot == null) {
                return index;
            }
            preorder[index] = TreeRoot.data;
            index++;
            
            index = preorderTraversal(TreeRoot.left, preorder, index);
            index = preorderTraversal(TreeRoot.right, preorder, index);
            
            return index;
        }
        
        public static void main(String[] args) {
            BiST list = new BiST();
            list.insertion(9);
            list.insertion(14);
            list.insertion(30);
            list.insertion(46);
            list.insertion(48);
            list.insertion(66);
            list.insertion(69);
    
            int[] preorder = convertToBST(list.head);
    
            for (int i = 0; i < preorder.length; i++) {
                System.out.print(preorder[i] + " ");
            }
        }
    }
    


