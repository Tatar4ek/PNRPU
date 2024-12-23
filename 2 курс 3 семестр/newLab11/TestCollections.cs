using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LibraryLab10;

namespace newLab11
{
    public class TestCollections
    {
        public Queue<Library> libraries = new Queue<Library>();
        public Queue<string> librariesString = new Queue<string>();
        public SortedDictionary<Organization, Library> dictionaryOrgLib = new SortedDictionary<Organization, Library>();
        public SortedDictionary<string, Library>dictionaryStringLib = new SortedDictionary<string, Library>();

        public TestCollections(int count)
        {
            

            for (int i = 0; i < count; i++)
            {
                Library library;
                
                do
                {
                    library = new Library();
                    library.RandomInit();
                }
                while (dictionaryOrgLib.ContainsKey(library.BaseOrganization) || dictionaryStringLib.ContainsKey(library.ToString()));

                libraries.Enqueue(library);
                librariesString.Enqueue(library.ToString());
                dictionaryOrgLib.Add(library.BaseOrganization, library);
                dictionaryStringLib.Add(library.ToString(), library);
            }
        }


        public void Add(Library library)
        {
            if (libraries.Contains(library.BaseOrganization))
                Console.WriteLine("Данный элемент уже содержится в коллекциях!");
            else
            {
                libraries.Enqueue(library);
                librariesString.Enqueue(library.ToString());
                dictionaryOrgLib.Add(library.BaseOrganization, library);
                dictionaryStringLib.Add(library.ToString(), library);
            }
        }

        public void Delete(Library library)
        {
            if (!libraries.Contains(library))
                Console.WriteLine("Данного элемента в коллекциях нет!");
            else
            {
                RemoveOrgQueue(libraries, library);
                RemoveStringQueue(librariesString, library.ToString());
                dictionaryOrgLib.Remove(library.BaseOrganization);
                dictionaryStringLib.Remove(library.ToString());
            }
        }

        public static void RemoveOrgQueue(Queue<Library> libraries, Library lib)
        {
            for (int i = 0; i < libraries.Count;i++)
            {
                var firstElem = libraries.Dequeue();
                if (firstElem == lib)
                    continue;
                libraries.Enqueue(firstElem);
            }
        }

        public static void RemoveStringQueue(Queue<string> libraries, string org)
        {
            for (int i = 0; i < libraries.Count; i++)
            {
                var firstElem = libraries.Dequeue();
                if (firstElem == org)
                    continue;
                libraries.Enqueue(firstElem);
            }
        }

        public Library GetMiddleElement()
        {
            var count = libraries.Count;
            var middleIndex = count / 2;
            var tempQueue = new Queue<Library>();
            for (int i = 0; i < middleIndex; i++)
            {
                tempQueue.Enqueue(libraries.Dequeue());
            }
            var middleElement = libraries.Peek();
            while (tempQueue.Count > 0)
            {
                libraries.Enqueue(tempQueue.Dequeue());
            }
            return middleElement;
        }

        public Library GetLastElement()
        {
            var count = libraries.Count;
            var tempQueue = new Queue<Library>();
            for (int i = 0; i < count - 1; i++)
            {
                tempQueue.Enqueue(libraries.Dequeue());
            }
            var lastElement = libraries.Peek();
            while (tempQueue.Count > 0)
            {
                libraries.Enqueue(tempQueue.Dequeue());
            }
            return lastElement;
        }

    }
}

