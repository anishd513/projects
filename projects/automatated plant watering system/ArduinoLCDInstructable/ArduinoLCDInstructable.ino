<OPEN WIRE DIAGRAM VERSION 1/>
<UNIT Unit1>
  <COMPONENT Arduino>
    <X 528/>
    <INSTANCE object Arduino: TArduinoBoard
  BoardType = 'Arduino Nano'
  AnalogInputReference = Default
  Serial.Items = <
    item
      _ = TArduinoHardwareSerial
      OutputPin.Form = __OpenWireRootUnit__
      OutputPin.SinkPins = (
        __OpenWireRootUnit__.LiquidCrystalDisplay1.InputPin)
    end\>
  Digital.Items = <
    item
      _ = TArduinoAdditionalDigitalChannel
    end
    item
      _ = TArduinoAdditionalDigitalChannel
    end
    item
      _ = TArduinoAdditionalDigitalChannel
      DigitalInputPin.Form = __OpenWireRootUnit__
      DigitalInputPin.SourcePin = (
        __OpenWireRootUnit__.LiquidCrystalDisplay1.OutputPins._Pin0
        
          '__OpenWireRootUnit__.LiquidCrystalDisplay1.OutputPins.RegisterSe' +
          'lect')
    end
    item
      _ = TArduinoBasicDigitalPWMChannel
      DigitalInputPin.Form = __OpenWireRootUnit__
      DigitalInputPin.SourcePin = (
        __OpenWireRootUnit__.LiquidCrystalDisplay1.OutputPins._Pin2
        '__OpenWireRootUnit__.LiquidCrystalDisplay1.OutputPins.Enable')
    end
    item
      _ = TArduinoAdditionalDigitalChannel
      DigitalInputPin.Form = __OpenWireRootUnit__
      DigitalInputPin.SourcePin = (
        __OpenWireRootUnit__.LiquidCrystalDisplay1.OutputPins._Pin3
        '__OpenWireRootUnit__.LiquidCrystalDisplay1.OutputPins.Data0')
    end
    item
      _ = TArduinoBasicDigitalPWMChannel
      DigitalInputPin.Form = __OpenWireRootUnit__
      DigitalInputPin.SourcePin = (
        __OpenWireRootUnit__.LiquidCrystalDisplay1.OutputPins._Pin4
        '__OpenWireRootUnit__.LiquidCrystalDisplay1.OutputPins.Data1')
    end
    item
      _ = TArduinoBasicDigitalPWMChannel
      DigitalInputPin.Form = __OpenWireRootUnit__
      DigitalInputPin.SourcePin = (
        __OpenWireRootUnit__.LiquidCrystalDisplay1.OutputPins._Pin5
        '__OpenWireRootUnit__.LiquidCrystalDisplay1.OutputPins.Data2')
    end
    item
      _ = TArduinoAdditionalDigitalChannel
      DigitalInputPin.Form = __OpenWireRootUnit__
      DigitalInputPin.SourcePin = (
        __OpenWireRootUnit__.LiquidCrystalDisplay1.OutputPins._Pin6
        '__OpenWireRootUnit__.LiquidCrystalDisplay1.OutputPins.Data3')
    end
    item
      _ = TArduinoAdditionalDigitalChannel
    end
    item
      _ = TArduinoBasicDigitalPWMChannel
    end
    item
      _ = TArduinoBasicDigitalPWMChannel
    end
    item
      _ = TArduinoBasicDigitalPWMChannel
    end
    item
      _ = TArduinoAdditionalDigitalChannel
    end
    item
      _ = TArduinoAdditionalDigitalChannel
    end
    item
      _ = TArduinoCombinedAnalogDigitalChannel
    end
    item
      _ = TArduinoCombinedAnalogDigitalChannel
    end
    item
      _ = TArduinoCombinedAnalogDigitalChannel
    end
    item
      _ = TArduinoCombinedAnalogDigitalChannel
    end
    item
      _ = TArduinoAdditionalDigitalI2CChannel
    end
    item
      _ = TArduinoAdditionalDigitalI2CChannel
    end\>
end
/>
    <Y 256/>
  </COMPONENT>
  <COMPONENT LiquidCrystalDisplay1>
    <X 256/>
    <INSTANCE object LiquidCrystalDisplay1: TArduinoLiquidCrystalDisplay
  InputPin.Form = __OpenWireRootUnit__
  InputPin.SourcePins = (
    (
      __OpenWireRootUnit__.Arduino.Serial._Item0.OutputPin
      '__OpenWireRootUnit__.Arduino.Serial[0].OutputPin'))
  OutputPins.Form = __OpenWireRootUnit__
  OutputPins.Pins = (
    Sinks
    (
      (
        __OpenWireRootUnit__.Arduino.Digital._Item2.DigitalInputPin
        '__OpenWireRootUnit__.Arduino.Digital[2].DigitalInputPin'))
    nil
    Sinks
    (
      (
        __OpenWireRootUnit__.Arduino.Digital._Item3.DigitalInputPin
        '__OpenWireRootUnit__.Arduino.Digital[3].DigitalInputPin'))
    Sinks
    (
      (
        __OpenWireRootUnit__.Arduino.Digital._Item4.DigitalInputPin
        '__OpenWireRootUnit__.Arduino.Digital[4].DigitalInputPin'))
    Sinks
    (
      (
        __OpenWireRootUnit__.Arduino.Digital._Item5.DigitalInputPin
        '__OpenWireRootUnit__.Arduino.Digital[5].DigitalInputPin'))
    Sinks
    (
      (
        __OpenWireRootUnit__.Arduino.Digital._Item6.DigitalInputPin
        '__OpenWireRootUnit__.Arduino.Digital[6].DigitalInputPin'))
    Sinks
    (
      (
        __OpenWireRootUnit__.Arduino.Digital._Item7.DigitalInputPin
        '__OpenWireRootUnit__.Arduino.Digital[7].DigitalInputPin'))
    nil
    nil
    nil
    nil)
end
/>
    <Y 416/>
  </COMPONENT>
    <SELECTION LiquidCrystalDisplay1/>
    <BINDINGS object TOWPinBindingManager
end
/>
</UNIT>
