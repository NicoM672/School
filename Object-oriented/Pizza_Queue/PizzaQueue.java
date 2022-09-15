public class pizza
{
	public String ingrediants, address;
	public pizza next;
	public pizza()
	{
			ingrediants = null;
			address = null;
			next = null;
	}
	public pizza(String ing, String add)
	{
		address = add;
		ingrediants = ing;
		next = null;
	}

	static void enqueue(pizza head, pizza tail, pizza thispizza)
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

	static pizza dequeue(pizza head, pizza tail)
	{
		pizza pizzatodeliver = null;
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

	static void deliver(pizza head, pizza tail)
	{
		pizza thispizza = dequeue(head, tail);
		if (thispizza == null)
		{
			System.out.println("No deliveries pending");
			return;
		}
			System.out.println("Deliver a pizza with " + thispizza.ingrediants + " to " + thispizza.address);
	}

	public static void main(String []args)
	{
		pizza first = null, last = null;

		enqueue(first, last, new pizza("pepperoni", "1234 Bobcat Trail"));
		enqueue(first, last, new pizza("sausage", "2345 University Drive"));
		deliver(first, last);
		enqueue(first, last, new pizza("extra cheese", "3456 Rickster Road"));
		enqueue(first, last, new pizza("everything", "4567 King Court"));
		enqueue(first, last, new pizza("coffee beans", "5678 Java Circle"));
		deliver(first, last);
		deliver(first, last);
		deliver(first, last);
		deliver(first, last);
		deliver(first, last);

	}
}
