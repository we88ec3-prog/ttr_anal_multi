
void FUN_00705970(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar3 = *(undefined4 **)(in_ECX + 0xc);
  puVar1 = *(undefined4 **)(in_ECX + 8);
  if (((puVar3 < puVar1) && (puVar3 != &DAT_00c0bfc8)) && (puVar3[2] == 6)) {
    if (puVar1 <= puVar3) {
      puVar3 = &DAT_00c0bfc8;
    }
    *puVar1 = *puVar3;
    puVar1[1] = puVar3[1];
    puVar1[2] = puVar3[2];
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 0x10;
    __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (((param_1 == 0) || (((puVar3 < puVar1 && (puVar3 != &DAT_00c0bfc8)) && (0 < (int)puVar3[2]))))
     && (iVar4 = FUN_006f6370(), iVar4 < 0)) {
    FUN_006f5da0(1);
  }
  iVar4 = FUN_006f7dd0();
  if (iVar4 == 0) {
    FUN_006f5da0(1);
  }
  FUN_006f8180(&DAT_00c43598);
  if ((*(undefined **)(in_ECX + 8) != &DAT_00c0bfd8) &&
     (*(int *)(*(undefined **)(in_ECX + 8) + -8) == 0)) {
    FUN_006f5f30();
  }
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

