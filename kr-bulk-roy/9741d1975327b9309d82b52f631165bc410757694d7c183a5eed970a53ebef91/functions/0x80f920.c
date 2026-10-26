
undefined4 FUN_0080f920(int param_1,int param_2)

{
  uint uVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  undefined1 local_12c [260];
  char *local_28;
  int local_24;
  undefined4 local_20;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009283b3;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_28 = (char *)0x0;
  local_24 = 0;
  local_20 = 0;
  local_8 = 0;
  local_18 = 0;
  FUN_00811120(local_12c);
  FUN_00811710(uVar1);
  local_8 = 1;
  iVar4 = (local_24 - (int)local_28) / 0x3c;
  FID_conflict__wprintf("Usable sound devices: %d\n",iVar4);
  if (iVar4 == 0) {
    FUN_008110c0();
    ExceptionList = local_10;
    return 0;
  }
  iVar8 = 0;
  if (0 < iVar4) {
    pcVar7 = local_28;
    if (iVar4 < 1) {
      pcVar2 = (char *)0x0;
      goto LAB_0080f9e3;
    }
    do {
      pcVar2 = pcVar7;
      if (0xf < *(uint *)(pcVar7 + 0x14)) {
        pcVar2 = *(char **)pcVar7;
      }
LAB_0080f9e3:
      FID_conflict__wprintf("Device #%d: %s\n",iVar8,pcVar2);
      iVar8 = iVar8 + 1;
      pcVar7 = pcVar7 + 0x3c;
    } while (iVar8 < iVar4);
  }
  if ((iVar4 <= local_18) || (iVar8 = local_18, param_2 == 1)) {
    iVar8 = 0;
    param_2 = -1;
    if (0 < iVar4) {
      pcVar7 = local_28;
      if (iVar4 < 1) {
        pcVar2 = (char *)0x0;
        goto LAB_0080fa2d;
      }
      do {
        pcVar2 = pcVar7;
        if (0xf < *(uint *)(pcVar7 + 0x14)) {
          pcVar2 = *(char **)pcVar7;
        }
LAB_0080fa2d:
        pcVar2 = _strstr(pcVar2,"Software");
        if (pcVar2 != (char *)0x0) {
          param_2 = iVar8;
        }
        iVar8 = iVar8 + 1;
        pcVar7 = pcVar7 + 0x3c;
      } while (iVar8 < iVar4);
      iVar8 = param_2;
      if (param_2 != -1) goto LAB_0080fa5c;
    }
    iVar8 = iVar4 + -1;
  }
LAB_0080fa5c:
  pcVar7 = local_28;
  if (iVar8 < iVar4) {
    iVar6 = *(int *)(local_28 + iVar8 * 0x3c + 0x24);
  }
  else {
    iVar6 = 0;
  }
  *(int *)(param_1 + 8) = iVar6;
  if (iVar6 == 0) {
    *(undefined4 *)(param_1 + 4) = 0;
  }
  else {
    if (iVar8 < iVar4) {
      piVar3 = (int *)(local_28 + iVar8 * 0x3c);
      if (0xf < *(uint *)(local_28 + iVar8 * 0x3c + 0x14)) {
        piVar3 = (int *)*piVar3;
      }
    }
    else {
      piVar3 = (int *)0x0;
    }
    iVar4 = alcOpenDevice(piVar3);
    if (iVar4 != 0) {
      iVar8 = alcCreateContext(iVar4,0);
      if (iVar8 == 0) {
        alcCloseDevice(iVar4);
        pcVar7 = local_28;
      }
      else {
        uVar5 = alcGetString(iVar4,0x1005);
        FID_conflict__wprintf("Opened %s Device\n",uVar5);
        alcMakeContextCurrent(iVar8);
        FUN_00811dd0();
        FUN_00811d10();
        pcVar7 = local_28;
      }
    }
    *(undefined4 *)(param_1 + 4) = 1;
  }
  if (DAT_00fba90c != (HMODULE)0x0) {
    FreeLibrary(DAT_00fba90c);
    DAT_00fba90c = (HMODULE)0x0;
  }
  if (pcVar7 != (char *)0x0) {
    FUN_00811ac0(local_24,param_1);
    FUN_0089120c(pcVar7);
  }
  ExceptionList = local_10;
  return 1;
}

