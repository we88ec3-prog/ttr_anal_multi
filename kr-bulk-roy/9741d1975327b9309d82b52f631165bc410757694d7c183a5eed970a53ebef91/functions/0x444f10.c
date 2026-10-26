
uint FUN_00444f10(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  void **ppvVar4;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ppvVar4 = &local_14;
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    ExceptionList = ppvVar4;
    ppvVar4 = (void **)(**(code **)(*(int *)param_1[1] + 8))(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    if (ppvVar4 == (void **)0xf4245) {
      iVar1 = param_1[1];
      iVar2 = *(int *)(iVar1 + 0x2d0);
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        uStack_c = 0;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
      }
      ppvVar4 = (void **)(iVar2 + -1);
      if ((ppvVar4 == (void **)0x0) && (iVar2 = iVar2 * 0xca8 + 0xa50 + DAT_00f94300, iVar2 != 0)) {
        uVar3 = *(uint *)(iVar1 + 0x20);
        if (uVar3 < 100) {
          ppvVar4 = (void **)((uVar3 + 1) * 0x20 + iVar2);
          if ((((ppvVar4[3] != (void *)0x0) && (ppvVar4[2] != (void *)0x0)) &&
              (ppvVar4 != (void **)0x0)) &&
             ((ppvVar4 = *ppvVar4, ppvVar4 == (void **)0xb || (ppvVar4 == (void **)0x19)))) {
            ExceptionList = local_14;
            return CONCAT31((int3)((uint)ppvVar4 >> 8),*(int *)(in_ECX + 0x2a4) != 0xb);
          }
        }
        else {
          ppvVar4 = (void **)FUN_006edb60(&DAT_00c0ddc0);
        }
      }
    }
  }
  ExceptionList = local_14;
  return (uint)ppvVar4 & 0xffffff00;
}

