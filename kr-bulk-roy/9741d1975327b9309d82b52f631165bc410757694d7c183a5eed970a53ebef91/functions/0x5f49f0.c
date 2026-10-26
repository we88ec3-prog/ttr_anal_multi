
void FUN_005f49f0(void)

{
  int iVar1;
  uint in_ECX;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined1 auStack_23c [4];
  uint local_238;
  uint local_234;
  uint local_230;
  int local_22c;
  int local_228;
  uint local_224;
  undefined1 local_220 [508];
  uint uStack_24;
  void *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009435a2;
  local_14 = ExceptionList;
  local_1c = (void *)(DAT_00d61f20 ^ (uint)auStack_23c);
  ExceptionList = &local_14;
  local_234 = in_ECX;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xfffffdb8);
  uVar3 = DAT_00f94390 & 1;
  *(undefined1 *)(in_ECX + 0xcc) = 0;
  if (uVar3 == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  local_224 = (uint)DAT_00f94240;
  local_230 = 1;
  local_238 = 1;
  local_22c = 0x210;
  piVar2 = (int *)(in_ECX + 0x88);
  local_228 = 9;
  do {
    FUN_0040aeb0(L"BotCha%02d",local_238);
    FUN_00763360(local_220);
    iVar1 = *piVar2;
    if (((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) &&
       (iVar1 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))(), iVar1 == 0xbf6b)) {
      FUN_0077b200();
    }
    *(uint *)(*piVar2 + 0x28) = *(uint *)(*piVar2 + 0x28) | 4;
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    if (((local_238 < 10) && (iVar1 = DAT_00f94304 + local_22c, *(int *)(iVar1 + 0x5c) != 0)) &&
       ((iVar1 != 0 && ((*(int *)(iVar1 + 0x5c) != 0 && ((local_230 & local_224 & 0xffff) != 0))))))
    {
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
    (**(code **)(*(int *)*piVar2 + 0x90))(uVar4);
    (**(code **)(*(int *)*piVar2 + 200))();
    local_22c = local_22c + 0x210;
    local_238 = local_238 + 1;
    piVar2 = piVar2 + 1;
    local_230 = local_230 << 1 | (uint)((int)local_230 < 0);
    local_228 = local_228 + -1;
  } while (local_228 != 0);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 2;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  iVar1 = FUN_004d43d0();
  if (iVar1 < 0x50) {
    (**(code **)(**(int **)(local_234 + 0xb8) + 0x90))(0);
    uVar3 = local_238;
  }
  else {
    (**(code **)(**(int **)(local_234 + 0xb8) + 0x90))(1);
    uVar3 = local_234;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    puStack_10 = (undefined1 *)0x3;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_00757f20();
  (**(code **)(**(int **)(uVar3 + 0x80) + 200))();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    puStack_10 = (undefined1 *)0x4;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  (**(code **)(**(int **)(uVar3 + 0xac) + 0x94))(DAT_00f94284 != 0);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_14 = (void *)0x5;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_14 = (void *)0xffffffff;
  }
  if (DAT_00f942a4 == '\0') {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_14 = (void *)0x6;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    DAT_00f942a4 = DAT_00f942a4 == '\0';
  }
  ExceptionList = local_1c;
  __security_check_cookie(uStack_24 ^ (uint)&stack0xfffffdbc);
  return;
}

