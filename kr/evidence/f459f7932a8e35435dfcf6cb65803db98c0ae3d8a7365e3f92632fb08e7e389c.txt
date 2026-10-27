
undefined4 FUN_004bbfa0(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 in_ECX;
  
  iVar1 = DAT_00fe1aa0;
  *(uint *)(DAT_00fe1aa0 + 0x1c) = (uint)*(byte *)(param_1 + 2);
  if (*(int *)(iVar1 + 8) != *(int *)(iVar1 + 0xc)) {
    uVar2 = FUN_00508b40(*(int *)(iVar1 + 0xc));
    FUN_00508b90(in_ECX);
    *(undefined4 *)(iVar1 + 0xc) = uVar2;
  }
  if (param_2 < 3) {
    uVar3 = 0;
  }
  else {
    uVar3 = param_2 - 3 >> 3;
  }
  if (uVar3 != 0) {
    param_1 = param_1 + 7;
    do {
      FUN_00508660(*(undefined2 *)(param_1 + -4),*(undefined2 *)(param_1 + -2));
      param_1 = param_1 + 8;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  FUN_0058aad0(0xf4249);
  return 0;
}

