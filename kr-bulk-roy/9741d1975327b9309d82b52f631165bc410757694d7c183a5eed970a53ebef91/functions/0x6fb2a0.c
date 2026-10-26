
undefined4 FUN_006fb2a0(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  undefined4 uVar3;
  int *piVar4;
  
  iVar1 = *(int *)(in_EAX + 0x10);
  switch(*(undefined1 *)(iVar1 + 0x15)) {
  case 0:
    FUN_006fb0c0();
    return 0;
  case 1:
    break;
  case 2:
    iVar2 = *(int *)(iVar1 + 0x44);
    *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
    FUN_006fab50();
    if (*(int *)(iVar1 + 8) <= *(int *)(iVar1 + 0x18)) {
      *(undefined1 *)(iVar1 + 0x15) = 3;
    }
    *(int *)(iVar1 + 0x48) = *(int *)(iVar1 + 0x48) + (*(int *)(iVar1 + 0x44) - iVar2);
    return 10;
  case 3:
    iVar2 = *(int *)(iVar1 + 0x44);
    piVar4 = (int *)FUN_006fab50();
    *(int **)(iVar1 + 0x20) = piVar4;
    if (*piVar4 == 0) {
      FUN_006fac80();
      *(undefined1 *)(iVar1 + 0x15) = 4;
    }
    *(int *)(iVar1 + 0x48) = *(int *)(iVar1 + 0x48) + (*(int *)(iVar1 + 0x44) - iVar2);
    return 400;
  case 4:
    if (*(int *)(iVar1 + 0x30) != 0) {
      FUN_006fad00();
      if (100 < *(uint *)(iVar1 + 0x48)) {
        *(uint *)(iVar1 + 0x48) = *(uint *)(iVar1 + 0x48) - 100;
      }
      return 100;
    }
    *(undefined1 *)(iVar1 + 0x15) = 0;
    *(undefined4 *)(iVar1 + 0x4c) = 0;
  default:
    return 0;
  }
  if (*(int *)(iVar1 + 0x24) == 0) {
    FUN_006fb170();
    return 0;
  }
  uVar3 = FUN_006fa790();
  return uVar3;
}

