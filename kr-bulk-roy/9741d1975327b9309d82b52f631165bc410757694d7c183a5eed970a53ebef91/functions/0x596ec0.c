
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00596ec0(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar1 = param_1;
  puStack_c = &LAB_009451fe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (((uint)param_2[10] >> 8 & 1) == 0) {
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      local_8 = 0;
      FUN_00539c20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bccfb0);
    }
    local_8 = 0xffffffff;
    if (DAT_00fb7258 != 0) {
      iVar2 = FUN_00404ba0();
      iVar2 = FUN_00539aa0(*(undefined4 *)(iVar2 + 0x5f50));
      if (iVar2 == 0) {
        ExceptionList = local_10;
        return;
      }
      if ((*(char *)(iVar2 + 8) != '\0') && (*(char *)((int)unaff_ESI + 6) == '\0')) {
        ExceptionList = local_10;
        return;
      }
    }
    if ((*unaff_ESI == 1) && (piVar1[0x3d] != 0)) {
      (**(code **)(*(int *)piVar1[0x3d] + 0xd4))();
    }
    if (*(char *)((int)unaff_ESI + 5) != '\0') {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      param_1 = (int *)0x10049;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&param_1,4);
      }
    }
    if ((char)unaff_ESI[1] != '\0') {
      *(undefined2 *)(piVar1 + 0x2c) = 0x101;
    }
    if ((char)unaff_ESI[2] != '\0') {
      (**(code **)(*piVar1 + 0x19c))(unaff_ESI[3]);
    }
    piVar1[*unaff_ESI + 0x3c] = (int)param_2;
    piVar1 = piVar1 + *unaff_ESI * 4 + 0x3f;
    *piVar1 = *unaff_ESI;
    piVar1[1] = unaff_ESI[1];
    piVar1[2] = unaff_ESI[2];
    piVar1[3] = unaff_ESI[3];
    (**(code **)(*param_2 + 0xd0))();
  }
  ExceptionList = local_10;
  return;
}

