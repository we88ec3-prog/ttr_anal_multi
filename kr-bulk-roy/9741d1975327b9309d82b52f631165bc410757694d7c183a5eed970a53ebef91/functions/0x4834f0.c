
void FUN_004834f0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int unaff_EBX;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_4c [12];
  undefined4 local_40;
  int local_3c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093ee66;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_4c;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffa8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((*(int *)(param_1 + 0x110) == 1) && (DAT_00f94300 + 0x16f8 != 0)) {
    if (*(int *)(param_1 + 0x114) - 1U < 100) {
      iVar4 = *(int *)(param_1 + 0x114) * 0x20 + DAT_00f94300 + 0x16f8;
      if (((*(int *)(iVar4 + 0xc) != 0) && (*(int *)(iVar4 + 8) != 0)) && (iVar4 != 0)) {
        local_40 = *(undefined4 *)(iVar4 + 4);
        iVar1 = FUN_004034e0();
        FUN_008438c0(&local_40);
        if ((local_3c != *(int *)(iVar1 + 4)) && (iVar1 = *(int *)(local_3c + 0x10), iVar1 != 0)) {
          local_40 = *(undefined4 *)(iVar1 + 0x68);
          (**(code **)(**(int **)(param_1 + 0xf8) + 0x19c))
                    (*(undefined4 *)(iVar4 + 4),*(undefined4 *)(iVar4 + 0xc),
                     *(undefined4 *)(iVar4 + 0x10),*(undefined4 *)(iVar4 + 0x14));
          (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
          iVar4 = FUN_004034e0();
          FUN_00827050(iVar4 + 0x20,&stack0xffffffa8);
          puVar2 = (undefined4 *)FUN_008271c0();
          *(undefined4 *)(param_1 + 0x118) = *puVar2;
          *(undefined4 *)(param_1 + 0x11c) = puVar2[1];
          FUN_00482ac0(puVar2 + 2);
          piVar3 = (int *)(iVar1 + 0x98);
          if (unaff_EBX < 2) {
            FUN_00757800(piVar3);
          }
          else {
            if (7 < *(uint *)(iVar1 + 0xac)) {
              piVar3 = (int *)*piVar3;
            }
            uVar5 = 0x18;
            FUN_00585620(0x18,piVar3);
            FUN_00585330(uVar5);
            uVar5 = FUN_00483f00();
            local_1c = 1;
            FUN_00757800(uVar5);
            local_1c = 0xffffffff;
            FUN_004fa440();
          }
          (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
        }
      }
    }
    else {
      FUN_006edb60(&DAT_00c0ddc0);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_4c);
  return;
}

