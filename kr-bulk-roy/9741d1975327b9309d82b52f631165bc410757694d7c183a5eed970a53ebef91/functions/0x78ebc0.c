
void FUN_0078ebc0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
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
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = param_1;
  if (param_1 != param_2) {
    while (iVar3 = iVar1 + 0x44, iVar3 != param_2) {
      FUN_00786620();
      if (local_38 < *(int *)(param_1 + 0x10)) {
        FUN_00790680(param_1,param_2);
        FUN_00789eb0();
        iVar1 = iVar3;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x10);
        iVar2 = iVar3;
        while (local_38 < iVar1) {
          *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar2 + -0x40);
          *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + -0x3c);
          *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + -0x38);
          *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar2 + -0x34);
          *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar2 + -0x30);
          *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar2 + -0x2c);
          *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + -0x28);
          *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar2 + -0x24);
          *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar2 + -0x20);
          *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(iVar2 + -0x1c);
          *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)(iVar2 + -0x18);
          *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar2 + -0x14);
          *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(iVar2 + -0x10);
          *(undefined4 *)(iVar2 + 0x38) = *(undefined4 *)(iVar2 + -0xc);
          *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(iVar2 + -8);
          *(undefined4 *)(iVar2 + 0x40) = *(undefined4 *)(iVar2 + -4);
          iVar1 = *(int *)(iVar2 + -0x78);
          iVar2 = iVar2 + -0x44;
        }
        *(undefined4 *)(iVar2 + 0x18) = local_30;
        *(undefined4 *)(iVar2 + 4) = local_44;
        *(undefined4 *)(iVar2 + 0x1c) = local_2c;
        *(undefined4 *)(iVar2 + 8) = local_40;
        *(undefined4 *)(iVar2 + 0x20) = local_28;
        *(int *)(iVar2 + 0x10) = local_38;
        *(undefined4 *)(iVar2 + 0x24) = local_24;
        *(undefined4 *)(iVar2 + 0xc) = local_3c;
        *(undefined4 *)(iVar2 + 0x28) = local_20;
        *(undefined4 *)(iVar2 + 0x14) = local_34;
        *(undefined4 *)(iVar2 + 0x2c) = local_1c;
        *(undefined4 *)(iVar2 + 0x30) = local_18;
        *(undefined4 *)(iVar2 + 0x34) = local_14;
        *(undefined4 *)(iVar2 + 0x38) = local_10;
        *(undefined4 *)(iVar2 + 0x3c) = local_c;
        *(undefined4 *)(iVar2 + 0x40) = local_8;
        iVar1 = iVar3;
      }
    }
  }
  return;
}

