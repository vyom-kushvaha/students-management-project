# 🎓 Student Management System

> A console-based C++ application for managing student records, attendance, and academic performance — built around clean OOP design.

![C++](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=flat-square&logo=c%2B%2B)
![Status](https://img.shields.io/badge/Status-Active-brightgreen?style=flat-square)
![License](https://img.shields.io/badge/License-MIT-blue?style=flat-square)

---

## 📌 Overview

The **Student Management System** is a C++ terminal application that models real-world academic workflows. It separates concerns using class-based design — each entity (student, admin) has its own responsibilities, state, and interface. The system is built to be extended, not just used.

---

## ✅ Features

### Implemented
- 🔐 Role-based login — Student and Admin flows
- 📋 Student menu with view options (details, marks, attendance)
- 📊 Attendance tracking (`markPresent` / `markAbsent` with cumulative count)
- 🧾 Per-student record: ID, name, attendance count, total classes, marks
- 🔄 Looped menu with input validation and graceful logout

### 🚧 Pending / Planned
- [ ] File I/O — persist student records between sessions
- [ ] Admin panel — add, update, delete students
- [ ] Search and filter by ID or name
- [ ] Grade computation from marks
- [ ] Multi-subject support

---

## 🛠️ Tech Stack

| Layer | Technology |
|---|---|
| Language | C++17 |
| Paradigm | Object-Oriented Programming |
| I/O | Standard console (`iostream`) |
| Data structures | `std::vector`, `std::string` |
| Build | g++ / any C++ compiler |

---

## ⚙️ How to Run

```bash
# Clone the repository
git clone https://github.com/vyom-kushvaha/students-management-project.git
cd students-management-project

# Compile
g++ -std=c++17 src/student.cpp src/main.cpp -o sms

# Run
./sms
```

> **Note:** Adjust the compile command based on your actual file structure. Ensure `student.h` is in the include path.

---

## 🔄 System Workflow

```
Program Start
    │
    ├── Login Prompt
    │       ├── Student Login  ──► stumenu()
    │       │                        ├── View Attendance  → viewattd()
    │       │                        ├── View Marks       → viewmarks()
    │       │                        ├── View Details     → viewdet()
    │       │                        └── Logout
    │       │
    │       └── Admin Login   ──► [Planned]
    │
    └── Exit
```

The `stufunctions()` method drives the student session loop — it calls `stumenu()` repeatedly until the user exits, routing each choice through a `switch` block to the appropriate method.

---

## 🧩 Challenges Faced

- **State management without persistence** — all data lives in-memory; no database or file system integration yet
- **Attendance ratio display** — the current output shows `ac/tc%` which mixes ratio and percentage notation; needs a formula fix
- **Input handling** — raw `cin` without sanitization can break the loop on invalid types
- **Constructor overloading** — managing three constructors cleanly while avoiding redundant state

---

## 📚 What I Learned

- Designing classes with clear responsibilities (`student` handles its own state and view logic)
- Using constructor overloading to support flexible object creation
- Building interactive terminal menus with persistent loops and input branching
- Separating interface (`.h`) from implementation (`.cpp`) for modularity

---

## 🔮 Future Improvements

- [ ] Implement **file-based persistence** using `fstream`
- [ ] Add **Admin class** with CRUD operations on student records
- [ ] Replace raw `cin` with validated input handlers
- [ ] Fix attendance display: compute `(ac * 100 / tc)` for a real percentage
- [ ] Add a **Makefile** for streamlined builds
- [ ] Introduce **exception handling** for edge cases (empty records, divide-by-zero)

---

## 👤 Author

**Vyom Kushvaha**
🔗 [GitHub Profile](https://github.com/vyom-kushvaha)
📁 [Project Repository](https://github.com/vyom-kushvaha/students-management-project)

---

*Built as a learning project to explore OOP design patterns in C++.*
