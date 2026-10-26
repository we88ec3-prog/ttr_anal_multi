
void FUN_005d2610(void)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  int *unaff_EDI;
  undefined1 auStack_88 [20];
  undefined4 uStack_74;
  undefined1 auStack_60 [4];
  int *piStack_5c;
  undefined1 *puStack_58;
  uint uStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00935fec;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_60;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    uStack_74 = 0x5d266d;
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  if (DAT_00fba7a4 != (int *)0x0) {
    uStack_74 = 0x5d26af;
    iVar3 = (**(code **)(*DAT_00fba7a4 + 0x1c))();
    if (iVar3 != 0) {
      uVar1 = *(ushort *)(iVar3 + 0x88);
      if ((DAT_00f94394 & 1) == 0) {
        DAT_00f94394 = DAT_00f94394 | 1;
        local_c = 1;
        FUN_005c3de0();
        uStack_74 = 0x5d26e3;
        _atexit((_func_4879 *)&LAB_00bccc30);
        local_c = 0xffffffff;
      }
      if ((&DAT_00f943f0)[uVar1] == 0) {
        if (((uint)unaff_EDI[10] >> 8 & 1) == 0) goto LAB_005d2980;
        pcVar4 = *(code **)(*unaff_EDI + 0xd4);
      }
      else {
        if (((uint)unaff_EDI[10] >> 8 & 1) == 0) {
          (**(code **)(*unaff_EDI + 0xd0))();
        }
        FUN_00745100();
        (**(code **)(*(int *)unaff_EDI[0x22] + 200))();
        FUN_004068f0();
        local_c = 2;
        uStack_74 = 0x5d2777;
        FUN_00757800();
        local_c = 0xffffffff;
        if (7 < uStack_24) {
          uStack_74 = 0x5d2790;
          FUN_0089120c();
        }
        (**(code **)(*(int *)unaff_EDI[0x27] + 200))();
        FUN_0040ef80();
        local_c = 3;
        uStack_74 = 0x5d27cc;
        FUN_00757800();
        local_c = 0xffffffff;
        if (7 < uStack_40) {
          uStack_74 = 0x5d27e5;
          FUN_0089120c();
        }
        uStack_54 = uStack_54 & 0xffff0000;
        uStack_40 = 7;
        uStack_44 = 0;
        (**(code **)(*(int *)unaff_EDI[0x23] + 200))();
        puStack_58 = auStack_88;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(unaff_EDI[0x24]);
        (**(code **)(*(int *)unaff_EDI[0x24] + 200))();
        piStack_5c = *(int **)(iVar3 + 0x3bc);
        piVar2 = (int *)unaff_EDI[0x24];
        pcVar4 = *(code **)(*piVar2 + 0x128);
        if ((int)piStack_5c < 1) {
          piVar2[0x34] = 0;
        }
        else {
          piVar2[0x34] = (int)((float)*(int *)(iVar3 + 0x3c8) / (float)(int)piStack_5c);
        }
        (*pcVar4)();
        puStack_58 = auStack_88;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(unaff_EDI[0x25]);
        (**(code **)(*(int *)unaff_EDI[0x25] + 200))();
        piStack_5c = *(int **)(iVar3 + 0x3c0);
        piVar2 = (int *)unaff_EDI[0x25];
        pcVar4 = *(code **)(*piVar2 + 0x128);
        if ((int)piStack_5c < 1) {
          piVar2[0x34] = 0;
        }
        else {
          piVar2[0x34] = (int)((float)*(int *)(iVar3 + 0x3cc) / (float)(int)piStack_5c);
        }
        (*pcVar4)();
        piStack_5c = (int *)(iVar3 + 0x3d0);
        puStack_58 = auStack_88;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(unaff_EDI[0x26]);
        (**(code **)(*(int *)unaff_EDI[0x26] + 200))();
        puStack_58 = *(undefined1 **)(iVar3 + 0x3c4);
        piVar2 = (int *)unaff_EDI[0x26];
        if ((int)puStack_58 < 1) {
          piVar2[0x34] = 0;
        }
        else {
          piVar2[0x34] = (int)((float)*piStack_5c / (float)(int)puStack_58);
        }
        pcVar4 = *(code **)(*piVar2 + 0x128);
      }
      (*pcVar4)();
      goto LAB_005d2980;
    }
  }
  if (((uint)unaff_EDI[10] >> 8 & 1) != 0) {
    (**(code **)(*unaff_EDI + 0xd4))();
  }
LAB_005d2980:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_60);
  return;
}

