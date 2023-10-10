proper = ["hello"]
greeting = input("Greeting: ")
word = greeting.strip()
if word.lower()[0:5] in proper:
    print("$0")
elif word.lower()[0] == "h":
    print("$20")
else:
    print("$100")
