module Cell = {
  type t = {
    x: int,
    y: int,
  };

  let make = (x, y) => {x, y};
};

type t = {
  x: int,
  y: int,
  dx: int, // direction x
  dy: int, // direction y
  cells: array(Cell.t),
  maxCells: int,
};

let make = () => {
  x: 160,
  y: 160,
  dx: Settings.grid,
  dy: 0,
  cells: [||],
  maxCells: 4,
};

let getCells = snake => snake.cells;
let getDx = snake => snake.dx;
let getDy = snake => snake.dy;
let setSpeedLeft = snake => {...snake, dx: - Settings.grid, dy: 0};
let setSpeedUp = snake => {...snake, dx: 0, dy: - Settings.grid};
let setSpeedRight = snake => {...snake, dx: Settings.grid, dy: 0};
let setSpeedDown = snake => {...snake, dx: 0, dy: Settings.grid};
let increaseMaxCells = snake => {...snake, maxCells: snake.maxCells + 1};

let iterateCells = (snake, callback) => {
  Belt.Array.forEach(snake.cells, cell => callback(~x=cell.x, ~y=cell.y));
};

let wrapX = (snakeX, width) =>
  if (snakeX < 0) {
    width - Settings.grid;
  } else if (snakeX >= width) {
    0;
  } else {
    snakeX;
  };

let wrapY = (snakeY, height) =>
  if (snakeY < 0) {
    height - Settings.grid;
  } else if (snakeY >= height) {
    0;
  } else {
    snakeY;
  };

let extendedCells = (newX, newY, cells, maxCells) => {
  let cells = Js.Array.copy(cells);
  let newCells = Cell.make(newX, newY);
  let _ = newCells->Js.Array.unshift(cells);
  if (Js.Array.length(cells) > maxCells) {
    Js.Array.pop(cells)->ignore;
  };
  cells;
};

let move = (snake, boardWidth, boardHeight) => {
  let newX = wrapX(snake.x + snake.dx, boardWidth);
  let newY = wrapY(snake.y + snake.dy, boardHeight);
  let newCells = extendedCells(newX, newY, snake.cells, snake.maxCells);
  {...snake, x: newX, y: newY, cells: newCells};
};

let hasEatenFood = (snake, food) => {
  let found =
    snake.cells
    |> Array.find_index((cell: Cell.t) =>
         if (cell.x === Food.getX(food) && cell.y === Food.getY(food)) {
           true;
         } else {
           false;
         }
       );

  switch (found) {
  | Some(_) => true
  | None => false
  };
};

let hasEatenItself = snake => {
  snake.cells
  |> Js.Array.reducei(
       (acc, cell: Cell.t, index) =>
         if (index > 0 && snake.x === cell.x && snake.y === cell.y) {
           true;
         } else {
           acc;
         },
       false,
     );
};
