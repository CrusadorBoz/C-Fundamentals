#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"

// Function to open or create the database
static int open_database(sqlite3 **db) {
    int rc = sqlite3_open("birthdays.db", db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(*db));
        return rc;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    return 0;
}

// Function to create the table
static int create_table(sqlite3 *db) {
    char *err_msg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS People("  \
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
                      "Name TEXT NOT NULL," \
                      "DateOfBirth TEXT NOT NULL);";

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        return 1;
    }
    fprintf(stdout, "Table created successfully\n");
    return 0;
}

// Function to insert data
static int insert_data(sqlite3 *db, const char *name, const char *dob) {
    char *err_msg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO People (Name, DateOfBirth) VALUES ('%s', '%s');", name, dob);

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        return 1;
    }
    fprintf(stdout, "Records created successfully\n");
    return 0;
}

// Function to read data
static int callback(void *data, int argc, char **argv, char **azColName){
   for(int i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

static void read_data(sqlite3 *db) {
    char *zErrMsg = 0;
    const char* sql = "SELECT * FROM People";

    int rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
    } else {
      fprintf(stdout, "Operation done successfully\n");
    }
}

// Function to update data
static int update_data(sqlite3 *db, int id, const char *name, const char *dob) {
    char *err_msg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "UPDATE People SET Name='%s', DateOfBirth='%s' WHERE ID=%d;", name, dob, id);

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        return 1;
    }
    fprintf(stdout, "Record updated successfully\n");
    return 0;
}

// Function to delete data
static int delete_data(sqlite3 *db, int id) {
    char *err_msg = 0;
    char sql[128];
    snprintf(sql, sizeof(sql), "DELETE FROM People WHERE ID=%d;", id);

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        return 1;
    }
    fprintf(stdout, "Record deleted successfully\n");
    return 0;
}

int main() {
    sqlite3 *db;
    int rc = open_database(&db);
    if (rc == 0) {
        create_table(db);

        // Example usage of CRUD operations
        insert_data(db, "John Doe", "1990-01-01");
        insert_data(db, "Jane Smith", "1985-05-15");
        read_data(db);

        update_data(db, 1, "John Updated", "1990-01-02");
        read_data(db);

        delete_data(db, 2);
        read_data(db);

        sqlite3_close(db);
    }
    return 0;
}

// To compile gcc -o crud.exe crud.c libsqlite3.a -- You might have to install sqlite.
// In this example, are are using the sqlite as static library.  We are not using dependencies.

// You download the amalgamation files, and then compile the sqlite3.c file.
// gcc -c sqlite3.c | We are doing this to get an object file.  It will be sqlite3.o

// Then we have to make an archive.  Called libsqlite3.a
// ar rcs libsqlite3.a sqlite3.o
// You will then have libsqlite3.a in the directory.  

// You need to move both the header file sqlite3.h and libsqlite3.a into the folder of your project.
