
while True:
    n_words = int(input())
    if n_words == 0:
        break
    best_word = ""
    best_score = -1
    for i in range(n_words):
        current_word = input()
        score = 0
        score += current_word.count("aa")
        score += current_word.count("ee")
        score += current_word.count("ii")
        score += current_word.count("oo")
        score += current_word.count("uu")
        score += current_word.count("yy")
        if score >= best_score:
            best_score = score
            best_word = current_word
    print(best_word)
