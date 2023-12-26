type t = {
  x: int,
  y: int,
};

let make = () => {
  let min = 0;
  let max = 25;

  {
    x: Utils.getRandomInt(~min, ~max) * Settings.grid,
    y: Utils.getRandomInt(~min, ~max) * Settings.grid,
  };
};

let getX = food => food.x;
let getY = food => food.y;
