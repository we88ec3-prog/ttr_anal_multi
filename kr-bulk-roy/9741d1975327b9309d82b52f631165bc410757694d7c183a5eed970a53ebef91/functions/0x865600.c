
undefined4 FUN_00865600(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_EAX;
  undefined4 uVar3;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x1c) != 0) ||
     ((iVar1 = *(int *)(in_ECX + 0x14), iVar1 != 1 && (iVar1 != 0x200)))) {
    return 1;
  }
  uVar3 = 0;
  if (*(int *)(in_ECX + 0x28) != 0) {
    uVar3 = FUN_008654c0(*(undefined4 *)(in_ECX + 0x2c),*(undefined4 *)(in_ECX + 0x30),iVar1,
                         *(undefined4 *)(in_ECX + 0x18));
    return uVar3;
  }
  iVar2 = *(int *)(in_ECX + 0x20);
  if (iVar2 == 1) {
    uVar3 = FUN_00865240(in_EAX,*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),
                         *(undefined4 *)(in_ECX + 0x10),iVar1);
  }
  else {
    if (iVar2 == 3) {
      uVar3 = FUN_008653c0(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),
                           *(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x10),iVar1,
                           *(undefined4 *)(in_ECX + 0x18));
      return uVar3;
    }
    if (iVar2 == 4) {
      uVar3 = FUN_00865300(in_EAX,*(undefined4 *)(in_ECX + 0x10),iVar1,
                           *(undefined4 *)(in_ECX + 0x18));
      return uVar3;
    }
  }
  return uVar3;
}

