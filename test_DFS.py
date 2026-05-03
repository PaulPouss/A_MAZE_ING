import random
from dataclasses import dataclass

@dataclass
class Position():
    x: int
    y: int


class Cell():
    def __init__(self, walls: str, visited: bool):
        self.walls: str = walls
        self.visited: bool = visited


class Maze():
    def __init__(self, width: int, height: int):
        self.width = width
        self.height = height
        self.grid: list[list[Cell]] = [[Cell("F", False) for _ in range(height)] for _ in range(width)]


class MazeGenerator():

    @staticmethod
    def determine_next_cell(matrice: Maze, position: Position) -> Position:
        temp: list[Position] = []
        if position.x > 0:
            temp.append(Position(position.x - 1, position.y))
        if position.x < matrice.height:
            temp.append(Position(position.x + 1, position.y))
        if position.y > 0:
            temp.append(Position(position.x, position.y - 1))
        if position.y < matrice.width:
            temp.append(Position(position.x, position.y + 1))
        result: Position = random.choice(temp)
        return result

    @staticmethod
    def generate_maze_DFS(height: int, width: int) -> Maze:
        matrice = Maze(width, height)
        matrice.grid[0][0].walls = random.choice("BD")
        matrice.grid[0][0].visited = True
        if matrice.grid[0][0].walls == "B":
            matrice.grid[1][0].walls = random.choice("AC")
        else:
            matrice.grid[0][1].walls = random.choice("35")
            next_position = Position(0, 0)
        for _ in range(10):
            next_position = MazeGenerator.determine_next_cell(matrice,
                                                              next_position)
            print(next_position)
        return matrice


##Idée de schéma general:
complete_maze_generation:
    while next_position != NULL:
        determiner next Step
    if at lest one cell unvisited:
        go to last non visited
        complete_maze_generation
    else:
    return maze completed (or create non perfect)
        

def main() -> None:
    matrice = MazeGenerator.generate_maze_DFS(8, 8)
    for line in matrice.grid:
        for cellule in line:
            print(cellule.walls, end="")
        print("")


if __name__ == "__main__":
    main()
