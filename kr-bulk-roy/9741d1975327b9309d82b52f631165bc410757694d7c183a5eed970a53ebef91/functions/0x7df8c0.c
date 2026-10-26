
/* WARNING: Removing unreachable block (ram,0x007df94e) */
/* WARNING: Removing unreachable block (ram,0x007df955) */
/* WARNING: Removing unreachable block (ram,0x007df958) */
/* WARNING: Removing unreachable block (ram,0x007df960) */
/* WARNING: Removing unreachable block (ram,0x007df969) */
/* WARNING: Removing unreachable block (ram,0x007df97b) */
/* WARNING: Removing unreachable block (ram,0x007df97e) */

int FUN_007df8c0(int param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00909d08;
  local_10 = ExceptionList;
  iVar2 = *(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18);
  iVar1 = iVar2 >> 0x1f;
  iVar2 = iVar2 / 0x14 + iVar1;
  uVar4 = 0;
  if (iVar2 != iVar1) {
    piVar3 = *(int **)(in_ECX + 0x18);
    do {
      if (*piVar3 == param_1) {
        return *(int *)(in_ECX + 0x18) + uVar4 * 0x14;
      }
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 5;
    } while (uVar4 < (uint)(iVar2 - iVar1));
  }
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_007dfb60(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  iVar1 = FUN_007df8c0(param_1);
  ExceptionList = local_10;
  return iVar1;
}

