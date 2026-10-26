
void FUN_008e65b0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uint local_54;
  undefined4 local_48 [16];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = *(int *)(param_1 + 0x210);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 4) == param_2)) {
    local_54 = 0;
    if (*(int *)(iVar1 + 4) != 0) {
      pbVar9 = (byte *)(iVar1 + 0x58);
      do {
        uVar10 = (uint)*pbVar9;
        iVar2 = *(int *)(pbVar9 + 4);
        iVar3 = *(int *)(param_3 + local_54 * 4);
        uVar5 = 0;
        uVar8 = 0xffffffff;
        if (uVar10 == 0) {
LAB_008e664a:
          uVar7 = **(undefined4 **)(pbVar9 + 8);
        }
        else {
          do {
            uVar6 = uVar5;
            iVar4 = *(int *)(iVar2 + uVar6 * 4);
            if (iVar3 == iVar4) {
              uVar7 = *(undefined4 *)(*(int *)(pbVar9 + 8) + uVar6 * 4);
              goto LAB_008e668b;
            }
            if (iVar3 < iVar4) goto LAB_008e6643;
            uVar5 = uVar6 + 1;
            uVar8 = uVar6;
          } while (uVar6 + 1 < uVar10);
          uVar6 = 0xffffffff;
LAB_008e6643:
          if ((int)uVar8 < 0) goto LAB_008e664a;
          if ((int)uVar6 < 0) {
            uVar7 = *(undefined4 *)(*(int *)(pbVar9 + 8) + -4 + uVar10 * 4);
          }
          else {
            iVar4 = *(int *)(iVar2 + uVar8 * 4);
            uVar7 = FUN_008b7dc0(iVar3 - iVar4,
                                 *(int *)(*(int *)(pbVar9 + 8) + uVar6 * 4) -
                                 *(int *)(*(int *)(pbVar9 + 8) + uVar8 * 4),
                                 *(int *)(iVar2 + uVar6 * 4) - iVar4);
          }
        }
LAB_008e668b:
        local_48[local_54] = uVar7;
        local_54 = local_54 + 1;
        pbVar9 = pbVar9 + 0xc;
      } while (local_54 < *(uint *)(iVar1 + 4));
    }
    FUN_008e64e0(param_1,param_2,local_48);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

