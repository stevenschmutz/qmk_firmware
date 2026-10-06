# Dosh layout

Dosh is a Taipo-style chorded layout (derived from [Posh](https://inkeys.wiki/en/keymaps/posh)) that leaves out the upper pinky key but keeps the lower one: 7 finger keys per hand plus 2 thumbs. Each half is a complete layout and the two halves can be alternated or mixed freely. The chord table is `dosh.rs` / `users/steventaipo/dosh.def`.

## Keys on each hand

The right hand is the mirror of the left hand. Both hands carry the same letters, so a chord means the same whichever hand (or mix of hands) presses it.

```
Left hand                           Right hand

        pinky  ring  middle  index   index  middle  ring  pinky
top      (r)    s      n       i       i      n      s     (r)
bottom    a     o      t       e       e      t      o      a

thumbs: outer = Space (capitals), inner = Backspace (symbols/navigation)
```

- `(r)` is the upper pinky key. Dosh never uses it.
- On the crkbd (`crkbd:steventaipo`) the Space thumb is the middle thumb key and the Backspace thumb is the one nearest the centre.

## Layers

| Thumb held | Layer | What it does |
|------------|-------|--------------|
| none | base | letters |
| Space (outer) | `_OUTER` | capitals, plus some shifted punctuation (see the chord table) |
| Backspace (inner) | `_INNER` | Esc, arrows, Enter, `.`, digits, symbols, brackets |
| both | `_BOTH` | Del, End, PgDn, Home, Tab, PgUp, `"`, F-keys |

Both thumbs together with no finger key is the null key and types nothing.

## Thumbs alone

| Key | Output |
|-----|--------|
| outer thumb | `Space` |
| inner thumb | `Backspace` |
| both thumbs | null (nothing) |

## Single finger keys

| Finger | Left hand | Right hand | Alone | +Space | +Backspace | +Both |
|--------|-----------|------------|-------|--------|------------|-------|
| bottom pinky (`a`) | `----`<br>`#---` | `----`<br>`---#` | `a` | `A` | `Esc` | `Del` |
| bottom index (`e`) | `----`<br>`---#` | `----`<br>`#---` | `e` | `E` | `Left` | `Home` |
| top index (`i`) | `---#`<br>`----` | `#---`<br>`----` | `i` | `I` | `.` | `"` |
| top middle (`n`) | `--#-`<br>`----` | `-#--`<br>`----` | `n` | `N` | `Up` | `PgUp` |
| bottom ring (`o`) | `----`<br>`-#--` | `----`<br>`--#-` | `o` | `O` | `Right` | `End` |
| top ring (`s`) | `-#--`<br>`----` | `--#-`<br>`----` | `s` | `S` | `Enter` | `Tab` |
| bottom middle (`t`) | `----`<br>`--#-` | `----`<br>`-#--` | `t` | `T` | `Down` | `PgDn` |

## Chords of two or more fingers

`#` is a finger that is pressed, `-` is one that is not. The chord is the same on either hand (or split across both). Empty cells are unmapped.

| Chord | Left hand | Right hand | Alone | +Space | +Backspace | +Both |
|-------|-----------|------------|-------|--------|------------|-------|
| `a+e` | `----`<br>`#--#` | `----`<br>`#--#` | `d` | `D` | `1` | `F1` |
| `a+i` | `---#`<br>`#---` | `#---`<br>`---#` | `w` | `W` | `6` | `F6` |
| `a+n` | `--#-`<br>`#---` | `-#--`<br>`---#` | `j` | `J` | `:` | `*` |
| `a+o` | `----`<br>`##--` | `----`<br>`--##` | `l` | `L` | `2` | `F2` |
| `a+t` | `----`<br>`#-#-` | `----`<br>`-#-#` | `q` | `Q` | `@` | `F11` |
| `e+i` | `---#`<br>`---#` | `#---`<br>`#---` | Shift (one-shot) | `]` | `[` |  |
| `e+n` | `--#-`<br>`---#` | `-#--`<br>`#---` | `r` | `R` | `0` | `F10` |
| `e+s` | `-#--`<br>`---#` | `--#-`<br>`#---` | `m` | `M` | `5` | `F5` |
| `n+i` | `--##`<br>`----` | `##--`<br>`----` | `y` | `Y` | `9` | `F9` |
| `o+e` | `----`<br>`-#-#` | `----`<br>`#-#-` | `c` | `C` | `3` | `F3` |
| `o+i` | `---#`<br>`-#--` | `#---`<br>`--#-` | `k` | `K` | `;` | `\|` |
| `o+n` | `--#-`<br>`-#--` | `-#--`<br>`--#-` | `g` | `G` | `8` | `F8` |
| `o+s` | `-#--`<br>`-#--` | `--#-`<br>`--#-` | Alt (one-shot) | `}` | `{` | Alt+Shift (one-shot) |
| `o+t` | `----`<br>`-##-` | `----`<br>`-##-` | `u` | `U` | `4` | `F4` |
| `s+i` | `-#-#`<br>`----` | `#-#-`<br>`----` | `f` | `F` | `7` | `F7` |
| `s+n` | `-##-`<br>`----` | `-##-`<br>`----` | `p` | `P` | `+` | `=` |
| `t+e` | `----`<br>`--##` | `----`<br>`##--` | `h` | `H` | `,` |  |
| `t+n` | `--#-`<br>`--#-` | `-#--`<br>`-#--` | Ctrl (one-shot) | `)` | `(` | Ctrl+Shift (one-shot) |
| `t+s` | `-#--`<br>`--#-` | `--#-`<br>`-#--` | `?` | `!` | `^` |  |
| `a+o+s` | `-#--`<br>`##--` | `--#-`<br>`--##` | Gui (one-shot) |  |  | Gui+Shift (one-shot) |
| `e+s+i` | `-#-#`<br>`---#` | `#-#-`<br>`#---` | `Ins` |  |  |  |
| `e+s+n` | `-##-`<br>`---#` | `-##-`<br>`#---` | `v` | `V` | `/` | `\` |
| `o+e+i` | `---#`<br>`-#-#` | `#---`<br>`#-#-` | ``` | `~` | `%` |  |
| `o+t+e` | `----`<br>`-###` | `----`<br>`###-` | `b` | `B` | `-` | `_` |
| `o+t+n` | `--#-`<br>`-##-` | `-#--`<br>`-##-` | `PrtSc` |  |  |  |
| `o+t+s` | `-#--`<br>`-##-` | `--#-`<br>`-##-` |  | `>` | `<` |  |
| `t+e+i` | `---#`<br>`--##` | `#---`<br>`##--` | `'` |  |  |  |
| `t+e+n` | `--#-`<br>`--##` | `-#--`<br>`##--` | `z` | `Z` | `&` | `F12` |
| `t+e+s` | `-#--`<br>`--##` | `--#-`<br>`##--` | `x` | `X` | `$` | `#` |

## Modifiers

Modifiers are one-shots: tap the chord, then press the next key. They are the same-finger vertical pairs.

| Modifier | Chord |
|----------|-------|
| Shift | `e+i` |
| Ctrl | `t+n` |
| Alt | `o+s` |
| Gui | `a+o+s` (Alt chord plus the lower pinky) |
| Ctrl+Shift | `t+n` +Both |
| Alt+Shift | `o+s` +Both |
| Gui+Shift | `a+o+s` +Both |

## Not mapped

- Media, volume and brightness keys (they need a consumer-control report).
- Seven chords are deliberately left empty: `s+n+i`, `t+i`, `o+t+i`, `o+n+i`, `e+n+i`, `o+e+s` and `o+e+n`.
- The upper pinky key and the chords that used it.
- The Taipo/Dosh/Orsy table-selection chords from the Rust firmware.
