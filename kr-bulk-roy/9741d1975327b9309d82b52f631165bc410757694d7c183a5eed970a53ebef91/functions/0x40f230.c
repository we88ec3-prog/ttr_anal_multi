
void FUN_0040f230(void)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  int *unaff_EDI;
  undefined1 auStack_68 [20];
  undefined4 uStack_54;
  int *piStack_40;
  undefined1 *puStack_3c;
  uint uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00937254;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&piStack_40;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    uStack_54 = 0x40f28d;
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  if (DAT_00fba7a4 != (int *)0x0) {
    uStack_54 = 0x40f2cf;
    iVar3 = (**(code **)(*DAT_00fba7a4 + 0x1c))();
    if (iVar3 != 0) {
      uVar1 = *(ushort *)(iVar3 + 0x88);
      if ((DAT_00f94394 & 1) == 0) {
        DAT_00f94394 = DAT_00f94394 | 1;
        local_c = 1;
        FUN_005c3de0();
        uStack_54 = 0x40f303;
        _atexit((_func_4879 *)&LAB_00bccc30);
        local_c = 0xffffffff;
      }
      if ((&DAT_00f943f0)[uVar1] == 0) {
        if (((uint)unaff_EDI[10] >> 8 & 1) == 0) goto LAB_0040f545;
        pcVar4 = *(code **)(*unaff_EDI + 0xd4);
      }
      else {
        if (((uint)unaff_EDI[10] >> 8 & 1) == 0) {
          (**(code **)(*unaff_EDI + 0xd0))();
        }
        FUN_00745100();
        (**(code **)(*(int *)unaff_EDI[0x22] + 200))();
        FUN_0040ef80();
        local_c = 2;
        uStack_54 = 0x40f391;
        FUN_00757800();
        local_c = 0xffffffff;
        if (7 < uStack_24) {
          uStack_54 = 0x40f3aa;
          FUN_0089120c();
        }
        uStack_38 = uStack_38 & 0xffff0000;
        uStack_24 = 7;
        uStack_28 = 0;
        (**(code **)(*(int *)unaff_EDI[0x23] + 200))();
        puStack_3c = auStack_68;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(unaff_EDI[0x24]);
        (**(code **)(*(int *)unaff_EDI[0x24] + 200))();
        piStack_40 = *(int **)(iVar3 + 0x3bc);
        piVar2 = (int *)unaff_EDI[0x24];
        pcVar4 = *(code **)(*piVar2 + 0x128);
        if ((int)piStack_40 < 1) {
          piVar2[0x34] = 0;
        }
        else {
          piVar2[0x34] = (int)((float)*(int *)(iVar3 + 0x3c8) / (float)(int)piStack_40);
        }
        (*pcVar4)();
        puStack_3c = auStack_68;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(unaff_EDI[0x25]);
        (**(code **)(*(int *)unaff_EDI[0x25] + 200))();
        piStack_40 = *(int **)(iVar3 + 0x3c0);
        piVar2 = (int *)unaff_EDI[0x25];
        pcVar4 = *(code **)(*piVar2 + 0x128);
        if ((int)piStack_40 < 1) {
          piVar2[0x34] = 0;
        }
        else {
          piVar2[0x34] = (int)((float)*(int *)(iVar3 + 0x3cc) / (float)(int)piStack_40);
        }
        (*pcVar4)();
        piStack_40 = (int *)(iVar3 + 0x3d0);
        puStack_3c = auStack_68;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(unaff_EDI[0x26]);
        (**(code **)(*(int *)unaff_EDI[0x26] + 200))();
        puStack_3c = *(undefined1 **)(iVar3 + 0x3c4);
        piVar2 = (int *)unaff_EDI[0x26];
        if ((int)puStack_3c < 1) {
          piVar2[0x34] = 0;
        }
        else {
          piVar2[0x34] = (int)((float)*piStack_40 / (float)(int)puStack_3c);
        }
        pcVar4 = *(code **)(*piVar2 + 0x128);
      }
      (*pcVar4)();
      goto LAB_0040f545;
    }
  }
  if (((uint)unaff_EDI[10] >> 8 & 1) != 0) {
    (**(code **)(*unaff_EDI + 0xd4))();
  }
LAB_0040f545:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&piStack_40);
  return;
}

