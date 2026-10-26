
void FUN_00713410(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint in_ECX;
  int in_EDX;
  
  uVar1 = (in_EDX + -1) / 0x32 + 1;
  uVar3 = -(uint)(in_ECX != 0xffffffff) & in_ECX;
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 8);
  if ((int)uVar1 < 0x200) {
    FUN_00713370(((uVar3 << 9 | uVar1) << 8 | param_2) << 6 | 0x22,uVar2);
    *(uint *)(param_1 + 0x24) = param_2 + 1;
    return;
  }
  FUN_00713370((uVar3 << 0x11 | param_2) << 6 | 0x22,uVar2);
  FUN_00713370(uVar1,*(undefined4 *)(*(int *)(param_1 + 0xc) + 8));
  *(uint *)(param_1 + 0x24) = param_2 + 1;
  return;
}

