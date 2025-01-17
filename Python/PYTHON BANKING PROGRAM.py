#PYTHON BANKING PROGRAM

def show_balance(balance):
    print(f"Your balance is ${balance:.2f}")

def deposit():
    amount = float(input("Enter an amount to be deposited: "))

    if amount <= 0:
        print(" That's not a valid amount")
        return 0
    else:
        return amount
    

def withdraw():
    amount = float(input("Enter amount to be withdraw : "))

    if amount > balance:
        print("Insufficient Funds")
        return amount
    elif amount < 0:
        print("Amount must be greate than zero ")
        return amount
    else:
        return amount

def main():
    balance = 0
    is_running = True

    print(" Banking Program")

    while is_running:
        print("1. Show Balance")
        print("2. Deposit")
        print("3. WIthdraw")
        print("4. Exit")

    choice = input("Enter your choice (1 - 4 ): ")

    if choice == "1":
        show_balance(balance)
    elif choice == "2":
        balance += deposit()
    elif choice == "3":
        balance -= withdraw(balance)
    elif choice == "4":
        is_running = False
    else:
        print(" enter valid number : ")

    print(" Thankyou have a nice day.!!! ")


if __name__ == "__main__":
    main()




