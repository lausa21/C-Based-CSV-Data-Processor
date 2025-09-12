# 📁 C-Based CSV Data Processor
This project is a command-line utility built in the C language to perform common data manipulation tasks on a `.csv` file. The program is designed to read a dataset from a CSV file into memory, and then provide a user-friendly, menu-driven interface to display, search, sort, and export the data. This tool demonstrates fundamental C programming concepts including file I/O, string parsing (using `strtok`), dynamic memory management, data structures, and the implementation of searching and sorting algorithms.

### 📎 Data Structure & File Format
The program is designed to work with a `.csv` file that has a specific header and column structure. The expected columns are:
`Location,City,Price,Rooms,Bathroom,Carpark,Type,Furnish`. A sample `file.csv` file with this format is included in this directory.

---

### ✨ Features
1.  **Display Data**
    * **Input:** The number of rows (`n`) you wish to see.
    * **Functionality:** Displays the first `n` rows from the dataset.
    * **Logic:** If the requested number of rows is greater than the total number of rows in the file, the program will display all the data.
2.  **Search Data**
    * **Input:** A target column name (e.g., `Location`) and a search query (e.g., `Jinjang`).
    * **Functionality:** Scans the specified column and displays all rows that contain an exact match for the query.
    * **Output:** If no matches are found, it prints a `Data not found!` message. If one or more matches are found, it displays the details of each matching row.
3.  **Sort Data**
    * **Input:** A target column name (e.g., `Price`) and a sort order (`asc` for ascending or `desc` for descending).
    * **Functionality:** Sorts the entire dataset in memory based on the chosen column and order.
    * **Output:** After sorting is complete, the program displays the first 10 rows of the newly sorted data to give a preview of the result.
4.  **Export Data**
    * **Input:** A desired filename for the output (e.g., `sorted_data`).
    * **Functionality:** Writes the current state of the data (which may have been sorted) into a new `.csv` file. The program automatically appends the `.csv` extension.
    * **Output:** Confirms the action with a success message, for example: `Data successfully written to file sorted_data.csv!`.
5.  **Exit**
    * Safely terminates the application.
