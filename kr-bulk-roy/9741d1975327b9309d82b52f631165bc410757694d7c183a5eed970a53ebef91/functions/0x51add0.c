
void FUN_0051add0(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  void **ppvVar4;
  uint uVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009170ed;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  cVar1 = *(char *)((int)param_1 + 0x55);
  ppvVar4 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar4, cVar1 == '\0') {
    FUN_0051add0(param_1[2]);
    piVar2 = (int *)*param_1;
    local_8 = 1;
    FUN_00537240(param_1 + 0xc);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00825810(*(undefined4 *)param_1[9],(undefined4 *)param_1[9]);
    FUN_0089120c(param_1[9],uVar5);
    local_8 = 0xffffffff;
    iVar3 = param_1[4];
    if (iVar3 != 0) {
      FUN_0089120c(iVar3);
    }
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    FUN_0089120c(param_1);
    ppvVar4 = ExceptionList;
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x55);
  }
  ExceptionList = local_10;
  return;
}

