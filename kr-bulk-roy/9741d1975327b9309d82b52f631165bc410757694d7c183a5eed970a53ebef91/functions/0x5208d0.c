
void FUN_005208d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  iVar1 = FUN_007300a0(&DAT_00c0e85c);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (puVar2 != (undefined4 *)0x0) {
      FUN_008917b4(puVar2);
    }
  }
  FUN_0044b4e0();
  iVar1 = FUN_0072e3c0();
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 4))(iVar1);
  }
  return;
}

