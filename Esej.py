a, b = map(int, input().split())
v_size = b//2


def create_vocab(current_vocab=[], depth=0, current_word=['' for _ in range(4)]):
    if depth == 4:
        current_vocab.append(''.join(current_word))
        return
    for i in range(97, 123):
        current_word[depth] = chr(i)
        create_vocab(current_vocab, depth+1, current_word)
    return current_vocab


vocab = create_vocab()
print(' '.join(vocab[:b]))
