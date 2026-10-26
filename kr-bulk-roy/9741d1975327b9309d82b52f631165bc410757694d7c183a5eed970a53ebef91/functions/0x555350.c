
/* WARNING: Removing unreachable block (ram,0x0055546c) */
/* WARNING: Removing unreachable block (ram,0x00555617) */

void FUN_00555350(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int unaff_ESI;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  uint local_64;
  float local_60;
  undefined4 local_5c;
  undefined4 local_58;
  uint local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(unaff_ESI + 0x84) != 0) && (*(int *)(unaff_ESI + 0x74) != 0)) {
    local_74 = 1.0;
    local_70 = 1.0;
    local_7c = 0.0;
    local_78 = 0.0;
    iVar3 = FUN_006dfc40();
    iVar4 = FUN_006dfc40();
    iVar5 = FUN_006dfc40();
    local_70 = (float)*(int *)(iVar3 + 0x1c);
    if (*(int *)(iVar3 + 0x1c) < 0) {
      local_70 = local_70 + 4.2949673e+09;
    }
    fVar1 = (float)*(int *)(unaff_ESI + 0xa4);
    if (*(int *)(unaff_ESI + 0xa4) < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    local_70 = local_70 / fVar1;
    fVar1 = (float)*(int *)(iVar4 + 0x18);
    if (*(int *)(iVar4 + 0x18) < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    fVar2 = (float)*(int *)(iVar5 + 0x1c);
    if (*(int *)(iVar5 + 0x1c) < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    local_74 = (fVar1 / fVar2) * local_70;
    local_60 = (float)*(int *)(unaff_ESI + 0xa0);
    if (*(int *)(unaff_ESI + 0xa0) < 0) {
      local_60 = local_60 + 4.2949673e+09;
    }
    local_60 = local_60 * local_74;
    fVar1 = (float)*(int *)(iVar3 + 0x18);
    if (*(int *)(iVar3 + 0x18) < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    local_6c = (fVar1 - local_60) * 0.5;
    local_7c = local_6c + 22.0;
    local_78 = (float)((uint)(*(int *)(iVar3 + 0x1c) - *(int *)(unaff_ESI + 0xc4)) >> 1);
    local_10 = 0x3f800000;
    local_24 = 0x3f800000;
    local_38 = 0x3f800000;
    local_4c = 0x3f800000;
    local_14 = 0;
    local_18 = 0;
    local_1c = 0;
    local_20 = 0;
    local_28 = 0;
    local_2c = 0;
    local_30 = 0;
    local_34 = 0;
    local_3c = 0;
    local_40 = 0;
    local_44 = 0;
    local_48 = 0;
    local_64 = 0;
    local_68 = local_6c;
    D3DXMatrixTransformation2D(&local_4c,0,0,&local_74,0,0,&local_68);
    (**(code **)(**(int **)(unaff_ESI + 0x84) + 0x14))(*(int **)(unaff_ESI + 0x84),&local_4c);
    iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x84) + 0x24))
                      (*(int **)(unaff_ESI + 0x84),*(undefined4 *)(unaff_ESI + 0x74),0,0,0,
                       0xffffffff);
    if (iVar3 < 0) {
      FUN_006edb60("FAIL 0x%x",iVar3);
    }
    if (*(int *)(unaff_ESI + 0x78) != 0) {
      local_14 = 0;
      local_18 = 0;
      local_1c = 0;
      local_20 = 0;
      local_28 = 0;
      local_2c = 0;
      local_30 = 0;
      local_34 = 0;
      local_3c = 0;
      local_40 = 0;
      local_44 = 0;
      local_48 = 0;
      local_10 = 0x3f800000;
      local_24 = 0x3f800000;
      local_38 = 0x3f800000;
      local_4c = 0x3f800000;
      D3DXMatrixTransformation2D(&local_4c,0,0,0,0,0,&local_7c);
      (**(code **)(**(int **)(unaff_ESI + 0x84) + 0x14))(*(int **)(unaff_ESI + 0x84),&local_4c);
      iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x84) + 0x24))
                        (*(int **)(unaff_ESI + 0x84),*(undefined4 *)(unaff_ESI + 0x78),0,0,0,
                         0xffffffff);
      if (iVar3 < 0) {
        FUN_006edb60("FAIL 0x%x",iVar3);
      }
      local_54 = *(uint *)(unaff_ESI + 0xe0);
      local_64 = local_54 >> 1;
      local_84 = local_60 * 0.5 - (float)local_64;
      fVar1 = (float)*(int *)(unaff_ESI + 0xa4);
      if (*(int *)(unaff_ESI + 0xa4) < 0) {
        fVar1 = fVar1 + 4.2949673e+09;
      }
      local_5c = 5;
      local_80 = fVar1 * local_70 - 120.0;
      local_58 = 5;
      local_50 = *(undefined4 *)(unaff_ESI + 0xe4);
      local_14 = 0;
      local_18 = 0;
      local_1c = 0;
      local_20 = 0;
      local_28 = 0;
      local_2c = 0;
      local_30 = 0;
      local_34 = 0;
      local_3c = 0;
      local_40 = 0;
      local_44 = 0;
      local_48 = 0;
      local_10 = 0x3f800000;
      local_24 = 0x3f800000;
      local_38 = 0x3f800000;
      local_4c = 0x3f800000;
      D3DXMatrixTransformation2D(&local_4c,0,0,0,0,0,&local_84);
      (**(code **)(**(int **)(unaff_ESI + 0x84) + 0x14))(*(int **)(unaff_ESI + 0x84),&local_4c);
      iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x84) + 0x24))
                        (*(int **)(unaff_ESI + 0x84),*(undefined4 *)(unaff_ESI + 0x7c),0,0,0,
                         0xffffffff);
      if (iVar3 < 0) {
        FUN_006edb60("FAIL 0x%x",iVar3);
      }
      piVar6 = (int *)(*(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0xf0) * 0x1c);
      if (7 < *(uint *)(*(int *)(unaff_ESI + 0x10) + 0x14 + *(int *)(unaff_ESI + 0xf0) * 0x1c)) {
        piVar6 = (int *)*piVar6;
      }
      (**(code **)(**(int **)(unaff_ESI + 0x80) + 0x3c))
                (*(int **)(unaff_ESI + 0x80),*(undefined4 *)(unaff_ESI + 0x84),piVar6,0xffffffff,
                 &local_5c,1,0xffffffff);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

