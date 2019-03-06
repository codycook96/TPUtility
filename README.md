# TPUtility
A utility program for searching, comparing, and mapping FANUC Teach Pendant files.

### Searching

The program is able to search all .ls files in a directory for a certain search term. This was usefuel in determining where a certain variable or command was showing up. In one instance, we were able to see that a variable used in a conditional statement was never set elsewhere in the program structure and so the entire branch of procedures beneath it were no longer in use.

### Comparing

The program is able to compare two .ls files and report back the line by line similarities of the files. This was mostly used to sniff out duplicate files, as there were often many versions of one procedure still in the directory.

## Mapping

One of the most interesting features of the utility is the mapping feature. The program recursively goes through each .ls file and finds calls to other procedures. An adjacency matrix is made that keeps track of every procedure that has been called and all the procedures that are called from within it. This adjaceny matrix can then be taken used to create a visual map of the program (I used [this](http://graphonline.ru/en/)). 


![pic1]()
![pic2]()
