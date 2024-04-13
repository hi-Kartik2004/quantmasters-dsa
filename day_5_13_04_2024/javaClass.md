# Java database connectivity

## Steps to download and configure driver in eclipse.

### Installation

1. Open the browser and search `download the mysql connect app`
2. Click on the first link
3. Choose platform independent from dropdown.
4. Click on second option i.e Zip archive.
5. After the download is completed, go to downloads and unzip the file.

### Configuration of the driver into eclipse

1. Click on `Ctrl N` and search for a java Project (Creating a new java project)
2. Click on next
3. Give a name for your project
4. Click on finish
5. After completion you can see the project folder
6. Select the project (You could see only src folder)
7. Select the project, click on `ctrl N` search as folder, select the folder -> click on next button -> give the folder name as lib -> Click on finish.
8. Go to your downloads/extracted_folder -> copy the jar file from the extracted folder and paste it in the lib folder.
9. Select the project Click on Alt Enter, -> New dialog box appears,
10. In the left sidebar, select java build path
11. Click on libraries, select the class path, in the right sidebar click on add jar, navigate to your jar file by expanding the project folder -> Click on the jar file -> click on ok -> click on apply and close, with this you finish configuration.

## Steps to communicate with the database

1. Load the driver.

```java
   Class.forname("com.mysql.cj.jdbc.Driver");
```

2. Establish a connection.

```java
    Connection conn = DriverManager.getConnection(url, username, password);

    url = "jdbc:mysql://localhost:3306/schema_name"
    username = "root" // generally
    password = "root" // generally
```

3. Create a statement.

```java
    Statement stmt = conn.createStatement();
```

4. Execute a statement.

```java
    String sql = "select * from student";
    ResultSet res = stmt.executeQuery(sql);
```

5. Process ResultSet

```java
    while(res.next()){
        // process individual record.
    }
```
