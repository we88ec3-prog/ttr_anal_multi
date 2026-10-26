
void FUN_00650e00(int param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 *puVar3;
  int iVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined1 auStack_4c [4];
  undefined4 *local_48;
  undefined4 *local_44;
  undefined4 local_40;
  undefined2 local_38 [4];
  uint uStack_30;
  uint local_28;
  undefined4 local_24;
  void *pvStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  puStack_10 = &LAB_0093d64e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_4c;
  ExceptionList = &local_14;
  local_24 = 7;
  local_28 = 0;
  local_38[0] = 0;
  local_c = 0;
  if ((DAT_00fdfb10 & 1) == 0) {
    DAT_00fdfb10 = DAT_00fdfb10 | 1;
    local_c = 1;
    FUN_00590760(DAT_00d61f20 ^ (uint)&stack0xffffffa8);
    _atexit((_func_4879 *)&LAB_00bce760);
  }
  local_48 = (undefined4 *)0x0;
  local_44 = (undefined4 *)0x0;
  local_40 = 0;
  local_c = CONCAT31(local_c._1_3_,2);
  FUN_006d4dc0(0x2904,2);
  FUN_00402160(&DAT_00bed1fc,0);
  puVar3 = local_48;
  if (local_48 == local_44) {
    FUN_0041f490(local_38);
  }
  else {
    FUN_00594570(*local_48);
  }
  local_c = local_c & 0xffffff00;
  if (puVar3 != (undefined4 *)0x0) {
    FUN_0089120c(puVar3);
  }
  FUN_00757800(local_38);
  if ((DAT_00fdfb10 & 1) == 0) {
    DAT_00fdfb10 = DAT_00fdfb10 | 1;
    local_c = CONCAT31(local_c._1_3_,0xc);
    FUN_00590760();
    _atexit((_func_4879 *)&LAB_00bce760);
  }
  local_48 = (undefined4 *)0x0;
  local_44 = (undefined4 *)0x0;
  local_40 = 0;
  local_c = CONCAT31(local_c._1_3_,0xd);
  FUN_006d4dc0(0x2906,2);
  FUN_00402160(&DAT_00bed1fc,0);
  puVar3 = local_48;
  if (local_48 == local_44) {
    FUN_0041f490(local_38);
  }
  else {
    FUN_00594570(*local_48);
  }
  local_c = local_c & 0xffffff00;
  if (puVar3 != (undefined4 *)0x0) {
    FUN_0089120c(puVar3);
  }
  FUN_00757800(local_38);
  if ((DAT_00fdfb10 & 1) == 0) {
    DAT_00fdfb10 = DAT_00fdfb10 | 1;
    local_c = CONCAT31(local_c._1_3_,0x17);
    FUN_00590760();
    _atexit((_func_4879 *)&LAB_00bce760);
  }
  local_48 = (undefined4 *)0x0;
  local_44 = (undefined4 *)0x0;
  local_40 = 0;
  local_c = CONCAT31(local_c._1_3_,0x18);
  FUN_006d4dc0(0x2905,2);
  FUN_00402160(&DAT_00bed1fc,0);
  puVar3 = local_48;
  if (local_48 == local_44) {
    FUN_0041f490(local_38);
  }
  else {
    FUN_00594570(*local_48);
  }
  local_c = local_c & 0xffffff00;
  if (puVar3 != (undefined4 *)0x0) {
    FUN_0089120c(puVar3);
  }
  FUN_00757800(local_38);
  if ((DAT_00fdfb10 & 1) == 0) {
    DAT_00fdfb10 = DAT_00fdfb10 | 1;
    local_c = CONCAT31(local_c._1_3_,0x22);
    FUN_00590760();
    _atexit((_func_4879 *)&LAB_00bce760);
  }
  local_48 = (undefined4 *)0x0;
  local_44 = (undefined4 *)0x0;
  local_40 = 0;
  local_c = CONCAT31(local_c._1_3_,0x23);
  FUN_006d4dc0(0x2907,2);
  FUN_00402160(&DAT_00bed1fc,0);
  puVar3 = local_48;
  if (local_48 == local_44) {
    FUN_0041f490(local_38);
  }
  else {
    FUN_00594570(*local_48);
  }
  local_c = local_c & 0xffffff00;
  if (puVar3 != (undefined4 *)0x0) {
    FUN_0089120c(puVar3);
  }
  FUN_00757800(local_38);
  uVar6 = 0;
  uVar2 = FUN_0049c410(extraout_ECX,0);
  FUN_00594610(uVar2,uVar6);
  FUN_00757800(local_38);
  FUN_00757710();
  FUN_00757710();
  uVar6 = 0;
  uVar2 = FUN_0049c410(extraout_ECX_00,0);
  FUN_00594610(uVar2,uVar6);
  FUN_00757800(local_38);
  FUN_00757710();
  FUN_00757710();
  uVar6 = 0;
  uVar2 = FUN_0049c410(extraout_ECX_01,0);
  FUN_00594610(uVar2,uVar6);
  FUN_00757800(local_38);
  uVar6 = 0;
  uVar2 = FUN_0049c410(extraout_ECX_02,0);
  FUN_00594610(uVar2,uVar6);
  FUN_00757800(local_38);
  puVar3 = (undefined4 *)(param_1 + 0x120);
  iVar4 = 0xd;
  do {
    (**(code **)(*(int *)*puVar3 + 200))();
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c._0_1_ = 0x2d;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = (uint)local_c._1_3_ << 8;
  }
  bVar5 = DAT_00f9392c == 1;
  pcVar1 = *(code **)(**(int **)(param_1 + 0x10c) + 0x90);
  if (bVar5) {
    (*pcVar1)(0);
    (**(code **)(**(int **)(param_1 + 0x110) + 0x90))(0);
  }
  else {
    (*pcVar1)(1);
    (**(code **)(**(int **)(param_1 + 0x110) + 0x90))(1);
  }
  (**(code **)(**(int **)(param_1 + 0x104) + 0x90))(!bVar5);
  if (7 < uStack_30) {
    FUN_0089120c(local_44);
  }
  ExceptionList = pvStack_20;
  __security_check_cookie(local_28 ^ (uint)&stack0xffffffa8);
  return;
}

