
void FUN_006c0170(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  int *in_ECX;
  int *piVar6;
  uint auStack_74 [4];
  undefined4 uStack_64;
  uint uStack_60;
  undefined1 auStack_58 [60];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00922a62;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_74;
  ExceptionList = &local_14;
  if (param_1 != (int *)0x0) {
    iVar2 = (**(code **)(*param_1 + 4))(DAT_00d61f20 ^ (uint)&stack0xffffff80);
    if (iVar2 == 0x105ba) goto LAB_006c01d6;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  param_1 = (int *)0x0;
LAB_006c01d6:
  iVar2 = param_1[6];
  if (((((iVar2 == 0) || (iVar2 == 4)) || (iVar2 == 6)) || (iVar2 == 10)) && (param_1[5] < 10)) {
    if (((uint)in_ECX[10] >> 8 & 1) == 0) {
      (**(code **)(*in_ECX + 0xd0))();
    }
    (**(code **)(*(int *)in_ECX[0x20] + 0x94))(param_1[5] != 6);
    puVar3 = (undefined4 *)FUN_0040ef80();
    puStack_10 = (undefined1 *)0x0;
    if (7 < (uint)puVar3[5]) {
      puVar3 = (undefined4 *)*puVar3;
    }
    FUN_0041f460(puVar3);
    puStack_10._0_1_ = 1;
    FUN_00405300(in_ECX[0x20] + 0xe8);
    puStack_10 = (undefined1 *)((uint)puStack_10._1_3_ << 8);
    FUN_00757640(auStack_58);
    puStack_10 = (undefined1 *)0xffffffff;
    if (7 < uStack_60) {
      FUN_0089120c(auStack_74[0]);
    }
    auStack_74[0] = auStack_74[0] & 0xffff0000;
    uStack_60 = 7;
    uStack_64 = 0;
    (**(code **)(*(int *)in_ECX[0x20] + 200))();
    piVar6 = in_ECX + 0x22;
    iVar2 = 7;
    do {
      (**(code **)(*(int *)*piVar6 + 0x94))(0);
      piVar6 = piVar6 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    piVar6 = in_ECX + 0x29;
    iVar2 = 8;
    do {
      (**(code **)(*(int *)*piVar6 + 0x94))(0);
      piVar6 = piVar6 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    (**(code **)(*(int *)in_ECX[0x21] + 0x94))(param_1[5] < 5);
    iVar2 = param_1[5];
    if ((iVar2 < 9) && (in_ECX[iVar2 * 2 + 0x39] != -1)) {
      (**(code **)(*(int *)in_ECX[in_ECX[iVar2 * 2 + 0x39] + 0x22] + 0x94))(1);
    }
    (**(code **)(*(int *)in_ECX[0x31] + 0x94))(param_1[5] == 9);
    uVar4 = param_1[6];
    if ((uVar4 == 4) || (uVar4 == 6)) {
      uVar4 = 1;
    }
    else {
      uVar4 = uVar4 & 0xffffff00;
    }
    (**(code **)(*(int *)in_ECX[0x2b] + 0x94))(uVar4);
    (**(code **)(*(int *)in_ECX[0x2c] + 0x94))(param_1[5] == 6);
    (**(code **)(*(int *)in_ECX[0x2d] + 0x94))(param_1[5] == 6);
    (**(code **)(*(int *)in_ECX[0x2e] + 0x94))(param_1[6] == 10);
    (**(code **)(*(int *)in_ECX[0x2f] + 0x94))(0);
    (**(code **)(*(int *)in_ECX[0x30] + 0x94))(0);
    if ((param_1[5] == 3) || (param_1[5] == 4)) {
      cVar1 = '\x01';
    }
    else {
      cVar1 = '\0';
    }
    *(char *)((int)in_ECX + 0xdd) = cVar1;
    if ((cVar1 == '\0') || (*(char *)((int)in_ECX + 0xde) == '\0')) {
      uVar5 = 0;
    }
    else {
      uVar5 = 1;
    }
    (**(code **)(*(int *)in_ECX[0x2a] + 0x94))(uVar5);
    if ((*(char *)((int)in_ECX + 0xdd) == '\0') || (*(char *)((int)in_ECX + 0xde) != '\0')) {
      uVar5 = 0;
    }
    else {
      uVar5 = 1;
    }
    (**(code **)(*(int *)in_ECX[0x29] + 0x94))(uVar5);
  }
  if (param_1[6] != 0) {
    (**(code **)(*(int *)in_ECX[0x20] + 0x94))(0);
    (**(code **)(*(int *)in_ECX[0x20] + 200))();
    piVar6 = in_ECX + 0x22;
    iVar2 = 7;
    do {
      (**(code **)(*(int *)*piVar6 + 0x94))(0);
      (**(code **)(*(int *)*piVar6 + 200))();
      piVar6 = piVar6 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_74);
  return;
}

