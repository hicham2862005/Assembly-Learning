## Description:
This section of the project contains one of the mutiple ways to link python code with assembly code, The **Python Part** works as the 
**Front-end** while the **Assembly Part** are the **Back-end**, in this example the **Assembly Code** are **Compiled Into a Shared Library**
(have the file format of **.so** in **Linux** and **.dll** in **Windows**), and the **Python Code** are linked to that Library and it can call
it's functions, this method are not limited to **Assembly** as the back-end but also we can use things like **CUDA**, **C/C++** ..., also the
front-end are not limited to **Python** only but can be used with any other framework or language

## How to run this example ?
for running this example:
first **build the Library** by using `make build-lib` command, then **run the python code** by using `python3 print.py` 
