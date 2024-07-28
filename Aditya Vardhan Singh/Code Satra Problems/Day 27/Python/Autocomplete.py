def autocomplete(words, prefix):
    words_list = list(words)

    suggestions = [word for word in words_list if word.startswith(prefix)]

    return suggestions

words = {"cat", "car", "cart", "dog", "dove", "door"}
prefix = "car"
print(autocomplete(words, prefix))