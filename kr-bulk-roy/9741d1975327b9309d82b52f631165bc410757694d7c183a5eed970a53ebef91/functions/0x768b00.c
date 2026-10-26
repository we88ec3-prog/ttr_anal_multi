
int FUN_00768b00(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  
  iVar2 = FUN_007680b0(param_1);
  if (0 < iVar2) {
    if (7 < (uint)param_1[5]) {
      param_1 = (undefined4 *)*param_1;
    }
    FUN_007660d0(in_ECX,param_1,*(undefined4 *)(in_ECX + 0x13c));
    uVar1 = *(int *)(in_ECX + 0x13c) + 1;
    if (uVar1 < (uint)(*(int *)(in_ECX + 0x114) - *(int *)(in_ECX + 0x110) >> 2)) {
      puVar3 = *(undefined4 **)(*(int *)(in_ECX + 0x110) + *(int *)(in_ECX + 0x13c) * 4);
      iVar4 = puVar3[4];
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        if (7 < (uint)puVar3[5]) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (*(short *)((int)puVar3 + iVar4 * 2 + -2) == 10) {
          iVar4 = iVar4 + -1;
        }
      }
      if (iVar4 <= *(int *)(in_ECX + 0x140)) {
        *(uint *)(in_ECX + 0x13c) = uVar1;
        *(undefined4 *)(in_ECX + 0x140) = 0;
        return iVar2;
      }
    }
  }
  return iVar2;
}

