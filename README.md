# Delta-Encoding-Algorithm

Group project for "Topics in Computer Science" that aims to implement a sample of the Delta Encoding Algorithm.
The algorithm compresses data by storing the difference between consecutive values wich are, normally, smaller than the absolute value itself.
These differences (or deltas) are then stored in a single byte rather than the common 4 bytes for integers.
The current implementation supports deltas ranging from -127 to 127. If some delta is out of this range, it will be truncated.

By  Carlos Davi Carvalho Lima dos Santos,
    Davi Gobo,
    Enzo Larger Manfio,
    Gil Daniel Silva Fernandes,
    Gustavo Tavares Gonçalves,                                                                                                                  
    Vitor Rodrigues Santana,
