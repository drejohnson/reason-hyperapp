type state = {. "count": int};

type actions = {
  .
  "increment": (. state) => state,
  "decrement": (. state) => state,
};

let state = {"count": 0};

let actions = {
  "increment": (. state: state) => {"count": state##count + 1},
  "decrement": (. state: state) => {"count": state##count - 1},
};

let view =
  (. state: state, actions: actions) =>
    Hyperapp.(
      h_(
        "div",
        [|
          h_("h2", [|string("Hello from Hyperapp from test view")|]),
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