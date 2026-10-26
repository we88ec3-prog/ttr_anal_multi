
PVOID FUN_008932ca(PVOID param_1)

{
  PVOID pvVar1;
  
  pvVar1 = DecodePointer(DAT_00f8cad8);
  DAT_00f8cad8 = EncodePointer(param_1);
  return pvVar1;
}

