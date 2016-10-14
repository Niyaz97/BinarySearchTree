#include <BinarySearchTree.hpp>
#include "catch.hpp"

  SCENARIO("the tree size must decrease by one after removing element")
  {
      GIVEN("two trees")
      {
           BinarySearchTree<int> bst1{ 15,17,12,10,13,19,18,20};
           BinarySearchTree<int> bst2{ 15,17,12,10,19,18,20};
           
           WHEN("remove node that hasn't children")
            {
              bst1.remove(bst1.root_,13);
              THEN("trees must be equal")
                {
                  REQUIRE(bst1==bst2);
                }
             }
             
            bst1 = BinarySearchTree<int> ({ 15,17,12,10,13,19,18,20});
            bst2 = BinarySearchTree<int> ({ 15,12,10,13,19,18,20});
             WHEN("remove node that has only right child")
            {
              bst1.remove(bst1.root_,17);
              THEN("trees must be equal")
                {
                  REQUIRE(bst1==bst2);
                }
             }
             
             bst1 = BinarySearchTree<int> ({ 15,17,12,10,13,19,18,20});
             bst2 = BinarySearchTree<int> ({ 15,17,12,13,19,18,20});
             WHEN("remove node that has only left child")
            {
               bst1.remove(bst1.root_,10);
              THEN("trees must be equal")
                {
                  REQUIRE(bst1==bst2);
                }
             }
             
            bst1 = BinarySearchTree<int> ({ 15,17,12,10,13,19,18,20});
            bst2 = BinarySearchTree<int> ({ 15,17,12,10,13,18,20});
             WHEN("remove node that has both children")
            {
               bst1.remove(bst1.root_,19);
              THEN("trees must be equal")
                {
                  REQUIRE(bst1==bst2);
                }
             }
             
            bst1 = BinarySearchTree<int> ({ 15,17,12,10,13,19,18,20});
            bst2 = BinarySearchTree<int> ({ 15,17,12,10,13,19,18,20});
             WHEN("remove node that doesn't exist")
            {
               bst1.remove(bst1.root_,6);
              THEN("trees must be equal")
                {
                  REQUIRE(bst1==bst2);
                }
             }
        
            bst1 = BinarySearchTree<int>({12,20});
	          bst2 = BinarySearchTree<int>({20});
             WHEN("remove root")
            {
               bst1.remove(bst1.root_,12);
              THEN("trees must be equal")
                {
                  REQUIRE(bst1==bst2);
                }
             }
          }
       }
