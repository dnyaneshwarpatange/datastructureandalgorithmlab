def initializeHashTable():
    size = int(input('Enter size of hash table: '))
    hashtable = [[-1, 'null'] for _ in range(size)]
    print('Hashtable of size', size, 'is successfully created .....')
    print(' ')
    return size, hashtable

choice = 1
while choice != 4:
    print('\n****** Menu ******')
    print(' 1.Linear Probing')
    print(' 2.Double Hashing')
    print(' 3.Exit\n')
    choice = int(input('Enter your choice: '))
    print()
    count = 0

    if choice == 1:
        size, hashtable = initializeHashTable()

        choice1 = 1
        while choice1 != 4:
            print('\n* Menu for Linear Probing *')
            print(' 1.Insert')
            print(' 2.Search')
            print(' 3.Display')
            print(' 4.Back\n')
            choice1 = int(input('Enter your choice: '))
            print()

            if choice1 == 1:
                if count == size:
                    print('Hash table is Full .........')
                else:
                    number = int(input('Enter number: '))
                    name = input('Enter Name: ')
                    hashvalue = number % size

                    while hashtable[hashvalue][0] != -1:
                        print('\nCollision has occurred .....')
                        print('Now, Calculating new hash value by using linear Probing')
                        hashvalue = (hashvalue + 1) % size

                    hashtable[hashvalue][0] = number
                    hashtable[hashvalue][1] = name
                    count += 1
                    print('Data is successfully inserted in the hash table ....')
                    print('Total inserted record =', count)
                    print('')

            elif choice1 == 2:
                number = int(input('Enter number to search: '))
                hashvalue = number % size
                comparison = 0

                while hashtable[hashvalue][0] != number and comparison <= size:
                    hashvalue = (hashvalue + 1) % size
                    comparison += 1

                if comparison <= size:
                    print('The number', number, 'is found at location', hashvalue, 'with total comparisons =', comparison)
                else:
                    print('The number is NOT found in the hashtable with comparisons', comparison)

            elif choice1 == 3:
                for i in range(size):
                    print('Hash Value', i, '->', hashtable[i])

    count = 0
    if choice == 2:
        size, hashtable = initializeHashTable()

        choice1 = 1
        while choice1 != 4:
            print('\n* Menu for Double Hashing *')
            print(' 1.Insert')
            print(' 2.Search')
            print(' 3.Display')
            print(' 4.Back\n')
            choice1 = int(input('Enter your choice: '))
            print()

            if choice1 == 1:
                if count == size:
                    print('Hash table is Full .........')
                else:
                    number = int(input('Enter number: '))
                    name = input('Enter Name: ')
                    hashvalue1 = number % size
                    i = 1

                    while hashtable[hashvalue1][0] != -1:
                        print('\nCollision has occurred ..... ')
                        print('Now, Calculating new hash value by Double Hashing Technique')
                        hashvalue1 = number % size

                    prime = int(input("\nEnter prime number lesser than size of HASH TABLE: "))
                    hashvalue2 = (prime - (number % prime))
                    hashvalue3 = (hashvalue1 + i * hashvalue2) % size
                    i += 1
                    hashvalue1 = hashvalue3

                    hashtable[hashvalue1][0] = number
                    hashtable[hashvalue1][1] = name
                    count += 1
                    print('Data is successfully inserted in the hash table .....')
                    print('Total inserted record =', count)

            elif choice1 == 2:
                number = int(input('Enter number to search: '))
                hashvalue1 = number % size
                comparison = 0
                i = 1

                while hashtable[hashvalue1][0] != number and comparison <= size:
                    hashvalue1 = number % size
                    prime = int(input("Enter prime number lesser than size of HASH TABLE: "))
                    hashvalue2 = (prime - (number % prime))
                    hashvalue3 = (hashvalue1 + i * hashvalue2) % size
                    hashvalue1 = hashvalue3
                    comparison += 1
                    i += 1

                if comparison <= size:
                    print('The number', number, 'is found at location', hashvalue1, 'with comparisons', comparison)
                else:
                    print('The number is NOT found in the hashtable with comparisons', comparison)

            elif choice1 == 3:
                for i in range(size):
                    print('Hash Value', i, '->', hashtable[i])

    if choice == 3:
        print("Exiting the program!!")
        exit()
