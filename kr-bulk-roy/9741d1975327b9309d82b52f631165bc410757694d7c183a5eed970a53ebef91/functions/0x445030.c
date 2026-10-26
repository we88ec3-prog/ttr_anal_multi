
undefined4 FUN_00445030(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    iVar1 = (**(code **)(*(int *)param_1[1] + 8))(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    if (iVar1 == 0xf4245) {
      iVar1 = param_1[1];
      iVar3 = *(int *)(iVar1 + 0x2d0);
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        uStack_c = 0;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        uStack_c = 0xffffffff;
      }
      if ((iVar3 == 1) && (DAT_00f94300 + 0x16f8 != 0)) {
        if (*(uint *)(iVar1 + 0x20) < 100) {
          piVar2 = (int *)((*(uint *)(iVar1 + 0x20) + 1) * 0x20 + DAT_00f94300 + 0x16f8);
          if ((((piVar2[3] != 0) && (piVar2[2] != 0)) && (piVar2 != (int *)0x0)) &&
             (((*piVar2 == 0xb || (*piVar2 == 0x19)) && (*(int *)(in_ECX + 0x2a4) != 0xb)))) {
            iVar3 = FUN_00891268(0x20);
            if (iVar3 != 0) {
              FUN_00753e30(0xf4439,*(int *)(iVar1 + 0x20) + 1,*(undefined4 *)(in_ECX + 0x2a4));
              FUN_004072a0();
              ExceptionList = local_14;
              return 1;
            }
            FUN_004072a0();
            ExceptionList = local_14;
            return 1;
          }
        }
        else {
          FUN_006edb60(&DAT_00c0ddc0);
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}

