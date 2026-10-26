
float10 FUN_0072e690(float param_1)

{
  undefined4 in_EAX;
  int iVar1;
  char *_String;
  double dVar2;
  
  iVar1 = FUN_007300a0(in_EAX);
  if (iVar1 != 0) {
    _String = (char *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      _String = *(char **)_String;
    }
    if (_String != (char *)0x0) {
      dVar2 = _atof(_String);
      return (float10)(float)dVar2;
    }
  }
  return (float10)param_1;
}

