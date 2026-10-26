
uint FUN_00804100(undefined4 *param_1,int param_2)

{
  byte bVar1;
  int in_EAX;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  bVar1 = *(byte *)(param_2 + 0x128 + in_EAX);
  iVar6 = param_2 * 2;
  iVar2 = (uint)bVar1 + iVar6;
  iVar5 = in_EAX + iVar2 * 0x18;
  if (*(int *)(in_EAX + 0x10 + iVar2 * 0x18) != 0) {
    piVar3 = (int *)FUN_00542210();
    if ((int *)*piVar3 == (int *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)*piVar3;
    }
    uVar4 = (uint)piVar3[2] >> 2;
    if (*(uint *)(iVar6 + 8) <= uVar4) {
      uVar4 = uVar4 - *(uint *)(iVar6 + 8);
    }
    iVar2 = *(int *)(iVar5 + 0x10);
    *param_1 = *(undefined4 *)(*(int *)(*(int *)(iVar6 + 4) + uVar4 * 4) + (piVar3[2] & 3U) * 4);
    if (iVar2 != 0) {
      *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + 1;
      if ((uint)(*(int *)(iVar5 + 8) * 4) <= *(uint *)(iVar5 + 0xc)) {
        *(undefined4 *)(iVar5 + 0xc) = 0;
      }
      iVar2 = iVar2 + -1;
      *(int *)(iVar5 + 0x10) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(iVar5 + 0xc) = 0;
      }
    }
    return CONCAT31((int3)((uint)iVar2 >> 8),1);
  }
  iVar5 = (uint)(bVar1 == 0) + iVar6;
  if (*(int *)(in_EAX + 0x10 + iVar5 * 0x18) != 0) {
    EnterCriticalSection(*(LPCRITICAL_SECTION *)(in_EAX + 0x124));
    *(bool *)(param_2 + 0x128 + in_EAX) = *(char *)(param_2 + 0x128 + in_EAX) == '\0';
    LeaveCriticalSection(*(LPCRITICAL_SECTION *)(in_EAX + 0x124));
    iVar5 = in_EAX + ((uint)*(byte *)(param_2 + 0x128 + in_EAX) + iVar6) * 0x18;
    piVar3 = (int *)FUN_00542210();
    if ((int *)*piVar3 == (int *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)*piVar3;
    }
    uVar4 = (uint)piVar3[2] >> 2;
    if (*(uint *)(iVar6 + 8) <= uVar4) {
      uVar4 = uVar4 - *(uint *)(iVar6 + 8);
    }
    iVar2 = *(int *)(iVar5 + 0x10);
    *param_1 = *(undefined4 *)(*(int *)(*(int *)(iVar6 + 4) + uVar4 * 4) + (piVar3[2] & 3U) * 4);
    if (iVar2 != 0) {
      *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + 1;
      if ((uint)(*(int *)(iVar5 + 8) * 4) <= *(uint *)(iVar5 + 0xc)) {
        *(undefined4 *)(iVar5 + 0xc) = 0;
      }
      iVar2 = iVar2 + -1;
      *(int *)(iVar5 + 0x10) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(iVar5 + 0xc) = 0;
      }
    }
    return CONCAT31((int3)((uint)iVar2 >> 8),1);
  }
  return iVar5 * 3 & 0xffffff00;
}

