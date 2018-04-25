let view = (state, actions) =>
  Hyperapp.(
    h(
      "div",
      {"class": "main"},
      [|
        h_("h2", [|string("Hello from Hyperapp")|]),
        h_("h3", [|string("Count is " ++ string_of_int(state##count))|]),
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