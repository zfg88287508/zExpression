{$IFDEF OverflowCheck}{$Q-}{$ENDIF}
{$IFDEF RangeCheck}{$R-}{$ENDIF}

function ROL8(const Value: Byte; Shift: Byte): Byte;
begin
  Shift := Shift and $07;
  Result := Byte((Value shl Shift) or (Value shr (8 - Shift)));
end;

function ROL16(const Value: Word; Shift: Byte): Word;
begin
  Shift := Shift and $0F;
  Result := Word((Value shl Shift) or (Value shr (16 - Shift)));
end;

function ROL32(const Value: Cardinal; Shift: Byte): Cardinal;
begin
  Shift := Shift and $1F;
  Result := Cardinal((Value shl Shift) or (Value shr (32 - Shift)));
end;

function ROL64(const Value: UInt64; Shift: Byte): UInt64;
begin
  Shift := Shift and $3F;
  Result := UInt64((Value shl Shift) or (Value shr (64 - Shift)));
end;

function ROR8(const Value: Byte; Shift: Byte): Byte;
begin
  Shift := Shift and $07;
  Result := UInt8((Value shr Shift) or (Value shl (8 - Shift)));
end;

function ROR16(const Value: Word; Shift: Byte): Word;
begin
  Shift := Shift and $0F;
  Result := Word((Value shr Shift) or (Value shl (16 - Shift)));
end;

function ROR32(const Value: Cardinal; Shift: Byte): Cardinal;
begin
  Shift := Shift and $1F;
  Result := Cardinal((Value shr Shift) or (Value shl (32 - Shift)));
end;

function ROR64(const Value: UInt64; Shift: Byte): UInt64;
begin
  Shift := Shift and $3F;
  Result := UInt64((Value shr Shift) or (Value shl (64 - Shift)));
end;

function Endian(const AValue: SmallInt): SmallInt;
begin
  { the extra Word type cast is necessary because the "AValue shr 8" }
  { is turned into "Integer(AValue) shr 8", so if AValue < 0 then }
  { the sign bits from the upper 16 bits are shifted in rather than }
  { zeroes. }
  Result := SmallInt((Word(AValue) shr 8) or (Word(AValue) shl 8));
end;

function Endian(const AValue: Word): Word;
begin
  Result := Word((AValue shr 8) or (AValue shl 8));
end;

function Endian(const AValue: Integer): Integer;
begin
  Result := ((Cardinal(AValue) shl 8) and $FF00FF00) or ((Cardinal(AValue) shr 8) and $00FF00FF);
  Result := (Cardinal(Result) shl 16) or (Cardinal(Result) shr 16);
end;

function Endian(const AValue: Cardinal): Cardinal;
begin
  Result := ((AValue shl 8) and $FF00FF00) or ((AValue shr 8) and $00FF00FF);
  Result := (Result shl 16) or (Result shr 16);
end;

function Endian(const AValue: Int64): Int64;
begin
  Result := ((UInt64(AValue) shl 8) and $FF00FF00FF00FF00) or ((UInt64(AValue) shr 8) and $00FF00FF00FF00FF);
  Result := ((UInt64(Result) shl 16) and $FFFF0000FFFF0000) or ((UInt64(Result) shr 16) and $0000FFFF0000FFFF);
  Result := (UInt64(Result) shl 32) or ((UInt64(Result) shr 32));
end;

function Endian(const AValue: UInt64): UInt64;
begin
  Result := ((AValue shl 8) and $FF00FF00FF00FF00) or ((AValue shr 8) and $00FF00FF00FF00FF);
  Result := ((Result shl 16) and $FFFF0000FFFF0000) or ((Result shr 16) and $0000FFFF0000FFFF);
  Result := (Result shl 32) or ((Result shr 32));
end;

