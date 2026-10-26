
void FUN_006b0660(int param_1,int param_2,int param_3)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *unaff_ESI;
  void *pvStack_28;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  unaff_ESI[99] = param_1;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  unaff_ESI[100] = DAT_00f93944;
  unaff_ESI[0x65] = param_2;
  pcVar1 = *(code **)(*(int *)unaff_ESI[0x3d] + 0x128);
  ((int *)unaff_ESI[0x3d])[0x34] = 0;
  (*pcVar1)();
  (**(code **)(*(int *)unaff_ESI[0x3d] + 200))();
  if (param_3 == 2) {
    (**(code **)(*(int *)unaff_ESI[0x3e] + 0x94))(1);
    iVar4 = unaff_ESI[3];
    iVar3 = iVar4 + 0xf0;
  }
  else {
    (**(code **)(*(int *)unaff_ESI[0x3e] + 0x94))(0);
    iVar4 = unaff_ESI[3];
    iVar3 = iVar4 + 0x9b;
  }
  (**(code **)(*unaff_ESI + 0xbc))(unaff_ESI[2],iVar4,unaff_ESI[4],iVar3);
  (**(code **)(*unaff_ESI + 0xd0))();
  ExceptionList = pvStack_28;
  return;
}

