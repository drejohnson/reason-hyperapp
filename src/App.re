let view = (state, actions) => {
  let count = state##count;
  Hyperapp.(
    h(
      "div",
      {"class": "main"},
      [|
        h("h2", Js.Obj.empty(), [|string("Hello from Hyperapp")|]),
        h(
          "h3",
          Js.Obj.empty(),
          [|string("Count is " ++ string_of_int(count))|],
        ),
        h(
          "button",
          {"onclick": () => actions##increment},
          [|string("Increment")|],
        ),
        h(
          "button",
          {"onclick": () => actions##decrement},
          [|string("Decrement")|],
        ),
      |],
    )
  );
};