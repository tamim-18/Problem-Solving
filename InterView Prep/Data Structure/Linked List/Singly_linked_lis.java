import java.util.*;
class LinkedList{
    Node head;
    static class Node{
        int data;
        Node next;
        Node(int data)
        {
            this.data=data;
            this.next=null;
        }
    }
    void createLinkedList()
    {
        Scanner scanner=new Scanner(System.in);
        System.out.println("Enter the data for the first node");
        int data=scanner.nextInt();
        head=new Node(data);
    }
    void insertAtBeginning(int new_data){
        Node new_node=new Node(new_data);
        new_node.next=head;
        head=new_node;
        System.out.println("Node the beginning has intserted");
    }
    void insertAfterNode(int prev_data,int new_data)
    {
        Node new_node=new Node(new_data);
        Node temp=head;
        while(temp!=null && temp.data!=prev_data) temp=temp.next;
        if(temp==null) System.out.println("No node found with "+prev_data+".");
        else {
            new_node.next=temp.next;
            new_node.data=new_data;
            temp.next=new_node;
            System.out.println("Node inserted after node with data " + prev_data + ".");

        }

    }
    void insertAtEnd(int new_data)
    {
        Node new_node=new Node(new_data);
        if(head==null) {head=new_node;
            return;
        }

        Node temp=head;
        while(temp.next!=null) temp=temp.next;
        new_node.next=null;
        temp.next=new_node;
        System.out.println("Node inserted at the end\n");
        

    }
    void displayLinkedList()
    {
        System.out.println("................");
        Node temp=head;
        while(temp!=null)
        {
            System.out.print(temp.data+" ");

            temp=temp.next;
        }
        System.out.println();
        System.out.println("................");

    }
    boolean searchTheKhoj(int data)
    {
        Node temp=head;
        while(temp!=null)
        {
            if(temp.data==data) return true;
            temp=temp.next;
        }
        return false;
    }
    int length()
    {
        Node temp=head;
        int cnt=0;
        while(temp!=null)
        {
            cnt++;
            temp=temp.next;
        }
        return cnt;
    }
    void ultaLinkedlist()
    {
        if (head == null) {
            System.out.println("Linked list is empty. Cannot reverse.");
            return;
        }
        Node current=head;
        Node next=null;
        Node prev=null;
        while(current!=null)
        {
            next=current.next;
            current.next=prev;
            prev=current;
            current=next;
        }
        head=prev;
    }
    void deleteBegin(){
        if(head==null) {
            System.out.println("The linked list is empty");
            return;
        }
        Node temp=head;
        head=head.next;
        temp.next=null;

    }



public static void main(String[] args){
    LinkedList linkedList=new LinkedList();
    Scanner scanner=new Scanner(System.in);
    int choice;
    do {
        System.out.println("\nChoose an option:");
        System.out.println("1. Create a linked list");
        System.out.println("2. Insert at the beginning");
        System.out.println("3. Insert after a node");
        System.out.println("4. Insert at the end");
        System.out.println("5. Display linked list");
        System.out.println("6. Search in the linked list");
        System.out.println("7. Disply the length of the Linkedlist");
        System.out.println("8. Reverse the Linked List");
        System.out.println("9. Delete from the beginning");
        System.out.println("10. Exit");

        choice = scanner.nextInt();

        switch (choice) {
            case 1:
                linkedList.createLinkedList();
                break;
            case 2:
                System.out.println("Enter the data for the new node:");
                int newData = scanner.nextInt();
                linkedList.insertAtBeginning(newData);
                break;
            case 3:
                System.out.println("Enter the data of the node after which to insert:");
                int prevData = scanner.nextInt();
                System.out.println("Enter the data for the new node:");
                int newDataAfter = scanner.nextInt();
                linkedList.insertAfterNode(prevData, newDataAfter);
                break;
            case 4:
                System.out.println("Enter the data for the new node:");
                int newDataEnd = scanner.nextInt();
                linkedList.insertAtEnd(newDataEnd);
                break;
            case 5:
                linkedList.displayLinkedList();
                break;
            case 6:
                System.out.println("Enter the data to be searched:");
                int data = scanner.nextInt();
                if(linkedList.searchTheKhoj(data))
                    System.out.println(data+" is found");
                else System.out.println(data+" is found not found");
                break;
            case 7:
                System.out.println("The length of linked list is: "+linkedList.length());
                break;
            case 8:
                linkedList.ultaLinkedlist();
                break;
            case 9:
                linkedList.deleteBegin();
                break;
            case 10:
                System.out.println("Exiting the program.");
                break;
                
            default:
                System.out.println("Invalid choice. Please enter a valid option.");
        }
    } while (choice != 10);




 }
}