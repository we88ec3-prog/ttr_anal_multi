
void FUN_0082fa80(int *param_1)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00907036;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar5 = (int *)((int)param_1 + 0x1c);
  local_18 = 0x20;
  do {
    iVar4 = *piVar5;
    if (iVar4 != 0) {
      pvVar1 = *(void **)(iVar4 + 0x18);
      if (pvVar1 != (void *)0x0) {
        _eh_vector_destructor_iterator_(pvVar1,0x10,*(int *)((int)pvVar1 + -4),FUN_00837b60);
        FUN_00891d3d((int)pvVar1 + -4);
        *(undefined4 *)(iVar4 + 0x18) = 0;
      }
      FUN_008333d0(iVar4 + 0x1c,uVar3);
      iVar4 = *piVar5;
      if (iVar4 != 0) {
        FUN_00833050(iVar4);
        FUN_0089120c(iVar4);
      }
      *piVar5 = 0;
    }
    piVar5 = piVar5 + 1;
    local_18 = local_18 + -1;
  } while (local_18 != 0);
  param_1 = (int *)((int)param_1 + 0x9c);
  local_18 = 0x20;
  do {
    if (*param_1 != 0) {
      piVar5 = *(int **)(*param_1 + 0x18);
      iVar4 = *piVar5;
      iVar2 = piVar5[1];
      FUN_0082fd30();
      local_34 = iVar4 / local_24;
      local_30 = iVar2 / local_20;
      local_2c = *piVar5 / local_34;
      local_28 = piVar5[1] / local_30;
      iVar4 = FUN_00891268(0x30);
      local_1c = iVar4;
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        iVar2 = *param_1;
        *(undefined4 *)(iVar4 + 0x18) = 0;
        *(undefined4 *)(iVar4 + 0x1c) = 0;
        *(undefined4 *)(iVar4 + 0x20) = 0;
        *(undefined4 *)(iVar4 + 0x24) = 0;
        local_8 = 1;
        *(undefined4 *)(iVar4 + 0x2c) = 0;
        FUN_008330e0(iVar4,&local_34,&local_2c,iVar2);
      }
      local_8 = 0xffffffff;
      param_1[-0x20] = iVar4;
    }
    param_1 = param_1 + 1;
    local_18 = local_18 + -1;
  } while (local_18 != 0);
  ExceptionList = local_10;
  return;
}

