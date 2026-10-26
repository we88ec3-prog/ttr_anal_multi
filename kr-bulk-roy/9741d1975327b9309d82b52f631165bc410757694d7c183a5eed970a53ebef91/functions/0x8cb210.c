
undefined4 FUN_008cb210(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  char cVar6;
  int in_EAX;
  uint uVar7;
  int iVar8;
  bool bVar9;
  
  *(uint *)(in_EAX + 0x34) = in_EAX + 0xb8U;
  *(undefined4 *)(in_EAX + 200) = *(undefined4 *)(in_EAX + 0x44);
  *(undefined4 *)(*(int *)(in_EAX + 0x34) + 0x14) = *(undefined4 *)(in_EAX + 0x48);
  *(uint *)(*(int *)(in_EAX + 0x34) + 8) = param_1;
  *(undefined4 *)(*(int *)(in_EAX + 0x34) + 0xc) = param_2;
  **(undefined4 **)(in_EAX + 0x34) = param_3;
  *(undefined4 *)(*(int *)(in_EAX + 0x34) + 4) = param_4;
  do {
    puVar2 = *(undefined4 **)(in_EAX + 0x34);
    uVar3 = puVar2[1];
    uVar4 = puVar2[5];
    uVar5 = *puVar2;
    uVar7 = uVar3;
    param_1 = uVar4;
    if ((int)uVar4 <= (int)uVar3) {
      uVar7 = uVar4;
      param_1 = uVar3;
    }
    if (((int)puVar2[3] < (int)uVar7) || ((int)param_1 < (int)puVar2[3])) {
      FUN_008cac20(puVar2);
      *(int *)(in_EAX + 0x34) = *(int *)(in_EAX + 0x34) + 0x10;
    }
    else if (uVar4 == uVar3) {
      *(undefined4 **)(in_EAX + 0x34) = puVar2 + -4;
    }
    else {
      iVar1 = ((int)uVar3 <= (int)uVar4) + 1;
      if (*(int *)(in_EAX + 100) != iVar1) {
        iVar8 = *(int *)(in_EAX + 4);
        if (iVar1 == 1) {
          iVar8 = (iVar8 + -1 + uVar4 & -iVar8) - uVar4;
          bVar9 = SBORROW4(iVar8,*(int *)(in_EAX + 8));
          iVar8 = iVar8 - *(int *)(in_EAX + 8);
        }
        else {
          iVar8 = uVar4 - (-iVar8 & uVar4);
          bVar9 = SBORROW4(iVar8,*(int *)(in_EAX + 8));
          iVar8 = iVar8 - *(int *)(in_EAX + 8);
        }
        if ((*(int *)(in_EAX + 100) != 0) &&
           (cVar6 = FUN_008caa50(bVar9 == iVar8 < 0), cVar6 != '\0')) {
          return 1;
        }
        cVar6 = FUN_008ca9a0();
        if (cVar6 != '\0') {
          return 1;
        }
      }
      if (iVar1 == 1) {
        cVar6 = FUN_008caef0(FUN_008cac20,*(undefined4 *)(in_EAX + 0x4c),
                             *(undefined4 *)(in_EAX + 0x50));
      }
      else {
        cVar6 = FUN_008cb060();
      }
      if (cVar6 != '\0') {
        return 1;
      }
    }
    if (*(uint *)(in_EAX + 0x34) < in_EAX + 0xb8U) {
      *(undefined4 *)(in_EAX + 0x44) = uVar5;
      *(uint *)(in_EAX + 0x48) = uVar3;
      return 0;
    }
  } while( true );
}

