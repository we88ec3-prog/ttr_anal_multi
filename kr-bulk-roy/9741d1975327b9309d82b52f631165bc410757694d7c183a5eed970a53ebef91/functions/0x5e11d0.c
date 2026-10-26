
ushort FUN_005e11d0(void)

{
  ushort uVar1;
  ushort *in_ECX;
  ushort in_DX;
  
  uVar1 = *in_ECX;
  if (uVar1 == 0) {
    if (in_ECX[1] != 0) {
      return (ushort)(in_DX <= in_ECX[1]);
    }
    return 1;
  }
  if (in_ECX[1] != 0) {
    return CONCAT11((char)(uVar1 >> 8),in_DX == uVar1);
  }
  return (ushort)(uVar1 <= in_DX);
}

