module Event = {
  type t = {
    key: [@mel.string] [ | `ArrowLeft | `ArrowUp | `ArrowRight | `ArrowDown],
  };
};

module Canvas = {
  module Context = {
    type t;

    [@mel.send]
    external clearRect:
      (t, ~x: int, ~y: int, ~width: int, ~height: int) => unit =
      "clearRect";

    [@mel.send]
    external fillRect: (t, ~x: int, ~y: int, ~width: int, ~height: int) => unit =
      "fillRect";

    [@mel.set] external setFillStyle: (t, string) => unit = "fillStyle";
  };

  type t = {
    width: int,
    height: int,
  };

  [@mel.send]
  external getContext:
    (
      t,
      [@mel.string] [
        | [@mel.as "2d"] `TwoD
        | [@mel.as "webgl"] `WebGL
        | [@mel.as "webgl2"] `WebGL2
        | [@mel.as "webgpu"] `WebGPU
        | [@mel.as "bitmaprenderer"] `BitMapRenderer
      ]
    ) =>
    Context.t =
    "getContext";
};

[@mel.scope "document"]
external getElementById: string => option(Canvas.t) = "getElementById";

[@mel.scope "document"]
external addEventListener:
  ([@mel.string] [ | [@mel.as "keydown"] `KeyDown], Event.t => unit) =>
  Canvas.t =
  "addEventListener";

[@mel.scope "window"]
external requestAnimationFrame: (unit => unit) => unit =
  "requestAnimationFrame";
