
void FUN_0061f710(char param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_88 [8];
  int local_68;
  undefined1 local_50 [60];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091260e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  puVar2 = (undefined4 *)FUN_006ea440(local_50,DAT_00d61f20 ^ (uint)&stack0xffffff68);
  puVar4 = local_88;
  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  if (param_1 == '\0') {
    if (local_68 != 0) goto LAB_0061f789;
  }
  else if (local_68 == 0) goto LAB_0061f789;
  FUN_006e71f0(1,1);
  FUN_006e2e20();
  FUN_006e71f0(0,0);
LAB_0061f789:
  bVar1 = FUN_006ea3d0();
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  if (DAT_00fb91d3 < bVar1) {
    bVar1 = DAT_00fb91d3;
  }
  DAT_00fb91d1 = DAT_00fb91d2;
  if (DAT_00fb91d2 <= bVar1) {
    DAT_00fb91d1 = bVar1;
  }
  ExceptionList = local_14;
  return;
}

