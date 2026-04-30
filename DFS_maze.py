import random

class Cell():
    def __init__(self, walls: str, visited: bool):
        self.walls: str = walls
        self.visited: bool = visited


class Maze():
    def __init__(self, width: int, height: int):
        self.grid: list[list[Cell]] = [[Cell("F", False) for _ in range(height)] for _ in range(width)]


class MazeGenerator():

    @staticmethod
    def generate_maze_DFS(height: int, width: int) -> Maze:
        matrice = Maze(width, height)
        matrice.grid[0][0].walls = random.choice("BD")
        matrice.grid[0][0].visited = True
        if matrice.grid[0][0].walls == "B":
            matrice.grid[1][0].walls = random.choice("AC")
        else:
            matrice.grid[0][1].walls = random.choice("35")
        
        return matrice


def main() -> None:
    matrice = MazeGenerator.generate_maze_DFS(8, 8)
    for line in matrice.grid:
        for cellule in line:
            print(cellule.walls, end="")
        print("")

if __name__ == "__main__":
    main()
