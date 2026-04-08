# 📚 Student Management System

## Description
A console-based **Student Management System** written in C++ that uses text files for persistent data storage. It offers role-based access for Admins, Teachers, and Students. Admins can manage student records dynamically (auto-syncing credentials), Teachers can mark attendance and enter marks, while Students can view their progress. The project demonstrates strong object-oriented principles mixed with raw file I/O operations for data persistence.

---

## Features
*All features listed below are fully implemented and functional.*

- **Role-Based Authentication:** Login system routing users to Student, Teacher, or Admin portals based on credentials in `stupass.txt`.
- **Dynamic Credential Syncing:** Whenever an Admin adds or removes a student from the system, their credentials are automatically appended or purged from the authentication database seamlessly.
- **Student Capabilities:**
  - View Attendance (Attended / Total classes with calculated percentage)
  - View Marks
  - View basic ID and Name details
- **Teacher Capabilities:**
  - Mark students as Present (P) or Absent (A)
  - Enter total marks for a specific student ID
- **Admin Capabilities:**
  - Add new student records (Auto-generates student login profiles)
  - Remove existing student records (Auto-deletes student login profiles and dynamically shifts data indexes)
  - View details of any active student
  - Update student names and marks

---

## Known Limitations & Missing Features
Based on a code review, here is what is still missing or slightly brittle:
- ⚠️ **Missing Input Validation:** The manual file parser (`log::check()`) relies on exact character counting and strict commas. Any malformed text file, trailing space, or missing comma will trigger an infinite loop or breakdown.
- ⚠️ **No Teacher/Admin Management:** Admins can only add or remove Students. There is no automated mechanism to add/remove other Teachers or Admins within the application itself without manually editing the text files.

---

## Tech Stack
- **Language:** C++ (Standard C++11 or later)
- **Compiler:** g++ (GCC / MinGW)
- **Data Persistence:** Plain Text Files (`.txt` formatting)
- **Libraries:** Standard C++ STL only (`iostream`, `fstream`, `vector`, `string`)

---

## Project Structure
```text
students-management-project/
├── src/                  # Source Code
│   ├── main.cpp          # Entry point & role-based routing loop
│   ├── admin.cpp         # Admin operations (Add/Remove/Update students + File synchronization)
│   ├── student.cpp       # Student viewer operations
│   ├── teacher.cpp       # Teacher assignment operations
│   ├── log.cpp           # Custom logic for file reading and authentication
│   └── loader.cpp        # Pre-loads .txt files into memory vectors
├── include/              # Header declarations for all source classes
├── data/                 # Text-based database files
│   ├── students.txt      # Primary student details
│   ├── teachers.txt      # Teacher references
│   ├── admins.txt        # Admin references
│   └── stupass.txt       # Combined login credentials and role definitions
└── README.md             # Project Documentation
```

---

## How to Run the Project

1. **Prerequisites:** Ensure you have the `g++` compiler installed and accessible in your system path.
2. **Navigate to the core directory:**
   ```bash
   cd path/to/students-management-project
   ```
3. **Compile the program:**
   ```bash
   g++ -I./include src/main.cpp src/student.cpp src/teacher.cpp src/admin.cpp src/log.cpp src/loader.cpp -o app.exe
   ```
4. **Execute the compiled file:**
   > **Note:** You MUST run the application from the project root so it can locate the `data/` folder correctly.
   ```bash
   ./app.exe
   ```

---

## Sample Output

**Expected Successful Workflow (Pre-loaded Teacher Login):**
```text
=== Student Management System ===
1. Login
2. Exit
Choice: 1

--- Login ---
Username: sir_raj
Password: teach456
username found
password is correct

--- Login Successful ---

=== Teacher Menu ===
1. Mark Attendance
2. Enter Marks
3. Logout
Enter your choice:
1
Enter Student ID: 101

--- Mark Attendance ---
P = Present  |  A = Absent : P
Marked Present.
```

---

## Challenges Faced

1. **State Synchronization:** A major architectural challenge was keeping the static memory state (`vector<student>`) synchronized with the plain text file database (`.txt`), especially concerning index shifting when items are erased. This has now been elegantly resolved using deep file rewrites on `remove`.
2. **Manual File Parsing (`log.cpp`):** Relying on nested `while` loops checking for specific delimiter chars (`char == ','`) makes parsing rigid and prone to infinite loops. Standard `stringstream` splitting would handle errors gracefully.
3. **Identifier Dependencies:** Originally, using array indexes for mapping credentials in `stupass.txt` rather than using a unique, immutable Student ID (`eid`) forced strict coupling. However, index synchronization loops ensure no breaking behavior occurs anymore.

---

## Future Improvements

To make this project even better, the following improvements are suggested:
1. **Refactor Identifiers:** `stupass.txt` should reference the exact Student ID, not an array index. `main.cpp` should perform an ID search upon login rather than routing via `students[index]`.
2. **Safer File Handlers:** Replace character-by-character parsing loops in `log.cpp` with `<sstream>` and `getline()` logic to split strings and handle corrupt text seamlessly without crashing.
3. **Use Structured Data Formats:** Moving from basic CSV-like structures to standard parsing files like JSON (`nlohmann::json`) or SQLite would eliminate most data synchronization headaches out of the box.

---

## Project Review

### Code Quality: 5.5 / 10
The code intelligently uses header files and splits logic natively among classes. Now that major logic bugs tying credentials to array indices are managed safely, the overall reliability has improved drastically. Eliminating strict `while` loops for simple string parsing would further raise this score.

### Structure: 7 / 10
The directory separation (`src/`, `include/`, `data/`) is strong. Coupling the file IO methods neatly inside their related classes (like doing Sync inside User admin scope) maintains respectable boundary structures.

### Practical Usefulness: 7.5 / 10
The system is now highly functional and ready for practical use cases! Because the dynamic syncing is completed and stable, adding or deleting students auto-manages the credentials under the hood. It serves perfectly as a lightweight text-file based management architecture.
