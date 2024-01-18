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
        System.out.println("6. Exit");
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
                System.out.println("Exiting the program.");
                break;
            default:
                System.out.println("Invalid choice. Please enter a valid option.");
        }
    } while (choice != 6);




 }
}