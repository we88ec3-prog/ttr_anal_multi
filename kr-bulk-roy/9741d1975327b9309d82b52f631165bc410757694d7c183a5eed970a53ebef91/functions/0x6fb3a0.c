
int FUN_006fb3a0(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  int local_8;
  
  iVar1 = *(int *)(in_EAX + 0x10);
  local_8 = *(int *)(iVar1 + 0x54) * 10;
  if (local_8 == 0) {
    local_8 = 0x7ffffffe;
  }
  *(int *)(iVar1 + 0x4c) =
       *(int *)(iVar1 + 0x4c) + (*(int *)(iVar1 + 0x44) - *(int *)(iVar1 + 0x40));
  do {
    iVar3 = *(int *)(in_EAX + 0x10);
    switch(*(undefined1 *)(iVar3 + 0x15)) {
    case 0:
      FUN_006fb0c0();
    default:
switchD_006fb3dc_default:
      iVar2 = 0;
      break;
    case 1:
      if (*(int *)(iVar3 + 0x24) == 0) {
        FUN_006fb170();
        goto switchD_006fb3dc_default;
      }
      iVar2 = FUN_006fa790();
      break;
    case 2:
      iVar2 = *(int *)(iVar3 + 0x44);
      *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 1;
      FUN_006fab50();
      if (*(int *)(iVar3 + 8) <= *(int *)(iVar3 + 0x18)) {
        *(undefined1 *)(iVar3 + 0x15) = 3;
      }
      *(int *)(iVar3 + 0x48) = *(int *)(iVar3 + 0x48) + (*(int *)(iVar3 + 0x44) - iVar2);
      iVar2 = 10;
      break;
    case 3:
      iVar2 = *(int *)(iVar3 + 0x44);
      piVar4 = (int *)FUN_006fab50();
      *(int **)(iVar3 + 0x20) = piVar4;
      if (*piVar4 == 0) {
        FUN_006fac80();
        *(undefined1 *)(iVar3 + 0x15) = 4;
      }
      *(int *)(iVar3 + 0x48) = *(int *)(iVar3 + 0x48) + (*(int *)(iVar3 + 0x44) - iVar2);
      iVar2 = 400;
      break;
    case 4:
      iVar2 = 0;
      if (*(int *)(iVar3 + 0x30) == 0) {
        *(undefined1 *)(iVar3 + 0x15) = 0;
        *(undefined4 *)(iVar3 + 0x4c) = 0;
      }
      else {
        FUN_006fad00();
        if (100 < *(uint *)(iVar3 + 0x48)) {
          *(uint *)(iVar3 + 0x48) = *(uint *)(iVar3 + 0x48) - 100;
        }
        iVar2 = 100;
      }
    }
    local_8 = local_8 - iVar2;
    bVar5 = true;
    if (*(char *)(iVar1 + 0x15) == '\0') goto LAB_006fb3ff;
  } while (0 < local_8);
  bVar5 = *(char *)(iVar1 + 0x15) == '\0';
LAB_006fb3ff:
  if (bVar5) {
    *(uint *)(iVar1 + 0x40) = (*(uint *)(iVar1 + 0x48) / 100) * *(int *)(iVar1 + 0x50);
    return *(uint *)(iVar1 + 0x48) * 0x51eb851f;
  }
  if (0x3ff < *(uint *)(iVar1 + 0x4c)) {
    iVar3 = *(uint *)(iVar1 + 0x4c) - 0x400;
    *(int *)(iVar1 + 0x4c) = iVar3;
    *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(iVar1 + 0x44);
    return iVar3;
  }
  iVar3 = *(int *)(iVar1 + 0x44) + 0x400;
  *(int *)(iVar1 + 0x40) = iVar3;
  return iVar3;
}

