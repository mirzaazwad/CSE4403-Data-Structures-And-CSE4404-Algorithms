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

 <table class="tg">
<thead>
  <tr>
    <th class="tg-0lax"></th>
    <th class="tg-0lax"></th>
    <th class="tg-0lax"></th>
    <th class="tg-0lax"></th>
    <th class="tg-0lax"></th>
    <th class="tg-0lax"></th>
    <th class="tg-0lax"></th>
    <th class="tg-0lax"></th>
    <th class="tg-0lax"></th>
    <th class="tg-0lax"></th>
    <th class="tg-0lax"></th>
    <th class="tg-0lax"></th>
    <th class="tg-0lax"></th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
  </tr>
  <tr>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
  </tr>
  <tr>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
  </tr>
</tbody>
</table>
 


