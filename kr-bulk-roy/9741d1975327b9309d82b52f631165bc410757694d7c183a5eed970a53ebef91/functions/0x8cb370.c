
undefined4
FUN_008cb370(uint param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  char cVar6;
  int in_EAX;
  int iVar7;
  bool bVar8;
  
  *(uint *)(in_EAX + 0x34) = in_EAX + 0xb8U;
  *(undefined4 *)(in_EAX + 0xd0) = *(undefined4 *)(in_EAX + 0x44);
  *(undefined4 *)(*(int *)(in_EAX + 0x34) + 0x1c) = *(undefined4 *)(in_EAX + 0x48);
  *(uint *)(*(int *)(in_EAX + 0x34) + 0x10) = param_1;
  *(uint *)(*(int *)(in_EAX + 0x34) + 0x14) = param_2;
  *(int *)(*(int *)(in_EAX + 0x34) + 8) = param_3;
  *(undefined4 *)(*(int *)(in_EAX + 0x34) + 0xc) = param_4;
  **(undefined4 **)(in_EAX + 0x34) = param_5;
  *(undefined4 *)(*(int *)(in_EAX + 0x34) + 4) = param_6;
  do {
    puVar1 = *(undefined4 **)(in_EAX + 0x34);
    uVar2 = puVar1[1];
    uVar3 = puVar1[7];
    uVar4 = *puVar1;
    param_3 = puVar1[5];
    param_1 = uVar2;
    param_2 = uVar3;
    if ((int)uVar3 <= (int)uVar2) {
      param_1 = uVar3;
      param_2 = uVar2;
    }
    iVar5 = puVar1[3];
    iVar7 = iVar5;
    if (param_3 <= iVar5) {
      iVar7 = param_3;
      param_3 = iVar5;
    }
    if ((iVar7 < (int)param_1) || ((int)param_2 < param_3)) {
      FUN_008cac90(puVar1);
      *(int *)(in_EAX + 0x34) = *(int *)(in_EAX + 0x34) + 0x18;
    }
    else if (uVar3 == uVar2) {
      *(undefined4 **)(in_EAX + 0x34) = puVar1 + -6;
    }
    else {
      iVar5 = ((int)uVar2 < (int)uVar3) + 1;
      if (*(int *)(in_EAX + 100) != iVar5) {
        iVar7 = *(int *)(in_EAX + 4);
        if (iVar5 == 1) {
          iVar7 = (iVar7 + -1 + uVar3 & -iVar7) - uVar3;
          bVar8 = SBORROW4(iVar7,*(int *)(in_EAX + 8));
          iVar7 = iVar7 - *(int *)(in_EAX + 8);
        }
        else {
          iVar7 = uVar3 - (-iVar7 & uVar3);
          bVar8 = SBORROW4(iVar7,*(int *)(in_EAX + 8));
          iVar7 = iVar7 - *(int *)(in_EAX + 8);
        }
        if ((*(int *)(in_EAX + 100) != 0) &&
           (cVar6 = FUN_008caa50(bVar8 == iVar7 < 0), cVar6 != '\0')) {
          return 1;
        }
        cVar6 = FUN_008ca9a0();
        if (cVar6 != '\0') {
          return 1;
        }
      }
      if (iVar5 == 1) {
        cVar6 = FUN_008caef0(FUN_008cac90,*(undefined4 *)(in_EAX + 0x4c),
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
      *(undefined4 *)(in_EAX + 0x44) = uVar4;
      *(uint *)(in_EAX + 0x48) = uVar2;
      return 0;
    }
  } while( true );
}

