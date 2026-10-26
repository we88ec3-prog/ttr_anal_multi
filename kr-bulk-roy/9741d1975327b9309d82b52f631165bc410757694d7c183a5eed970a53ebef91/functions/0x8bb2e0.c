
int FUN_008bb2e0(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  
  iVar5 = param_1;
  if (((param_1 == 0) || (*(int *)(param_1 + 0x58) == 0)) ||
     (iVar1 = *(int *)(param_1 + 0x54), iVar1 == 0)) {
    return 0x23;
  }
  FUN_008ba370();
  piVar2 = *(int **)((*(undefined4 **)(param_1 + 0x60))[1] + 0xa0);
  if ((param_3 & 0x400) != 0) {
    param_3 = param_3 | 0x801;
  }
  if ((param_3 & 1) != 0) {
    param_3 = param_3 & 0xfffffffb | 10;
  }
  if ((((piVar2 != (int *)0x0) && ((param_3 & 2) == 0)) &&
      (((param_3 & 0x8000) == 0 &&
       ((uVar8 = *(uint *)**(undefined4 **)(param_1 + 0x60), (uVar8 & 0x100) != 0 &&
        ((uVar8 & 0x200) == 0)))))) && ((*(uint *)(param_1 + 8) & 0x2000) == 0)) {
    if ((param_3 & 0x800) == 0) {
      piVar3 = *(int **)(param_1 + 0x80);
      if (((piVar3[2] != 0) || (*piVar3 == 0)) && ((*piVar3 != 0 || (piVar3[2] == 0))))
      goto LAB_008bb490;
    }
    if ((((((param_3 & 0x20) != 0) || ((uVar8 & 0x400) == 0)) || ((param_3 & 0xf0000) == 0x10000))
        || (*(char *)(*(int *)(param_1 + 0x80) + 0x34) != '\0')) ||
       (((((*(byte *)(param_1 + 8) & 8) != 0 && (*(int *)(param_1 + 0x2b8) != 0)) &&
         (*(short *)(param_1 + 0x11e) == 0)) &&
        ((*(int *)(param_1 + 0x274) == 0 && (*(int *)(param_1 + 0x27c) == 0)))))) {
      if (((((*(byte *)(param_1 + 8) & 2) == 0) || ((param_3 & 8) != 0)) ||
          (iVar6 = (**(code **)(*(int *)(*(int *)(param_1 + 0x60) + 0xc) + 0x48))
                             (iVar1,*(undefined4 *)(param_1 + 0x58),param_2,param_3 | 0x4000),
          iVar6 != 0)) || (iVar6 = 0, *(int *)(iVar1 + 0x48) != 0x62697473)) {
        iVar4 = *(int *)(param_1 + 0x80);
        uVar7 = *(undefined4 *)(iVar4 + 0x18);
        *(undefined4 *)(iVar4 + 0x18) = 0;
        iVar6 = (**(code **)(*(int *)(*piVar2 + 0x14) + 0xc))
                          (piVar2,iVar1,*(undefined4 *)(param_1 + 0x58),param_2,param_3);
        *(undefined4 *)(iVar4 + 0x18) = uVar7;
      }
      goto LAB_008bb4eb;
    }
  }
LAB_008bb490:
  iVar6 = (**(code **)(*(int *)(*(int *)(param_1 + 0x60) + 0xc) + 0x48))
                    (iVar1,*(undefined4 *)(param_1 + 0x58),param_2,param_3);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = 0;
  if (*(int *)(iVar1 + 0x48) == 0x6f75746c) {
    iVar6 = FUN_008b93d0(iVar1 + 0x6c);
    if (iVar6 != 0) {
      return iVar6;
    }
    iVar6 = 0;
    if ((param_3 & 2) == 0) {
      FUN_008b8480((byte)param_3 & 0x10);
    }
  }
LAB_008bb4eb:
  param_1 = iVar6;
  if ((param_3 & 0x10) == 0) {
    *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(iVar1 + 0x28);
    *(undefined4 *)(iVar1 + 0x44) = 0;
  }
  else {
    *(undefined4 *)(iVar1 + 0x40) = 0;
    *(undefined4 *)(iVar1 + 0x44) = *(undefined4 *)(iVar1 + 0x34);
  }
  if (((param_3 & 0x2000) == 0) && ((*(byte *)(iVar5 + 8) & 1) != 0)) {
    iVar6 = *(int *)(iVar5 + 0x58);
    uVar7 = FUN_008b7dc0(*(undefined4 *)(iVar1 + 0x38),*(undefined4 *)(iVar6 + 0x10),0x40);
    *(undefined4 *)(iVar1 + 0x38) = uVar7;
    uVar7 = FUN_008b7dc0(*(undefined4 *)(iVar1 + 0x3c),*(undefined4 *)(iVar6 + 0x14),0x40);
    *(undefined4 *)(iVar1 + 0x3c) = uVar7;
  }
  if (((param_3 & 0x800) == 0) && (iVar5 = *(int *)(iVar5 + 0x80), *(int *)(iVar5 + 0x18) != 0)) {
    iVar6 = FUN_008b8ee0();
    if (iVar6 == 0) {
      if (*(int *)(iVar1 + 0x48) == 0x6f75746c) {
        if ((*(byte *)(iVar5 + 0x18) & 1) != 0) {
          FUN_008b9570(iVar1 + 0x6c,iVar5);
        }
        if ((*(byte *)(iVar5 + 0x18) & 2) != 0) {
          FUN_008b94d0(iVar1 + 0x6c,*(undefined4 *)(iVar5 + 0x10),*(undefined4 *)(iVar5 + 0x14));
        }
      }
    }
    else {
      param_1 = (**(code **)(*(int *)(iVar6 + 0xc) + 0x2c))(iVar6,iVar1,iVar5,iVar5 + 0x10);
    }
    FUN_008b9510(iVar1 + 0x40,iVar5);
  }
  if ((((param_1 == 0) && (*(int *)(iVar1 + 0x48) != 0x62697473)) &&
      (*(int *)(iVar1 + 0x48) != 0x636f6d70)) && ((param_3 & 4) != 0)) {
    uVar8 = (int)param_3 >> 0x10 & 0xf;
    if ((uVar8 == 0) && ((param_3 & 0x1000) != 0)) {
      uVar8 = 2;
    }
    param_1 = FUN_008ba9b0(iVar1,uVar8);
  }
  return param_1;
}

