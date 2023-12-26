let getRandomInt = (~min, ~max) => {
  let max = Float.of_int(max);
  let min = Float.of_int(min);
  let diff = max -. min;
  let rand = Js.Math.floor_int(Js.Math.random() *. diff);

  Int.of_float(Float.of_int(rand) +. min);
};
