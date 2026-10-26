
void FUN_0064fc40(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_7c [4];
  int local_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  undefined4 local_58;
  undefined **local_54 [3];
  undefined4 local_48;
  uint local_34;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00935d34;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_7c;
  ExceptionList = &local_14;
  local_78 = param_2;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffff78);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  uVar3 = DAT_00fab1c0;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_c = 1;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
  }
  iVar4 = DAT_00f94520;
  local_c = 0xffffffff;
  if (DAT_00f94520 != 0) {
    local_70 = uVar3;
    FUN_0082ef00(&local_70);
    if (local_74 != *(int *)(iVar4 + 0xc)) {
      iVar4 = *(int *)(local_74 + 0x10);
      goto LAB_0064fd27;
    }
  }
  iVar4 = 0;
LAB_0064fd27:
  if (iVar4 == 0) {
    if (*(int *)(param_1 + 0xb4) != 0) {
      piVar2 = *(int **)(*(int *)(param_1 + 0xb4) + 8);
      if (piVar2 != (int *)0x0) {
        piVar1 = piVar2 + 0x27;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)(*piVar2 + 0x28))();
        }
      }
      *(undefined4 *)(param_1 + 0xb4) = 0;
    }
  }
  else {
    FUN_00776650();
  }
  if (*(int *)(param_1 + 0xb4) != 0) {
    FUN_0064fe30(local_54);
    local_c = 2;
    local_6c = 0x3f800000;
    local_68 = 0x3f800000;
    local_64 = 0x3f800000;
    local_60 = (float)local_78;
    local_28 = 0;
    local_2c = 0;
    local_5c = (float)param_3;
    local_24 = 0xa4;
    local_20 = 0xa4;
    local_58 = 0;
    FUN_00751f90(local_54,&local_60,&local_6c);
    local_54[0] = FoxUI::FXUIImageSetItem::vftable;
    if (7 < local_34) {
      FUN_0089120c(local_48);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_7c);
  return;
}

