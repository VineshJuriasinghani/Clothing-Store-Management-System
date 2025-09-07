

# Clothing Store Management System (C Language)

This is a **console-based Clothing Store Management System** written in **C**, using **file handling** for data storage. It simulates a small retail outlet with two types of users: **customers (clients)** and **managers (admins)**. The system allows new customers to register, browse products, and make purchases, while managers can add and manage inventory and view customer information.


## Features

### User Roles

### Customer Portal
- Register a new customer account (data saved in `DATA.txt`)
- Log in with an existing email and password
- Browse products by categories (T-Shirts, Shirts, Paints, Shoes)
- Purchase items and receive a generated bill
- Passwords are stored encrypted (encryption method can be implemented or customized)

### Admin (Manager) Portal
- Log in using predefined credentials (stored in `DATA1.txt`)
- Add, view, update, or delete stock by category
- Track total sales and total profit
- Products managed through category files like `t-shirts.txt`, `shirts.txt`, etc.

## Tech Stack
- **Language**: C (C99/C11)
- **Storage**: File I/O (text files)
- **Compiler**: GCC / Turbo C / Dev C/C++

## Manager Login Credentials
Manager ID : vineshjuriasinghani@outlook.com
Password : stream1 (stored securely using encryption)

## File Structure
```text
ClothingStore/
│
├── main.c              // Complete source code
├── DATA.txt            // Stores customer login and contact info
├── DATA1.txt           // Stores admin credentials
├── sale.txt            // Temporary file for storing purchases during a session
├── manager.txt         // Stores all purchases for profit/sales calculation
├── t-shirts.txt        // Inventory for T-Shirts
├── shirts.txt          // Inventory for Shirts
├── paints.txt          // Inventory for Paints
├── shoes.txt           // Inventory for Shoes
└── README.md           // Project documentation



