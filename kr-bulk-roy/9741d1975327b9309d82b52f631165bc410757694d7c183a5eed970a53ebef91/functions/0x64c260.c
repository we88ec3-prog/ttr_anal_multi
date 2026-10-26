
void FUN_0064c260(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091a00c;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00744640(param_1,param_2);
  if (*(int *)(in_ECX + 0x24) != 0) {
    iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))(uVar4);
    if (iVar5 != 0) {
      piVar1 = *(int **)(in_ECX + 0xa8);
      if (*piVar1 != 0) {
        piVar6 = (int *)FUN_0056f7a0(*(undefined4 *)(iVar5 + 0xa0),*(undefined4 *)(iVar5 + 0xa4));
        piVar1[5] = *piVar6;
        piVar1[6] = piVar6[1];
      }
      iVar5 = *(int *)(in_ECX + 0xa8);
      *(undefined4 *)(iVar5 + 0xc) = param_1;
      *(undefined4 *)(iVar5 + 0x10) = param_2;
      iVar5 = *(int *)(in_ECX + 0x14);
      iVar2 = *(int *)(in_ECX + 0xc);
      iVar3 = *(int *)(in_ECX + 0xa8);
      uVar4 = DAT_00fcde40 & 1;
      *(int *)(iVar3 + 4) = *(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8);
      *(int *)(iVar3 + 8) = iVar5 - iVar2;
      if (uVar4 == 0) {
        DAT_00fcde40 = DAT_00fcde40 | 1;
        local_8 = 0;
        FUN_00736880();
        _atexit(FUN_00bce6f0);
        local_8 = 0xffffffff;
      }
      (**(code **)(*DAT_00fcde28 + 0x20))(DAT_00fcde28,0);
      FUN_00570dd0();
      if ((DAT_00fcde40 & 1) == 0) {
        DAT_00fcde40 = DAT_00fcde40 | 1;
        local_8 = 1;
        FUN_00736880();
        _atexit(FUN_00bce6f0);
        local_8 = 0xffffffff;
      }
      (**(code **)(*DAT_00fcde28 + 0x2c))(DAT_00fcde28);
    }
  }
  ExceptionList = local_10;
  return;
}

