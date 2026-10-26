
undefined4 FUN_00730dc0(byte param_1)

{
  int iVar1;
  
  iVar1 = _isspace((uint)param_1);
  if (((iVar1 == 0) && (param_1 != 10)) && (param_1 != 0xd)) {
    return 0;
  }
  return 1;
}

