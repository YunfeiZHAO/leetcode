def tournamentWinner(competitions, results):
    scores = {}
    for i, e in enumerate(competitions):
        if not e[0] in scores:
            scores[e[0]] = 0
        if not e[1] in scores:
            scores[e[1]] = 0
        if results[i] == 0:
            scores[e[1]] += 6
        else:
            scores[e[0]] += 6
    team = max(scores, key=scores.get)
    return team

if __name__ == "__main__":
    competitions = [['s'], ['d']]