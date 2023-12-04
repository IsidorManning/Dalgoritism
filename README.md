# Algoritism
Simply put, a portfolio of a bunch algorithms 

# Purpose

This will be a long term project that I dynamically will update as I learn more and more about different algorithms such as sorting algorithms. By implementing the algorithms I learn about by myself I force myself to learn exactly how they work and to acheive an intuitive feel for them. 

# The Design

We have two classes, one class called IntManipulation and another one called StringManipulation. Both of them can be used to manipulate vectors containing elements of their respective data type (either type int or type string). The idea is that a user would be able to input a vector to either of the class's constructors and then simply call methods of that class to manipulate their vector. This is why you will see that we always pass around the inputted vector by reference so that we don't need to make a copy of the vector and then return a whole new vector; we will always manipulate the reference to the actual vector itself.

Other than that, we have our usual getter (or accessor if you will) called get_size() that simply returns the size of the member variable _data that is the vector inputted by the user that got initialized in the constructor. This getter is prefixed with the const keyword to reassure that we don't change anything when we simply want to get the size. We also have serialization methods so that the user can easily visualize their vector at any point.
