open Revery_UI;
open Style;
let component = React.nativeComponent("Text");

let make =
    (
      ~key=?,
      ~onMouseDown=?,
      ~onMouseMove=?,
      ~onMouseUp=?,
      ~onMouseOver=?,
      ~onMouseOut=?,
      ~onMouseWheel=?,
      ~ref=?,
      ~style=emptyTextStyle,
      ~text="",
      ~gamma,
      children,
    ) =>
  component(~key?, hooks =>
    (
      hooks,
      {
        make: () => {
          let styles = create(~style, ());
          let events =
            NodeEvents.make(
              ~ref?,
              ~onMouseDown?,
              ~onMouseMove?,
              ~onMouseUp?,
      ~onMouseOver?,
      ~onMouseOut?,
              ~onMouseWheel?,
              (),
            );
          let node = PrimitiveNodeFactory.get().createTextNode(text);
          node#setEvents(events);
          node#setStyle(styles);
          Obj.magic(node);
        },
        configureInstance: (~isFirstRender as _, node) => {
          let styles = create(~style, ());
          let events =
            NodeEvents.make(
              ~ref?,
              ~onMouseDown?,
              ~onMouseMove?,
              ~onMouseUp?,
        ~onMouseOver?,
        ~onMouseOut?,
              ~onMouseWheel?,
              (),
            );

          /* TODO: Proper way to downcast? */
          let tn: textNode = Obj.magic(node);
          tn#setEvents(events);
          tn#setStyle(styles);
          tn#setText(text);
          tn#setGamma(gamma);
          node;
        },
        children,
      },
    )
  );

let createElement =
    (
      ~onMouseDown=?,
      ~onMouseMove=?,
      ~onMouseUp=?,
      ~onMouseWheel=?,
      ~onMouseOver=?,
      ~onMouseOut=?,
      ~ref=?,
      ~style=emptyTextStyle,
      ~text="",
      ~children,
      ~gamma=2.2,
      (),
    ) =>
  make(
    ~onMouseDown?,
    ~onMouseMove?,
    ~onMouseUp?,
    ~onMouseWheel?,
      ~onMouseOver?,
      ~onMouseOut?,
    ~ref?,
    ~style,
    ~text,
    ~gamma,
    React.listToElement(children),
  );
