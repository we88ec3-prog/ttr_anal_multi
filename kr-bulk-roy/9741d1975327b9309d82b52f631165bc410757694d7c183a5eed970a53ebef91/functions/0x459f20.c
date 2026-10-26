
void FUN_00459f20(void)

{
  int iVar1;
  int *unaff_ESI;
  void *pvVar2;
  undefined1 auStack_18 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093f80e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((unaff_ESI[0xb0] == -1) || (unaff_ESI[0xb1] == -1)) {
    pvVar2 = (void *)0x0;
    (**(code **)(*unaff_ESI + 0x1ac))(0xffffffff,0xffffffff,0,0,0,DAT_00d61f20 ^ (uint)auStack_18);
    ExceptionList = pvVar2;
    return;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (unaff_ESI[0xac] == 1) {
    iVar1 = DAT_00f94300 + 0x16f8;
  }
  else {
    iVar1 = 0;
  }
  if (unaff_ESI[0xad] - 1U < 100) {
    iVar1 = unaff_ESI[0xad] * 0x20 + iVar1;
    if ((*(int *)(iVar1 + 0xc) != 0) && (*(int *)(iVar1 + 8) != 0)) goto LAB_00459fea;
  }
  else {
    FUN_006edb60(&DAT_00c0ddc0);
  }
  iVar1 = 0;
LAB_00459fea:
  pvVar2 = *(void **)(iVar1 + 0x10);
  (**(code **)(*unaff_ESI + 0x1ac))
            (*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 0xc),pvVar2,
             *(undefined4 *)(iVar1 + 0x14),unaff_ESI[0xaa]);
  ExceptionList = pvVar2;
  return;
}

