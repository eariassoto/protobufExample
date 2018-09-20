using System;
using System.IO;
using Google.Protobuf;
using Google.Protobuf.Examples.AddressBook;
using static Google.Protobuf.Examples.AddressBook.Person.Types;


namespace ProtoBufCs
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 1)
            {
                Console.WriteLine("Usage: ProtoBufCs.txt ADDRESS_BOOK_FILE\n");
                return;
            }
            
            Person john = new Person
            {
                Id = 1234,
                Name = "John Doe",
                Email = "jdoe@example.com",
                Phones = { new PhoneNumber { Number = "555-4321", Type = PhoneType.Home } }
            };

            AddressBook book = new AddressBook
            {
                People = { john }
            };
            using (var output = File.Create(args[0]))
            {
                book.WriteTo(output);
            }
        }
    }
}
