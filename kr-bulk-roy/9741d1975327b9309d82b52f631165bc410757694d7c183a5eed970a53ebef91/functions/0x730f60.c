
int FUN_00730f60(void)

{
  byte in_AL;
  int iVar1;
  
  if (in_AL < 0x7f) {
    iVar1 = _isalpha((uint)in_AL);
    return iVar1;
  }
  return 1;
}

