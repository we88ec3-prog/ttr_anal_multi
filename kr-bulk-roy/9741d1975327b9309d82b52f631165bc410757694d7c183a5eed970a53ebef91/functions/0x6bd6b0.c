
void FUN_006bd6b0(void)

{
  int iVar1;
  int *in_ECX;
  
  if (in_ECX[0x27] != 0) {
    (**(code **)(*in_ECX + 0xd0))();
    iVar1 = in_ECX[0x27];
    in_ECX[0x26] = 0;
    in_ECX[0x25] = 0;
    in_ECX[0x28] = *(int *)(iVar1 + 0x10);
    if ((*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0x10)) / 0xc < 2) {
      in_ECX[0x25] = 1;
    }
    FUN_006bd050(in_ECX);
  }
  return;
}

