
int FUN_007296a0(void)

{
  int iVar1;
  undefined4 *in_EDX;
  undefined4 *extraout_EDX;
  
  if ((in_EDX != (undefined4 *)0x0) && (*(char *)(in_EDX + 0x17) == 'r')) {
    in_EDX[0xe] = 0;
    in_EDX[0xf] = 0;
    in_EDX[0x1b] = 0xffffffff;
    in_EDX[1] = 0;
    *in_EDX = in_EDX[0x11];
    in_EDX[0x13] = 0;
    if (in_EDX[0x16] == 0) {
      FUN_007272b0();
      in_EDX = extraout_EDX;
    }
    in_EDX[0x19] = 0;
    in_EDX[0x1a] = 0;
    iVar1 = _fseek((FILE *)in_EDX[0x10],in_EDX[0x18],0);
    return iVar1;
  }
  return -1;
}

