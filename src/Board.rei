module Canvas = Bindings.Canvas;
module Context = Canvas.Context;
type t = {
  context: Context.t,
  width: int,
  height: int,
};
let make: Canvas.t => t;
let getWidth: t => int;
let getHeight: t => int;
let clear: t => unit;
let drawFood: (t, Food.t) => unit;
let drawSnake: (t, Snake.t) => unit;
