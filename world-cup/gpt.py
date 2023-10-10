import csv
import sys
import random

N = 1000  # Number of simulations to run

def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = read_teams_from_file(sys.argv[1])

    win_counts = simulate_tournaments(teams)

    print_win_probabilities(win_counts)

def read_teams_from_file(filename):
    teams = []
    with open(filename) as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            team_name = row["team"]
            rating = int(row["rating"])
            team = {"team_name": team_name, "rating": rating}
            teams.append(team)
    return teams

def simulate_tournaments(teams):
    counts = {}
    for _ in range(N):
        winner = simulate_tournaments(teams)
        counts[winner] = counts.get(winner, 0) + 1
    return counts

def print_win_probabilities(win_counts):
    total_simulations = N
    for team, count in sorted(win_counts.items(), key=lambda x: x[1], reverse=True):
        probability = count * 100 / total_simulations
        print(f"{team}: {probability:.1f}% chance of winning")

if __name__ == "__main__":
    main()
