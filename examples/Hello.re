open Revery;
open Revery.Math;
open Revery.UI;
open Revery.UI.Components;

let logo = {
  [@component]
  let make = ((), hooks) => {
    let (logoOpacity, setOpacity, hooks) = Hooks.state(1.0, hooks);

    let (rotation, hooks) =
      Hooks.animation(
        Animated.floatValue(0.),
        Animated.options(
          ~toValue=6.28,
          ~duration=Seconds(8.),
          ~delay=Seconds(1.0),
          ~repeat=true,
          (),
        ),
        hooks,
      );

    let (rotationY, hooks) =
      Hooks.animation(
        Animated.floatValue(0.),
        Animated.options(
          ~toValue=6.28,
          ~duration=Seconds(4.),
          ~delay=Seconds(0.5),
          ~repeat=true,
          (),
        ),
        hooks,
      );

    let onMouseDown = _ => setOpacity(0.5);

    let onMouseUp = _ => setOpacity(1.0);

    (
      hooks,
      <View onMouseDown onMouseUp>
        <Opacity opacity=logoOpacity>
          <Image
            src="outrun-logo.png"
            style=Style.[
              width(512),
              height(256),
              transform([
                Transform.RotateY(Angle.from_radians(rotationY)),
                Transform.RotateX(Angle.from_radians(rotation)),
              ]),
            ]
          />
        </Opacity>
      </View>,
    );
  };
  ();
};

let animatedText = {
  [@component]
  let make = (~text: string, ~delay: float, (), hooks) => {
    let (animatedOpacity, hooks) =
      Hooks.animation(
        Animated.floatValue(0.),
        Animated.options(
          ~toValue=1.0,
          ~duration=Seconds(1.),
          ~delay=Seconds(delay),
          (),
        ),
        hooks,
      );

    let (translate, hooks) =
      Hooks.animation(
        Animated.floatValue(50.),
        Animated.options(
          ~toValue=1.0,
          ~duration=Seconds(0.5),
          ~delay=Seconds(delay),
          (),
        ),
        hooks,
      );

    let textHeaderStyle =
      Style.[
        color(Colors.white),
        fontFamily("Roboto-Regular.ttf"),
        fontSize(24),
        marginHorizontal(8),
        transform([Transform.TranslateY(translate)]),
      ];

    (
      hooks,
      <Opacity opacity=animatedOpacity>
        <Text style=textHeaderStyle text />
      </Opacity>,
    );
  };
  ();
};

let render = () =>
  <Center>
    <Row>
      <animatedText delay=0.0 text="Welcome" />
      <animatedText delay=0.5 text="to" />
      <animatedText delay=1. text="Revery" />
    </Row>
    <logo />
  </Center>;
