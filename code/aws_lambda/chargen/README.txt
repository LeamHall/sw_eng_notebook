AWS Lambda Character Generator
==============================

This is a simple AWS Lambda function that generates random character attributes for an RPG character generator.


Files
-----

lambda_function_v1.py   - Original monolithic version (all code in one file)
lambda_function.py      - Refactored version (uses Person module)
person/                 - Person module directory
  person.py             - Person class with character generation logic
  __init__.py           - Python package marker


Refactoring Journey
-------------------

Version 1 (lambda_function_v1.py):
- Single file containing both the Person class and lambda_handler
- Good for quick prototyping and simple functions
- All code is in one place, easy to understand initially

Version 2 (lambda_function.py + person/):
- Separated Person class into its own module
- Better code organization and maintainability
- Person class can be tested independently
- Follows separation of concerns principle


Functionality
-------------

The Person class provides:
- gen_upp(): Generates 6 random hex values (1-12) for character attributes
- set_name(): Randomly selects first and last name
- supp_4(): Formats output as "Name [Attributes]"

The lambda_handler:
- Creates a Person instance
- Generates attributes and name
- Returns HTML-formatted response


Usage with AWS Lambda
----------------------

1. Deploy to AWS Lambda using the refactored version
2. Create an API Gateway integration
3. Test via the API Gateway invoke URL
4. See sections/aws__lambda_api_gateway.txt for full setup instructions


Testing Locally
---------------

python3
>>> from person.person import Person
>>> char = Person()
>>> char.gen_upp()
>>> char.set_name()
>>> print(char.supp_4())
