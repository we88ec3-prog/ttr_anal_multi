
uint FUN_00761bd0(void)

{
  uint uVar1;
  int in_ECX;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = *(uint *)(in_ECX + 0x160);
  uVar4 = *(uint *)(in_ECX + 0x164);
  uVar2 = uVar4;
  if ((int)uVar1 < (int)uVar4) {
    uVar2 = uVar1;
  }
  if ((int)uVar4 < (int)uVar1) {
    uVar4 = uVar1;
  }
  iVar3 = uVar4 - uVar2;
  if (iVar3 < 1) {
    return uVar1 & 0xffffff00;
  }
  if (*(char *)(in_ECX + 0x141) == '\0') {
    FUN_00757e40(iVar3,uVar2);
  }
  else {
    FUN_00757e40(iVar3,uVar2);
    FUN_006ee170(uVar2);
  }
  *(uint *)(in_ECX + 0x160) = uVar2;
  *(uint *)(in_ECX + 0x164) = uVar2;
  uVar1 = *(uint *)(in_ECX + 0x168);
  if ((int)uVar2 < (int)*(uint *)(in_ECX + 0x168)) {
    uVar1 = uVar2;
  }
  *(uint *)(in_ECX + 0x14c) = uVar2;
  *(uint *)(in_ECX + 0x168) = uVar1;
  return CONCAT31((int3)(uVar1 >> 8),1);
}

