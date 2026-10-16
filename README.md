# Verispeed

A 3-key macropad built around the Seeed Studio XIAO RP2040, with per-key
`SK6812MINI-E` addressable RGB LEDs. The project includes the KiCad PCB design
and the Fusion 360 case.

## Overview

| | |
|---|---|
| **MCU** | Seeed Studio XIAO RP2040 |
| **Keys** | 3 (MX-style switches) |
| **Lighting** | 3 × SK6812MINI-E addressable RGB |
| **Firmware** | QMK / KMK (RP2040) |

## Repository layout

```
verispeed/
├── pcb/                     # KiCad project (schematic + board)
│   ├── audio.kicad_pro
│   ├── audio.kicad_sch
│   ├── audio.kicad_pcb
│   └── fp-lib-table         # points at ../libraries/footprints.pretty
├── case/
│   └── verispeed_case.f3d   # Fusion 360 case model
├── libraries/
│   ├── symbols/             # Standalone symbol libraries
│   │   ├── XIAO_RP2040.kicad_sym
│   │   └── SK6812MINI-E.kicad_sym
│   └── footprints.pretty/   # Shared footprint library
│       ├── SK6812MINI-E_fixed.kicad_mod
│       ├── XIAO-Generic-Hybrid-14P-2.54-21X17.8MM.kicad_mod
│       └── hackclub-logo.kicad_mod
└── images/                  # Renders and photos (see below)
```

## Images

### Case (Fusion 360)

![Verispeed case render](images/case.png)

### PCB (KiCad)

![Verispeed PCB render](images/pcb.png)

## Bill of Materials

| Qty | Part | Notes |
|-----|------|-------|
| 1 | Seeed Studio XIAO RP2040 | Controller |
| 3 | SK6812MINI-E | Addressable RGB LEDs |
| 3 | MX-compatible switches | Hot-swap or soldered |
| 3 | Keycaps | MX stem |
| 1 | PCB | See `pcb/` |
| 1 | 3D-printed case | See `case/` |

## Getting started

### PCB

Open `pcb/audio.kicad_pro` in KiCad 8/9. The footprint library resolves via
`${KIPRJMOD}/../libraries/footprints.pretty`, so keep the `pcb/` and
`libraries/` folders side by side.

### Case

Open `case/verispeed_case.f3d` in Fusion 360.

## License

Released under the [MIT License](LICENSE).
