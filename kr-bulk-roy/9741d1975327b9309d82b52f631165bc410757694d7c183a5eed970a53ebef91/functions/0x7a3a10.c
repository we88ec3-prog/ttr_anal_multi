
undefined4 * FUN_007a3a10(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0090a1b1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  do {
    if (param_1 == param_2) {
      ExceptionList = local_10;
      return param_3;
    }
    local_8 = 1;
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0;
      param_3[1] = 0;
      iVar1 = param_1[1];
      uVar2 = *param_1;
      if (iVar1 != 0) {
        do {
          iVar3 = *(int *)(iVar1 + 4);
          if (iVar3 == 0) goto LAB_007a3a95;
          LOCK();
          iVar4 = *(int *)(iVar1 + 4);
          if (iVar3 == iVar4) {
            *(int *)(iVar1 + 4) = iVar3 + 1;
            iVar4 = iVar3;
          }
          UNLOCK();
        } while (iVar4 != iVar3);
        FUN_007a31c0(uVar2,iVar1);
      }
    }
LAB_007a3a95:
    param_3 = param_3 + 2;
    param_1 = param_1 + 2;
  } while( true );
}

