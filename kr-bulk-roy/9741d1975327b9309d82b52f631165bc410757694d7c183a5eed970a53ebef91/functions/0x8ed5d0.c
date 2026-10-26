
void FUN_008ed5d0(uint *param_1)

{
  int in_EAX;
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = *(byte *)(in_EAX + 0x170) - 0xaf;
  uVar2 = (uint)uVar1;
  if (uVar2 < (*(int *)(in_EAX + 0x14) - *(int *)(in_EAX + 0x10)) + 1U) {
    if (uVar1 != 0) {
      iVar3 = 1;
      do {
        iVar3 = iVar3 + 1;
        *param_1 = (uint)*(byte *)(*(int *)(in_EAX + 0x164) + *(int *)(in_EAX + 0x168) + -1 + iVar3)
        ;
        param_1 = param_1 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    return;
  }
  *(undefined4 *)(in_EAX + 0xc) = 0x82;
  return;
}

