import re
import random

class Chatbot:
    def __init__(self):
        self.rules = {
            'greet' : {
                'patterns': [r'hi', r'hello', r'hey'],
                'responses': [r'Hi, There!', r'Hello !', r'Hey, There!'],
            },
            'status' : {
                'patterns': [r'how are you', r'how you doing'],
                'responses': ['Fine, Thanks for asking!', 'Fine, till now :)'],
            },
            'joke': {
                'patterns': [r'joke', r'laugh'],
                'responses': ['how do you organize a space party? you planet', 'I am reading a book about anti-gravity. its impossible to put down'],
            },
            'weather': {
                'patterns': [r'weather'],
                'responses': ['I think, It will be raining', 'It will be warm cloudy day'],
            },
            'time': {
                'patterns': [r'time'],
                'responses': ['Its 9:54AM'],
            },
            'exit': {
                'patterns': [r'bye', r'quit', r'exit'],
                'responses': ['Ok, Bye', 'Byeee'],
            },
            'default': {
                'responses': ['I dont know how to respond to this', 'I didnt understand that. Can you please rephrase?']
            }
        }

    def match_patterns(self, input_text, patterns):
        for pattern in patterns:
            match = re.search(pattern, input_text, re.IGNORECASE)
            if match:
                return True
        return False

    def process_input(self, input_text):
        for intent, data in self.rules.items():
            if self.match_patterns(input_text, data.get('patterns', [])):
                responses = data.get('responses')
                return random.choice(responses)

        return random.choice(self.rules['default']['responses'])


    def start(self):
        input_text = ''
        while (not self.match_patterns(input_text, self.rules['exit']['patterns'])):
            input_text = input()
            print(self.process_input(input_text))


c = Chatbot()
c.start()

