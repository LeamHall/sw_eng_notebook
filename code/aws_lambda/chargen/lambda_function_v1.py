import json
import random

class Person:

    def gen_upp(self):
        self.upp = ''
        for _ in range(6):
            self.upp += "{:X}".format(random.randint(1,6) + random.randint(1,6))

    def set_name(self):
        first_name = random.sample(['Fred', 'George', 'Jane', 'Sally'], 1 )
        last_name  = random.sample(['Smith', 'Jones', 'Vinderhoken'], 1 )
        self.name = "<b>{} {}</b>".format(first_name[0], last_name[0])

    def supp_4(self):
        response = "{} [{}] ".format(self.name, self.upp)
        response += "   "
        return response


def lambda_handler(event, context):
    char = Person()
    char.gen_upp()
    char.set_name()
    response = char.supp_4()
    return {
        'statusCode': 200,
        'headers': {
            'Content-Type': "text/html"
            },
        'body': response
    }
