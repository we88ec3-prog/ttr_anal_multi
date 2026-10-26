
void FUN_00642e60(char param_1,short *param_2,char param_3)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  short *psVar6;
  undefined4 ****ppppuVar7;
  uint uVar8;
  int iVar9;
  int unaff_EDI;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  int iStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined1 **ppuStack_6c;
  int iStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined4 uStack_50;
  int iStack_4c;
  undefined1 *puStack_48;
  int iStack_44;
  undefined4 ***apppuStack_40 [2];
  void *pvStack_38;
  int iStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009332a8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_50;
  uStack_5c = DAT_00d61f20 ^ (uint)&stack0xffffffa8;
  ExceptionList = &local_14;
  uStack_60 = 6;
  uStack_64 = 0x642eab;
  (**(code **)(**(int **)(unaff_EDI + 0x134) + 0xb4))();
  uStack_64 = 6;
  iStack_68 = 0x642ebd;
  (**(code **)(**(int **)(unaff_EDI + 0x138) + 0xb4))();
  if (param_1 == '\0') {
    iStack_68 = 0;
    ppuStack_6c = (undefined1 **)0x643111;
    (**(code **)(**(int **)(unaff_EDI + 0x134) + 0x94))();
    iVar5 = *(int *)(unaff_EDI + 0x138);
    if (*(char *)(iVar5 + 0x141) == '\0') goto LAB_00643134;
LAB_00643120:
    ppuStack_6c = (undefined1 **)0xc4ab18;
    uStack_70 = 0x64312a;
    FUN_006edb10();
  }
  else {
    if (param_2 != (short *)0x0) {
      uStack_2c = 7;
      iStack_30 = 0;
      apppuStack_40[0] = (undefined4 ***)((uint)apppuStack_40[0] & 0xffff0000);
      psVar6 = param_2;
      do {
        sVar1 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar1 != 0);
      iStack_68 = (int)psVar6 - (int)(param_2 + 1) >> 1;
      ppuStack_6c = (undefined1 **)param_2;
      uStack_70 = 0x642f6a;
      FUN_00402160();
      local_14 = (void *)0x0;
      iStack_68 = iStack_30 + -8;
      if (0 < iStack_68) {
        ppuStack_6c = (undefined1 **)0x8;
        uStack_70 = 0x642f85;
        FUN_00402400();
      }
      iStack_68 = *(undefined4 *)(unaff_EDI + 0x130);
      ppuStack_6c = (undefined1 **)0x642f96;
      FUN_0075cd30();
      iStack_68 = 0x642fa6;
      (**(code **)(**(int **)(unaff_EDI + 0x130) + 200))();
      if (param_3 != '\0') {
        ppppuVar7 = (undefined4 ****)apppuStack_40[0];
        if (uStack_2c < 8) {
          ppppuVar7 = apppuStack_40;
        }
        puStack_48 = (undefined1 *)&uStack_80;
        FUN_00402250(ppppuVar7);
        FUN_00641e00();
      }
      iStack_68 = 1;
      ppuStack_6c = (undefined1 **)0x642fe3;
      (**(code **)(**(int **)(unaff_EDI + 0x134) + 0x94))();
      iVar5 = *(int *)(unaff_EDI + 0x138);
      uVar2 = *(undefined4 *)(iVar5 + 0xc);
      uVar3 = *(undefined4 *)(iVar5 + 0x10);
      uStack_50 = *(undefined4 *)(iVar5 + 0x14);
      iVar9 = ((*(int *)(*(int *)(unaff_EDI + 0x134) + 0x10) +
               *(int *)(*(int *)(unaff_EDI + 0x130) + 0x10)) -
              *(int *)(*(int *)(unaff_EDI + 0x134) + 8)) - *(int *)(*(int *)(unaff_EDI + 0x130) + 8)
      ;
      uStack_5c = iVar9;
      if (*(char *)(iVar5 + 0x141) == '\0') {
        ppuStack_6c = (undefined1 **)0x643049;
        FUN_00757710();
        iStack_78 = uStack_5c;
      }
      else {
        ppuStack_6c = (undefined1 **)0xc4ab18;
        uStack_70 = 0x643034;
        FUN_006edb10();
        iStack_78 = iVar9;
      }
      *(undefined4 *)(iVar5 + 0x168) = 0;
      *(undefined4 *)(iVar5 + 0x160) = 0;
      *(undefined4 *)(iVar5 + 0x164) = 0;
      *(undefined4 *)(iVar5 + 0x14c) = 0;
      ppuStack_6c = (undefined1 **)uStack_50;
      uStack_7c = 0x643093;
      uStack_74 = uVar2;
      uStack_70 = uVar3;
      (**(code **)(**(int **)(unaff_EDI + 0x138) + 0xbc))();
      uStack_7c = 0x6430a3;
      (**(code **)(**(int **)(unaff_EDI + 0x138) + 200))();
      uVar8 = 0x32 - (iStack_44 + 3);
      *(uint *)(*(int *)(unaff_EDI + 0x138) + 0x144) = uVar8 & ((int)uVar8 < 0) - 1;
      uStack_28 = 0xffffffff;
      if ((undefined4 ****)0x7 < apppuStack_40[0]) {
        uStack_80 = 0x6430e1;
        uStack_7c = uVar3;
        FUN_0089120c();
      }
      apppuStack_40[0] = (undefined4 ***)0x7;
      iStack_44 = 0;
      goto LAB_006431c9;
    }
    iStack_68 = 0;
    ppuStack_6c = (undefined1 **)0x642ede;
    (**(code **)(**(int **)(unaff_EDI + 0x134) + 0x94))();
    puStack_48 = (undefined1 *)0x4b;
    ppuStack_6c = (undefined1 **)0x642eeb;
    iVar5 = FUN_005855b0();
    ppuStack_6c = &puStack_48;
    uStack_70 = 0x642efd;
    FUN_005740f0();
    if (iStack_4c == *(int *)(iVar5 + 4)) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    iVar5 = *(int *)(unaff_EDI + 0x138);
    if (*(char *)(iVar5 + 0x141) != '\0') goto LAB_00643120;
LAB_00643134:
    ppuStack_6c = (undefined1 **)0x64313f;
    FUN_00757710();
  }
  *(undefined4 *)(iVar5 + 0x164) = 0;
  *(undefined4 *)(iVar5 + 0x160) = 0;
  *(undefined4 *)(iVar5 + 0x168) = 0;
  *(undefined4 *)(iVar5 + 0x14c) = 0;
  iVar5 = *(int *)(unaff_EDI + 0x138);
  uStack_5c = *(int *)(iVar5 + 8);
  uStack_70 = *(undefined4 *)(iVar5 + 0x10);
  uStack_74 = *(undefined4 *)(iVar5 + 0xc);
  ppuStack_6c = *(undefined1 ***)(iVar5 + 0x14);
  iStack_78 = *(int *)(*(int *)(unaff_EDI + 0x130) + 0x10) -
              *(int *)(*(int *)(unaff_EDI + 0x130) + 8);
  uStack_7c = 0x6431a9;
  uStack_50 = ppuStack_6c;
  (**(code **)(**(int **)(unaff_EDI + 0x138) + 0xbc))();
  uStack_7c = 0x6431b9;
  (**(code **)(**(int **)(unaff_EDI + 0x138) + 200))();
  *(undefined4 *)(*(int *)(unaff_EDI + 0x138) + 0x144) = 0x32;
LAB_006431c9:
  uStack_7c = 0xcb;
  uStack_80 = 0x6431de;
  (**(code **)(**(int **)(unaff_EDI + 0x134) + 0xb4))();
  uStack_80 = 0xd7;
  (**(code **)(**(int **)(unaff_EDI + 0x138) + 0xb4))();
  ExceptionList = pvStack_38;
  iStack_78 = 0x64320c;
  __security_check_cookie((uint)apppuStack_40[0] ^ (uint)&uStack_74);
  return;
}

