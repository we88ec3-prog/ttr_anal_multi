
undefined4 FUN_00810ec0(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar1;
  int in_EAX;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(in_EAX + 0x1c);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(in_EAX + 0x14) != 0) {
    piVar2 = (int *)FUN_00542210();
    if ((int *)*piVar2 == (int *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)*piVar2;
    }
    uVar3 = (uint)piVar2[2] >> 2;
    if (*(uint *)(iVar4 + 8) <= uVar3) {
      uVar3 = uVar3 - *(uint *)(iVar4 + 8);
    }
    uVar1 = *(undefined4 *)(*(int *)(*(int *)(iVar4 + 4) + uVar3 * 4) + (piVar2[2] & 3U) * 4);
    if (*(int *)(in_EAX + 0x14) != 0) {
      *(int *)(in_EAX + 0x10) = *(int *)(in_EAX + 0x10) + 1;
      if ((uint)(*(int *)(in_EAX + 0xc) * 4) <= *(uint *)(in_EAX + 0x10)) {
        *(undefined4 *)(in_EAX + 0x10) = 0;
      }
      iVar4 = *(int *)(in_EAX + 0x14) + -1;
      *(int *)(in_EAX + 0x14) = iVar4;
      if (iVar4 == 0) {
        *(undefined4 *)(in_EAX + 0x10) = 0;
      }
    }
    LeaveCriticalSection(lpCriticalSection);
    return uVar1;
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}

