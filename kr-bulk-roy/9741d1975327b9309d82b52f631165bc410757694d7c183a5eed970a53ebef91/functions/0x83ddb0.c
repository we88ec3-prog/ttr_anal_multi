
bool FUN_0083ddb0(uint *param_1)

{
  uint uVar1;
  int in_ECX;
  uint uVar2;
  int *piVar3;
  
  uVar1 = *param_1;
  if (uVar1 != 0) {
    uVar2 = uVar1 & 0xffff;
    if (((uVar2 < (uint)((*(int *)(in_ECX + 0x104) - *(int *)(in_ECX + 0x100)) / 0x34)) &&
        (*(uint *)(*(int *)(in_ECX + 0x110) + uVar2 * 4) == uVar1 >> 0x10)) &&
       (piVar3 = (int *)(uVar2 * 0x34 + *(int *)(in_ECX + 0x100)), piVar3 != (int *)0x0)) {
      return *piVar3 != 0;
    }
  }
  return false;
}

