- **Course Name** 
    Algorithmic Problem Solving(APS)
- **Course Code**
    23ECSE309
- **Course Instructor**
    Prakash Hegade
- **Name**
    Dheeraj Dalbanjan
- **University**
    KLE Technological University, Hubballi-31


# Introduction
The motive of building this portfolio is to enhance E
-commerce search and filter functionalities. The use of effiecient Data structure and algorithms (DSA) algorithms are crucial for this process

# Functionalities Identified

![e-commerce drawio (1)](https://github.com/dheerajdalbanjan/aps.github.io/assets/100364283/b5b2a535-f99b-4e6c-9512-d327c40934d1)

# Functionalities Implemented.

1. **Search Optimization**
   - **Autocomplete and Suggestions**:
     Autocomplete and suggestion functionalites enhace the user experience by predicting the
     possible search terms while the user types. It basically involves real time suggestions.

     ![image](https://github.com/dheerajdalbanjan/aps.github.io/assets/100364283/a2fc033c-04b4-44e8-a978-a09a149e43a8)
     
     **Key Components**:
     1. *Input Handling*:
        - capture user input in real-time.
        - detect key events to trigger autocomplete suggestions.
     2. *Query Processing*:
        - After handling the input the next step is to process the input string to get possible suggestions.
        - Efficient data strutures need to be used to store and retrieve the search queries.
     3. *Data Structures*:
         - *Trie Data Structure*:
           - It efficiently stores large set of strings.
           - It is fast in terms of lookups of words starting with a given prefix.
           - *Time Complexity*: O(m), where m is the length of the query.
         - *B+ Trees*:
            - B+ Tree is a self-balancing data structure that maintains sorted data and allows searches, sequential access and more.
            - It is prefered for handling large datasets with balanced tree structure.
            - *Time Complecxity*: Insert/Delete/Search: O(log n).

2. **Filtering Mechanisms**
   - **Dynamic Filters**:
     Filtering mechanisms allow users to narrow down search results based on specific creteria select by the user such as (price, brand, category and other attributes). This is the feature that helps user to find exactly what they are looking for.
     
     <table>
         <tr>
             <td><img src="https://github.com/dheerajdalbanjan/aps.github.io/assets/100364283/c732419d-e512-4227-b62e-98c67ae7356d"/></td>
             <td>
                 <ul>
                     <li>It provides various filter options relevant to the product categories and also allow user t o select multiple filters.</li> <li>Once the filters are selected the search results are dynamically updated. </li> 
                     <li> <b>Segment Trees</b>: Manage and update range queries efficiently.</li>
                     <li>Time complexity of *Segment trees* is O(nlogn)</li>
                     <li> <b>Fenwick Trees</b>: Handle dynamic frequency counts.</li>
                     <li>Time complexity of *Fenwick trees* is O(nlogn)</li>
                 </ul>
             </td>
         </tr>
     </table>
     




3. **Relevance and Ranking**:
   
    Relvance and ranking algorithms ensure that the results are ordered by their relevance and importance based on the user's query.
     This enhances search exprerience and help them effectively find the product they are looking for in the site.
   - *Relevance Calculation*:
     The relevance calculations is usually done based on the term frequency, user behavior and contextual relevance.
   - Inverted Index and Heap data structure could be used here to efficiently map terms to their locaiton in a database of documents and maintain a dynamically sorted list of top-k elements respectively.
   - *Ranking Algorithms*
     - **TF-IDF (Term Frequency-Inverse Document Frequency)**: Measures importance of terms.
     - **PageRank**: Ranks items based on user interactions.
       
       
   - ![image](https://github.com/dheerajdalbanjan/aps.github.io/assets/100364283/d049cb8d-f45e-40de-bea5-e8cb7a7bfc12)
    So for the search query "laptop for gaming" the above is the most relevant according to <a href="https://amazon.in"> Amazon</a>.


4. **Personalization**

   Personalization is E-commerce platform is to enhance the shopping experience of the user by recommending productions based on their preferences, behaviours, and interactions.
   
   This increases user satisfaction and increases the likelihood of purchases (in bussiness terms "customer repeat rate (CRR)").
   - *User Data Collection*:
     
     It basically involves collecting user data based on their behavior, such as browsing history, purchase history, and interactions patterns.

     The data collected above can be stored as client side cookies or explicitly in the database itself.
   
   - *Data Structures and Algoritms used*
     - *Collaborative Filtering*:
       - Recommends items based on user behavior.
       - it can be user based or item based.
       - Time Complexity is O(mn)
     - *Matrix Factorization*:
       - Reduces dimensionality for personalized recommendations.
       - includes latent factors representing user preferences and item characteristics.
       - Time Complexity is O(nk + mk), k is the no. of latent features.

5. **Real-time Updates**
   
   Real-time Updates in E-commerce applications refer to providing the user the latest and the most current information related to products that is price, product availability and other dynamic data.

   This enhances the user experience by providing accurate and timely information.
   - *Real-time Data Processing*:
     - It involves continously process and udpate data.
     - It also involves handling of large volume of data.
   - *Data Structures and Algorithms uses*:
     - *Heap Data Structure*:
       - Manages real-time task scheduling.
       - It is useful for keeping track of the most recent data.
       - Time complexity is O(log n).
     - *Dynamic Hash Tables*:
       - Provides fast access to updated data.
       - handling of dynamic data is done by resizing and rehashing as needed.
       - Time complexity is O(1) for insert, delete and search.

# Algorithms and Data Structures

| **Data Structure/Algorithm** | **Time Complexity**                            | **Space Complexity** |
|:--|:--|:--|
| **Trie Data Structure**      | Insert/Search: O(m)                            | O(m) per node        |
| **B+ Trees**                 | Insert/Delete/Search: O(log n)                 | O(n)                 |
| **Segment Trees**            | Build: O(n log n), Query/Update: O(log n)      | O(n)                 |
| **Fenwick Trees**            | Build: O(n log n), Update/Query: O(log n)      | O(n)                 |
| **Collaborative Filtering**  | O(nm)                                          | O(nm)                |


# Combining Solutions

1. **Integration of Autocomplete and Suggestions**
   - Use Trie for efficient query storage and B+ Trees for balanced access.
2. **Dynamic Filter Updates**
   - Implement Segment Trees and Fenwick Trees for real-time filter adjustments.
3. **Enhanced Search Relevance**
   - Apply TF-IDF and PageRank for ranking search results.
4. **Personalized Recommendations**
   - Combine Collaborative Filtering and Matrix Factorization for user-specific suggestions.
5. **Real-time Data Handling**
   - Utilize Heap Data Structure and Dynamic Hash Tables for processing live data updates.

### Conclusion

Integrating these functionalities and algorithms can significantly enhance the search and filter experience in e-commerce platforms, providing users with more relevant and personalized results efficiently.
