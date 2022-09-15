//This is the revised PizzaQueue for Prog Assigment #1
public class Pizza
{
   public String ingredients, address;
   public Pizza next;

   //Added
   static public Pizza head, tail;

   //Changed the NULL's to null
   public Pizza(String setIngredients, String setAddress)
   {
     ingredients = setIngredients;
     address = setAddress;
     next = null;
   }

   static void enqueue(Pizza thispizza)
   {
     if (head == null)
     {
       head = thispizza;
     }
     else
     {
       tail.next = thispizza;
     }
     tail = thispizza;
     return;
   }

   static Pizza dequeue()
   {
     Pizza pizzatodeliver = null;
     if (head != null)
     {
       pizzatodeliver = head;
       head = head.next;
     }
     if (head == null)
     {
       tail = null;
     }
     return pizzatodeliver;
   }

  static void deliver()
  {
    Pizza thisPizza = dequeue();
    if (thisPizza == null)
    {
      System.out.println("no deliveries pending");
      return;
    }
    System.out.println("Deliver a pizza with " + thisPizza.ingredients + " to " + thisPizza.address);
  }

  public static void main(String[] args)
  {
    enqueue(new Pizza("cheese", "1234 Bobcat Trail"));
    enqueue(new Pizza("Sausage", "2345 University Drive"));
    deliver();
    enqueue(new Pizza("extra cheese", "3456 Rickster Road"));
    enqueue(new Pizza("everything", "4567 King Court"));
    enqueue(new Pizza("coffee beans", "5678 Java Circle"));
    deliver();
    deliver();
    deliver();
    deliver();
    deliver();
    //Got rid of the cin.get and return statement because it is not needed
    //this is because we have a void return type
  }

}
