
void FUN_0086ee50(int *param_1)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  byte ****ppppbVar6;
  uint unaff_EBX;
  int unaff_EDI;
  bool bVar7;
  uint uStack_6c;
  undefined1 auStack_5c [4];
  byte *local_58;
  undefined1 local_54 [12];
  byte ***apppbStack_48 [5];
  uint uStack_34;
  uint uStack_2c;
  void *pvStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00917e58;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_5c;
  uStack_6c = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  ExceptionList = &local_14;
  iVar4 = *param_1;
  uVar3 = (**(code **)(iVar4 + 0xec))(param_1,local_54);
  (**(code **)(iVar4 + 0x14))(param_1,uVar3);
  FUN_0086d5d0();
  local_1c = 0;
  *(undefined4 *)(unaff_EDI + 0x40) = 0;
  uStack_6c = 0;
  if (unaff_EBX != 0) {
    do {
      iVar4 = *param_1;
      uVar3 = (**(code **)(iVar4 + 0xec))(param_1,uStack_6c);
      iVar4 = (**(code **)(iVar4 + 0x38))(param_1,uVar3);
      if (iVar4 != 0) {
        (**(code **)(*param_1 + 0x18))(param_1,iVar4,&local_58);
        pbVar5 = local_58;
        ppppbVar6 = (byte ****)apppbStack_48[0];
        if (uStack_34 < 0x10) {
          ppppbVar6 = apppbStack_48;
        }
        do {
          bVar2 = *pbVar5;
          bVar7 = bVar2 < *(byte *)ppppbVar6;
          if (bVar2 != *(byte *)ppppbVar6) {
LAB_0086ef31:
            iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
            goto LAB_0086ef36;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar5[1];
          bVar7 = bVar2 < *(byte *)((int)ppppbVar6 + 1);
          if (bVar2 != *(byte *)((int)ppppbVar6 + 1)) goto LAB_0086ef31;
          pbVar5 = pbVar5 + 2;
          ppppbVar6 = (byte ****)((int)ppppbVar6 + 2);
        } while (bVar2 != 0);
        iVar4 = 0;
LAB_0086ef36:
        if (iVar4 == 0) {
          pbVar5 = local_58;
          do {
            bVar2 = *pbVar5;
            pbVar5 = pbVar5 + 1;
          } while (bVar2 != 0);
          ppppbVar6 = (byte ****)apppbStack_48[0];
          if (uStack_34 < 0x10) {
            ppppbVar6 = apppbStack_48;
          }
          pbVar1 = (byte *)((int)ppppbVar6 + 1);
          do {
            bVar2 = *(byte *)ppppbVar6;
            ppppbVar6 = (byte ****)((int)ppppbVar6 + 1);
          } while (bVar2 != 0);
          if ((int)pbVar5 - (int)(local_58 + 1) == (int)ppppbVar6 - (int)pbVar1) {
            *(uint *)(unaff_EDI + 0x40) = uStack_6c;
            break;
          }
        }
      }
      uStack_6c = uStack_6c + 1;
    } while (uStack_6c < unaff_EBX);
  }
  *(undefined4 *)(unaff_EDI + 0x38) = 0;
  if (0xf < uStack_34) {
    FUN_0089120c(apppbStack_48[0]);
  }
  ExceptionList = pvStack_24;
  __security_check_cookie(uStack_2c ^ (uint)&uStack_6c);
  return;
}

