let snakeRef = ref(Snake.make());
let foodRef = ref(Food.make());

Bindings.getElementById(Settings.boardId)
->(
    fun
    | Some(canvas) => {
        let board = Board.make(canvas);

        let _ = Controls.makeControl(snakeRef);
        let play = Game.make(board, snakeRef, foodRef);

        play();
      }
    | None =>
      Js.Console.error(
        "Failed to start React: couldn't find the #root element",
      )
  );
