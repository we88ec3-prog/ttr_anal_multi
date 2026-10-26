
void FUN_008ed4e0(uint *param_1)

{
  byte bVar1;
  int in_EAX;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  bVar1 = *(byte *)(*(int *)(in_EAX + 0x164) + 1 + *(int *)(in_EAX + 0x168));
  uVar2 = (uint)bVar1;
  if (uVar2 < (*(int *)(in_EAX + 0x14) - *(int *)(in_EAX + 0x10)) + 1U) {
    if (bVar1 != 0) {
      iVar3 = 1;
      uVar4 = uVar2;
      do {
        *param_1 = (uint)*(byte *)(*(int *)(in_EAX + 0x164) + iVar3 + 1 + *(int *)(in_EAX + 0x168));
        iVar3 = iVar3 + 1;
        param_1 = param_1 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    *(int *)(in_EAX + 0x20) = *(int *)(in_EAX + 0x20) + uVar2;
    return;
  }
  *(undefined4 *)(in_EAX + 0xc) = 0x82;
  return;
}

