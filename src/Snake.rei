module Cell: {
  type t = {
    x: int,
    y: int,
  };
  let make: (int, int) => t;
};
type t = {
  x: int,
  y: int,
  dx: int,
  dy: int,
  cells: array(Cell.t),
  maxCells: int,
};
let make: unit => t;
let getCells: t => array(Cell.t);
let getDx: t => int;
let getDy: t => int;
let setSpeedLeft: t => t;
let setSpeedUp: t => t;
let setSpeedRight: t => t;
let setSpeedDown: t => t;
let increaseMaxCells: t => t;
let iterateCells: (t, (~x: int, ~y: int) => unit) => unit;
let wrapX: (int, int) => int;
let wrapY: (int, int) => int;
let extendedCells: (int, int, array(Cell.t), int) => array(Cell.t);
let move: (t, int, int) => t;
let hasEatenFood: (t, Food.t) => bool;
let hasEatenItself: t => bool;
