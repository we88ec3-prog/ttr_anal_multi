
void FUN_00507130(int *param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908783;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  iVar4 = param_1[1];
  if (iVar4 != *param_1) {
    do {
      if (*(undefined4 **)(iVar4 + -4) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(iVar4 + -4))(1,uVar3);
      }
      iVar4 = iVar4 + -4;
    } while (iVar4 != *param_1);
  }
  iVar4 = param_1[5];
  if (iVar4 != param_1[4]) {
    do {
      if (*(undefined4 **)(iVar4 + -4) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(iVar4 + -4))(1);
      }
      iVar4 = iVar4 + -4;
    } while (iVar4 != param_1[4]);
  }
  pvVar1 = (void *)*param_1;
  if (pvVar1 != (void *)param_1[1]) {
    FID_conflict__memcpy(pvVar1,(void *)param_1[1],0);
    param_1[1] = (int)pvVar1;
  }
  pvVar1 = (void *)param_1[4];
  if (pvVar1 != (void *)param_1[5]) {
    FID_conflict__memcpy(pvVar1,(void *)param_1[5],0);
    param_1[5] = (int)pvVar1;
  }
  puVar2 = (undefined4 *)param_1[9];
  if (puVar2 != (undefined4 *)0x0) {
    if ((HANDLE)*puVar2 != (HANDLE)0xffffffff) {
      WaitForSingleObject((HANDLE)*puVar2,0xffffffff);
      CloseHandle((HANDLE)*puVar2);
      *puVar2 = 0xffffffff;
      if ((undefined4 *)puVar2[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)puVar2[2])(1);
      }
      puVar2[2] = 0;
    }
    FUN_0089120c(puVar2);
    param_1[9] = 0;
  }
  if (param_1[4] != 0) {
    FUN_0089120c(param_1[4]);
  }
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  if (*param_1 != 0) {
    FUN_0089120c(*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  ExceptionList = local_10;
  return;
}

