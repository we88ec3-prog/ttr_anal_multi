
/* WARNING: Removing unreachable block (ram,0x007dfa50) */

int FUN_007df9c0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907688;
  local_10 = ExceptionList;
  iVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
  iVar1 = iVar2 >> 0x1f;
  iVar2 = iVar2 / 0x18 + iVar1;
  uVar4 = 0;
  if (iVar2 != iVar1) {
    piVar3 = (int *)(*(int *)(param_1 + 4) + 4);
    do {
      if (*piVar3 == param_2) {
        return *(int *)(param_1 + 4) + uVar4 * 0x18;
      }
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 6;
    } while (uVar4 < (uint)(iVar2 - iVar1));
  }
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_007dfa90(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  iVar1 = FUN_007df9c0(param_1,param_2);
  ExceptionList = local_10;
  return iVar1;
}

