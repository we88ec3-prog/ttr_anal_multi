
PVOID FUN_00891fdc(PVOID param_1)

{
  PVOID pvVar1;
  
  pvVar1 = DecodePointer(DAT_00f8d4d8);
  DAT_00f8d4d8 = EncodePointer(param_1);
  return pvVar1;
}

