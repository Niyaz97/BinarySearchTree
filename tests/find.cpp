#include "../include/BinarySearchTree.hpp"
#include "catch.hpp"

SCENARIO("if element exists in tree, return pointer to this element") 
{
    GIVEN("tree") 
    {
        BinarySearchTree<int> tree{1, 3, 5};
        WHEN("find") 
        {
            THEN("return poinet to this element") 
            {
                REQUIRE(*(tree.find(3)) == 3);
            }
        }
    }
}

SCENARIO("if element doesn't exist in tree, return nullptr") 
{
    GIVEN("tree") 
    {
        BinarySearchTree<int> tree{1, 3, 5};
        WHEN("find") 
        {
            THEN("return nullptr") 
            {
                REQUIRE(tree.find(2) == nullptr);
            }
        }
    }
}

SCENARIO("find method must work for constant tree and non-constant tree") 
{
    GIVEN("constant and non-constant tree") 
    {
        const BinarySearchTree<int> tree1{4, 5, 6};
        BinarySearchTree<int> tree2{7, 8, 9};
        WHEN("find") 
        {
            THEN("return element for constant and non-constant tree") 
            {
                REQUIRE(tree1.find(4));
                REQUIRE(tree2.find(9));
            }
        }
    }
}
