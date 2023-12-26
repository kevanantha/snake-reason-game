let make = (board, snakeRef, foodRef) => {
  let countRef = ref(0);

  let rec loop = () => {
    loop->Bindings.requestAnimationFrame;

    let count = countRef.contents;
    if (count < Settings.countPerUpdate) {
      countRef := count + 1;
    } else {
      countRef := 0;
      let snake = snakeRef.contents;
      let food = foodRef.contents;
      let boardWidth = Board.getWidth(board);
      let boardHeight = Board.getHeight(board);

      // Move the snake
      snakeRef := Snake.move(snake, boardWidth, boardHeight);

      // Check if the snake has eaten the food
      if (Snake.hasEatenFood(snake, food)) {
        // If so, make the snake longer and generate new food
        snakeRef := Snake.increaseMaxCells(snake);
        foodRef := Food.make();
      };
      // Check if the snake has eaten itself
      if (Snake.hasEatenItself(snake)) {
        // If so, reset the snake and generate new food
        snakeRef := Snake.make();
        foodRef := Food.make();
      };

      Board.clear(board);
      Board.drawSnake(board, snake);
      Board.drawFood(board, food);
    };
  };

  loop;
};
