
/* WARNING: Removing unreachable block (ram,0x0056fd88) */

undefined4 FUN_0056fd60(void)

{
  uint uVar1;
  int in_EAX;
  int iVar2;
  int in_ECX;
  uint uVar3;
  
  FUN_005704f0(&stack0x00000004);
  if (in_ECX != *(int *)(in_EAX + 0x28)) {
    uVar1 = *(uint *)(in_ECX + 0x20);
    uVar3 = uVar1;
    if (5 < uVar1) {
      uVar3 = 6;
    }
    iVar2 = FUN_00407e70(uVar3);
    if (((iVar2 == 0) && (5 < uVar1)) && (uVar1 == 6)) {
      return 1;
    }
  }
  return 0;
}

