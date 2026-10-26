
void FUN_0050d920(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint *in_EDX;
  undefined4 *puVar4;
  undefined **local_9c [3];
  char *local_90;
  uint *local_8c;
  uint local_88;
  uint local_84 [4];
  undefined4 local_74;
  uint local_70;
  undefined1 local_68;
  undefined4 local_64 [6];
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  undefined1 local_30;
  int *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912ef6;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar4 = DAT_00fe17c4;
  if (*(char *)((int)DAT_00fe17c4[1] + 0x49) == '\0') {
    puVar1 = (undefined4 *)DAT_00fe17c4[1];
    do {
      if ((int)puVar1[3] < (int)*in_EDX) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar4 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x49) == '\0');
  }
  local_8c = in_EDX;
  if ((puVar4 == DAT_00fe17c4) || ((int)*in_EDX < (int)puVar4[3])) {
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffff0000;
    local_8 = 0;
    local_2c = (int *)0x0;
    piVar3 = (int *)FUN_00891268(8,local_14);
    if (piVar3 == (int *)0x0) {
      local_90 = (char *)0x0;
      std::exception::exception((exception *)local_9c,&local_90);
      local_9c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_9c,&DAT_00c857a8);
    }
    piVar3[1] = 0;
    *piVar3 = 0;
    *piVar3 = (int)&local_2c;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_8 = 1;
    local_88 = *local_8c;
    local_8c = local_84;
    local_84[0] = local_84[0] & 0xffff0000;
    local_70 = 7;
    local_74 = 0;
    local_2c = piVar3;
    FUN_004026e0(local_4c,0,0xffffffff);
    local_8._0_1_ = 2;
    local_68 = local_30;
    FUN_0050e250(local_64,&local_2c);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_0050fcb0(&local_88);
    FUN_0050f050(&local_8c,puVar4);
    FUN_007b6d70();
    FUN_0089120c(local_64[0]);
    local_64[0] = 0;
    if (7 < local_70) {
      FUN_0089120c(local_84[0]);
    }
    local_70 = 7;
    local_74 = 0;
    local_84[0] = local_84[0] & 0xffff0000;
    FUN_007b6d70();
    FUN_0089120c(local_2c);
    local_2c = (int *)0x0;
    if (7 < local_38) {
      FUN_0089120c(local_4c[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

