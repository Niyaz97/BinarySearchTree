#include "../include/BinarySearchTree.hpp"
#include "catch.hpp"

SCENARIO("if element exists in tree, return pointer to this element") 
{
    GIVEN("tree") 
    {
        BinarySearchTree<int> tree{5, 6, 7};
        WHEN("find") 
        {
            THEN("return poinet to this element") 
            {
                REQUIRE(*(tree.find(5)) == 5);
            }
        }
    }
}

SCENARIO("if element doesn't exist in tree, throw an exception") 
{
    GIVEN("tree") 
    {
        BinarySearchTree<int> tree{5, 6, 7};
        WHEN("find") 
        {
            THEN("throw an exception") 
            {
                REQUIRE_THROW_AS(tree.find(4), BinarySearchTree<int>::Exceptions);
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
