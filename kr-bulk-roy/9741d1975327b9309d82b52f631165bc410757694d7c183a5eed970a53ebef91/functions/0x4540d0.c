
undefined4 FUN_004540d0(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009454de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(char *)((int)param_1 + 2) != '\x05') {
    FUN_006edb60(&DAT_00bfd3c4,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    param_1 = (undefined4 *)CONCAT22(0x19,param_1._0_2_);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,(int)&param_1 + 2,2);
    }
    ExceptionList = local_10;
    return 0x80004005;
  }
  if (param_2 < 0x47) {
    FUN_006edb60(&DAT_00bf6cbc,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  }
  puVar4 = (undefined4 *)(DAT_00fc0c68 + 8);
  for (iVar2 = 0x10; puVar3 = puVar1 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar4 = puVar4 + 1;
    puVar1 = puVar3;
  }
  *(undefined2 *)puVar4 = *(undefined2 *)puVar3;
  *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar1 + 6);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  puVar1 = (undefined4 *)FUN_00891268(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = FoxUI::FXUIEvent::vftable;
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = 0xf426d;
  }
  FUN_0058aa50(puVar1);
  FUN_004ba8c0(1);
  ExceptionList = local_10;
  return 0;
}

