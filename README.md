# 🚌 PakRus Travels — Travel Agency Management System

A console-based **C++ Travel Agency Management System** that allows admins to manage customers, book hotels, hire cabs, and generate billing receipts.

---

## 📋 Features

- 🔐 **Admin Login** — Secure access with username & password verification
- 👤 **Customer Management** — Add new customers and view existing records
- 🚕 **Cab Booking** — Choose between Standard (Rs.25/km) and Luxury (Rs.35/km) cabs
- 🏨 **Hotel Booking** — Book packages at partner hotels
- 🧾 **Receipt Generation** — Auto-generate and display billing receipts

---

## 🛠️ Built With

- **Language:** C++
- **Concepts Used:** OOP (Classes, Inheritance, Static Members), File Handling (`fstream`), Console I/O

---

## 🚀 How to Run

### Prerequisites
- Windows OS (uses `windows.h` for `Sleep()` and `system("cls")`)
- A C++ compiler (e.g., MinGW / g++ / MSVC)

### Compile & Run
```bash
g++ project_final.cpp -o PakRusTravels
./PakRusTravels
```

Or simply run the pre-built executable:
```bash
project_final.exe
```

---

## 🔑 Default Admin Credentials

| Username | Password |
|----------|----------|
| hazam    | 1234     |
| waleed   | 1234     |
| husnain  | 1234     |
| shahbaz  | 1234     |

---

## 📁 Project Structure

```
PakRus-Travels/
├── project_final.cpp   # Main source code
├── old-customers.txt   # Customer records (auto-generated)
├── receipt.txt         # Receipt output (auto-generated)
└── README.md           # Project documentation
```

---

## 📌 Notes

- Customer data is saved in `old-customers.txt` automatically after each entry.
- Receipts are saved to `receipt.txt` and can be viewed inside the app.
- This project is **Windows-only** due to use of `windows.h`.

---

## 👨‍💻 Authors

- Hazam
<br>
- Shahbaz
<br>
- Waleed
<br>
- Husnain
<br>

