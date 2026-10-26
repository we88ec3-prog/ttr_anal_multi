
void FUN_00601bb0(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
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
  if ((param_2 == 1) && (DAT_00f94300 + 0x16f8 != 0)) {
    if (99 < param_3 - 1U) {
      FUN_006edb60(&DAT_00c0ddc0);
      ExceptionList = local_14;
      return;
    }
    piVar6 = (int *)(param_3 * 0x20 + DAT_00f94300 + 0x16f8);
    if (((piVar6[3] != 0) && (piVar6[2] != 0)) && (piVar6 != (int *)0x0)) {
      if ((*piVar6 == 0x17) || (*piVar6 == 6)) {
        local_20 = 0x196;
        iVar2 = FUN_005854b0();
        FUN_005740f0(&local_20);
        if (local_1c[0] == *(int *)(iVar2 + 4)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        if (*(uint *)(local_1c[0] + 0x24) < 8) {
          iVar2 = local_1c[0] + 0x10;
        }
        else {
          iVar2 = *(int *)(local_1c[0] + 0x10);
        }
        local_1c[0] = 0xbd;
        iVar5 = FUN_005854b0();
        FUN_005740f0(local_1c);
        if (local_20 == *(int *)(iVar5 + 4)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        puVar4 = (undefined4 *)(local_20 + 0x10);
        if (7 < *(uint *)(local_20 + 0x24)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        iVar5 = 0;
        iVar3 = 0;
      }
      else {
        iVar2 = FUN_00404ba0();
        uVar7 = *(undefined4 *)(*(int *)(iVar2 + 0x6920) + 0x50bc);
        FUN_00404ba0();
        iVar3 = FUN_005093a0();
        if (iVar3 != 0) {
          iVar2 = piVar6[2];
          if (1 < iVar2) {
            FUN_005f5d20(param_1,0xf4374,iVar2,iVar2,1,param_3,uVar7,iVar3);
            ExceptionList = local_14;
            return;
          }
          FUN_00602270(1,uVar7,iVar3);
          ExceptionList = local_14;
          return;
        }
        uVar7 = 0x196;
        iVar5 = iVar3;
        FUN_005854b0(0x196,0,0);
        iVar2 = FUN_00585330(uVar7);
        uVar7 = 0xbe;
        FUN_005854b0(0xbe,iVar2);
        puVar4 = (undefined4 *)FUN_00585330(uVar7);
      }
      FUN_00404b10(0xca,puVar4,iVar2,iVar3,iVar5);
    }
  }
  ExceptionList = local_14;
  return;
}

