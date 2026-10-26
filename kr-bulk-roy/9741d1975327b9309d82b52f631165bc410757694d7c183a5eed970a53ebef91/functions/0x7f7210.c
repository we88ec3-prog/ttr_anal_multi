
void FUN_007f7210(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_00838860(in_ECX[0xb],in_ECX[0xc],in_ECX[0xd],in_ECX[0x1a]);
  while( true ) {
    if (iVar1 == 0) {
      in_ECX[0x1b] = 0;
      return;
    }
    iVar1 = FUN_00838800(in_ECX[0xe],in_ECX[0xf],in_ECX[0x10]);
    if ((((iVar1 != 0) && (iVar1 = FUN_00838800(in_ECX[0x11],in_ECX[0x12],in_ECX[0x13]), iVar1 != 0)
         ) && (iVar1 = FUN_00838800(in_ECX[0x14],in_ECX[0x15],in_ECX[0x16]), iVar1 != 0)) &&
       (iVar1 = FUN_00838800(in_ECX[0x17],in_ECX[0x18],in_ECX[0x19]), iVar1 != 0)) break;
    in_ECX[0x1b] = 2;
    if (*in_ECX != 0) {
      return;
    }
    FUN_007f7210(param_1);
    FUN_007f7210(param_1);
    FUN_007f7210(param_1);
    in_ECX = (int *)in_ECX[10];
    iVar1 = FUN_00838860(in_ECX[0xb],in_ECX[0xc],in_ECX[0xd],in_ECX[0x1a]);
  }
  in_ECX[0x1b] = 1;
  return;
}

