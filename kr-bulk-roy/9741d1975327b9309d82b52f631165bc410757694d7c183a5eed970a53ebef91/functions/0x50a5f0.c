
undefined4 FUN_0050a5f0(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009248cc;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(char *)(param_1 + 2) == '\0') {
    if (param_2 < 3) {
      uVar2 = 0;
    }
    else {
      uVar2 = param_2 - 3 >> 3;
    }
    uVar3 = 0;
    if (uVar2 != 0) {
      puVar4 = (undefined4 *)(param_1 + 3);
      do {
        if ((DAT_00faadd4 & 1) == 0) {
          DAT_00faadd4 = DAT_00faadd4 | 1;
          local_8 = 0;
          FUN_00587480(uVar1);
          _atexit((_func_4879 *)&LAB_00bcccc0);
          local_8 = 0xffffffff;
        }
        FUN_0058acf0(0xf428a,uVar3,*puVar4,*(undefined2 *)((int)puVar4 + 6));
        uVar3 = uVar3 + 1;
        puVar4 = puVar4 + 2;
      } while (uVar3 < uVar2);
    }
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 1;
    FUN_00587480(uVar1);
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058ab80(0xf4289,(int)*(char *)(param_1 + 2));
  ExceptionList = local_10;
  return 0;
}

