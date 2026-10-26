
void FUN_007abcd0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int in_ECX;
  int *in_EDX;
  undefined4 *puVar6;
  int iVar7;
  bool bVar8;
  undefined4 *local_5c;
  int local_58;
  int *local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 *local_44;
  int local_40;
  uint local_3c;
  undefined4 local_2c;
  uint local_28;
  undefined1 local_21;
  char local_20 [12];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = -1;
  puStack_c = &LAB_00935506;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = uVar3;
  ExceptionList = &local_10;
  local_58 = param_1;
  bVar8 = in_ECX < 0;
  if (bVar8) {
    in_ECX = -in_ECX;
  }
  local_44 = (undefined1 *)(uint)bVar8;
  iVar7 = 0;
  local_54 = in_EDX;
  if (in_ECX != 0) {
    do {
      iVar5 = in_ECX / 10;
      local_20[iVar7] = (char)in_ECX + (char)iVar5 * -10;
      iVar7 = iVar7 + 1;
      in_ECX = iVar5;
    } while (iVar5 != 0);
    for (; (iVar7 < 0 && (local_20[iVar7] == '\0')); iVar7 = iVar7 + -1) {
    }
    local_40 = iVar7;
    if (iVar7 != 0) {
      local_28 = 0xf;
      local_2c = 0;
      local_3c = local_3c & 0xffffff00;
      local_8 = 0;
      if (local_44 != (undefined1 *)0x0) {
        param_1 = in_EDX[param_1 + 0x2d];
      }
      FUN_00403040(in_EDX + param_1 * 7 + 3,0,0xffffffff);
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8._0_1_ = 1;
        FUN_00798de0(uVar3);
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = (uint)local_8._1_3_ << 8;
      }
      fVar1 = (float)local_40;
      local_40 = 0;
      local_44 = (undefined1 *)(fVar1 * 7.5);
      puVar4 = (undefined4 *)FUN_00891268(0x30);
      puVar6 = (undefined4 *)0x0;
      if (puVar4 != (undefined4 *)0x0) {
        puVar4[1] = 0;
        puVar4[4] = 0x3f800000;
        puVar4[2] = 0;
        puVar4[3] = 0;
        *puVar4 = IS3D::CFieldPanel::vftable;
        puVar4[9] = 0;
        puVar4[5] = 0;
        puVar4[10] = 0;
        puVar4[6] = 0;
        puVar4[7] = 0;
        puVar4[0xb] = 0;
        puVar6 = puVar4;
      }
      fVar1 = (float)local_44 * 0.5;
      puVar6[9] = param_2;
      puVar6[10] = param_3;
      local_44 = &local_21;
      puVar6[0xb] = param_4;
      local_4c = 0;
      local_48 = 0x3c23d70a;
      local_5c = puVar6;
      do {
        local_50 = (float)local_40 * 6.0 + (3.0 - fVar1);
        FUN_007bedc0(puVar6,*(undefined4 *)(local_54[0x50] + (char)local_44[iVar7] * 4),0x40f00000,
                     0x41380000,local_50,local_4c,local_48);
        local_40 = local_40 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      if (local_58 == 5) {
        local_50 = 0.0;
        local_4c = 0;
        local_48 = 0;
        FUN_007bedc0(puVar6,0,0x42440000,0x42100000,0,0,0);
      }
      local_50 = 0.0;
      local_4c = 0;
      local_48 = 0xc3af0000;
      local_20[0] = '\0';
      local_20[1] = '\0';
      local_20[2] = '\0';
      local_20[3] = '\0';
      local_20[4] = '\0';
      local_20[5] = '\0';
      local_20[6] = '\0';
      local_20[7] = '\0';
      local_20[8] = '\0';
      local_20[9] = '\0';
      local_20[10] = 'H';
      local_20[0xb] = 'C';
      FUN_007bee40(0,0,0x43480000,0,0,0xc3af0000,0x3f800000,0x40000000,0xc0000000,0xbf800000,
                   0xbf800000);
      FUN_007be770(puVar6);
      piVar2 = local_54;
      local_54 = (int *)local_54[0x4f];
      puVar6[4] = local_54;
      if (puVar6[1] != 0) {
        FUN_0077ef50(local_54,local_54,local_54);
      }
      iVar7 = *piVar2;
      iVar5 = FUN_0074d700(iVar7,*(undefined4 *)(iVar7 + 4),&local_5c);
      if (piVar2[1] == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("list<T> too long");
      }
      piVar2[1] = piVar2[1] + 1;
      *(int *)(iVar7 + 4) = iVar5;
      **(int **)(iVar5 + 4) = iVar5;
      if (0xf < local_28) {
        FUN_0089120c(local_3c);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

