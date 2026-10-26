
void FUN_007e9520(int param_1,int param_2)

{
  float *pfVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  int *piVar6;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  undefined2 local_54;
  undefined2 local_52;
  undefined2 local_50;
  int local_4c;
  int *local_48;
  int local_44;
  int *local_40;
  uint local_3c;
  undefined1 local_38 [16];
  uint local_28;
  float local_20;
  undefined4 local_1c;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009349de;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar5 = *(int *)(param_2 + 0x78);
  local_44 = in_ECX;
  if (iVar5 != 0) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(local_14);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_8 = 0xffffffff;
    uVar2 = FUN_0079a5f0(&DAT_00fb76a8);
    FUN_008629e0(uVar2,&local_40,&local_48);
    piVar6 = *(int **)(iVar5 + 0x44);
    local_48 = piVar6;
    if (piVar6 != (int *)0x0) {
      local_4c = 0;
      (**(code **)(*local_40 + 0x34))(local_40,local_38);
      (**(code **)(*local_40 + 0x2c))(local_40,0,0,&local_4c,0);
      *(undefined4 *)(param_1 + 4) = 0x477fff00;
      *(undefined4 *)(param_1 + 8) = 0x477fff00;
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
      if (local_28 >> 5 != 0) {
        iVar5 = 0;
        local_3c = local_28 >> 5;
        do {
          FUN_007cd220();
          pfVar1 = (float *)(iVar5 + 8 + local_4c);
          local_20 = *pfVar1 * local_70 +
                     *(float *)(iVar5 + local_4c) * local_88 +
                     *(float *)(iVar5 + 4 + local_4c) * local_7c + local_64;
          local_1c = *pfVar1 * local_6c +
                     *(float *)(iVar5 + 4 + local_4c) * local_78 +
                     *(float *)(iVar5 + local_4c) * local_84 + local_60;
          local_18 = *pfVar1 * local_68 +
                     *(float *)(iVar5 + local_4c) * local_80 +
                     *(float *)(iVar5 + 4 + local_4c) * local_74 + local_5c;
          if (local_20 < *(float *)(param_1 + 4)) {
            *(float *)(param_1 + 4) = local_20;
          }
          if (*(float *)(param_1 + 0xc) < local_20) {
            *(float *)(param_1 + 0xc) = local_20;
          }
          if (local_1c < *(float *)(param_1 + 8)) {
            *(float *)(param_1 + 8) = local_1c;
          }
          if (*(float *)(param_1 + 0x10) < local_1c) {
            *(float *)(param_1 + 0x10) = local_1c;
          }
          FUN_00857f00();
          FUN_0085df00();
          iVar5 = iVar5 + 0x20;
          local_3c = local_3c - 1;
        } while (local_3c != 0);
        local_3c = 0;
        piVar6 = local_48;
      }
      (**(code **)(*local_40 + 0x30))(local_40);
      (**(code **)(*local_40 + 8))(local_40);
      iVar5 = (piVar6[1] - *piVar6) / 0x14;
      if (iVar5 != 0) {
        local_44 = param_1 + 0x34;
        iVar4 = 0;
        local_3c = iVar5;
        do {
          iVar5 = *piVar6;
          if ((iVar5 != piVar6[1]) && (iVar3 = FUN_00857b00(0,0), iVar3 != -1)) {
            iVar5 = *(int *)(iVar4 + iVar5);
            local_54 = *(undefined2 *)(iVar5 + iVar3 * 0xc);
            iVar5 = iVar5 + iVar3 * 0xc;
            local_52 = *(undefined2 *)(iVar5 + 4);
            local_50 = *(undefined2 *)(iVar5 + 8);
          }
          local_1c = (float)CONCAT22(local_52,local_54);
          local_18 = (float)CONCAT22(local_18._2_2_,local_50);
          FUN_007e9990();
          iVar4 = iVar4 + 0x14;
          local_3c = local_3c + -1;
          piVar6 = local_48;
        } while (local_3c != 0);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

