// Recovered declaration skeleton, NOT the original source unit.
// Exact class, component and event names come from the binary DFM.
// Base class, signatures, field layout and method bodies are unknown.
// This incomplete class is an inventory; it is not a buildable VCL form.
// Source resource: recovered/forms/_ency/TDATAMODULE1.dfm.bin
#pragma once

class TADOConnection;
class TADOQuery;
class TAggregateField;
class TAutoIncField;
class TDataSource;
class TMemoField;
class TSmallintField;
class TWideStringField;

class TDataModule1 {
public:
    TADOConnection *ADOConnection1;
    TADOQuery *ADOQuery1;
    TSmallintField *ADOQuery1elenum;
    TWideStringField *ADOQuery1finder;
    TWideStringField *ADOQuery1findtime;
    TWideStringField *ADOQuery1howtofind;
    TWideStringField *ADOQuery1nameby;
    TMemoField *ADOQuery1describe1;
    TMemoField *ADOQuery1source;
    TMemoField *ADOQuery1use;
    TAggregateField *ADOQuery1zhhtest;
    TADOQuery *ADOQuery2;
    TADOQuery *ADOQuery3;
    TADOQuery *ADOQuery4;
    TADOQuery *links;
    TAutoIncField *linksid;
    TWideStringField *linkslinkname;
    TWideStringField *linksmastertable;
    TWideStringField *linksmasterfield;
    TWideStringField *linksmastervalue;
    TWideStringField *linksslavertable;
    TWideStringField *linksslaverfield;
    TWideStringField *linksslavervalue;
    TDataSource *links_ds;
    // Recorded event bindings; signatures must be recovered from code:
    // DataModule1.OnCreate -> DataModuleCreate
    // ADOQuery1elenum.OnGetText -> ADOQuery1elenumGetText
    // linksmastervalue.OnGetText -> linksmastervalueGetText
    // linksslavervalue.OnGetText -> linksslavervalueGetText
};
