import re
import random


class Chatbot:
    def __init__(self):
        self.rules = [
                {
                    "patterns": [r'hi', r'Hello', r'hey'],
                    'responses': ["Hola Mi aniga!!", "hey there"]
                },
                {
                    "responses": ["Dont Know"]
                }
        ]

    def match_patterns(self, input_text, patterns):
        for pattern in patterns:
            match = re.search(pattern, input_text, re.IGNORECASE)
            if match:
                return True
            return False

    def process_input(self, input_text):
        for data in self.rules:
            if self.match_patterns(input_text, data.get("patterns", [])):
                responses = data.get("responses")
                return random.choice(responses)
        return random.choice(self.rules[-1]['responses'])



    def start(self):
        while True:
            input_text = input(">")
            print(self.process_input(input_text))

c = Chatbot()
c.start()

