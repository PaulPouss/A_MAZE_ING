import random

liste = ["0", "1", "2", "3", "4", "5", "6", "7", "8",
         "9", "A", "B", "C", "D", "E", "F"]
liste_start = ["9", "B", "D", "F"]
liste_wall_east = ["2", "3", "6", "7", "A", "B", "E", "F"]
liste_wall_west = ["8", "9", "A", "B", "C", "D", "E", "F"]
liste_wall_south = ["4", "5", "6", "7", "C", "D", "E", "F"]
liste_wall_north = ["3", "5", "7", "9", "B", "D", "F"]

def maze_generator(length: int, width: int) -> None:
    matrice: list[list[str]] = [['0' for _ in range(width)] for _ in range(length)]
    matrice[0][0] = random.choice(liste_start)
    for i in range(width):
        for j in range(length):
            if i != 0 and i != width - 1:
                if matrice[j][i - 1] in liste_wall_east:
                    temp: list[str] = liste_wall_west
                else:
                    temp = list(set(liste) - set(liste_wall_west))
            elif i == width - 1:
                temp = liste_wall_east
            else:
                temp = liste_wall_west
            if j != 0 and j != length:
                if matrice[j - 1][i] in liste_wall_south:
                    temp = list(set(temp) & set(liste_wall_north))
                else:
                    temp = list(set(temp) - set(liste_wall_north))
            elif j == length:
                temp = list(set(temp) & set(liste_wall_south))
            else:
                temp = list(set(temp) & set(liste_wall_north))
            matrice[j][i] = random.choice(temp)
    for line in matrice:
        print(line)


def main() -> None:
    maze_generator(15, 15)


if __name__ == "__main__":
    main()