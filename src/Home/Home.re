[@react.component]
let make = _ => {
  <div>
    <button onClick={ _ => ReasonReactRouter.push("/greetings")} > {React.string("Greetings")} </button>
    <button onClick={ _ => ReasonReactRouter.push("/reduce")} > {React.string("Reduce")} </button>
    <button onClick={ _ => ReasonReactRouter.push("/blinking")} > {React.string("Blinking")} </button>
    <button onClick={ _ => ReasonReactRouter.push("/dog/many")} > {React.string("View Dogs")} </button>
    <button onClick={ _ => ReasonReactRouter.push("/dog/random")} > {React.string("Random Dog")} </button>
  </div>;
};