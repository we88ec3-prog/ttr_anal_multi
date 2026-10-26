
void FUN_008e9f60(uint param_1,undefined4 *param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  param_1 = in_EAX << 0x10 | param_1;
  uVar4 = *(uint *)(in_ECX + 0x24);
  uVar5 = (uVar4 - 0x10) + *(int *)(in_ECX + 0x28) * 0x10;
  if (uVar4 <= uVar5) {
    do {
      iVar1 = (((int)(uVar5 - uVar4) >> 4) - ((int)(uVar5 - uVar4) >> 0x1f) >> 1) * 0x10;
      iVar2 = iVar1 + uVar4;
      uVar3 = *(int *)(iVar1 + uVar4) << 0x10 | *(uint *)(iVar2 + 4);
      if (uVar3 == param_1) {
        *param_2 = *(undefined4 *)(iVar2 + 8);
        param_2[1] = *(undefined4 *)(iVar2 + 0xc);
        return;
      }
      if (uVar3 < param_1) {
        uVar4 = iVar2 + 0x10;
      }
      else {
        uVar5 = iVar2 - 0x10;
      }
    } while (uVar4 <= uVar5);
  }
  *param_2 = 0;
  param_2[1] = 0;
  return;
}

