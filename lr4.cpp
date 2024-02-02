using System;

class Hotel
{
    string nameHotel;
    int numberHotel;
    double priceHotel;

    public Hotel(string name, int number, double price)
    {
        nameHotel = name;
        numberHotel = number;
        priceHotel = price;
    }

    public override string ToString()
    {
        return $"Hotel Name: {nameHotel}, Room Number: {numberHotel}, Price: {priceHotel}";
    }

    public override bool Equals(object obj)
    {
        if (obj == null || GetType() != obj.GetType())
        {
            return false;
        }

        Hotel otherHotel = (Hotel)obj;

        return nameHotel == otherHotel.nameHotel && numberHotel == otherHotel.numberHotel && priceHotel == otherHotel.priceHotel;
    }
}

struct HotelStruct
{
    string nameHotel;
    int numberHotel;
    double priceHotel;

    public HotelStruct(string name, int number, double price)
    {
        nameHotel = name;
        numberHotel = number;
        priceHotel = price;
    }

    public override string ToString()
    {
        return $"Hotel Name: {nameHotel}, Room Number: {numberHotel}, Price: {priceHotel}";
    }

    public bool Equals(HotelStruct otherHotel)
    {
        return nameHotel == otherHotel.nameHotel && numberHotel == otherHotel.numberHotel && priceHotel == otherHotel.priceHotel;
    }

    public override bool Equals(object obj)
    {
        if (obj is HotelStruct)
        {
            return Equals((HotelStruct)obj);
        }
        return false;
    }
}
// struct Testhotel
 //{
//  public int X;
//    }

 //   struct Hotel : Testhotel
 //   {
//         public int Y;
//    }

class Program
{
    static void Main()
    {
        Hotel hotel1 = new Hotel("Greatles", 15, 2000.34);
        Hotel hotel2 = new Hotel("Greatles", 15, 2000.34);

        Console.WriteLine(hotel1.Equals(hotel2));
        Console.WriteLine(hotel1.ToString());

        //  'is'
        if (hotel1 is Hotel)
        {
            Console.WriteLine("hotel1 is an object of the Hotel class.");
        }
        else
        {
            Console.WriteLine("hotel1 is not an object of the Hotel class.");
        }

        //  'as' 
        object obj = hotel1;
        Hotel hotel3 = obj as Hotel;

        if (hotel3 != null)
        {
            Console.WriteLine("Conversion of obj to Hotel successful: " + hotel3.ToString());
        }
        else
        {
            Console.WriteLine("Conversion of obj to Hotel failed.");
        }
        //  HotelStruct
        HotelStruct struct1 = new HotelStruct("Marriott", 20, 1500.50);
        HotelStruct struct2 = new HotelStruct("Marriott", 20, 1500.50);

        Console.WriteLine(struct1.Equals(struct2)); // T
        Console.WriteLine(struct1.ToString());
    }
}
