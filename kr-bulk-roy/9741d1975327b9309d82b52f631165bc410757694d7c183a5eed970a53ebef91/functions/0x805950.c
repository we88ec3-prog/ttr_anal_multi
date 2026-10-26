
int FUN_00805950(int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915a2b;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar4 = 0;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)(in_ECX + 0x34));
  if (*(int *)(in_ECX + 0x20) == 0) {
    if (param_1 != 0) {
      iVar4 = FUN_00891268(0xa0d8,uVar1);
      local_8 = 0;
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_00805ca0(iVar4);
      }
      local_8 = 0xffffffff;
      *(undefined4 *)(iVar4 + 0xa0c8) = *(undefined4 *)(in_ECX + 0x38);
      *(undefined4 *)(iVar4 + 0xa0cc) = *(undefined4 *)(in_ECX + 0x3c);
      *(undefined4 *)(iVar4 + 0xa0d0) = *(undefined4 *)(in_ECX + 0x40);
      FUN_007bb350();
      *(undefined4 *)(iVar4 + 0xa0ac) = 1;
    }
  }
  else {
    piVar2 = (int *)FUN_00542210();
    if ((int *)*piVar2 == (int *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)*piVar2;
    }
    uVar1 = (uint)piVar2[2] >> 2;
    if (*(uint *)(iVar4 + 8) <= uVar1) {
      uVar1 = uVar1 - *(uint *)(iVar4 + 8);
    }
    iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 4) + uVar1 * 4) + (piVar2[2] & 3U) * 4);
    if (*(int *)(in_ECX + 0x20) != 0) {
      *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + 1;
      if ((uint)(*(int *)(in_ECX + 0x18) * 4) <= *(uint *)(in_ECX + 0x1c)) {
        *(undefined4 *)(in_ECX + 0x1c) = 0;
      }
      iVar3 = *(int *)(in_ECX + 0x20) + -1;
      *(int *)(in_ECX + 0x20) = iVar3;
      if (iVar3 == 0) {
        *(undefined4 *)(in_ECX + 0x1c) = 0;
      }
    }
    FUN_00805f50();
    *(undefined4 *)(iVar4 + 0xa0ac) = 1;
    *(int *)(in_ECX + 0x44) = *(int *)(in_ECX + 0x44) + 1;
  }
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(in_ECX + 0x34));
  ExceptionList = local_10;
  return iVar4;
}

