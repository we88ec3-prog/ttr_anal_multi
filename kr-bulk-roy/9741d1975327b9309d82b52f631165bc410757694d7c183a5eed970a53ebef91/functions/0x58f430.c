
void FUN_0058f430(int *param_1)

{
  char cVar1;
  int *piVar2;
  void **ppvVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f980;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  cVar1 = *(char *)((int)param_1 + 0x3d);
  ppvVar3 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar3, cVar1 == '\0') {
    FUN_0058f430(param_1[2]);
    piVar2 = (int *)*param_1;
    param_1[10] = (int)FUI::FXUIAttributeHistory::vftable;
    local_8 = 1;
    FUN_0051af60(*(undefined4 *)param_1[0xc],(undefined4 *)param_1[0xc]);
    FUN_0089120c(param_1[0xc],uVar4);
    local_8 = 0xffffffff;
    if (7 < (uint)param_1[8]) {
      FUN_0089120c(param_1[3],uVar4);
    }
    param_1[8] = 7;
    param_1[7] = 0;
    *(undefined2 *)(param_1 + 3) = 0;
    FUN_0089120c(param_1);
    ppvVar3 = ExceptionList;
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x3d);
  }
  ExceptionList = local_10;
  return;
}

