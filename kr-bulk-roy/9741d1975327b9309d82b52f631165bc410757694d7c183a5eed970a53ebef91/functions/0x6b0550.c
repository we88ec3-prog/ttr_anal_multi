
void FUN_006b0550(void)

{
  int iVar1;
  code *pcVar2;
  float fVar3;
  int *unaff_ESI;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  iVar1 = unaff_ESI[100];
  fVar3 = 1.0;
  if ((float)(DAT_00f93944 - iVar1) / (float)(unaff_ESI[0x65] - iVar1) < 1.0) {
    fVar3 = (float)(DAT_00f93944 - iVar1) / (float)(unaff_ESI[0x65] - iVar1);
  }
  pcVar2 = *(code **)(*(int *)unaff_ESI[0x3d] + 0x128);
  ((int *)unaff_ESI[0x3d])[0x34] = (int)fVar3;
  (*pcVar2)();
  (**(code **)(*(int *)unaff_ESI[0x3d] + 200))();
  if (fVar3 == 1.0) {
    (**(code **)(*unaff_ESI + 0xd4))();
  }
  FUN_00749920(unaff_ESI[0x3e]);
  ExceptionList = local_14;
  return;
}

