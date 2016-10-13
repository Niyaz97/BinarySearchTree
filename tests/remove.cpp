#include <BinarySearchTree.hpp>
#include "catch.hpp"

  SCENARIO("the tree size must decrease by one after removing element")
  {
      GIVEN("two trees")
      {
           BinarySearchTree<int> bst1{ 15,17,12,10,13,9,19,18,20};
           BinarySearchTree<int> bst2{ 15,17,12,13,9,19,18,20};
           
           WHEN("remove node that hasn't children")
            {
              bst1.remove(bst1.root_,10);
              THEN("trees must be equal")
                {
                  REQUIRE(bst1==bst2);
                }
             }
             
            bst1 = BinarySearchTree<int> ({ 15,17,12,10,13,9,19,18,20});
            bst2 = BinarySearchTree<int> ({ 15,12,10,13,9,19,18,20});
             WHEN("remove node that has only right child")
            {
              bst1.remove(bst1.root_,17);
              THEN("trees must be equal")
                {
                  REQUIRE(bst1==bst2);
                }
             }
             
             bst1 = BinarySearchTree<int> ({ 15,17,12,10,13,9,19,18,20});
             bst2 = BinarySearchTree<int> ({ 15,17,12,13,9,19,18,20});
             WHEN("remove node that has only left child")
            {
              bst1.remove(bst1.root_,10);
              THEN("trees must be equal")
                {
                  REQUIRE(bst1==bst2);
                }
             }
             
            bst1 = BinarySearchTree<int> ({ 15,17,12,10,13,9,19,18,20});
            bst2 = BinarySearchTree<int> ({ 15,17,10,13,9,19,18,20});
             WHEN("remove node that has both children")
            {
              bst1.remove(bst1.root_,12);
              THEN("trees must be equal")
                {
                  REQUIRE(bst1==bst2);
                }
             }
             
            bst1 = BinarySearchTree<int> ({ 15,17,12,10,13,9,19,18,20});
            bst2 = BinarySearchTree<int> ({ 15,17,12,10,13,9,19,18,20});
             WHEN("remove node that doesn't exist")
            {
              bst1.remove(bst1.root_,5);
              THEN("trees must be equal")
                {
                  REQUIRE(bst1==bst2);
                }
             }
        
            bst1 = BinarySearchTree<int> ({ 30});
            bst2 = BinarySearchTree<int> ();
             WHEN("remove root")
            {
              bst1.remove(bst1.root_,30);
              THEN("trees must be equal")
                {
                  REQUIRE(bst1==bst2);
                }
             }
          }
       }
