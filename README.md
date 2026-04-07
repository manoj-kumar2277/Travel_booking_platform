# Travel_booking_platform
# 📘 Travel Booking Platform Using Graph Data Structure in C

## 📌 Project Title

**Travel Booking Platform Using C**

------------------------------------------------------------------------

## 👥 Team Members

-   Manoj Kumar Reddy
-   Kushi

------------------------------------------------------------------------

## ❗ Problem Statement

Managing travel routes between multiple destinations manually can be
difficult and inefficient. This project provides a simple system to:

-   Add, delete, update, and search travel routes between destinations
-   Manage destinations in a travel network
-   Book trips between available routes
-   Store travel data permanently using files
-   Provide a menu-driven interface for easy management

------------------------------------------------------------------------

## 🧠 Data Structure Used

### 🔹 Structure (Struct)

``` c
typedef struct {
    char destinations[MAX][50];
    int graph[MAX][MAX];
    int destCount;
} TravelGraph;
```

This structure stores: - Destination names - Travel connection graph -
Total number of destinations

------------------------------------------------------------------------

### 🔹 Graph (Adjacency Matrix)

The system uses a **Graph Data Structure** to represent travel
connections.

-   Each destination is a **node**
-   Each route between destinations is an **edge**
-   The edge weight represents the **travel price**

Example:

            Chennai   Delhi   Mumbai
    Chennai     0      5000     3000
    Delhi     5000       0      2500
    Mumbai    3000     2500       0

------------------------------------------------------------------------

### 🔹 File Handling

**File Used:** `travel.dat`

**Purpose:** - Stores destination and route information - Keeps travel
data permanently stored even after program exits

**Functions Used:** - `saveData()` → Saves graph data into file -
`loadData()` → Loads graph data when program starts

------------------------------------------------------------------------

## ⚙️ Algorithm Explanation

### 1️⃣ Add Destination

-   Enter destination name
-   Check if destination already exists
-   Add destination to the graph
-   Initialize connection values
-   Save updated data to file

### 2️⃣ Add Route

-   Enter source destination
-   Enter destination
-   Enter travel price
-   Store price in adjacency matrix
-   Save updated data

### 3️⃣ Delete Route

-   Enter source and destination
-   Check if route exists
-   Remove the route by setting value to **0**
-   Save changes to file

### 4️⃣ Update Route

-   Enter source and destination
-   Find the existing route
-   Update the travel price
-   Save updated data

### 5️⃣ Search Route

-   Enter source destination
-   Enter destination
-   If route exists, display travel price
-   Otherwise display **route not available**

### 6️⃣ Book Trip

-   Enter source destination
-   Enter destination
-   Enter number of seats
-   Calculate total travel cost

**Formula:**

    Total Cost = Travel Price × Number of Seats

### 7️⃣ Display Routes

-   Display all destinations
-   Show travel routes between them
-   Print the destination connection graph

------------------------------------------------------------------------

## 💻 Compilation Instructions

### 🔧 Compile

    gcc travel.c -o project

### ▶️ Run

**For Linux / Mac**

    ./project

**For Windows**

    project.exe

------------------------------------------------------------------------

## 📊 Sample Output

    Travel Booking Platform

    1. Add Destination
 <img width="516" height="314" alt="Screenshot 2026-04-03 150744" src="https://github.com/user-attachments/assets/0adca232-309a-4869-9b11-dbbadaae8f90" />

    2. Add Route
<img width="436" height="340" alt="Screenshot 2026-04-03 151403" src="https://github.com/user-attachments/assets/9cf9acb2-c638-43d2-8d30-9e7ad873b15c" />

    3. Delete Route
<img width="352" height="307" alt="Screenshot 2026-04-03 151413" src="https://github.com/user-attachments/assets/825c3014-7a21-4202-a0b6-cdf0d165f6f3" />

    4. Update Route
<img width="703" height="323" alt="Screenshot 2026-04-03 151857" src="https://github.com/user-attachments/assets/7a3a8cd3-89b8-41f5-8c5f-d2bd6e5951ad" />


    5. Search Route
<img width="561" height="295" alt="Screenshot 2026-04-03 151455" src="https://github.com/user-attachments/assets/157a24cc-8a46-4928-af23-07140db149f1" />


    6. Book Trip
 <img width="526" height="386" alt="Screenshot 2026-04-03 151501" src="https://github.com/user-attachments/assets/1dba95eb-1ea3-4b94-a09b-f844046bb676" />


    7. Display Graph
<img width="753" height="474" alt="Screenshot 2026-04-03 151510" src="https://github.com/user-attachments/assets/26a2760f-2645-496f-851b-a26e5da83b31" />


    8. Exit
<img width="518" height="243" alt="Screenshot 2026-04-03 151515" src="https://github.com/user-attachments/assets/55e1359d-85af-4e94-a0b9-92fd4e81a24c" />

    Enter choice:

------------------------------------------------------------------------


------------------------------------------------------------------------

## ✅ Features

✔ Menu-driven interface\
✔ Graph data structure implementation\
✔ Destination connection management\
✔ Travel route CRUD operations (Create, Read, Update, Delete)\
✔ Trip booking functionality\
✔ Persistent data storage using file handling\
✔ Easy travel network management
