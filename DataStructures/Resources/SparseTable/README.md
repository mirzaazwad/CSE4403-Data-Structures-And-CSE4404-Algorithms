# Sparse Table

Sparse tables are mostly applicable for range queries as these queries tend to be overlapping queries which allow the answer to be retrieved in O(1) time. For most other queries it can work in O(logn). The main issue with sparse tables as compared to other data structures is that it can only be applicable for immutable arrays or arrays that cannot be changed between queries. 

The primary idea behind using sparse tables is that any number can be represented in the binary form using at best ⌈log<sub>2</sub>x⌉ summands say the number 31 which in binary is:
![binaryRepresentation](https://github.com/mirzaazwad/Data-Structures-And-Algorithms/blob/main/DataStructures/Resources/SparseTable/binaryRepresentation.png)

By the same reasoning any interval can be uniquely represented with decreasing powers of 2, for instance
<h4>
  [0..18] = [0..2<sup>4</sup>) U [2<sup>4</sup>..2<sup>4</sup>+2<sup>1</sup>) U [2<sup>4</sup>+2<sup>1</sup>..2<sup>4</sup>+2<sup>1</sup>+2<sup>0</sup>)
 </h4>
 
 Precompute the values of these subranges and build the table in such a way so that [i,j] stores the value for [j,j+2<sup>i</sup>] 
 
 Let's take the example of the array, 
 
 ```cpp
 int arr[13]={4,2,3,7,1,5,3,3,9,6,7,-1,4};
 ```

 <table>
<thead>
  <tr>
    <th></th>
    <th>0</th>
    <th>1</th>
    <th>2</th>
    <th>3</th>
    <th>4</th>
    <th>5</th>
    <th>6</th>
    <th>7</th>
    <th>8</th>
    <th>9</th>
    <th>10</th>
    <th>11</th>
    <th>12</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>0</td>
    <td>4</td>
    <td>2</td>
    <td>3</td>
    <td>7</td>
    <td>1</td>
    <td>5</td>
    <td>3</td>
    <td>3</td>
    <td>9</td>
    <td>6</td>
    <td>7</td>
    <td>-1</td>
    <td>4</td>
  </tr>
  <tr>
    <td>1</td>
    <td>2</td>
    <td>2</td>
    <td>3</td>
    <td>1</td>
    <td>1</td>
    <td>3</td>
    <td>3</td>
    <td>3</td>
    <td>6</td>
    <td>6</td>
    <td>-1</td>
    <td>-1</td>
    <td> X </td>
  </tr>
  <tr>
    <td>2</td>
    <td>2</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>3</td>
    <td>3</td>
    <td>3</td>
    <td>-1</td>
    <td>-1</td>
    <td>X</td>
    <td>X</td>
    <td>X</td>
  </tr>
  <tr>
    <td>3</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>-1</td>
    <td>-1</td>
    <td>X</td>
    <td>X</td>
    <td>X</td>
    <td>X</td>
    <td>X</td>
    <td>X</td>
    <td>X</td>
  </tr>
</tbody>
</table>
 
 O(nlogn) time is still required for precalculation. But for queries it takes O(1) time for overlapping queries and O(logn) time for non-overlapping queries. So each value in the cells can be calculated as follows:

 ```cpp
 SparseTable[i][j]=f(SparseTable[i-1][j],SparseTable[i-1][j+(1<<(i-1))]);
 ```

 Which essentially translates to the function f that is performed on SparseTable[i-1][j] and SparseTable[i-1][j+2<sup>i</sup>].

 


