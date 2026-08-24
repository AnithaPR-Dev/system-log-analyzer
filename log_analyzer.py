import json

with open("logs.json", "r") as file:
    entries = json.load(file)

print(entries)