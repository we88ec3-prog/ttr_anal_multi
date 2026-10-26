
void FUN_0061cf40(int param_1,byte param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int in_ECX;
  bool bVar7;
  int local_1c;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009430ae;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0082ef00(&param_1);
  iVar3 = local_14;
  param_3 = param_3 & 0xffffff00;
  if (local_14 != *(int *)(in_ECX + 0xf8)) {
    cVar4 = FUN_0061d0c0(in_ECX,param_4);
    if (cVar4 != '\0') {
      if ((DAT_00fb11a8 & 1) == 0) {
        DAT_00fb11a8 = DAT_00fb11a8 | 1;
        local_8 = 0;
        FUN_00813890(uVar5);
        _atexit((_func_4879 *)&LAB_00bccec0);
        local_8 = 0xffffffff;
      }
      local_14 = param_1;
      FUN_0082ef00(&local_14);
      if (local_1c == DAT_00fb11b0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(local_1c + 0x10);
      }
      bVar1 = *(byte *)(iVar3 + 0x10);
      if (((uint)bVar1 < (uint)(*(int *)(iVar6 + 0x18) - *(int *)(iVar6 + 0x14) >> 2)) &&
         (piVar2 = *(int **)(*(int *)(iVar6 + 0x14) + (uint)bVar1 * 4), piVar2 != (int *)0x0)) {
        local_14 = *piVar2;
      }
      else {
        local_14 = 0;
      }
      if (param_2 < bVar1) {
        *(char *)(iVar3 + 0x10) = *(char *)(iVar3 + 0x10) + -1;
        bVar1 = *(byte *)(iVar3 + 0x10);
        param_3 = CONCAT31(param_3._1_3_,bVar1);
      }
      bVar7 = param_2 == bVar1;
      if (bVar7) {
        FUN_007b6890(in_ECX + 0xf4,&param_2,iVar3);
      }
      FUN_00616790();
      FUN_0061d120(-*(int *)(local_14 + 4));
      FUN_0061cac0(param_1,param_3,param_4,!bVar7);
      FUN_0061d540(in_ECX);
    }
  }
  ExceptionList = local_10;
  return;
}

