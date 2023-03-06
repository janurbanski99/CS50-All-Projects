# Simulate a sports tournament

import csv
import sys
import random
import math

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    with open(sys.argv[1], "r") as file:
        reader =  csv.DictReader(file)
        for team in reader:
            team["rating"] = int(team["rating"])
            teams.append(team)

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    #while N > 0:
    for x in range(N):      #DO ZMIANY JKBC
        winner = str(simulate_tournament(teams))
        if winner in counts:
            counts[winner] += 1
        else:
            counts[winner] = 1
        #x += 1     jak in range to nie trzeba aaa
        #N = N - 1

    # while N > 0:
    #     simulate_tournament(teams)
    #     if winners in counts:
    #         counts[winners] += 1
    #     else:
    #         counts[winners] = 1
    #     N -= 1

    # Print each team's chances of winning, according to simulation

    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])
    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    #num_rounds = math.log2(len(teams))  #wiem ile razy trzeba przywołać simulate_round

    next_round = simulate_round(teams)  #ew poprawić to na listę i niżej też

    while len(next_round) > 1:
        copy = next_round.copy()
        next_round = simulate_round(copy)

    #print(next_round)


    for dict in next_round:
        res = list(dict.values())[0]
        #print(res)
        return res

    #return next_round   #zwraca mi to 1 el listę z 1 słownikiem

    # winner = [simulate_round(teams)]
    # n_teams = len(teams)
    # while(n_teams > 1):
    #     simulate_round(teams)
    #     n_teams = n_teams / 2



if __name__ == "__main__":
    main()
