[@bs.deriving abstract]
type state = {count: int};

let state = state(~count=0);

let initState = {"count": state |. count};

let actions = {
  "increment": (. state: state) => {count: (state |. count) + 1},
  "decrement": (. state: state) => {count: (state |. count) - 1},
};

let view = (. initState, actions) => App.view(initState, actions);

Js.Nullable.bind(Hyperapp.getElementById("main"), (. main) =>
  Hyperapp.app(~state=initState, ~actions, ~view, main)
);