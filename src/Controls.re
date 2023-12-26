let changeDirection = (snakeRef, event: Bindings.Event.t) => {
  let snake = snakeRef.contents;
  let data = (event.key, Snake.getDx(snake), Snake.getDy(snake));
  switch (data) {
  | (`ArrowLeft, 0, _) => snakeRef := Snake.setSpeedLeft(snake)
  | (`ArrowRight, 0, _) => snakeRef := Snake.setSpeedRight(snake)
  | (`ArrowUp, _, 0) => snakeRef := Snake.setSpeedUp(snake)
  | (`ArrowDown, _, 0) => snakeRef := Snake.setSpeedDown(snake)
  | _ => ()
  };
};

let makeControl = snakeRef => {
  Bindings.addEventListener(`KeyDown, event => {
    changeDirection(snakeRef, event)
  });
};
