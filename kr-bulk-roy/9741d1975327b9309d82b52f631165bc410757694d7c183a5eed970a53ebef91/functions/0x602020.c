
void FUN_00602020(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  int in_EDX;
  int local_20;
  int local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((in_EDX == 1) && (DAT_00f94300 + 0x16f8 != 0)) {
    if (99 < in_ECX - 1U) {
      FUN_006edb60(&DAT_00c0ddc0);
      ExceptionList = local_14;
      return;
    }
    piVar2 = (int *)(DAT_00f94300 + 0x16f8 + in_ECX * 0x20);
    if (((piVar2[3] != 0) && (piVar2[2] != 0)) && (piVar2 != (int *)0x0)) {
      if ((*piVar2 != 0x17) && (*piVar2 != 6)) {
        iVar3 = piVar2[2];
        if (1 < iVar3) {
          FUN_005f5d20(param_1,0xf4374,iVar3,iVar3,1,in_ECX,param_2,param_3);
          ExceptionList = local_14;
          return;
        }
        FUN_00602270(1,param_2,param_3);
        ExceptionList = local_14;
        return;
      }
      local_20 = 0x196;
      iVar3 = FUN_005854b0();
      FUN_005740f0(&local_20);
      if (local_1c[0] == *(int *)(iVar3 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if (*(uint *)(local_1c[0] + 0x24) < 8) {
        iVar3 = local_1c[0] + 0x10;
      }
      else {
        iVar3 = *(int *)(local_1c[0] + 0x10);
      }
      local_1c[0] = 0xbd;
      iVar4 = FUN_005854b0();
      FUN_005740f0(local_1c);
      if (local_20 == *(int *)(iVar4 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      puVar5 = (undefined4 *)(local_20 + 0x10);
      if (7 < *(uint *)(local_20 + 0x24)) {
        puVar5 = (undefined4 *)*puVar5;
      }
      FUN_00404b10(0xca,puVar5,iVar3,0,0);
    }
  }
  ExceptionList = local_14;
  return;
}