function BE2N(const AValue: SmallInt): SmallInt;
begin
{$IFDEF BIG_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function BE2N(const AValue: Word): Word;
begin
{$IFDEF BIG_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function BE2N(const AValue: Integer): Integer;
begin
{$IFDEF BIG_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function BE2N(const AValue: Cardinal): Cardinal;
begin
{$IFDEF BIG_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function BE2N(const AValue: Int64): Int64;
begin
{$IFDEF BIG_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function BE2N(const AValue: UInt64): UInt64;
begin
{$IFDEF BIG_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function LE2N(const AValue: SmallInt): SmallInt;
begin
{$IFDEF LITTLE_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function LE2N(const AValue: Word): Word;
begin
{$IFDEF LITTLE_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function LE2N(const AValue: Integer): Integer;
begin
{$IFDEF LITTLE_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function LE2N(const AValue: Cardinal): Cardinal;
begin
{$IFDEF LITTLE_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function LE2N(const AValue: Int64): Int64;
begin
{$IFDEF LITTLE_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function LE2N(const AValue: UInt64): UInt64;
begin
{$IFDEF LITTLE_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function N2BE(const AValue: SmallInt): SmallInt;
begin
{$IFDEF BIG_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function N2BE(const AValue: Word): Word;
begin
{$IFDEF BIG_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function N2BE(const AValue: Integer): Integer;
begin
{$IFDEF BIG_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function N2BE(const AValue: Cardinal): Cardinal;
begin
{$IFDEF BIG_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function N2BE(const AValue: Int64): Int64;
begin
{$IFDEF BIG_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function N2BE(const AValue: UInt64): UInt64;
begin
{$IFDEF BIG_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function N2LE(const AValue: SmallInt): SmallInt;
begin
{$IFDEF LITTLE_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function N2LE(const AValue: Word): Word;
begin
{$IFDEF LITTLE_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function N2LE(const AValue: Integer): Integer;
begin
{$IFDEF LITTLE_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function N2LE(const AValue: Cardinal): Cardinal;
begin
{$IFDEF LITTLE_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function N2LE(const AValue: Int64): Int64;
begin
{$IFDEF LITTLE_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

function N2LE(const AValue: UInt64): UInt64;
begin
{$IFDEF LITTLE_ENDIAN}
  Result := AValue;
{$ELSE}
  Result := Endian(AValue);
{$ENDIF}
end;

procedure Swap(var v1, v2: Byte);
var
  v: Byte;
begin
  v := v1;
  v1 := v2;
  v2 := v;
end;

procedure Swap(var v1, v2: Word);
var
  v: Word;
begin
  v := v1;
  v1 := v2;
  v2 := v;
end;

procedure Swap(var v1, v2: Integer);
var
  v: Integer;
begin
  v := v1;
  v1 := v2;
  v2 := v;
end;

procedure Swap(var v1, v2: Cardinal);
var
  v: Cardinal;
begin
  v := v1;
  v1 := v2;
  v2 := v;
end;

procedure Swap(var v1, v2: Int64);
var
  v: Int64;
begin
  v := v1;
  v1 := v2;
  v2 := v;
end;

procedure Swap(var v1, v2: UInt64);
var
  v: UInt64;
begin
  v := v1;
  v1 := v2;
  v2 := v;
end;

procedure Swap(var v1, v2: SystemString);
var
  v: SystemString;
begin
  v := v1;
  v1 := v2;
  v2 := v;
end;

procedure Swap(var v1, v2: Single);
var
  v: Single;
begin
  v := v1;
  v1 := v2;
  v2 := v;
end;

procedure Swap(var v1, v2: Double);
var
  v: Double;
begin
  v := v1;
  v1 := v2;
  v2 := v;
end;

procedure Swap(var v1, v2: Pointer);
var
  v: Pointer;
begin
  v := v1;
  v1 := v2;
  v2 := v;
end;

function Swap(const v: Word): Word;
begin
  Result := Endian(v);
end;

function Swap(const v: Cardinal): Cardinal;
begin
  Result := Endian(v);
end;

function Swap(const v: UInt64): UInt64;
begin
  Result := Endian(v);
end;

function SAR16(const AValue: SmallInt; const Shift: Byte): SmallInt;
begin
  Result := SmallInt(Word(Word(Word(AValue) shr (Shift and 15)) or (Word(SmallInt(Word(0 - Word(Word(AValue) shr 15)) and Word(SmallInt(0 - (Ord((Shift and 15) <> 0) { and 1 } ))))) shl (16 - (Shift and 15)))));
end;

function SAR32(const AValue: Integer; Shift: Byte): Integer;
begin
  Result := Integer(Cardinal(Cardinal(Cardinal(AValue) shr (Shift and 31)) or (Cardinal(Integer(Cardinal(0 - Cardinal(Cardinal(AValue) shr 31)) and Cardinal(Integer(0 - (Ord((Shift and 31) <> 0) { and 1 } ))))) shl (32 - (Shift and 31)))));
end;

function SAR64(const AValue: Int64; Shift: Byte): Int64;
begin
  Result := Int64(UInt64(UInt64(UInt64(AValue) shr (Shift and 63)) or (UInt64(Int64(UInt64(0 - UInt64(UInt64(AValue) shr 63)) and UInt64(Int64(0 - (Ord((Shift and 63) <> 0) { and 1 } ))))) shl (64 - (Shift and 63)))));
end;

function MemoryAlign(addr: Pointer; alignment: nativeUInt): Pointer;
var
  tmp: nativeUInt;
begin
  tmp := nativeUInt(addr) + (alignment - 1);
  Result := Pointer(tmp - (tmp mod alignment));
end;


{$IFDEF OverflowCheck}{$Q+}{$ENDIF}
{$IFDEF RangeCheck}{$R+}{$ENDIF}
