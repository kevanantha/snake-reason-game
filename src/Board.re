module Canvas = Bindings.Canvas;
module Context = Canvas.Context;

type t = {
  context: Context.t,
  width: int,
  height: int,
};

let make = canvas => {
  context: Canvas.getContext(canvas, `TwoD),
  width: canvas.width,
  height: canvas.height,
};

let getWidth = canvas => canvas.width;
let getHeight = canvas => canvas.height;

let clear = board => {
  let {context, width, height} = board;
  context->Context.clearRect(~x=0, ~y=0, ~width, ~height);
};
let drawFood = (board, food) => {
  open Context;
  open Settings;

  let {context, _} = board;
  let rectSize = grid - 1;

  context->setFillStyle(foodColor);

  context->fillRect(
    ~x=Food.getX(food),
    ~y=Food.getY(food),
    ~width=rectSize,
    ~height=rectSize,
  );
};

let drawSnake = (board, snake) => {
  open Context;
  open Settings;

  let {context, _} = board;
  let rectSize = grid - 1;

  context->setFillStyle(snakeColor);

  Snake.iterateCells(snake, (~x, ~y) => {
    context->fillRect(~x, ~y, ~width=rectSize, ~height=rectSize)
  });
};
