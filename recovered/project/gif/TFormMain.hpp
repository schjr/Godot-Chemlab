// Recovered declaration skeleton, NOT the original source unit.
// Exact class, component and event names come from the binary DFM.
// Base class, signatures, field layout and method bodies are unknown.
// This incomplete class is an inventory; it is not a buildable VCL form.
// Source resource: recovered/forms/gif/TFORMMAIN.dfm.bin
#pragma once

class TBitBtn;
class TImage;
class TMemo;
class TPanel;
class TProgressBar;
class TSaveDialog;

class TFormMain {
public:
    TPanel *PanelGIF;
    TImage *ImageGIF;
    TPanel *PanelButton;
    TBitBtn *ButtonConvert;
    TBitBtn *ButtonSave;
    TMemo *Memo1;
    TProgressBar *ProgressBar;
    TSaveDialog *SaveDialog;
    // Recorded event bindings; signatures must be recovered from code:
    // FormMain.OnCreate -> FormCreate
    // FormMain.OnDestroy -> FormDestroy
    // ButtonConvert.OnClick -> ButtonConvertClick
    // ButtonSave.OnClick -> ButtonSaveClick
};
