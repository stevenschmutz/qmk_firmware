# Corne Keyboard Layout

This is an example for the Corne keyboard.

- The core layout is 2x(3x5 + 3) = 36

```options
layoutFn = LAYOUT
```

```aliases
lock = c+g+q
```

## Keyboard Structure

```structure
49  1  2  3  4  5    ||     6  7  8  9 10 50
51 11 12 13 14 15    ||    16 17 18 19 20 52
53 21 22 23 24 25    ||    26 27 28 29 30 56
            31 32 33 || 34 35 36
```

## Base layer

```layer:base
tab       q      w      e      r      t                  ||      y    u      i      o      p      \
lgui      lctl/a lsft/s lgui/d l(f)/f g                  ||      h    l(j)/j rgui/k rsft/l rctl/; '
osm(lsft) z      x      lalt/c l(v)/v b                  ||      n    l(m)/m lalt/, .      /      osm(rsft)
                               lctl   osm(lgui) spc      || ent  bs   ralt
```

## Layer: F (when F is held)

```layer:f
__        esc    __     __     __     __                 ||      ~    pgdn   s+tab  tab    pgup   __
__        __     __     __     __     to(game)           ||      left down   up     right  __     __
__        __     __     __     __     __                 ||      bs   ent    home   end    /      __
                               __     __        __       || __   __   __
```

## Layer: J (when J is held)

```layer:j
*         `      :      (      )      ~                  ||      __   __     __     __     __     __
=         _      -      [      ]      $                  ||      __   __     __     __     __     __
__        |      <      {      }      >                  ||      __   __     __     __     __     __
                               __     __        __       || __   __   __
```

## Layer: V (when V is held)

```layer:v
__        __     vol+   __     __     __                 ||      +    7      8      9      *      __
__        __     play   __     __     __                 ||      -    4      5      6      =      __
__        __     vol-   __     __     __                 ||      0    1      2      3      .      __
                               __     __        __       || __   __   ,
```

## Layer: M (when M is held)

```layer:m
__        __     __     __     __     __                 ||      __   __     __     vol+   __     __
__        __     __     __     __     __                 ||      __   __     __     play   __     __
__        __     __     __     __     __                 ||      __   __     __     vol-   __     __
                               __     __        __       || __   __   __
```

## Layer: Gaming

```layer:game
tab       q      w      e      r      t                  ||      y    u      i      o      p      \
lgui      a      s      d      f      g                  ||      h    j      k      l      ;      '
lsft      z      x      c      v      b                  ||      n    m      ,      .      /      rsft
                               lctl   osm(lgui) spc      || ent  bs   ralt
```

## Layer template

```disabled:layer
__   __     __     __      __     __            ||          __  __     __     __     __     __
__   __     __     __      __     __            ||          __  __     __     __     __     __
__   __     __     __      __     __            ||          __  __     __     __     __     __
                           __     __       __   || __       __  __
```
