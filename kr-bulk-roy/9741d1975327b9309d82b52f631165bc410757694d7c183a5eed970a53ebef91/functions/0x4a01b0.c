
void FUN_004a01b0(int param_1,undefined4 param_2,char param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_EDX;
  int iVar8;
  int local_140;
  int local_13c;
  int local_138;
  uint local_134 [4];
  undefined4 local_124;
  uint local_120;
  undefined1 local_118 [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00927909;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_13c = param_1;
  iVar8 = (int)param_3;
  local_138 = in_EDX;
  iVar4 = FUN_0049fd10("Voice/V%05d_%02d.ogg",param_2,iVar8,local_14);
  if (iVar4 == 0) {
    iVar4 = 0xf;
    do {
      FUN_00401d90("Sound/Voice/V%05d_%02d_%02d.ogg",param_2,iVar8,iVar4);
      iVar5 = FUN_00714550(local_118);
      if (iVar5 != 0) {
        if (iVar4 != -1) {
          iVar5 = FUN_0089289d();
          iVar4 = FUN_0049fd10("Voice/V%05d_%02d_%02d.ogg",param_2,iVar8,iVar5 % (iVar4 + 1));
          if (iVar4 != 0) goto LAB_004a0287;
        }
        break;
      }
      iVar4 = iVar4 + -1;
    } while (-1 < iVar4);
    iVar4 = FUN_0049fd10("Voice/V%05d_%02d_%02d_%02d.ogg",param_2,iVar8,local_138,0);
    if (iVar4 == 0) goto LAB_004a0378;
  }
LAB_004a0287:
  local_120 = 0xf;
  local_124 = 0;
  local_134[0] = local_134[0] & 0xffffff00;
  FUN_0040b310("Voice");
  local_8 = 0;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_0080a3a0();
    _atexit((_func_4879 *)&LAB_00bccdd0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  local_138 = FUN_0080c1c0(local_134);
  if ((local_138 == DAT_00fab054) || (cVar3 = FUN_005436a0(), cVar3 != '\0')) {
    local_140 = DAT_00fab054;
    piVar6 = &local_140;
  }
  else {
    piVar6 = &local_138;
  }
  uVar7 = DAT_00fab04c;
  if (*piVar6 != DAT_00fab054) {
    uVar7 = *(undefined4 *)(*piVar6 + 0x28);
  }
  local_8 = 0xffffffff;
  *(undefined4 *)(iVar4 + 8) = uVar7;
  if (0xf < local_120) {
    FUN_0089120c(local_134[0]);
  }
  local_120 = 0xf;
  local_124 = 0;
  local_134[0] = local_134[0] & 0xffffff00;
LAB_004a0378:
  puVar1 = *(undefined4 **)(local_13c + 0x20);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if (*(int *)(puVar2[2] + 8) != 0) {
      (**(code **)(**(int **)(puVar2[2] + 8) + 0x24))();
    }
  }
  FUN_0049fe30(local_13c);
  *(undefined4 *)(local_13c + 0x2c) = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

