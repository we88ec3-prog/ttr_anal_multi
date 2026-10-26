
void FUN_004df1a0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  char *in_ECX;
  undefined1 *puStack_7c;
  int *piStack_78;
  undefined4 uStack_74;
  int local_70;
  undefined1 auStack_6c [12];
  char acStack_60 [68];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00940588;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&puStack_7c;
  ExceptionList = &local_14;
  local_70 = param_1;
  if (*(int *)(param_1 + 0xa0) != 0) {
    FUN_0082cd30();
    FUN_0089120c();
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  pcVar5 = in_ECX;
  do {
    cVar4 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar4 != '\0');
  if (pcVar5 != in_ECX + 1) {
    _strcpy_s(acStack_60,0x40,"Map/BoundMap/");
    _strcat_s(acStack_60,0x40,in_ECX);
    _strcat_s(acStack_60,0x40,".bnd");
    puStack_7c = (undefined1 *)FUN_00891268();
    uStack_c = 0;
    if (puStack_7c != (undefined1 *)0x0) {
      FUN_0082f470();
    }
    uStack_c = 0xffffffff;
    puStack_7c = (undefined1 *)0x0;
    piStack_78 = (int *)0x0;
    FUN_004e1130();
    uStack_c = 1;
    FUN_004e0f60();
    piVar3 = piStack_78;
    uStack_c = 0xffffffff;
    if (piStack_78 != (int *)0x0) {
      LOCK();
      iVar2 = piStack_78[1] + -1;
      piStack_78[1] = iVar2;
      UNLOCK();
      if (iVar2 == 0) {
        (**(code **)*piStack_78)();
        piVar1 = piVar3 + 2;
        LOCK();
        iVar2 = *piVar1 + -1;
        *piVar1 = iVar2;
        UNLOCK();
        if (iVar2 == 0) {
          (**(code **)(*piVar3 + 4))();
        }
      }
    }
    puStack_7c = (undefined1 *)FUN_00830040();
    FUN_00830230();
    FUN_0082fa40();
    iVar2 = *(int *)(param_1 + 0x9c);
    uStack_74 = *(undefined4 *)(param_1 + 0x98);
    if ((iVar2 != 0) && (cVar4 = FUN_0047c250(), cVar4 != '\0')) {
      FUN_007a31c0(uStack_74,iVar2);
    }
    uVar6 = FUN_0082ff10();
    iVar2 = local_70;
    *(undefined4 *)(local_70 + 0xa0) = uVar6;
    if (*(int *)(local_70 + 0xa4) != 0) {
      FUN_0082cf90();
      FUN_0089120c();
      *(undefined4 *)(iVar2 + 0xa4) = 0;
    }
    if ((puStack_7c != (undefined1 *)0x0) && (iVar7 = FUN_00404ba0(), *(int *)(iVar7 + 0x5f4c) == 2)
       ) {
      puStack_7c = (undefined1 *)FUN_00891268();
      uStack_c = 2;
      if (puStack_7c == (undefined1 *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = FUN_0082cee0();
      }
      uStack_c = 0xffffffff;
      puStack_7c = &stack0xffffff6c;
      *(undefined4 *)(iVar2 + 0xa4) = uVar6;
      FUN_004e0f20();
      FUN_00830630(auStack_6c);
      uStack_c = 3;
      iVar2 = *(int *)(DAT_00fba838 + 0x40);
      if (iVar2 == 0) {
        puStack_7c = (undefined1 *)0x0;
        uVar6 = 0;
        piStack_78 = (int *)0x0;
        uVar8 = 0;
      }
      else {
        uVar6 = *(undefined4 *)(iVar2 + 0x158);
        uVar8 = *(undefined4 *)(iVar2 + 0x15c);
      }
      FUN_0082d050(auStack_6c,uVar6,uVar8);
      uStack_c = 0xffffffff;
      FUN_004df490();
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&puStack_7c);
  return;
}

