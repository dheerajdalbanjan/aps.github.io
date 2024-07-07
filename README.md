# E-Commerce Search and Filter Optimization

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
         - **Trie Data Structure**:
           - It efficiently stores large set of strings.
           - It is fast in terms of lookups of words starting with a given prefix.
           - *Time Complexity*: O(m), where m is the length of the query.
         - **B+ Trees**:
            - B+ Tree is a self-balancing data structure that maintains sorted data and allows searches, sequential access and more.
            - It is prefered for handling large datasets with balanced tree structure.
            - *Time Complecxity*: Insert/Delete/Search: O(log n).

2. **Filtering Mechanisms**
   - **Dynamic Filters**
     Filtering mechanisms allow users to narrow down search results based on specific creteria select by the user such as (price, brand, category and other attributes). This is the feature that helps user to find exactly what they are looking for.
     
| ![image](https://github.com/dheerajdalbanjan/aps.github.io/assets/100364283/c732419d-e512-4227-b62e-98c67ae7356d) |<li>It provides various filter options relevant to the product categories and also allow user t o select multiple filters.</li> <li>Once the filters are selected the search results are dynamically updated. </li> <li> **Segment Trees**: Manage and update range queries efficiently.</li> <li> **Fenwick Trees**: Handle dynamic frequency counts.</li> |
|---|---|


3. **Relevance and Ranking**
   - **Ranking Algorithms**
     - **TF-IDF (Term Frequency-Inverse Document Frequency)**: Measures importance of terms.
     - **PageRank**: Ranks items based on user interactions.

4. **Personalization**
   - **User-based Filtering**
     - **Collaborative Filtering**: Recommends items based on user behavior.
     - **Matrix Factorization**: Reduces dimensionality for personalized recommendations.

5. **Real-time Updates**
   - **Real-time Data Processing**
     - **Heap Data Structure**: Manages real-time task scheduling.
     - **Dynamic Hash Tables**: Provides fast access to updated data.

# Algorithms and Data Structures

| **Data Structure/Algorithm** | **Time Complexity**                            | **Space Complexity** |
|------------------------------|------------------------------------------------|----------------------|
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
