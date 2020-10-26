# Prover #

### HOW TO UNDERSTAND THIS PROJECT ###

This is an attempt to prove theorems with computer programs.

Suppose a proof is equivalent to an expression, then it is essential to **PARSE**, **BUILD** and **STORE** an expression first.

Therefore essentially there are three steps to evaluate an expression: **PARSE**, **BUILD** and **STORE**. I will demonstrate them separately later but I want to talk about expression in this project first.

### EXPRESSION ###
An expression consists of two types of **elements**: *property* and *object*. Here is an expression for example: "A tree is acylic.". "Tree" and "Acyclic" are two different elements. A tree exists as an object but acyclic is a property used to describe an object. In other words, properties cannot be interpreted without objects.

To describe "A tree is acyclic" we can represent it as a linked list:
	Tree -- Acyclic
	(Object)   (Property)

However when there are more objects and properties in the expression, the expression will become a tree that has a root object. An object can have another object as well. For example a graphcan have a cycle that has its own objects and properties.

To conclude, properties are always pointed to but never point to another object/property in the expression graph but an object can be pointed to by its parent object and points to its child object.

### PARSE ###



