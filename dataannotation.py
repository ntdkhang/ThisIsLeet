def decode(message_file):
    word_map = {}
    while True:
        line = message_file.readline()
        if not line:
            break
        if line.strip():
            index, word = int(line.split(" ")[0]), line.split(" ")[1].strip()
            word_map[index] = word

    height = 1
    index = 1
    final_message = ""
    while index <= len(word_map):
        final_message += word_map[index]
        height += 1
        index += height
        if index <= len(word_map):
            final_message += " "

    return final_message



print(decode(message_file=open("input.txt", "r")))


