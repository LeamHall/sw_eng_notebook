import json
import random
from person.person import Person

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
