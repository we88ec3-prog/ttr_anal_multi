
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005464c0(int param_1,float param_2,byte param_3,byte *param_4)

{
  float fVar1;
  float fVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 unaff_EBX;
  uint uVar5;
  undefined2 in_FPUControlWord;
  float10 fVar6;
  undefined4 uStack_20;
  undefined1 local_1c;
  undefined4 local_10;
  undefined4 local_c;
  
  *param_4 = param_3;
  if (param_1 != 0) {
    iVar4 = FUN_00545f30(param_3 + 0x80,param_2 * 0.0333333);
    if (iVar4 != 0) {
      return 0;
    }
    *param_4 = param_3 + 0x80;
    return 1;
  }
  if ((DAT_00fb7c18 & 1) == 0) {
    DAT_00fb7c18 = DAT_00fb7c18 | 1;
    FUN_004449d0();
  }
  fVar1 = (float)(&DAT_00fb8020)[(uint)param_3 * 2];
  fVar2 = (float)(&DAT_00fb8024)[(uint)param_3 * 2];
  local_10 = 0;
  local_c = 0;
  fVar6 = (float10)FUN_008fedca();
  if ((DAT_00fb7c18 & 1) == 0) {
    DAT_00fb7c18 = DAT_00fb7c18 | 1;
    FUN_004449d0();
  }
  uStack_20 = CONCAT22(uStack_20._2_2_,in_FPUControlWord);
  local_1c = (undefined1)(int)ROUND(_DAT_00fb8824 * ((float)fVar6 + 1.5707964));
  uStack_20 = CONCAT31(uStack_20._1_3_,local_1c);
  param_2 = param_2 * 0.0333333;
  iVar4 = FUN_00545f30(uStack_20,param_2);
  if (iVar4 == 0) {
    fVar6 = (float10)FUN_008fedca(uStack_20,param_2);
    uVar3 = FUN_004bb450((float)fVar6 + 1.5707964);
    iVar4 = FUN_00545f30(uVar3,param_2);
    if (iVar4 != 0) {
      if (fVar2 <= 0.0) {
        local_c = 0x3f800000;
      }
      else {
        local_c = 0xbf800000;
      }
    }
  }
  else if (fVar1 <= 0.0) {
    local_10 = 0x3f800000;
  }
  else {
    local_10 = 0xbf800000;
  }
  D3DXVec2Normalize(&local_10,&local_10);
  fVar6 = (float10)FUN_008fedca();
  if ((DAT_00fb7c18 & 1) == 0) {
    DAT_00fb7c18 = DAT_00fb7c18 | 1;
    FUN_004449d0();
  }
  iVar4 = (int)ROUND(_DAT_00fb8824 * ((float)fVar6 + 1.5707964));
  uStack_20._0_1_ = (byte)iVar4;
  uStack_20._1_3_ = (undefined3)((uint)iVar4 >> 8);
  *param_4 = (byte)uStack_20;
  iVar4 = FUN_00545f30(iVar4,unaff_EBX);
  if (iVar4 != 0) {
    uVar5 = (uint)(byte)(param_3 + 0x80);
    uStack_20 = CONCAT31(uStack_20._1_3_,param_3 + 0x80);
    iVar4 = FUN_00545f30(uStack_20,unaff_EBX);
    if (iVar4 != 0) {
      uVar5 = 0;
      while (iVar4 = FUN_00545f30(uVar5,unaff_EBX), iVar4 != 0) {
        uVar5 = uVar5 + 1;
        if (0xff < (int)uVar5) {
          *param_4 = param_3;
          return 0;
        }
      }
    }
    *param_4 = (byte)uVar5;
  }
  return 1;
}

